#include "Controller.h"



bool* Controller::ptr_axis = 0;

void Controller::Initialize() {

	ptr_axis = new bool[sf::Joystick::AxisCount];
	for (size_t i = 0; i < sf::Joystick::AxisCount; i++) {

		ptr_axis[i] = false;
	}
}

void Controller::SetAxis(sf::Joystick::Axis axis) {

	ptr_axis[axis] = true;
}

bool Controller::IsAxis(sf::Joystick::Axis axis) {

	return ptr_axis[axis];
}

void Controller::ClearAxis() {

	for (size_t i = 0; i < sf::Joystick::AxisCount; i++) {

		ptr_axis[i] = false;
	}
}
