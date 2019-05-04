#include "CEventsHandler.h"


CEventsHandler::CEventsHandler()
{

	// initialize maps
	this->maps.insert(std::pair<int, string>(1, "Mashimaro Zone"));
	this->maps.insert(std::pair<int, string>(2, "Herseba Entrance"));
	this->maps.insert(std::pair<int, string>(3, "Northern Magirita"));
	this->maps.insert(std::pair<int, string>(4, "Mashimaro Zone"));
	this->maps.insert(std::pair<int, string>(5, "Mashimaro Zone"));
	this->maps.insert(std::pair<int, string>(6, "Magirita West Sea"));
	this->maps.insert(std::pair<int, string>(7, "Mashimaro Zone"));
	this->maps.insert(std::pair<int, string>(8, "Mashimaro Zone"));
	this->maps.insert(std::pair<int, string>(9, "Kambu Zone"));
	this->maps.insert(std::pair<int, string>(10, "Kambu Zone"));
	this->maps.insert(std::pair<int, string>(11, "Kambu Zone"));
	this->maps.insert(std::pair<int, string>(12, "Kambu Zone"));
	this->maps.insert(std::pair<int, string>(13, "Kambu Zone"));
	this->maps.insert(std::pair<int, string>(14, "Islaba Damp Area"));
	this->maps.insert(std::pair<int, string>(15, "Owalljae Prairie"));
	this->maps.insert(std::pair<int, string>(17, "Mekrita East Sea"));
	this->maps.insert(std::pair<int, string>(21, "Tamer's Field"));
	this->maps.insert(std::pair<int, string>(23, "Mekrita South Prairi"));
	this->maps.insert(std::pair<int, string>(25, "Fishcroll"));
	this->maps.insert(std::pair<int, string>(31, "Southern Rudis"));
	this->maps.insert(std::pair<int, string>(33, "Valcan Access Road"));
	this->maps.insert(std::pair<int, string>(35, "White Prairie"));
	this->maps.insert(std::pair<int, string>(36, "Twin Valley"));
	this->maps.insert(std::pair<int, string>(38, "Fork Road"));
	this->maps.insert(std::pair<int, string>(39, "Beast? stage 1"));
	this->maps.insert(std::pair<int, string>(40, "Beast's stage 2"));
	this->maps.insert(std::pair<int, string>(41, "Beast's stage 4"));
	this->maps.insert(std::pair<int, string>(42, "Beast's stage 5"));
	this->maps.insert(std::pair<int, string>(43, "Beast's stage 6"));
	this->maps.insert(std::pair<int, string>(44, "Beast's stage 7"));
	this->maps.insert(std::pair<int, string>(45, "Beast's stage 8"));
	this->maps.insert(std::pair<int, string>(46, "Beast's stage 9"));
	this->maps.insert(std::pair<int, string>(47, "NOVA DUNGEON"));
	this->maps.insert(std::pair<int, string>(50, "Rollingcores Field"));
	this->maps.insert(std::pair<int, string>(51, "Colorful Zoo"));
	this->maps.insert(std::pair<int, string>(52, "Cheseva Ruins"));
	this->maps.insert(std::pair<int, string>(57, "Magirita"));
	this->maps.insert(std::pair<int, string>(59, "Mekrita"));
	this->maps.insert(std::pair<int, string>(60, "VeHerseba"));
	this->maps.insert(std::pair<int, string>(63, "Herseba"));
	this->maps.insert(std::pair<int, string>(66, "Southern VeHerseba"));
	this->maps.insert(std::pair<int, string>(67, "Rudis"));
	this->maps.insert(std::pair<int, string>(69, "Forest of Chaos"));
	this->maps.insert(std::pair<int, string>(70, "Free Batte Zone"));
	this->maps.insert(std::pair<int, string>(71, "Battle Hall"));
	this->maps.insert(std::pair<int, string>(72, "Forest of Darkness"));
	this->maps.insert(std::pair<int, string>(73, "Field of Lunacy"));
	this->maps.insert(std::pair<int, string>(74, "Illusion Swamp"));
	this->maps.insert(std::pair<int, string>(75, "Lunacy Dungeon Entra"));
	this->maps.insert(std::pair<int, string>(81, "Rojeta 1st Basement"));
	this->maps.insert(std::pair<int, string>(82, "Rojeta 2nd Basement"));
	this->maps.insert(std::pair<int, string>(83, "Rojeta 3rd Basement"));
	this->maps.insert(std::pair<int, string>(84, "Rojeta 4th Basement"));
	this->maps.insert(std::pair<int, string>(85, "Rojeta 5th Basement"));
	this->maps.insert(std::pair<int, string>(86, "Rojeta 6th Basement"));
	this->maps.insert(std::pair<int, string>(87, "Rojeta 7th Basement"));
	this->maps.insert(std::pair<int, string>(91, "Lunacy Dungeon L1"));
	this->maps.insert(std::pair<int, string>(92, "Lunacy Dungeon L2"));
	this->maps.insert(std::pair<int, string>(93, "Lunacy Dungeon L3"));
	this->maps.insert(std::pair<int, string>(94, "Lunacy Dungeon L4"));
	this->maps.insert(std::pair<int, string>(95, "Lunacy Dungeon L5"));
	this->maps.insert(std::pair<int, string>(95, "Lunacy Dungeon L5"));
	this->maps.insert(std::pair<int, string>(96, "Valor Dongeon L1"));
	this->maps.insert(std::pair<int, string>(97, "Valor Dongeon L2"));
	this->maps.insert(std::pair<int, string>(98, "Valor Dongeon L3"));
	this->maps.insert(std::pair<int, string>(99, "Valor Dongeon L4"));
	this->maps.insert(std::pair<int, string>(100, "Rudis Dungeon"));
	this->maps.insert(std::pair<int, string>(101, "Magirita Castle"));
	this->maps.insert(std::pair<int, string>(102, "Mekrita Castle"));
	this->maps.insert(std::pair<int, string>(103, "Elysion 1st floor"));
	this->maps.insert(std::pair<int, string>(104, "Elysion 2nd floor"));
	this->maps.insert(std::pair<int, string>(105, "Elysion 3rd floor"));
	this->maps.insert(std::pair<int, string>(106, "Elysion 4th floor"));
	this->maps.insert(std::pair<int, string>(107, "Elysion 5th floor"));
	this->maps.insert(std::pair<int, string>(108, "Elysion 6th floor"));
	this->maps.insert(std::pair<int, string>(109, "Elysion 7th floor"));
	this->maps.insert(std::pair<int, string>(110, "Elysion 8th floor"));
	this->maps.insert(std::pair<int, string>(111, "Purmai"));
	this->maps.insert(std::pair<int, string>(112, "White Seashore"));
	this->maps.insert(std::pair<int, string>(113, "Iskai Forest"));
	this->maps.insert(std::pair<int, string>(114, "Ruins of Silence"));
	this->maps.insert(std::pair<int, string>(115, "Summer Snow Field"));
	this->maps.insert(std::pair<int, string>(116, "Sinan Ruins Entrance"));
	this->maps.insert(std::pair<int, string>(117, "Sinan Ruins"));
	this->maps.insert(std::pair<int, string>(118, "Ruins of Purmai"));
	this->maps.insert(std::pair<int, string>(119, "Dragon's stage 1"));
	this->maps.insert(std::pair<int, string>(120, "Dragon's stage 2"));
	this->maps.insert(std::pair<int, string>(121, "Dragon's stage 3"));
	this->maps.insert(std::pair<int, string>(122, "Dragon's stage 4"));
	this->maps.insert(std::pair<int, string>(123, "Dragon's stage 5"));
	this->maps.insert(std::pair<int, string>(124, "Dragon's stage 6"));
	this->maps.insert(std::pair<int, string>(125, "Dragon's stage"));
	this->maps.insert(std::pair<int, string>(126, "Dragon's stage"));
	this->maps.insert(std::pair<int, string>(127, "Devil's stage 1"));
	this->maps.insert(std::pair<int, string>(128, "Devil's stage 2"));
	this->maps.insert(std::pair<int, string>(129, "Devil's stage 3"));
	this->maps.insert(std::pair<int, string>(130, "Tutorial Zone"));
	this->maps.insert(std::pair<int, string>(131, "Valcan Valley"));
	this->maps.insert(std::pair<int, string>(132, "Devil's stage 4"));
	this->maps.insert(std::pair<int, string>(133, "Devil's stage 5"));
	this->maps.insert(std::pair<int, string>(134, "Devil's stage 6"));
	this->maps.insert(std::pair<int, string>(135, "Devil's stage"));
	this->maps.insert(std::pair<int, string>(136, "Devil's stage"));
	this->maps.insert(std::pair<int, string>(137, "Plant's stage 1"));
	this->maps.insert(std::pair<int, string>(138, "Plant's stage 2"));
	this->maps.insert(std::pair<int, string>(139, "Plant's stage 3"));
	this->maps.insert(std::pair<int, string>(140, "Plant's stage 4"));
	this->maps.insert(std::pair<int, string>(141, "Plant's stage 5"));
	this->maps.insert(std::pair<int, string>(142, "Plant's stage 6"));
	this->maps.insert(std::pair<int, string>(143, "Plant's stage"));
	this->maps.insert(std::pair<int, string>(144, "Plant's stage"));
	this->maps.insert(std::pair<int, string>(145, "Mystery's stage 1"));
	this->maps.insert(std::pair<int, string>(146, "Mystery's stage 2"));
	this->maps.insert(std::pair<int, string>(147, "Mystery's stage 3"));
	this->maps.insert(std::pair<int, string>(148, "Mystery's stage 4"));
	this->maps.insert(std::pair<int, string>(149, "Mystery's stage 5"));
	this->maps.insert(std::pair<int, string>(150, "Dragon Room"));
	this->maps.insert(std::pair<int, string>(151, "Metal Room"));
	this->maps.insert(std::pair<int, string>(152, "Bird Room"));
	this->maps.insert(std::pair<int, string>(153, "Plant Room"));
	this->maps.insert(std::pair<int, string>(154, "Mystery's stage 6"));
	this->maps.insert(std::pair<int, string>(155, "Mystery's stage"));
	this->maps.insert(std::pair<int, string>(156, "Mystery's stage"));
	this->maps.insert(std::pair<int, string>(160, "Eastern Magirita"));
	this->maps.insert(std::pair<int, string>(161, "Mekrita Central Prai"));
	this->maps.insert(std::pair<int, string>(162, "Bird's stage 1"));
	this->maps.insert(std::pair<int, string>(163, "Bird's stage 2"));
	this->maps.insert(std::pair<int, string>(164, "Bird's stage 3"));
	this->maps.insert(std::pair<int, string>(165, "Bird's stage 4"));
	this->maps.insert(std::pair<int, string>(166, "Bird's stage 5"));
	this->maps.insert(std::pair<int, string>(167, "Bird's stage 6"));
	this->maps.insert(std::pair<int, string>(168, "Bird's wrath"));
	this->maps.insert(std::pair<int, string>(169, "Bird's disaster"));
	this->maps.insert(std::pair<int, string>(171, "Magirita Basement"));
	this->maps.insert(std::pair<int, string>(172, "Free Battle Ranking"));
	this->maps.insert(std::pair<int, string>(174, "Fan Island"));
	this->maps.insert(std::pair<int, string>(175, "Garden of Stone Stat"));
	this->maps.insert(std::pair<int, string>(176, "Actopus"));
	this->maps.insert(std::pair<int, string>(177, "Ilha do Chaos"));
	this->maps.insert(std::pair<int, string>(180, "Jardim do Enigma"));
	this->maps.insert(std::pair<int, string>(181, "Rojeta 10(Futuro)"));
	this->maps.insert(std::pair<int, string>(182, "Rojeta 10 2"));
	this->maps.insert(std::pair<int, string>(183, "??? ??"));
	this->maps.insert(std::pair<int, string>(184, "??? ??"));
	this->maps.insert(std::pair<int, string>(185, "??? ??"));
	this->maps.insert(std::pair<int, string>(186, "??? ??"));
	this->maps.insert(std::pair<int, string>(187, "?? ???"));
	this->maps.insert(std::pair<int, string>(188, "?? ???"));
	this->maps.insert(std::pair<int, string>(189, "?? ???"));
	this->maps.insert(std::pair<int, string>(190, "?? ???"));
	this->maps.insert(std::pair<int, string>(191, "?? ???"));
	this->maps.insert(std::pair<int, string>(192, "??????"));
	this->maps.insert(std::pair<int, string>(193, "??????"));
	this->maps.insert(std::pair<int, string>(194, "??????"));
	this->maps.insert(std::pair<int, string>(195, "??????"));
	this->maps.insert(std::pair<int, string>(196, "??????"));
	this->maps.insert(std::pair<int, string>(197, "??????"));
	this->maps.insert(std::pair<int, string>(198, "??????"));
	this->maps.insert(std::pair<int, string>(199, "??????"));
	this->maps.insert(std::pair<int, string>(200, "????????"));
	this->maps.insert(std::pair<int, string>(201, "????????"));
	this->maps.insert(std::pair<int, string>(202, "????????"));
	this->maps.insert(std::pair<int, string>(203, "????????"));
	this->maps.insert(std::pair<int, string>(204, "????????"));
	this->maps.insert(std::pair<int, string>(205, "????????"));
	this->maps.insert(std::pair<int, string>(206, "????????"));
	this->maps.insert(std::pair<int, string>(207, "????????"));
	this->maps.insert(std::pair<int, string>(208, "???? ???"));
	this->maps.insert(std::pair<int, string>(209, "???? ???"));
	this->maps.insert(std::pair<int, string>(210, "???? ???"));
	this->maps.insert(std::pair<int, string>(211, "???? ???"));
	this->maps.insert(std::pair<int, string>(212, "???? ???"));
	this->maps.insert(std::pair<int, string>(213, "??? ??"));
	this->maps.insert(std::pair<int, string>(214, "??? ??"));
	this->maps.insert(std::pair<int, string>(215, "Insect's stage 1"));
	this->maps.insert(std::pair<int, string>(216, "Insect's stage 2"));
	this->maps.insert(std::pair<int, string>(217, "Insect's stage 3"));
	this->maps.insert(std::pair<int, string>(218, "Insect's stage 4"));
	this->maps.insert(std::pair<int, string>(219, "Insect's stage 5"));
	this->maps.insert(std::pair<int, string>(220, "Insect's stage 6"));
	this->maps.insert(std::pair<int, string>(221, "Insect's wrath"));
	this->maps.insert(std::pair<int, string>(222, "Insect's disaster"));
	this->maps.insert(std::pair<int, string>(223, "Metal's stage 1"));
	this->maps.insert(std::pair<int, string>(224, "Metal's stage 2"));
	this->maps.insert(std::pair<int, string>(225, "Metal's stage 3"));
	this->maps.insert(std::pair<int, string>(226, "Metal's stage 4"));
	this->maps.insert(std::pair<int, string>(227, "Metal's stage 5"));
	this->maps.insert(std::pair<int, string>(228, "Metal's stage 6"));
	this->maps.insert(std::pair<int, string>(229, "Metal's wrath"));
	this->maps.insert(std::pair<int, string>(230, "Metal's disaster"));
	this->maps.insert(std::pair<int, string>(237, "Consultation Office"));
	this->maps.insert(std::pair<int, string>(238, "Ruins of Magirita"));
	this->maps.insert(std::pair<int, string>(239, "Ruins of VeHerseba"));
	this->maps.insert(std::pair<int, string>(240, "Ruins of Rudis"));
	this->maps.insert(std::pair<int, string>(241, "Ruins of Magirita"));
	this->maps.insert(std::pair<int, string>(242, "Ruins of VeHerseba"));
	this->maps.insert(std::pair<int, string>(243, "Ruins of Rudis"));
	this->maps.insert(std::pair<int, string>(244, "Rojeta 8th Basement"));
	this->maps.insert(std::pair<int, string>(245, "Rojeta 9th Basement"));
	this->maps.insert(std::pair<int, string>(246, "Forest of the Past"));
	this->maps.insert(std::pair<int, string>(247, "Dungeon of Wind"));
	this->maps.insert(std::pair<int, string>(251, "BBQ Zone Valley Farm"));
	this->maps.insert(std::pair<int, string>(252, "BBQ Zone Outback Far"));
	this->maps.insert(std::pair<int, string>(255, "The Forbidden Room"));
	
}

