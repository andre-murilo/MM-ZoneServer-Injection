#pragma

#include <string>
#include <stdio.h>
#include <vector>
#include "XHero.h"
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream
#include <stdlib.h>
#include "CMemory.h"
#include "MemoryWritter.h"
#include "CPacket.h"
#include <map>


using namespace std;

class CEventsHandler
{
    public:
        CEventsHandler();
        ~CEventsHandler();

        typedef int(*RefreshHench)(int, bool a2, bool a3); // XHENCH_INFO, bool, bool



        void OnServerStarted();
        void OnHeroEnterGame(int hero);
        void OnHeroChangeMap(short hero, short mapTarget);
        void OnHeroExitGame(int hero);
        void OnHeroSit(int heroAddr);
        vector<string> split(string str, char delimiter);
        bool OnHeroSpeakerChat(int hero, char *message);
        void OnHeroDead(int hero);
        void OnHeroRevive(int hero);
        void OnHeroSetMoney(int hero);
        void OnHeroDamage(int hero, unsigned short damageCount);
        void OnHeroSetStoreMoney(int hero);
        void OnHeroSetNickname(int hero);
        void OnHeroSetSts(int hero);
        void OnHeroReviveCore(int hero);
        void OnHeroStartQuest(int hero);
        void OnHeroEndQuest(int hero);
        void OnHeroWarp(int hero);
        void OnHeroWarpToReviveZone(int hero);
        void OnHeroRemovePocketHench(int hero);
        void OnHeroRemoveStoreHench(int hero);
        void OnHeroEquipHench(int xbattle_hench);

        void OnMobDeath(int xmob);

        void OnSendPacket(int client, int xpacket);

        void OnDropCore(int hero, int core);
        void OnMixCore(int hero, int core);



        map<int, string> maps;
};