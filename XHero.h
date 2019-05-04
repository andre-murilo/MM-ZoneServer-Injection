#pragma once

#include "CMemory.h"

// functions templates
typedef int(*TDead)(int);  // heroID
typedef int(*TRevive)(int);  // heroID
typedef int(*TSetAsyncGold)(int, unsigned int);  // heroID, amount
typedef int(*TSetAsyncStoreGold)(int, unsigned int);  // heroID, amount
typedef int(*TSetNickname)(int, unsigned short);  // heroID, nicknameID
typedef int(*TSetAsyncColor)(int, char, int);  // heroID, unk, unk
typedef int(*TSetAsyncSts)(int, unsigned char, unsigned short);  // heroID, stsType, value
typedef int(*TGetRemainPocket)(int);  // heroID; retorno a quantia de espaco livre no inventario
typedef int(*TReviveCore)(int, unsigned char);  // heroID, henchID 
typedef int(*TStartQuest)(int, unsigned short);  // heroID, questID
typedef int(*TEndQuest)(int, unsigned short);  // heroID, questID
typedef int(*TMoveToReviveZone)(int);  // heroID
typedef int(*TMoveZone)(int, unsigned short, unsigned short);  // heroID, mapaID, layerID
typedef int(*TRemovePocketHench)(int, char);  // heroID, henchID
typedef int(*TRemoveMyStoreHench)(int, char);  // heroID, henchID
typedef int(*TGetSts)(int, char);   // heroID, stsType
typedef int(*TGetItemCount)(int, char, unsigned int);    // heroID, bagType, itemID
typedef int(*TAddPocketItem)(int, unsigned int itemID, int count, bool refresh, int time); 
typedef int(*TAddPocketHench)(int, unsigned short, int); // hero, id, count

// send packets
typedef int(*TSendRefreshExpPercentData)(int);  // heroID
typedef int(*TSendRefreshSTS)(int);  // heroID

// hench
typedef int(*TGetHench)(int, unsigned short, unsigned short);  // heroID, henchID, unknow



class XHero
{
	CMemory memory;

	private:
		int BASE_ADDR;
		int XHERO_ADDR;
	public:
		XHero(int base_addr)
		{
			// 500

			this->BASE_ADDR = base_addr;
			this->XHERO_ADDR = this->BASE_ADDR + 0x6C;
		}
	
		XHero(int base_addr, bool not_offset)
		{
			// 500

			if (not_offset)
			{
				this->BASE_ADDR = base_addr - 0x6C;
				this->XHERO_ADDR = base_addr;
			}
			
		}

		bool IsLogged()
		{
			if (memory.ReadByte(this->BASE_ADDR + (char)0x00))
				return true;
			else
				return false;
		}

		char GetHeroType()
		{
			return memory.ReadByte(this->XHERO_ADDR + (char)0x1A);
		}
	
		char IsAdmin()
		{
			return memory.ReadByte(this->XHERO_ADDR + (char)0x0C);
		}


	
		char* GetHeroName()
		{
			return memory.ReadString(this->XHERO_ADDR + 0xD);
		}

		unsigned short GetHeroFreePoints()
		{
			return memory.ReadUInt16(this->XHERO_ADDR + 0xB6);
		}

		unsigned short GetMaxHP()
		{
			return memory.ReadUInt16(this->XHERO_ADDR + 0x6A);
		}

		unsigned short GetCurrentZone()
		{
			return memory.ReadUInt16(this->XHERO_ADDR + 0x1c);
		}




		int GetSourceAttack()
		{
			// return hero addr
			return memory.ReadInt32(this->XHERO_ADDR + 0x1AED0); // + 2 ?
		}
	
		unsigned short GetHP()
		{
			return memory.ReadUInt16(this->XHERO_ADDR + 0x66);
		}

		unsigned int GetMoney()
		{
			return memory.ReadUInt32(this->XHERO_ADDR + 0x28);
		}
	
		unsigned short GetLv()
		{
			return memory.ReadUInt16(this->XHERO_ADDR + 0x22);
		}

		unsigned short GetPower()
		{
			return memory.ReadUInt16(this->XHERO_ADDR + 0x54);
		}

		unsigned short GetAgility()
		{
			return memory.ReadUInt16(this->XHERO_ADDR + 0x56);
		}

		unsigned short GetExatidao()
		{
			return memory.ReadUInt16(this->XHERO_ADDR + 0x58);
		}

