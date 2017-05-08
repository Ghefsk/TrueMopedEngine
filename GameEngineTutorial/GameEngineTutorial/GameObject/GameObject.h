#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>

#include "../Component/Component.h"
#include "../Spells/Spells.h"
#include "../Controller/Controller.h"

#pragma once

#define AUTO_DEL(x) if(x) { delete x; x = nullptr; }



class GameObject {
public:
	GameObject() {}
	~GameObject();

	template<typename T>
	T* AddComponent();
	template<typename T>
	const T* GetComponent() const;

	void PrintVec();
	void Draw(sf::RenderWindow& win, sf::Sprite& sprite);

private:
	std::vector<Component*> vComponents;
};



// PlayerObj
class Player : public GameObject {
public:
	const void SetTexture(const std::string& filePath);
	const void SetTextureRect(const unsigned int& left, const unsigned int& top, const unsigned int& width, const unsigned int& height);
	const sf::IntRect& GetTextureRect() const;
	sf::Sprite& GetSprite();
	const void SetPosition(const float& newX, const float& newY);
	const float& GetPositionX() const;
	const float& GetPositionY() const;
	const void MovePlayer(float& dt);

	Animator animator;

private:
	sf::Texture m_playerTexture;
	sf::IntRect m_intRect;
	sf::Sprite m_playerSprite;

	std::vector<Spells> vSpells;

	float m_speedMulti = 250;
};


