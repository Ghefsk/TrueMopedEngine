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
namespace TmxFinc {
	int GetObjectInt(std::string ObjectName, std::string PropertyName, const Tmx::ObjectGroup *ObjectGroup);



	// string
	std::string GetObjectString(std::string ObjectName, std::string PropertyName, const Tmx::ObjectGroup *ObjectGroup);


	// name  
}