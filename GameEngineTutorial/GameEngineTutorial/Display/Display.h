#pragma once
#include <SFML\Graphics.hpp>

namespace Display
{
	void init(); 
	void clear();
	void display(); 
	void checkWindowEvents(); 
	void draw(const sf::Drawable& drawable); 
	bool isOpen(); 

	constexpr int HEIGHT = 1000; 
	constexpr int WIDTH = 1000; 
}
