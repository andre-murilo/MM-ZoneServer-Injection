#include "Script.h"



Script::Script()
{
	this->IsOpen = false;
	this->L = luaL_newstate();
	this->m_EventsSize = 0;
}


Script::Script(char* name, std::vector<Script> *scripts)
{
	this->script_name = name;
	this->IsOpen = false;
	this->L = luaL_newstate();
	this->m_EventsSize = 0;
	this->scripts = scripts;
}


Script::~Script()
{

}


void Script::SetName(char *name)
{
	this->script_name = name;
}

char* Script::GetName()
{
	return this->script_name;
}

lua_State *Script::GetLState()
{
	return this->L;
}

bool Script::Load()
{
	luaL_openlibs(this->L);
	int result = luaL_dofile(this->L, this->script_name);
	if (result != LUA_OK)
	{
		this->IsOpen = false;
		return false;
	}

	this->IsOpen = true;
	return true;
}



void Script::CallFunction(string name, int hero_addr)
{
	printf("call func: %s\n", name.c_str());
	
	lua_getglobal(this->L, name.c_str());
	lua_pushnumber(this->L, hero_addr);
	
	lua_pcall(this->L, 1, 0, 0);
}


int Script::AddEventHandler(lua_State *L)
{
	/*
	std::string event_name = lua_tostring(L, 1);
	std::string target_name = lua_tostring(L, 2);

	
	int index = sctManager.GetScriptIndex(L);
	
	if (index == -1)
	{
		int result = 0;          // failed
		lua_pushnumber(L, result);
		
		//printf("Falha ao achar script index!\n");
		return 1;
	}
	
	
	Event event(event_name, target_name);
	
	// adiciona novo event
	
	
	sctManager.scripts[index].events.push_back(event);

	//printf("Funcao: %s => %s foi adicionada com sucesso!\n", event_name.c_str(), target_name.c_str());
	
	int result = 1;         // sucesso
	lua_pushnumber(L, result);

	*/
	return 1;
}




void Script::Close()
{
	if (this->IsOpen)
		lua_close(this->L);
}


/*
void TriggerEvent(string source, int heroAddr, EventArgs args)
{
	for (int i = 0; i < (int)sctManager.ScriptsCount(); i++)
	{
		for (int j = 0; j < (int)sctManager.scripts[i].events.size(); j++)
		{
			if (strcmp(sctManager.scripts[i].events[j].EventName.c_str(), source.c_str()))
			{				
				sctManager.scripts[i].CallFunction(sctManager.scripts[i].events[j].TargetFunction, heroAddr, args);
			}
		}
	}
} */


#pragma region HERO_FUNC_LUA


int GetItemCount(lua_State *L)
{
	int h_addr = lua_tointeger(L, 1); 
	XHero *myHero = new XHero(h_addr, true);
	
	char bagType = (char)lua_tointeger(L, 2);
	unsigned int itemID = lua_tounsigned(L, 3);
	
	// pega o numero de slots restantes
	int result = myHero->GetItemCount(bagType, itemID);  // 30 slots
	lua_pushnumber(L, result);
	delete(myHero);
	return 1;
}

int GetItemDuration(lua_State *L)
{
	int hero = lua_tointeger(L, 1); 
	int itemID = lua_tointeger(L, 2);

	int result = 3600;  // 1 hora

	lua_pushnumber(L, result);
	return 1;
}

int GetHeroType(lua_State *L)
{
	int h_addr = lua_tointeger(L, 1); 
	XHero *myHero = new XHero(h_addr, true);
	

	int result = myHero->GetHeroType();  // ditt
	lua_pushnumber(L, result);
	delete(myHero);
	return 1;
}

int AddItemCount(lua_State *L)
{
	int h_addr = lua_tointeger(L, 1); 
	XHero *myHero = new XHero(h_addr, true);
	int itemID = lua_tounsigned(L, 2); 
	int count = lua_tointeger(L, 3); 
	
	
	int result = myHero->AddPocketItem(itemID, count, true, -1);  // sucesso
	lua_pushnumber(L, result);
	delete(myHero);
	return 1;
}