CEventsHandler::~CEventsHandler()
{

}

void CEventsHandler::OnServerStarted()
{

}


int ddda = 0;
void CEventsHandler::OnHeroEnterGame(int hero)
{
}

void CEventsHandler::OnHeroChangeMap(short heroID, short mapTarget)
{
	CMemory memory;
	CPacket packet;
	char buffer[128];

	XHero *myHero = new XHero(memory.ReadXHero(heroID));


	for(int i = 1; i < 1025; i++)
	{
		XHero *h = new XHero(memory.ReadXHero(i));
		if(!h->IsLogged()) 
		{
			continue;
		}


		sprintf(buffer, "%s moveu-se para %s", myHero->GetHeroName(), maps[(int)mapTarget].c_str());

		packet.SendWhisper(i, "[vmo]", buffer);

	}

}



void CEventsHandler::OnHeroExitGame(int hero)
{

}

void CEventsHandler::OnHeroSit(int heroAddr)
{

}

vector<string> CEventsHandler::split(string str, char delimiter)
{
	vector<string> internal;
	stringstream ss(str);  // Turn the string into a stream.
	string tok;

	while (getline(ss, tok, delimiter)) 
	{
		internal.push_back(tok);
	}

	return internal;
}


bool CEventsHandler::OnHeroSpeakerChat(int hero, char *message)
{
    // verifica se a fala comeca com @
	if (message[0] != '@') return false;

	vector<string> splited = split(message, (char)0x20);
	if (splited.size() <= 0) return false;

	XHero *myHero = new XHero(hero, true);
	if(!myHero->IsAdmin()) return false;

	CMemory memory;



	bool result = true;

	
	printf("Comando: %s\n", message);

	
	if (splited[0] == "@dead")
	{
		myHero->Dead();
		result = true;
	}
	else if(splited[0] == "@revive")
	{
		myHero->Revive();
		result = true;
	}
	else if(splited[0] == "@addmoney")
	{
		if(splited.size() < 2) return false;
		int value = atoi(splited[1].c_str());

		myHero->AddMoney(value);
		result = true;
	}
	else if(splited[0] == "@additem")
	{
		if(splited.size() < 3) return false;
		int id = atoi(splited[1].c_str());
		int count = atoi(splited[2].c_str());

		myHero->AddPocketItem(id, count, 1, -1);
		result = true;
	}
	else if(splited[0] == "@addhench")
	{
		if(splited.size() < 3) return false;
		int id = atoi(splited[1].c_str());
		int count = atoi(splited[2].c_str());

		for(int i = 0; i < count; i++)
		{
			myHero->AddPocketHench(id, 1);
		}

		result = true;
	}
	else if(splited[0] == "@setnick")
	{
		if(splited.size() < 2) return false;
		int id = atoi(splited[1].c_str());

		myHero->SetNickname(id);
		result = true;
	}
	else if(splited[0] == "@revivecores")
	{
		for(int i = 0; i < 20; i++)
		{
			myHero->ReviveCore(i);
		}
		result = true;
	}
	else if(splited[0] == "@warp")
	{
		if(splited.size() < 2) return false;
		int id = atoi(splited[1].c_str());


		myHero->MoveZone(id, 254);
		result = true;
	}
	else if(splited[0] == "@clear")
	{
		if(splited.size() < 2) return false;

		if(splited[1] == "cores")
		{
			for(int i = 0; i < 20; i++)
			{
				myHero->RemovePocketHench(i);
			}
			result = true;
		}
		else if(splited[1] == "inventory")
		{
			result = true;
		}
	}
	else if(splited[0] == "@dump")
	{
		FILE *file = fopen("dump_char01.data", "w+b");
		fwrite((void*)(hero), 0x1DA90, 1, file);
		fclose(file);
	}


	
	return result;
}

