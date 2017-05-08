#include <iostream>
#include "Application.h"
#include "Random/Random.h"



int main()
{
	Application app;
	Random::init();
	app.runMainLoop();
	
	
}