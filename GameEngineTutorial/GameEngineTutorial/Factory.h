#pragma once
#include <map>
#include "GameObject\GameObject.h"
#include <memory>


//Used to create Gameobject and then adds them to a list for the update functions to work. 
namespace Factory
{
		void createObject(std::string Name); 
		std::map<std::string, std::unique_ptr<GameObject>>::iterator getObject(std::string Name);
}

