#include "CHookManager.h"

// constructor
CHookManager::CHookManager()
{

}

// desconstructor
CHookManager::~CHookManager()
{
    
}

void CHookManager::PlaceInitHook(int callback)
{
    CMemory memory;

    printf("[HOOK] Hooking [Initialize] function ...\n");
    memory.PlaceJMP((char*)InitFuncAddr, (int)callback, 5);
}

void CHookManager::PlaceHeroSitHook(int callback)
{
    CMemory memory;

    printf("[HOOK] Hooking [HeroSit] function ...\n");
	memory.PlaceJMP((char*)HeroSitFuncAddr, (int)callback, 5);
}

void CHookManager::PlaceHeroChatHook(int callback)
{
    CMemory memory;

    printf("[HOOK] Hooking [HeroSpeakerChat] function ...\n");
    memory.PlaceJMP((char*)HeroNormalChatAddr, (int)callback, 5);
	//memory.PlaceJMP((char*)HeroNormalChatAddr, (int)&myChatFunction, 5);
}

void CHookManager::PlaceMobDeathHook(int callback)
{
    CMemory memory;

    printf("[HOOK] Hooking [ProcDeath] function ...\n");
    memory.PlaceJMP((char*)XMobDeath, (int)callback, 5);
}

void CHookManager::PlaceEquipHenchHook(int callback)
{
    CMemory memory;
    printf("[HOOK] Hooking [XBATTLE_HENCH::Refresh] function ...\n");

    memory.PlaceJMP((char*)XRefreshHench, (int)callback, 5);
}

void CHookManager::PlaceSendQtoZsHook(int callback)
{
    CMemory memory;
    printf("[HOOK] Hooking [AddTo_ZS_SendQ] function ...\n");

    memory.PlaceJMP((char*)SendQtoZsAddr, (int)callback, 7);
}

void CHookManager::PlaceDropCoreHook(int callback)
{
    CMemory memory;
    printf("[HOOK] Hooking [XMOB::DropCore] function ...\n");

    memory.PlaceCall((char*)DropCoreAddr, (int)callback, 8);
}

void CHookManager::PlaceMixCoreHook(int callback)
{
    CMemory memory;
    printf("[HOOK] Hooking [XNPC::MixCore] function ...\n");

    memory.PlaceJMP((char*)MixCoreAddr, (int)callback, 7);
}

void CHookManager::PlaceSetHeroHook(int callback)
{
    CMemory memory;
    printf("[HOOK] Hooking [ZS_CLIENT_DATA::SetHero] function ...\n");

    memory.PlaceJMP((char*)SetHero, (int)callback, 5);
}

void CHookManager::PlaceMoveClientHook(int callback)
{
    CMemory memory;
    printf("[HOOK] Hooking [X_ZONE::MoveClient_ToZone] function ...\n");

    memory.PlaceJMP((char*)MoveClientZone, (int)callback, 9);
}