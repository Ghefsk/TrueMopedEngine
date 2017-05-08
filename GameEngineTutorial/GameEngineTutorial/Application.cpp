#include "Application.h"
#include "Display\Display.h"
#include "Input\Input.h"
#include "States\PlayingState.h"
#include <SFML\Window.hpp>

Application::Application()
{
	Display::init(); 
	Input::Joystick::Initialize(); 
	Input::Keyboard::Initialize(); 
	pushState(std::make_unique<State::Playing>(*this));
	
}

void Application::runMainLoop()
{
	sf::Clock clock;

	while (Display::isOpen())
	{
		float dt = clock.restart().asSeconds(); 
		Display::checkWindowEvents(); 
		Display::clear(); 
		

		m_states.top()->input();
		m_states.top()->update(dt); 
		m_states.top()->draw();
		//Input::Keyboard::clearKeys(); 
		

		Display::display(); 
	}
}

void Application::pushState(std::unique_ptr<State::Game_State> state)
{
	m_states.push(std::move(state));
}

void Application::popState()

{
	m_states.pop(); 
}

void Application::changeState(std::unique_ptr<State::Game_State> state)
{
	popState(); 
	pushState(std::move(state));
}