int AddItemOnTime(lua_State *L)
{
	int h_addr = lua_tointeger(L, 1); 
	XHero *myHero = new XHero(h_addr, true);
	
	int itemID = lua_tounsigned(L, 2); 
	int count = lua_tointeger(L, 3); 
	int duration = lua_tointeger(L, 4);

	myHero->AddPocketItem(itemID, count, true, duration);
	
	int result = 1;  // sucesso
	lua_pushnumber(L, result);
	delete(myHero);
	return 1;
}

int GetHeroLv(lua_State *L)
{
	int h_addr = lua_tointeger(L, 1); 
	XHero *myHero = new XHero(h_addr, true);
	
	
	unsigned short result = myHero->GetLv();   // lv
	lua_pushunsigned(L, result);
	delete(myHero);
	return 1;
}


// exist
int GetHeroSts(lua_State *L)
{
	int h_addr = lua_tointeger(L, 1); 
	XHero *myHero = new XHero(h_addr, true);
	
	char stsType = (char)lua_tounsigned(L, 2);  

	int result = myHero->GetSts(stsType);   // hp, mp, agility etc
	lua_pushnumber(L, result);
	delete(myHero);
	return 1;
}

// exist
int SetHeroSts(lua_State *L)
{
	int h_addr = lua_tointeger(L, 1); 
	XHero *myHero = new XHero(h_addr, true);
	
	unsigned char stsType = (unsigned char)lua_tounsigned(L, 2); 
	unsigned short count = lua_tounsigned(L, 3); 

	myHero->SetAsyncSTS(stsType, count);
	
	
	int result = myHero->GetSts(stsType);  // novo valor
	lua_pushnumber(L, result);
	delete(myHero);
	return 1;
}

int GetHeroFreePoint(lua_State *L)
{
	int h_addr = lua_tointeger(L, 1); 
	XHero *myHero = new XHero(h_addr, true); 

	
	
	unsigned short result = myHero->GetHeroFreePoints();   // status free points
	lua_pushunsigned(L, result);
	delete(myHero);
	return 1;
}

int AddHeroFreePoint(lua_State *L)
{
	int hero = lua_tointeger(L, 1); 
	int count = lua_tointeger(L, 2); 

	int result = 50;  // nova quantia
	lua_pushnumber(L, result);
	return 1;
}

int AddHeroExp(lua_State *L)
{
	int hero = lua_tointeger(L, 1); 
	long double exp_count = lua_tointeger(L, 2);

	long double result = 8005601230;  // nova quantia
	lua_pushnumber(L, result);
	return 1;
}

int GetSwitchCount(lua_State *L)
{
	int hero = lua_tointeger(L, 1); 
	int switch_id = lua_tointeger(L, 2);

	int result = 2;  // switch count result
	lua_pushnumber(L, result);
	return 1;
}

int AddSwitchCount(lua_State *L)
{
	int hero = lua_tointeger(L, 1); 
	int switch_id = lua_tointeger(L, 2);
	int value = lua_tointeger(L, 3);

	int result = 5;  // novo valor do switch
	lua_pushnumber(L, result);
	return 1;
}

int SetSwitchCount(lua_State *L)
{
	int hero = lua_tointeger(L, 1); 
	int switch_id = lua_tointeger(L, 2);
	int value = lua_tointeger(L, 3);

	int result = 3;  // novo valor do switch
	lua_pushnumber(L, result);
	return 1;
}

int GetSwitchTime(lua_State *L)
{
	int hero = lua_tointeger(L, 1); 
	int switch_id = lua_tointeger(L, 2);

	int result = 7200;  // tempo do switch
	lua_pushnumber(L, result);
	return 1;
}

