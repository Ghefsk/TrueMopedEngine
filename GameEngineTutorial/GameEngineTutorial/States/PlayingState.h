#pragma once
#include "GameState.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

namespace State
{

	class Playing : public Game_State
	{

		

	public : 
		Playing(Application& application);
		void input() override;
		void update(float dt) override;
		void draw() override;

	private: 
		float ySpeed; 
		float xSpeed; 
		sf::RectangleShape shape; 
		sf::Sound sound; 
		sf::Text text; 



	};
}