void CEventsHandler::OnHeroDead(int hero)
{

}

void CEventsHandler::OnHeroRevive(int hero)
{

}

void CEventsHandler::OnHeroSetMoney(int hero)
{

}

void CEventsHandler::OnHeroDamage(int hero, unsigned short damageCount)
{

}

void CEventsHandler::OnHeroSetStoreMoney(int hero)
{

}

void CEventsHandler::OnHeroSetNickname(int hero)
{

}

void CEventsHandler::OnHeroSetSts(int hero)
{

}

void CEventsHandler::OnHeroReviveCore(int hero)
{

}

void CEventsHandler::OnHeroStartQuest(int hero)
{

}

void CEventsHandler::OnHeroEndQuest(int hero)
{

}

void CEventsHandler::OnHeroWarp(int hero)
{

}

void CEventsHandler::OnHeroWarpToReviveZone(int hero)
{

}

void CEventsHandler::OnHeroRemovePocketHench(int hero)
{

}

void CEventsHandler::OnHeroRemoveStoreHench(int hero)
{

}

// quando o mob morrer
int mobsDeath = 0;
void CEventsHandler::OnMobDeath(int xmob)
{
	CMemory memory;

	// save in file
	/*
	char buffer[30];
	sprintf((char*)buffer, "mob%000d.dat", mobsDeath);
	FILE *file = fopen(buffer, "w+b");
	fwrite((char*)xmob, 5200, 1, file);
	fclose(file);
	mobsDeath++;
	*/

	// variables from xmob
	int unkAddr = memory.ReadInt32(xmob + 0x4FC); // 1276 bytes
	int unkAddr2 = memory.ReadInt32(unkAddr + 0x8);
	int heroIndex = memory.ReadInt16(unkAddr2 + 0x06); 
	int heroAddr = memory.ReadXHero(heroIndex);
	XHero *myHero = new XHero(heroAddr);

	unsigned short id = memory.ReadUInt16(xmob + 18);


	if(id == 238)
	{
		for(int i = 1; i < 1025; i++)
		{
			XHero *h = new XHero(memory.ReadXHero(i));
			if(!h->IsLogged()) 
			{
				continue;
			}

			if(h->GetCurrentZone() == 247)
			{
				h->AddPocketItem(9687, 1, 1, -1);
			}
		}
	}
}