int SetSwitchCurTime(lua_State *L)
{
	int hero = lua_tointeger(L, 1); 
	int switch_id = lua_tointeger(L, 2);

	int result = 3600;  // tempo novo do switch
	lua_pushnumber(L, result);
	return 1;
}

int SetSwitchTime(lua_State *L)
{
	int hero = lua_tointeger(L, 1); 
	int switch_id = lua_tointeger(L, 2);
	long double switch_time = lua_tointeger(L, 3);

	long double result = 3600;  // tempo novo do switch
	lua_pushnumber(L, result);
	return 1;
}





int GetHench(lua_State *L)
{
	int hero = lua_tointeger(L, 1); 
	int hench_ID = lua_tointeger(L, 2); 

	int result = 57;  // henchID
	lua_pushnumber(L, result);
	return 1;
}

int AddHench(lua_State *L)
{
	int hero = lua_tointeger(L, 1); 
	int hench_ID = lua_tointeger(L, 2); 
	int count = lua_tointeger(L, 3); 

	int result = 1;  // sucesso
	lua_pushnumber(L, result);
	return 1;
}

int GetHenchDuration(lua_State *L)
{
	int hero = lua_tointeger(L, 1); 
	int hench_ID = lua_tointeger(L, 2); 

	long double result = 3600;  // tempo de duracao do hench
	lua_pushnumber(L, result);
	return 1;
}

int GetEmptyHenchPocket(lua_State *L)
{
	int hero = lua_tointeger(L, 1); 
	int bag_type = lua_tointeger(L, 2);  // se equipado ou na mochila

	int result = 3;  // espacos livres
	lua_pushnumber(L, result);
	return 1;
}

int GetOccupiedHenchPocket(lua_State *L)
{
	int hero = lua_tointeger(L, 1); 
	int bag_type = lua_tointeger(L, 2);  // se equipado ou na mochila

	int result = 17;  // espacoes usados
	lua_pushnumber(L, result);
	return 1;
}



int SetReturnTimer(lua_State *L)
{
	int hero = lua_tointeger(L, 1); 
	long double time_cnt = lua_tointeger(L, 2); 
	int map_target = lua_tointeger(L, 3); 

	int result = 1;  // sucesso
	lua_pushnumber(L, result);
	return 1;
}

int GetZone(lua_State *L)
{
	int hero = lua_tointeger(L, 1); 

	int result = 57;  // posicao do jogador
	lua_pushnumber(L, result);
	return 1;
}

int GetReviveLayer(lua_State *L)
{
	int hero = lua_tointeger(L, 1); 

	int result = 254;  // layer de ressureicao
	lua_pushnumber(L, result);
	return 1;
}

int SetReviveZone(lua_State *L)
{
	int hero = lua_tointeger(L, 1); 
	int map_id = lua_tointeger(L, 2); 

	int result = 1;  // sucesso
	lua_pushnumber(L, result);
	return 1;
}


int ChangeAllSTSToFPoint(lua_State *L)
{
	int hero = lua_tointeger(L, 1);

	int result = 1;  // sucesso
	lua_pushnumber(L, result);
	return 1;
}



// exist (OK)
int GetMoney(lua_State *L)
{
	int h_addr = lua_tointeger(L, 1); 
	XHero *myHero = new XHero(h_addr, true);
	
	unsigned int cur_money = myHero->GetMoney();
	

	lua_pushunsigned(L, cur_money);
	
	delete(myHero);
	return 1;
}

// exist (OK)
int AddMoney(lua_State *L)
{
	int h_addr = lua_tointeger(L, 1); 
	XHero *myHero = new XHero(h_addr, true);
	
	unsigned int amount = lua_tounsigned(L, 2); 

	myHero->AddMoney(amount);
	
	unsigned int cur_money = myHero->GetMoney();   // nova quantia de gp
	lua_pushunsigned(L, cur_money);
	
	delete(myHero);
	return 1;
}

