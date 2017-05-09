#include "Factory.h"
#include <memory>
#include <map>
#include <iostream>

namespace Factory
{
	//Map for the Objects that we load from tmx and an iterator to extract info 
	std::map<std::string, std::unique_ptr<GameObject>> loadedObjects;
	std::map<std::string, std::unique_ptr<GameObject>>::iterator it;



	//Function for creating objects. Should be linked through LUA where the designer only needs to give the new object a name
	void Factory::createObject(std::string Name)
	{
		loadedObjects.insert(std::make_pair(Name, std::unique_ptr<GameObject>(new GameObject)));
	}


	//Function for finding and getting the info from the map. Searches by name
	std::map<std::string, std::unique_ptr<GameObject>>::iterator Factory::getObject(std::string Name)
	{

		it = loadedObjects.find(Name);
		
		if (loadedObjects["Ludvig"] != NULL)
		{
			std::cout << "Ludvig Finns" << std::endl; 
		}
		return it;


	}
}