int increments = 0;
// quando o jogador equipar o hench
void CEventsHandler::OnHeroEquipHench(int xbattle_hench)
{
	CMemory memory;

	// dump hench
	/*
	char buffer[30];
	sprintf((char*)buffer, "digi%d.data", increments);

	FILE *file = fopen(buffer, "w+b");
	fwrite((void*)xbattle_hench, 5288, 1, file);
	fclose(file);
	*/

	char classe = memory.ReadByte(xbattle_hench + 168);
	int sizeOfXbattleHench = 5288;
	int sizeOfXHench = 5284;

	int attack_speed = memory.ReadUInt16(xbattle_hench + 78);


	// status
    // max_hp = memory.ReadUInt16(xbattle_hench + 96);
	// power = ReadUInt16(xbattle_hench + 98);
	// velocidade = memory.ReadUInt16(xbattle_hench + 100);
	// precisao = memory.ReadUInt16(xbattle_hench + 102);
	// sorte = memory.ReadUInt16(xbattle_hench + 104);
	// cured = memory.ReadUInt16(xbattle_hench + 116);

	//max_hp 		= 	memory.ReadUInt16(xbattle_hench + 114);
	//current_hp 	= 	memory.ReadUInt16(xbattle_hench + 116);
	//max_mp       =	memory.ReadUInt16(xbattle_hench + 118);
	//current_mp   =	memory.ReadUInt16(xbattle_hench + 120);

	// teste

	/*
	// block 1
	memory.WriteUint16(xbattle_hench + 818, 400);
	memory.WriteUint16(xbattle_hench + 820, 400);
	memory.WriteUint16(xbattle_hench + 822, 400);
	memory.WriteUint16(xbattle_hench + 824, 400);
	memory.WriteUint16(xbattle_hench + 826, 400);
	memory.WriteUint16(xbattle_hench + 828, 400);
	memory.WriteUint16(xbattle_hench + 830, 400);
	memory.WriteUint16(xbattle_hench + 832, 400);

	// block 2
	memory.WriteUint16(xbattle_hench + 838, 400);
	memory.WriteUint16(xbattle_hench + 840, 400);

	// block 3
	memory.WriteUint16(xbattle_hench + 850, 400);
	memory.WriteUint16(xbattle_hench + 852, 400);
	memory.WriteUint16(xbattle_hench + 854, 400);
	memory.WriteUint16(xbattle_hench + 856, 400);
	memory.WriteUint16(xbattle_hench + 858, 400);
	memory.WriteUint16(xbattle_hench + 860, 400);
	memory.WriteUint16(xbattle_hench + 862, 400);
	memory.WriteUint16(xbattle_hench + 864, 400);
	memory.WriteUint16(xbattle_hench + 866, 400);
	memory.WriteUint16(xbattle_hench + 868, 400);
	memory.WriteUint16(xbattle_hench + 870, 400);
	memory.WriteUint16(xbattle_hench + 872, 400);
	memory.WriteUint16(xbattle_hench + 874, 400);
	memory.WriteUint16(xbattle_hench + 876, 400);
	*/

	/*
	// block 1
	memory.WriteUint16(xbattle_hench + 898, 400);
	memory.WriteUint16(xbattle_hench + 900, 400);
	memory.WriteUint16(xbattle_hench + 902, 400);
	memory.WriteUint16(xbattle_hench + 904, 400);
	memory.WriteUint16(xbattle_hench + 906, 400);
	memory.WriteUint16(xbattle_hench + 908, 400);
	memory.WriteUint16(xbattle_hench + 910, 400);
	memory.WriteUint16(xbattle_hench + 912, 400);
	memory.WriteUint16(xbattle_hench + 914, 400);

	// block 2
	memory.WriteUint16(xbattle_hench + 920, 400);	
	memory.WriteUint16(xbattle_hench + 922, 400);

	// block 3
	memory.WriteUint16(xbattle_hench + 932, 400);
	memory.WriteUint16(xbattle_hench + 934, 400);
	memory.WriteUint16(xbattle_hench + 936, 400);
	memory.WriteUint16(xbattle_hench + 938, 400);
	memory.WriteUint16(xbattle_hench + 940, 400);
	memory.WriteUint16(xbattle_hench + 942, 400);
	memory.WriteUint16(xbattle_hench + 944, 400);
	memory.WriteUint16(xbattle_hench + 946, 400);
	memory.WriteUint16(xbattle_hench + 948, 400);
	memory.WriteUint16(xbattle_hench + 950, 400);
	memory.WriteUint16(xbattle_hench + 956, 400);
	memory.WriteUint16(xbattle_hench + 958, 400);

	/*
	// block 1
	memory.WriteUint16(xbattle_hench + 980, 400);
	memory.WriteUint16(xbattle_hench + 982, 400);
	memory.WriteUint16(xbattle_hench + 984, 400);
	memory.WriteUint16(xbattle_hench + 986, 400);
	memory.WriteUint16(xbattle_hench + 988, 400);
	memory.WriteUint16(xbattle_hench + 990, 400);
	memory.WriteUint16(xbattle_hench + 992, 400);
	memory.WriteUint16(xbattle_hench + 994, 400);
	memory.WriteUint16(xbattle_hench + 996, 400);

	// block 2
	memory.WriteUint16(xbattle_hench + 1002, 400);	
	memory.WriteUint16(xbattle_hench + 1004, 400);

	// block 3
	memory.WriteUint16(xbattle_hench + 1014, 400);
	memory.WriteUint16(xbattle_hench + 1016, 400);
	memory.WriteUint16(xbattle_hench + 1018, 400);
	memory.WriteUint16(xbattle_hench + 1020, 400);
	memory.WriteUint16(xbattle_hench + 1022, 400);
	memory.WriteUint16(xbattle_hench + 1024, 400);
	memory.WriteUint16(xbattle_hench + 1026, 400);
	memory.WriteUint16(xbattle_hench + 1028, 400);
	memory.WriteUint16(xbattle_hench + 1030, 400);
	memory.WriteUint16(xbattle_hench + 1032, 400);
	memory.WriteUint16(xbattle_hench + 1036, 400);
	memory.WriteUint16(xbattle_hench + 1038, 400);
	memory.WriteUint16(xbattle_hench + 1040, 400);
	*/



	
	/*
	
	// aditional
	memory.WriteUint16(xbattle_hench + 1062, 400);
	memory.WriteUint16(xbattle_hench + 1280, 400);

	/*
	// tier 2
	// block 10
	memory.WriteUint16(xbattle_hench + 2182, 400);
	memory.WriteUint16(xbattle_hench + 2184, 400);
	memory.WriteUint16(xbattle_hench + 2186, 400);
	memory.WriteUint16(xbattle_hench + 2188, 400);
	memory.WriteUint16(xbattle_hench + 2190, 400);
	memory.WriteUint16(xbattle_hench + 2192, 400);
	memory.WriteUint16(xbattle_hench + 2194, 400);
	memory.WriteUint16(xbattle_hench + 2196, 400);

	// block 11
	memory.WriteUint16(xbattle_hench + 2102, 400);
	memory.WriteUint16(xbattle_hench + 2104, 400);

	// block 12
	memory.WriteUint16(xbattle_hench + 2214, 400);
	memory.WriteUint16(xbattle_hench + 2216, 400);
	memory.WriteUint16(xbattle_hench + 2218, 400);
	memory.WriteUint16(xbattle_hench + 2220, 400);
	memory.WriteUint16(xbattle_hench + 2222, 400);
	memory.WriteUint16(xbattle_hench + 2224, 400);
	memory.WriteUint16(xbattle_hench + 2226, 400);
	memory.WriteUint16(xbattle_hench + 2228, 400);
	memory.WriteUint16(xbattle_hench + 2230, 400);
	memory.WriteUint16(xbattle_hench + 2232, 400);
	memory.WriteUint16(xbattle_hench + 2234, 400);
	memory.WriteUint16(xbattle_hench + 2236, 400);
	memory.WriteUint16(xbattle_hench + 2238, 400);
	memory.WriteUint16(xbattle_hench + 2240, 400);

	// block 13
	memory.WriteUint16(xbattle_hench + 2262, 400);
	memory.WriteUint16(xbattle_hench + 2264, 400);
	memory.WriteUint16(xbattle_hench + 2266, 400);
	memory.WriteUint16(xbattle_hench + 2268, 400);
	memory.WriteUint16(xbattle_hench + 2270, 400);
	memory.WriteUint16(xbattle_hench + 2272, 400);
	memory.WriteUint16(xbattle_hench + 2274, 400);
	memory.WriteUint16(xbattle_hench + 2276, 400);
	memory.WriteUint16(xbattle_hench + 2278, 400);

	// block 14
	memory.WriteUint16(xbattle_hench + 2284, 400);
	memory.WriteUint16(xbattle_hench + 2286, 400);

	// block 15
	memory.WriteUint16(xbattle_hench + 2296, 400);
	memory.WriteUint16(xbattle_hench + 2298, 400);
	memory.WriteUint16(xbattle_hench + 2300, 400);
	memory.WriteUint16(xbattle_hench + 2302, 400);
	memory.WriteUint16(xbattle_hench + 2304, 400);
	memory.WriteUint16(xbattle_hench + 2306, 400);
	memory.WriteUint16(xbattle_hench + 2308, 400);
	memory.WriteUint16(xbattle_hench + 2310, 400);
	memory.WriteUint16(xbattle_hench + 2312, 400);
	memory.WriteUint16(xbattle_hench + 2314, 400);
	memory.WriteUint16(xbattle_hench + 2316, 400);
	memory.WriteUint16(xbattle_hench + 2318, 400);
	memory.WriteUint16(xbattle_hench + 2320, 400);
	memory.WriteUint16(xbattle_hench + 2322, 400);
	memory.WriteUint16(xbattle_hench + 2324, 400);
	memory.WriteUint16(xbattle_hench + 2326, 400);
	memory.WriteUint16(xbattle_hench + 2328, 400);
	memory.WriteUint16(xbattle_hench + 2330, 400);
	memory.WriteUint16(xbattle_hench + 2332, 400);

	// block 16
	memory.WriteUint16(xbattle_hench + 2344, 400);
	memory.WriteUint16(xbattle_hench + 2346, 400);
	memory.WriteUint16(xbattle_hench + 2348, 400);
	memory.WriteUint16(xbattle_hench + 2350, 400);
	memory.WriteUint16(xbattle_hench + 2352, 400);
	memory.WriteUint16(xbattle_hench + 2354, 400);
	memory.WriteUint16(xbattle_hench + 2356, 400);
	memory.WriteUint16(xbattle_hench + 2358, 400);
	memory.WriteUint16(xbattle_hench + 2360, 400);

	// block 17
	memory.WriteUint16(xbattle_hench + 2366, 400);
	memory.WriteUint16(xbattle_hench + 2368, 400);

	// block 18
	memory.WriteUint16(xbattle_hench + 2378, 400);
	memory.WriteUint16(xbattle_hench + 2380, 400);
	memory.WriteUint16(xbattle_hench + 2382, 400);
	memory.WriteUint16(xbattle_hench + 2384, 400);
	memory.WriteUint16(xbattle_hench + 2386, 400);
	memory.WriteUint16(xbattle_hench + 2388, 400);
	memory.WriteUint16(xbattle_hench + 2390, 400);
	memory.WriteUint16(xbattle_hench + 2392, 400);
	memory.WriteUint16(xbattle_hench + 2394, 400);
	memory.WriteUint16(xbattle_hench + 2396, 400);
	memory.WriteUint16(xbattle_hench + 2398, 400);
	memory.WriteUint16(xbattle_hench + 2400, 400);
	memory.WriteUint16(xbattle_hench + 2402, 400);
	memory.WriteUint16(xbattle_hench + 2404, 400);

	// others
	memory.WriteUint16(xbattle_hench + 2426, 400);
	memory.WriteUint16(xbattle_hench + 2644, 400);
	*/
	
	switch(classe)
	{
		case 1: // power
			printf("[%d] Hench Updated! Type: Power - AttackSpeed: %u\n", increments, attack_speed);
			break;
		case 2: // agile
			printf("[%d] Hench Updated! Type: Agile - AttackSpeed: %u\n", increments, attack_speed);
			break;
		case 3: // accurracy
			printf("[%d] Hench Updated! Type: Accuracy - AttackSpeed: %u\n", increments, attack_speed);
			break;
		case 4: // lucky
			printf("[%d] Hench Updated! Type: Lucky - AttackSpeed: %u\n", increments, attack_speed);
			break;
		case 5: // Elemental
			printf("[%d] Hench Updated! Type: Elemental - AttackSpeed: %u\n", increments, attack_speed);
			break;
	}

	increments++;
	//printf("Hench Refreshed!\n");	
}

