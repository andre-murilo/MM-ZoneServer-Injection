#pragma once

extern "C" {
#include "lua/lualib.h"
#include "lua/lauxlib.h"
#include "lua/lua.h"
}

#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include "XHero.h"


/*
struct Event
{
	std::string EventName;
	std::string TargetFunction;

	Event(std::string name, std::string TargetFunction)
	{
		this->EventName = EventName;
		this->TargetFunction = TargetFunction;
	}
	Event()
	{

	}
	
	
};*/

using namespace std;

class Script
{
public:
	//std::vector<Event> events;
	int m_EventsSize;
	std::vector<Script> *scripts;

	Script();
	Script(char* name, std::vector<Script> *scripts);
	~Script();

	void SetName(char *name);
	char* GetName();
	lua_State *GetLState();
	bool Load();
	void CallFunction(std::string name, int hero_addr);
	int AddEventHandler(lua_State *L);
	//void RegisterFunctions(lua_State *L);
	void Close();

private:
	char *script_name;
	lua_State *L;
	bool IsOpen;

};

//void TriggerEvent(std::string source, int heroAddr, EventArgs args);

