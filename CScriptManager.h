#pragma once

#include <vector>
#include <string>
#include <stdio.h>
#include "Script.h"
#include <sys/types.h>
#include <dirent.h>
#include <iostream>

using namespace std;
class CScriptManager
{
	
public:
	CScriptManager();
	~CScriptManager();
	vector<Script> scripts;
	
	void LoadALL();
	void Reload();
	
	int ScriptsCount();
	
	int GetScriptIndex(lua_State *L);
	
};
