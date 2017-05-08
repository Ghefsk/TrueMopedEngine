#include "Display.h"
#include <memory>
#include "../Input/Input.h"
#include <iostream>


namespace Display
{
	std::unique_ptr<sf::RenderWindow> window; 

	void Display::init()
	{
		window = std::make_unique<sf::RenderWindow>(sf::VideoMode::getDesktopMode(), "Window");
		window->setKeyRepeatEnabled(false);
		
	}

	void Display::clear()
	{
		window->clear();
	}

	void Display::display()
	{
		window->display(); 
	}

	void Display::checkWindowEvents()
	{
		sf::Event e; 

		while (window->pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window->close();
			}
			if (e.type == sf::Event::KeyPressed)
			{
				Input::Keyboard::setKeyDown(e.key.code);
			}
			if (e.type == sf::Event::KeyReleased)
			{
				Input::Keyboard::setKeyUp(e.key.code);
			}
		
			if (e.type == sf::Event::JoystickButtonPressed)
			{
				
			}
			if (e.type == sf::Event::JoystickMoved)
			{

			}
		}
	}

	void draw(const sf::Drawable & drawable)
	{
		window->draw(drawable);
	}

	bool Display::isOpen()
	{
		return true; 
	}
	 
}

