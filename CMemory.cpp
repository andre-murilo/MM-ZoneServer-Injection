#include "CMemory.h"

CMemory::CMemory()
{

}

CMemory::~CMemory()
{

}


char CMemory::ReadByte(int addr)
{
    return *(char*)addr;
}

unsigned char CMemory::ReadUByte(int addr)
{
    return *(unsigned char*)addr;
}


short CMemory::ReadInt16(int addr)
{
    return *(short*)addr;
}


unsigned short CMemory::ReadUInt16(int addr)
{
    return *(unsigned short*)addr;
}


int CMemory::ReadInt32(int addr)
{
    return *(int*)addr;
}


unsigned CMemory::ReadUInt32(int addr)
{
    return *(unsigned int*)addr;
}


float CMemory::ReadFloat(int addr)
{
    return *(float*)addr;
}


char* CMemory::ReadString(int addr)
{
    return (char*)addr;
}


int CMemory::CalculateJMP(int oriAddr, int myFunc)
{
    int offset = (int)myFunc - (int)oriAddr - 5;
	return offset;
}


void CMemory::ChangeMemProtect(int addr)
{

	size_t pageSize = sysconf(_SC_PAGESIZE);
	intptr_t start = (intptr_t)addr;
	intptr_t pageStart = start & -pageSize;
	/*
    
	intptr_t start = (intptr_t)addr;
	intptr_t end = start + 1;
	intptr_t pageStart = start & -pageSize;
	mprotect((void*)pageStart, end - pageStart, PROT_READ | PROT_WRITE | PROT_EXEC);
	*/
	mprotect((void*)pageStart, 1024, PROT_READ | PROT_WRITE | PROT_EXEC);
}


void CMemory::PlaceJMP(char *pAddress, int dwJumpTo, int len)
{
    ChangeMemProtect((int)pAddress);
	ChangeMemProtect((int)dwJumpTo);

	int offset = CalculateJMP((int)pAddress, (int)dwJumpTo);

	*pAddress = 0xE9;
	*((int*)(pAddress + 0x1)) = offset;

	for (char i = 5; i < len; i++)
	{
		*(char*)(pAddress + i) = 0x90;
	}
}

void CMemory::PlaceCall(char *pAddress, int dest, int len)
{
	ChangeMemProtect((int)pAddress);
	ChangeMemProtect((int)dest);

	int offset = CalculateJMP((int)pAddress, (int)dest);

	*pAddress = 0xE8;
	*((int*)(pAddress + 0x1)) = offset;


	for (char i = 5; i < len; i++)
	{
		*(char*)(pAddress + i) = 0x90;
	}
}


void CMemory::WriteByte(int *addr, char value)
{
    ChangeMemProtect(*addr);
	*(char*)addr = value;
}


void CMemory::WriteInt32(int addr, int value)
{
    int *p = (int*)addr;
	ChangeMemProtect((int)p);
	*p = value;
}

void CMemory::WriteInt16(int addr, short value)
{
	ChangeMemProtect((int)(int*)addr);
	
	*(short*)addr = value;
}

void CMemory::WriteUint16(int addr, unsigned short value)
{
	ChangeMemProtect(addr);
	*(unsigned short*)addr = value;
}

void CMemory::WriteFloat(int *addr, int value)
{
    ChangeMemProtect(*addr);
	*(float*)addr = value;
}


void CMemory::WriteMemory(int addr, unsigned char data[], short length)
{
    ChangeMemProtect(addr);
	int i = 0;
	for (i = 0; i < length; i++)
	{
		*(char*)(addr + (char)i) = data[i];
	}
}


void CMemory::ChangeCoreRate(float value)
{
	WriteFloat((int*)CORE_DROP_RATE_addr, value);
}

void CMemory::ChangeItemRate(float value)
{
	WriteFloat((int*)ITEM_DROP_RATE_addr, value);
}

void CMemory::ChangeExpRate(float value)
{	
	WriteFloat((int*)EXP_RATE_addr, value);
}

void CMemory::ChangeMoneyRate(float value)
{
	WriteFloat((int*)MONEY_RATE_addr, value);
}



int CMemory::swap_int32(int val)
{
    val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF); 
	return (val << 16) | ((val >> 16) & 0xFFFF);
}


int CMemory::ReadXHero(int index)
{
	// ZC_CLIENT_DATA
	return ReadInt32(zc_client_data_addr) + (XHero_len * index);
}

int CMemory::SendPacket(int client, int *packet)
{
	void* addr = (void*)0x80E47C0;
	return ((TAddTo_ZC_SendQ)addr)(client, packet);
}