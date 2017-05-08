#include "Factory.h"
#include <memory>
#include <map>
#include <iostream>

namespace Factory
{

	std::map<std::string, std::unique_ptr<GameObject>> loadedObjects;
	std::map<std::string, std::unique_ptr<GameObject>>::iterator it;

	void Factory::createObject(std::string Name)

	{
		loadedObjects.insert(std::make_pair(Name, std::unique_ptr<GameObject>(new GameObject)));
	}

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
