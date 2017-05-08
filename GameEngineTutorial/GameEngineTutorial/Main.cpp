//#include <iostream>
//#include "Application.h"
//#include "Random/Random.h"
#include <lua.hpp>
#include <LuaBridge.h>
#include <iostream>






//int main()
//{
//	/*Application app;
//	Random::init();
//	app.runMainLoop();*/
//
//
//	}



	using namespace luabridge;
	int main() {

		lua_State* L = luaL_newstate();
		luaL_dofile(L, "script.lua");
		luaL_openlibs(L);
		lua_pcall(L, 0, 0, 0);
		LuaRef s = getGlobal(L, "testString");
		LuaRef n = getGlobal(L, "number");
		std::string luaString = s.cast<std::string>();
		int answer = n.cast<int>();
		std::cout << luaString << std::endl;
		std::cout << "And here's our number:" << answer << std::endl;
	}
	
	