// exist (OK)
int MoveZone(lua_State *L)
{
	int h_addr = lua_tointeger(L, 1); 
	XHero *myHero = new XHero(h_addr, true);
	
	unsigned short map_id = lua_tointeger(L, 2); 
	unsigned short layer = lua_tointeger(L, 3); 

	
	int result = myHero->MoveZone(map_id, layer);
	
	lua_pushnumber(L, result);
	
	delete(myHero);
	return 1;
}

// exist (OK)
int SetNickname(lua_State *L)
{
	int h_addr = lua_tointeger(L, 1); 
	XHero *myHero = new XHero(h_addr, true);
	unsigned short nickname_id = lua_tounsigned(L, 2);

	myHero->SetNickname(nickname_id);
	
	int result = 1;   // sucesso
	lua_pushnumber(L, result);
	
	delete(myHero);
	return 1;
}

// exist (OK)
int KillHero(lua_State *L)
{
	int h_addr = lua_tointeger(L, 1); 
	XHero *myHero = new XHero(h_addr, true);

	myHero->Dead();
	
	int result = 1;   // sucesso
	lua_pushnumber(L, result);
	
	delete(myHero);
	return 1;
}

// exist (OK)
int ReviveHero(lua_State *L)
{
	int h_addr = lua_tointeger(L, 1); 
	XHero *myHero = new XHero(h_addr, true);
	
	myHero->Revive();

	int result = 1;    // sucesso
	lua_pushnumber(L, result);
	
	delete(myHero);
	return 1;
}

// exist (OK)
int ReviveCore(lua_State *L)
{
	int h_addr = lua_tointeger(L, 1); 
	XHero *myHero = new XHero(h_addr, true);
	
	unsigned char hench_id = (unsigned char)lua_tounsigned(L, 2);

	
	int result = myHero->ReviveCore(hench_id);
	lua_pushnumber(L, result);
	
	
	delete(myHero);
	return 1;
}

// exist (OK)
int StartQuest(lua_State *L)
{
	int h_addr = lua_tointeger(L, 1); 
	XHero *myHero = new XHero(h_addr, true);
	
	unsigned short quest_id = lua_tounsigned(L, 2);

	int result = myHero->StartQuest(quest_id);
	lua_pushnumber(L, result);
	
	
	delete(myHero);
	return 1;
}

// exist (OK)
int EndQuest(lua_State *L)
{
	int h_addr = lua_tointeger(L, 1); 
	XHero *myHero = new XHero(h_addr, true);
	

	unsigned short quest_id = lua_tounsigned(L, 2);

	
	int result = myHero->EndQuest(quest_id);
	lua_pushnumber(L, result);
	
	delete(myHero);
	return 1;
}

// not exist
int MoveToReviveZone(lua_State *L)
{
	int hero = lua_tointeger(L, 1);
	
	int result = 1;        // sucesso
	lua_pushnumber(L, result);
	return 1;
}

// exist (OK)
int RemoveHenchPocket(lua_State *L)
{
	int h_addr = lua_tointeger(L, 1); 
	XHero *myHero = new XHero(h_addr, true);
	
	unsigned char hench_id = (unsigned char)lua_tounsigned(L, 2);
	
	
	int result = myHero->RemovePocketHench(hench_id);
	lua_pushnumber(L, result);
	
	delete(myHero);
	return 1;
}

// exist (OK)
int RemoveMyStoreHench(lua_State *L)
{
	int h_addr = lua_tointeger(L, 1); 
	XHero *myHero = new XHero(h_addr, true);
	
	unsigned char hench_id = (unsigned char)lua_tounsigned(L, 2);
	
	
	int result = myHero->RemoveStoreHench(hench_id);
	lua_pushnumber(L, result);
	
	delete(myHero);
	return 1;
}

// exist
int IsHeroAdmin(lua_State *L)
{
	int h_addr = lua_tointeger(L, 1); 
	XHero *myHero = new XHero(h_addr, true);
	
	int result = 0;
	
	if (myHero->IsAdmin())
		result = 1; // admin
	else
		result = 0; // normal player
	
	
	lua_pushnumber(L, result);
	
	delete(myHero);
	return 1;
}

