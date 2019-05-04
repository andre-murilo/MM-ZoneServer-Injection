#pragma once

#include <sys/mman.h>
#include <unistd.h>

class CMemory
{
    public:
        CMemory();
        ~CMemory();

        typedef int(*TAddTo_ZC_SendQ)(int, int *);  // heroID, xpacket

        const int zc_privkey_addr = 0x825B8C0;
        const int zc_maxclient_addr = 0x825B8C2;
        const int LOCALE_MODE_addr = 0x825BBA0;
        const int ZC_BIND_IP_addr = 0x825B8C4;
        const int ZC_BIND_PORT_addr = 0x825B8D4;
        const int gms_num_addr = 0x825B8EC;
        const int GMS_IP_addr = 0x825B8D8;
        const int GMS_PORT_addr = 0x825B8E8;

        const int CORE_DROP_RATE_addr = 0x814CC30;
        const int ITEM_DROP_RATE_addr = 0x814CC34;
        const int EXP_RATE_addr	= 0x814CC38;
        const int MONEY_RATE_addr = 0x814CC3C;

        const int zc_client_data_addr = 0x91005DC;
        const int XHero_len = 0x1DA90;


        char ReadByte(int addr);
        unsigned char ReadUByte(int addr);
        short ReadInt16(int addr);
        unsigned short ReadUInt16(int addr);
        int ReadInt32(int addr);
        unsigned ReadUInt32(int addr);
        float ReadFloat(int addr);
        char* ReadString(int addr);
        int CalculateJMP(int oriAddr, int myFunc);
        void ChangeMemProtect(int addr);
        void PlaceJMP(char *pAddress, int dwJumpTo, int len);
        void PlaceCall(char *pAddress, int dest, int len);
        void WriteByte(int *addr, char value);
        void WriteInt32(int addr, int value);
        void WriteInt16(int addr, short value);
        void WriteUint16(int addr, unsigned short value);
        void WriteFloat(int *addr, int value);
        void WriteMemory(int addr, unsigned char data[], short length);

        void ChangeCoreRate(float value);
        void ChangeItemRate(float value);
        void ChangeExpRate(float value);
        void ChangeMoneyRate(float value);

        int swap_int32(int val);
        int ReadXHero(int index);

        int SendPacket(int client, int *packet);

    private:

};

