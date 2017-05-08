#include <SFML\Graphics.hpp>

#pragma once



class Controller {
public:
	Controller() {}
	~Controller() { delete ptr_axis; ptr_axis = nullptr; }

	static void Initialize();

	static void SetAxis(sf::Joystick::Axis axis);
	static bool IsAxis(sf::Joystick::Axis axis);
	static void ClearAxis();

private:
	static bool* ptr_axis;
};
