#pragma once
#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include <memory>
#include <stack>
#include "States\GameState.h"



class Application
{
public:

	Application();

	void runMainLoop(); 
	void pushState(std::unique_ptr<State::Game_State> state);
	void popState(); 
	void changeState(std::unique_ptr<State::Game_State> state);




private: 
	std::stack<std::unique_ptr<State::Game_State>> m_states; 

	

};

#endif // !APPLICATION_H_INCLUDED