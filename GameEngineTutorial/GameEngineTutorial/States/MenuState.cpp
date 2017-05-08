#include "MenuState.h"
#include "../Application.h"
#include "../Display/Display.h"



namespace State
{

	MenuState::MenuState(Application& application) 
		: Game_State(application)
	{
		menuTexture.loadFromFile("../Resources/Textures/PNG/blue_panel.png"); 
		menuSprite.setTexture(menuTexture);
		menuSprite.setOrigin(50, 50); 
		menuSprite.setPosition(500, 500); 

		buttonTexture.loadFromFile("../Resources/Textures/PNG/blue_button00.png");
		buttonSprite.setTexture(buttonTexture); 
		buttonSprite.setOrigin(95, 25);
		buttonSprite.setPosition(500, 600);

	}


	MenuState::~MenuState()
	{

	}

	void MenuState::input()
	{
		
	}

	void MenuState::update(float dt)
	{
	}

	void MenuState::draw()
	{
		Display::draw(menuSprite);
		Display::draw(buttonSprite);
	}

}