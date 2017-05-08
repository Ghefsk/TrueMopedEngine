#include "GameObject.h"



// GameObject
GameObject::~GameObject() {

	for (auto c : vComponents)
		AUTO_DEL(c);
}

template <typename T>
T* GameObject::AddComponent() {

	//typeid(T*).hash_code;
	T* c = new T();

	vComponents.push_back(c);

	return c;
}

template<typename T>
const T* GameObject::GetComponent() const {

	T* c = new T();

	for (unsigned i = 0; i < vComponents.size(); i++) {

		if (typeid(c) == typeid(vComponents[i])) {

			std::cout << "Hej" << std::endl;
			return c;
		} 
		else {

			std::cout << "Dra" << std::endl;
			return NULL;
		}
	}
}

void GameObject::PrintVec() {

	for (unsigned i = 0; i < vComponents.size(); i++)
		std::cout << vComponents[i]->GetName() << std::endl;
}

void GameObject::Draw(sf::RenderWindow& win, sf::Sprite& sprite) {

	win.draw(sprite);
}



// Player
const void Player::SetTexture(const std::string& filePath) {

	m_playerTexture.loadFromFile(filePath);
	m_playerSprite.setTexture(m_playerTexture);
}

const void Player::SetTextureRect(const unsigned int& left, const unsigned int& top, const unsigned int& width, const unsigned int& height) {

	m_intRect = sf::IntRect(left, top, width, height);
	m_playerSprite.setTextureRect(m_intRect);
}

const sf::IntRect& Player::GetTextureRect() const {
	
	return m_intRect;
}

sf::Sprite& Player::GetSprite() {

	return m_playerSprite;
}

const void Player::SetPosition(const float& newX, const float& newY) {
	
	m_playerSprite.setPosition(sf::Vector2f(newX, newY));
}

const float& Player::GetPositionX() const {

	return m_playerSprite.getPosition().x;
}

const float& Player::GetPositionY() const {

	return m_playerSprite.getPosition().y;
}

const void Player::MovePlayer(float& dt) {

	sf::Vector2f vMove;

	float lsHori = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis(0));
	float lsVert = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis(1));

	float dpHori = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis(6));
	float dpVert = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis(7));

	if (lsHori <= -50 ||
		dpHori <= -50 ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

		vMove.x += -1;
	}
	if (lsHori >= 50 ||
		dpHori >= 50 ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

		vMove.x += 1;
	}
	if (lsVert <= -50 ||
		dpVert <= -50 ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

		vMove.y += 1;
	}
	if (lsVert >= 50 ||
		dpVert >= 50 ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

		vMove.y -= 1;
	}

	if (vMove.x != 0 && vMove.y != 0)
		vMove /= sqrt(2.0f);

	m_playerSprite.move(vMove * dt * m_speedMulti);
}
