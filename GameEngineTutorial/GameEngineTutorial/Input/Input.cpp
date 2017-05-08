#include "Input.h"
#include <iostream>

bool* Input::Keyboard::keys = 0; 

//Keyboard 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Input::Keyboard::Initialize()
{
	keys = new bool[sf::Keyboard::KeyCount]; 

	for (size_t i = 0; i < sf::Keyboard::KeyCount; i++)
	{
		keys[i] = false;
	}

}

void Input::Keyboard::setKeyDown(sf::Keyboard::Key key)
{
	keys[key] = true;
}

void Input::Keyboard::setKeyUp(sf::Keyboard::Key key)
{
	keys[key] = false; 
}

bool Input::Keyboard::isKeyDown(sf::Keyboard::Key key)
{
	return keys[key];
}

void Input::Keyboard::clearKeys()
{
	for (size_t i = 0; i < sf::Keyboard::KeyCount; i++)
	{
		keys[i] = false;
	}
}



//JoyStick
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Input::Joystick::Initialize()
{
	if (sf::Joystick::isConnected(0))
	{
		//Collects joystick info 
		sf::Joystick::Identification id = sf::Joystick::getIdentification(0);
		sf::String controller("Joystick Use: " + id.name); 
		std::cout << "\nVendor ID: " << id.vendorId << "\nProduct ID: " << id.productId << std::endl; 


		//Get the number of buttons on the joystick 
		unsigned int buttonCount = sf::Joystick::getButtonCount(0); 
		bool hasZ = sf::Joystick::hasAxis(0, sf::Joystick::Z); 

		std::cout << buttonCount << std::endl; 
		std::cout << "Has a Z axis: " << hasZ << std::endl; 

		//Check for axis Z 
		
	}


	

}


//Returns the axis position, can be used for any axis on the controller including trigger buttons. 
float Input::Joystick::getAxisPosition(sf::Joystick::Axis axis)
{
	return sf::Joystick::getAxisPosition(0, axis); 
}
