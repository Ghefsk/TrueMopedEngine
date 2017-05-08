#pragma once
#include <lua.hpp>
#include <LuaBridge.h>


using namespace luabridge; 
namespace LuaTest
{
	
		void init();

	
	
	/*luaL_dofile(L, "script.lua");
	luaL_openlibs(L);
	lua_pcall(L, 0, 0, 0);
	LuaRef s = getGlobal(L, "testString");
	LuaRef n = getGlobal(L, "number");
	std::string luaString = s.cast<std::string>();
	int answer = n.cast<int>();*/



}; 


