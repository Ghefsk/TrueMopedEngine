#pragma once
#include <SFML\Window.hpp>

namespace Input
{
	class Keyboard
	{	
	public : 
		static void Initialize(); 

		static void setKeyDown(sf::Keyboard::Key key);
		static void setKeyUp(sf::Keyboard::Key key);
		static bool isKeyDown(sf::Keyboard::Key key); 

		static void clearKeys(); 
		
	private: 
		static bool* keys; 
	};

	class Joystick
	{

		


	public: 

		enum Xbox
		{
			A = 0,
			B = 1,
			X = 2,
			Y = 3,
			LB = 4,
			RB = 5,
			Back = 6,
			Start = 7,
			LSB = 8,
			RSB = 9
		};

		static void Initialize(); 
		static float getAxisPosition(sf::Joystick::Axis axis); 
	
	private: 
		
		

	};

} 
