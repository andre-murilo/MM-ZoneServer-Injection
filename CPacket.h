#pragma once

#include <string>
#include <stdio.h>
#include <vector>
#include "XHero.h"
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream
#include <stdlib.h>
#include "CMemory.h"
#include "MemoryWritter.h"

using namespace std;


typedef int(*TSendWhisper)(unsigned short, const char *, const char *);  // heroID, fromMessage, message


class CPacket
{

public:    

	void SendAnouncement(string message)
	{
		CMemory memory;

        // writter
		MemoryWritter writter(4190);
		writter.WriteInt16(0, 4100); // zero buffer
		writter.ZeroBuffer(4190);

		writter.WriteByte(181);
		writter.WriteString(message, message.size());
		// end
		writter.WriteByte(0);

		for(int i = 1; i < 1025; i++)
		{
			XHero *h = new XHero(memory.ReadXHero(i));
			if(!h->IsLogged()) 
			{
				continue;
			}

			memory.SendPacket(i, (int*)&writter.buffer[0]);
		}
	}

	void SendWhisper(unsigned short heroTarget, const char *from, const char *msg)
	{
		void* addr = (void*)0x808AC10;
		((TSendWhisper)addr)(heroTarget, from, msg);
	}


    void SendNotifyHappyHour()
    {
        CMemory memory;

        // writter
		MemoryWritter writter(4109);
		writter.WriteInt16(0, 4100); // zero buffer
		writter.ZeroBuffer(4109);

		// head 1
		writter.WriteInt16(45);
		writter.WriteByte(0);
		// head 2
		writter.WriteInt16(45);
		writter.WriteByte(0);
		// packet type
		writter.WriteByte(181);
		writter.WriteString(string("Happy Hour: 2x Rates de 19:00 ate as 23:00."), 43);
		// end
		writter.WriteByte(0);
		
		for(int i = 1; i < 1025; i++)
		{
			XHero *h = new XHero(memory.ReadXHero(i));
			if(!h->IsLogged()) 
			{
				continue;
			}

			memory.SendPacket(i, (int*)&writter.buffer[0]);
		}
    }

    void SendEventMakurimon()
    {
        CMemory memory;

        // writter
		MemoryWritter writter(4109);
		writter.WriteInt16(0, 4100); // zero buffer
		writter.ZeroBuffer(4109);

		// head 1
		writter.WriteInt16(47);
		writter.WriteByte(0);
		// head 2
		writter.WriteInt16(47);
		writter.WriteByte(0);
		// packet type
		writter.WriteByte(181);
		writter.WriteString(string("Noticia: Evento do Makurimon acaba dia 27/02."), 45);
		// end
		writter.WriteByte(0);
		
		for(int i = 1; i < 1025; i++)
		{
			XHero *h = new XHero(memory.ReadXHero(i));
			if(!h->IsLogged()) 
			{
				continue;
			}

			memory.SendPacket(i, (int*)&writter.buffer[0]);
		}
    }

    void SendPageFeed()
    {
        CMemory memory;

        // writter
		MemoryWritter writter(4109);
		writter.WriteInt16(0, 4100); // zero buffer
		writter.ZeroBuffer(4109);

		// head 1
		writter.WriteInt16(42);
		writter.WriteByte(0);
		// head 2
		writter.WriteInt16(42);
		writter.WriteByte(0);
		// packet type
		writter.WriteByte(181);
		writter.WriteString(string("Mais informacoes, visite a nossa pagina."), 42);
		// end
		writter.WriteByte(0);
		
		for(int i = 1; i < 1025; i++)
		{
			XHero *h = new XHero(memory.ReadXHero(i));
			if(!h->IsLogged()) 
			{
				continue;
			}

			memory.SendPacket(i, (int*)&writter.buffer[0]);
		}
    }





};