// exist (OK)
int GetHeroName(lua_State *L)
{
	int h_addr = lua_tointeger(L, 1); 
	XHero *myHero = new XHero(h_addr, true);
	
	
	std:string name = myHero->GetHeroName();
	
	lua_pushstring(L, name.c_str());
	delete(myHero);
	return 1;
}

int GetRemainPocket(lua_State *L)
{
	int h_addr = lua_tointeger(L, 1); 
	XHero *myHero = new XHero(h_addr, true);
	
	int result = myHero->GetRemainPocket();
	
	lua_pushnumber(L, result);
	
	delete(myHero);
	return 1;
}


#pragma endregion



/*
void RegisterFunctions(lua_State *L)
{
	// AddEventHandler
	lua_pushcfunction(L, AddEventHandler);
	lua_setglobal(L, "AddEventHandler");
	

	// GetItemCount
	lua_pushcfunction(L, GetItemCount);
	lua_setglobal(L, "GetItemCount");
	
	
	// GetHeroSts
	lua_pushcfunction(L, GetHeroSts);
	lua_setglobal(L, "GetHeroSts");
	
	// SetHeroSts
	lua_pushcfunction(L, SetHeroSts);
	lua_setglobal(L, "SetHeroSts");
	
	
	// KillHero
	lua_pushcfunction(L, KillHero);
	lua_setglobal(L, "KillHero");
	
	// ReviveHero
	lua_pushcfunction(L, ReviveHero);
	lua_setglobal(L, "ReviveHero");
	 
	// SetAsyncGold
	lua_pushcfunction(L, AddMoney);
	lua_setglobal(L, "AddMoney");
	
	// SetNickname
	lua_pushcfunction(L, SetNickname);
	lua_setglobal(L, "SetNickname");
	
	// GetEmptyHenchPocket
	lua_pushcfunction(L, GetEmptyHenchPocket);
	lua_setglobal(L, "GetEmptyHenchPocket");
	
	// ReviveCore
	lua_pushcfunction(L, ReviveCore);
	lua_setglobal(L, "ReviveCore");
	
	// StartQuest
	lua_pushcfunction(L, StartQuest);
	lua_setglobal(L, "StartQuest");
	
	// EndQuest
	lua_pushcfunction(L, EndQuest);
	lua_setglobal(L, "EndQuest");
	
	// MoveToReviveZone
	lua_pushcfunction(L, MoveToReviveZone);
	lua_setglobal(L, "MoveToReviveZone");
	
	// MoveZone
	lua_pushcfunction(L, MoveZone);
	lua_setglobal(L, "MoveZone");
	
	// RemoveHenchPocket
	lua_pushcfunction(L, RemoveHenchPocket);
	lua_setglobal(L, "RemoveHenchPocket");
	
	// RemoveMyStoreHench
	lua_pushcfunction(L, RemoveMyStoreHench);
	lua_setglobal(L, "RemoveMyStoreHench");
	
	// GetHench
	lua_pushcfunction(L, GetHench);
	lua_setglobal(L, "GetHench");
	
	// IsHeroAdmin
	lua_pushcfunction(L, IsHeroAdmin);
	lua_setglobal(L, "IsHeroAdmin");
	
	
	// GetHeroFreePoint
	lua_pushcfunction(L, GetHeroFreePoint);
	lua_setglobal(L, "GetHeroFreePoint");
	
	// GetHeroName
	lua_pushcfunction(L, GetHeroName);
	lua_setglobal(L, "GetHeroName");
	
	// GetMoney
	lua_pushcfunction(L, GetMoney);
	lua_setglobal(L, "GetMoney");
	
	
	// GetRemainPocket
	lua_pushcfunction(L, GetRemainPocket);
	lua_setglobal(L, "GetRemainPocket");
}
*/


