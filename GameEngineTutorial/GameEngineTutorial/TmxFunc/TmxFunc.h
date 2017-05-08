#pragma once
// all TMX bibl we need 
#include <Tmx\TmxMap.h>
#include <Tmx\TmxObjectGroup.h>
#include <Tmx\TmxObject.h>
#include <Tmx\TmxTileset.h>
#include <Tmx\TmxTileLayer.h>
#include <Tmx\TmxImage.h>
#include <Tmx\TmxTile.h>
#include <Tmx\TmxMapTile.h>


// functions depending on variable types

// int 
int GetObjectInt(std::string ObjectName, std::string PropertyName, const Tmx::ObjectGroup *ObjectGroup)
{

	for (size_t i = 0; i < ObjectGroup->GetNumObjects(); i++)
	{	

		if (ObjectName == ObjectGroup->GetObject(i)->GetName())
		{
	
			if (ObjectGroup->GetObject(i)->GetProperties().HasProperty(PropertyName))



			return ObjectGroup->GetObject(i)->GetProperties().GetIntProperty(PropertyName);
		}
	}
}


// string
std::string GetObjectString(std::string ObjectName, std::string PropertyName, const Tmx::ObjectGroup *ObjectGroup)
{

	for (size_t i = 0; i < ObjectGroup->GetNumObjects(); i++)
	{
	
		if (ObjectName == ObjectGroup->GetObject(i)->GetName())
		{


			if (ObjectGroup->GetObject(i)->GetProperties().HasProperty(PropertyName))

			return ObjectGroup->GetObject(i)->GetProperties().GetStringProperty(PropertyName);
		}
	}
}

// name  
