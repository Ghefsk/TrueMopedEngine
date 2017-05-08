#pragma once
#include "GameState.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

namespace State
{
	class MenuState : public Game_State
	{
	public:

		MenuState(Application& application);
		~MenuState();
		void input() override; 
		void update(float dt) override; 
		void draw() override; 

	private : 

		sf::Texture menuTexture; 
		sf::Sprite menuSprite; 
		sf::Texture buttonTexture; 
		sf::Sprite buttonSprite; 


	};

}

