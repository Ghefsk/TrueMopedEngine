#include "Component.h"



// Super
int& Component::GetHash() {

	return m_hash;
}

void Component::SetName(const std::string& name) {

	m_name = name;
}

const std::string Component::GetName() const {

	return m_name;
}



// Texture
void Texture::SetTexture(std::string texture) {

	std::string filePath = "D:\BadGame\Textures";
	filePath.append(texture);
	m_textureComponent.loadFromFile(filePath);
}



// Sprite
const sf::Sprite& Sprite::GetSprite() {

	return m_spriteComponent;
}

void Sprite::SetTexture(sf::Texture& texture) {

	m_spriteComponent.setTexture(texture);
}



// Animator
const void Animator::SetUpdateFreq(const float& newUpFreq) {

	m_updateFreq = newUpFreq;
}

const void Animator::SetTextureRects(const unsigned int& numOfRects, const unsigned int& newWidth, const unsigned int& newHeight) {

	for (unsigned int i = 0; i < numOfRects; i++)
		vIntRect.push_back(sf::IntRect(0, 0, newWidth, newHeight));
}

const void Animator::AddTextureRect(const unsigned int& vIndex, const unsigned int& newWidth, const unsigned int& newHeight) {

	vIntRect.insert(vIntRect.begin() + vIndex, sf::IntRect(0, 0, newWidth, newHeight));
}

const void Animator::RemoveTextureRect(const unsigned int& vIndex) {

	vIntRect.erase(vIntRect.begin() + vIndex);
}

const void Animator::SetRectPos(const unsigned int& vIndex, const unsigned int& newLeft, const unsigned int& newTop) {

	vIntRect[vIndex].left = newLeft;
	vIntRect[vIndex].top = newTop;
}

const void Animator::Swap(const unsigned int firstIndex, const unsigned int secondIndex) {

	sf::IntRect tempRect = vIntRect[firstIndex];
	vIntRect[firstIndex] = vIntRect[secondIndex];
	vIntRect[secondIndex] = tempRect;
}

const void Animator::SetBeginEndRects(unsigned int indexBegin, unsigned int indexEnd) {
	
	m_indexBegin = indexBegin;
	m_indexEnd = indexEnd;

	m_currentRect = indexBegin;
}

const void Animator::Animate(sf::Sprite& sprite) {

	timer = clock.getElapsedTime();

	if (timer.asSeconds() >= m_updateFreq) {

		if (m_currentRect > m_indexEnd)
			m_currentRect = m_indexBegin;

		sprite.setTextureRect(vIntRect[m_currentRect]);

		timer.Zero;
		clock.restart();
		m_currentRect++;
	}
}