		unsigned short GetLuck()
		{
			return memory.ReadUInt16(this->XHERO_ADDR + 0x5A);
		}

	
		void AddMoney(unsigned int count)
		{
			unsigned int myMoney =  this->GetMoney();
			if (myMoney + count >= 4200000000)
				return;
			
			this->SetAsyncGold(myMoney + count);
		}

		


		void Dead()
		{
			void* addr = (void*)0x80ACCA0;
			((TDead)addr)(this->XHERO_ADDR);
		}

		void Revive()
		{
			void* addr = (void*)0x80A0D60;
			((TRevive)addr)(this->XHERO_ADDR);
		}

		void SetAsyncGold(int value)
		{
			void* addr = (void*)0x809C6B0;
			((TSetAsyncGold)addr)(this->XHERO_ADDR, value);
		}

		int GetItemCount(char bagType, unsigned int itemID)
		{
			void* addr = (void*)0x809AB30;
			((TGetItemCount)addr)(this->XHERO_ADDR, bagType, itemID);
		}
	
		int AddPocketItem(unsigned int itemID, int count, bool refresh, int time)
		{
			void* addr = (void*)0x80A6530;
			((TAddPocketItem)addr)(this->XHERO_ADDR, itemID, count, refresh, time);
		}

		int AddPocketHench(unsigned short id, int count)
		{
			void* addr = (void*)0x80B7730;
			((TAddPocketHench)addr)(this->XHERO_ADDR, id, count);
		}
	
		void SetAsyncStoreGold(int value)
		{
			void* addr = (void*)0x809C620;
			((TSetAsyncStoreGold)addr)(this->XHERO_ADDR, value);
		}

		void SetNickname(unsigned short nicknameID)
		{
			void* addr = (void*)0x809B610;
			((TSetNickname)addr)(this->XHERO_ADDR, nicknameID);
		}

		void SetAsyncColor(char a, int b)
		{
			void* addr = (void*)0x809C350;
			((TSetAsyncColor)addr)(this->XHERO_ADDR, a, b);
		}


		void SetAsyncSTS(unsigned char type, unsigned short value)
		{
			void* addr = (void*)0x809C720;
			((TSetAsyncSts)addr)(this->XHERO_ADDR, type, value);
		}

		int GetSts(char type)
		{
			void* addr = (void*)0x809A8F0;
			((TGetSts)addr)(this->XHERO_ADDR, type);
		}

		int GetHench(short henchID)
		{
			void* addr = (void*)0x809A830;
			return ((TGetHench)addr)(this->XHERO_ADDR, henchID, 1);
		}

		void SetReviveZone(char zone)
		{
			memory.WriteByte((int*)(this->XHERO_ADDR + 0x24), zone);
		}

		int GetRemainPocket()
		{
			void* addr = (void*)0x809A930;
			return ((TGetRemainPocket)addr)(this->XHERO_ADDR);
		}

		int ReviveCore(unsigned char henchID)
		{
			void* addr = (void*)0x809C2C0;
			return ((TReviveCore)addr)(this->XHERO_ADDR, henchID);
		}


		int StartQuest(unsigned short questID)
		{
			void* addr = (void*)0x809CA20;
			return ((TStartQuest)addr)(this->XHERO_ADDR, questID);
		}


		int EndQuest(unsigned short questID)
		{
			void* addr = (void*)0x809C9E0;
			return ((TEndQuest)addr)(this->XHERO_ADDR, questID);
		}

		int SendRefreshExpPercentData()
		{
			void* addr = (void*)0x809CB10;
			return ((TSendRefreshExpPercentData)addr)(this->XHERO_ADDR);
		}

		int MoveToReviveZone()
		{
			void* addr = (void*)0x809D0B0;
			return ((TMoveToReviveZone)addr)(this->XHERO_ADDR);
		}

		int MoveZone(unsigned short mapID, unsigned short layerID)
		{
			void* addr = (void*)0x809D110;
			return ((TMoveZone)addr)(this->XHERO_ADDR, mapID, layerID);
		}

		int SendRefreshSTS()
		{
			void* addr = (void*)0x809DE00;
			return ((TSendRefreshSTS)addr)(this->XHERO_ADDR);
		}

		int RemovePocketHench(char henchID)
		{
			void* addr = (void*)0x809E150;
			return ((TRemovePocketHench)addr)(this->XHERO_ADDR, henchID);
		}

		int RemoveStoreHench(char henchID)
		{
			void* addr = (void*)0x809E300;
			return ((TRemoveMyStoreHench)addr)(this->XHERO_ADDR, henchID);
		}
	
	
	
	
};