int packets = 0;
void CEventsHandler::OnSendPacket(int client, int xpacket)
{
	CMemory memory;
	int bodySize = (unsigned short)(*(short *)xpacket);
	char * bodyData = (char *)xpacket + *((char *)xpacket + 4109) + 6;


	printf("[%d] Enviando pacote. Client: %d | Addr: 0x%x | Size: %d\n", packets, client, xpacket, bodySize);
	



	// save in file
	char buffer[36];
	sprintf((char*)buffer, "./packets/pack%000d.dat", packets);

	// wirte
	//FILE *file = fopen(buffer, "w+b");
	//fwrite((char*)xpacket, 5200, 1, file);
	
	//fclose(file);

	packets++;
}

void CEventsHandler::OnDropCore(int hero, int core)
{
	CMemory memory;
	CPacket packet;

	// hero is pointer
	int hIndex = *(int*)hero;
	XHero *myHero = new XHero(memory.ReadXHero(hIndex));

	//printf("Drop hench! Hero: 0x%x | Hench: 0x%x\n", HeroDropCore, dropCoreSrc);

	char buffer[120];


	short henchLv = memory.ReadInt16(core + 0x2e);


	if(henchLv >= 50)
	{
		sprintf(buffer, "Jogador \"%s\" acabou de dropar o \"%s\" level %d", myHero->GetHeroName(), memory.ReadString(core + 0x10), henchLv);
		packet.SendAnouncement(string(buffer));
	}

}

void CEventsHandler::OnMixCore(int hero, int core)
{
	CMemory memory;
	CPacket packet;

	XHero *myHero = new XHero(hero, true);


	printf("Mix Core: Hero: 0x%x | Core: 0x%x\n", hero, core);
	printf("Nome: %s - %s\n", myHero->GetHeroName(), memory.ReadString(core + 0x10));
	
	char buffer[120];

	short henchLv = memory.ReadInt16(core + 0x2e);


	if(henchLv >= 50)
	{
	
		sprintf(buffer, "Jogador \"%s\" fez uma DigiEvo do \"%s\" level %d", myHero->GetHeroName(), memory.ReadString(core + 0x10), henchLv);
		packet.SendAnouncement(string(buffer));
	}
}