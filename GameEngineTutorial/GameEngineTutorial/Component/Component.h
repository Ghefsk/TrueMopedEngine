#include <SFML\Graphics.hpp>
#include <string>
#include <vector>
#include <typeinfo>
#include <iostream>

#pragma once



// SuperComponent
class Component {
public:
	Component() {}

	int& GetHash();
	void SetName(const std::string& name);
	const std::string GetName() const;

	virtual void CastDown() = 0;

private:
	int m_hash;

	std::string m_name;
};



// TextComponent
class Texture : public Component {
public:
	Texture() { SetName("TextureComponent"); }

	void SetTexture(std::string texture);

	virtual void CastDown() {}

private:
	sf::Texture m_textureComponent;
};



// SpriteComponent
class Sprite : public Component {
public:
	Sprite() { SetName("SpriteComponent"); }

	const sf::Sprite& GetSprite();
	void SetTexture(sf::Texture& texture);

	virtual void CastDown() {}

private:
	sf::Sprite m_spriteComponent;
};



// AnimatorComponent
class Animator : public Component {
public:
	Animator() : m_numberOfRects(0), m_currentRect(0), m_updateFreq(0) { SetName("AnimatorComponent"); }
	~Animator() {}

	const void SetUpdateFreq(const float& newUpFreq);
	const void SetTextureRects(const unsigned int& numOfRects, const unsigned int& newWidth, const unsigned int& newHeight);
	const void AddTextureRect(const unsigned int& vIndex, const unsigned int& newWidth, const unsigned int& newHeight);
	const void RemoveTextureRect(const unsigned int& vecIndex);
	const void SetRectPos(const unsigned int& vIndex, const unsigned int& newLeft, const unsigned int& newTop);
	const void Swap(const unsigned int firstIndex, const unsigned int secondIndex);
	const void SetBeginEndRects(unsigned int indexStart, unsigned int indexEnd);
	const void Animate(sf::Sprite& sprite);

	virtual void CastDown() {}
	
private:
	unsigned int m_numberOfRects;
	unsigned int m_currentRect;
	unsigned int m_indexBegin;
	unsigned int m_indexEnd;
	float m_updateFreq;


	std::vector<sf::IntRect> vIntRect;

	sf::Clock clock;
	sf::Time timer;
};
