#pragma once

#include "CMemory.h"
#include <stdio.h>


class CHookManager
{
    public:
        // ZoneServer Functions address
        const int InitFuncAddr = 0x80EA2C0;
        const int HeroSitFuncAddr = 0x80A0E90;
        const int HeroNormalChatAddr = 0x809CC70;
        const int HeroDamageAddr = 0x80AD310;
        const int XMobDeath = 0x80C67A0;
        const int XRefreshHench = 0x809956A;
        const int SendQtoZsAddr = 0x80E47C0;
        const int DropCoreAddr = 0x80C554B;
        const int MixCoreAddr = 0x80CBC32;
        const int SetHero = 0x80B4FF0;
        const int MoveClientZone = 0x80D4060;

        void PlaceInitHook(int callback);
        void PlaceHeroSitHook(int callback);
        void PlaceHeroChatHook(int callback);
        void PlaceMobDeathHook(int callback);
        void PlaceEquipHenchHook(int callback);
        void PlaceSendQtoZsHook(int callback);
        void PlaceDropCoreHook(int callback);
        void PlaceMixCoreHook(int callback);
        void PlaceSetHeroHook(int callback);
        void PlaceMoveClientHook(int callback);

        CHookManager();
        ~CHookManager();
};
