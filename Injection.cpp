
#ifndef  VMO


#include <stdint.h>
#include <stdio.h>
#include <pthread.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <list>
#include <sys/mman.h>
#include <unistd.h>
#include <ctime>
#include "CScriptManager.h"
#include "CHookManager.h"
#include "CEventsHandler.h"
#include "CPacket.h"


CScriptManager sctManager;
CHookManager hookManager;
CEventsHandler eventsHandler;

pthread_t tid;


// estrutura do evento
struct Event
{
	int beginDay; 				// dia inicial
	int endDay; 				// dia final

	int beginHour; 				// hora de inicio
	int endHour; 				// hora de termino
	int beginMinute;			// hora minuto inicio
	int endMinute;				// hora minuto termino

	bool weekRestricted; 		// evento funciona apenas em um dia especifico da semana
	std::vector<int> weekDays; 	// dias da semana

	string message; 			// mensagem
	int interval; 				// intervalo
	int contador; 				// contador do intervalo

	bool event_rate; 			// evento rate type
	float core_rate; 			// rate core quando tiver rolando evento
	float item_rate; 			// rate item quanto tiver rolando evento
	float exp_rate; 			// rate exp quando tiver rolando evento
	float gp_rate; 				// rate gp quando tiver rolando evento
};


std::vector<Event> eventos;




// callbacks
__attribute__((naked)) void myInitFunc();
__attribute__((naked)) void myHeroSitFunction();
__attribute__((naked)) void myChatFunction();
__attribute__((naked)) void myProcDeathFunction();
__attribute__((naked)) void myEquipHenchFunction();
__attribute__((naked)) void myAddToZsSend();
__attribute__((naked)) void myDropCore();
__attribute__((naked)) void myMixCore();
__attribute__((naked)) void mySetHero();
__attribute__((naked)) void myMoveClient_ToZone();

void InitializeEvents()
{
	// happyHour diario
	Event happyHour;
	happyHour.beginDay = 0;
	happyHour.endDay = 31;
	happyHour.beginHour = 19;
	happyHour.endHour = 23;
	happyHour.beginMinute = 0;
	happyHour.endMinute = 50;

	happyHour.weekRestricted = false;
	happyHour.event_rate = true;
	happyHour.core_rate = 2.0f;
	happyHour.item_rate = 2.0f;
	happyHour.exp_rate = 2.0f;
	happyHour.gp_rate = 2.0f;

	happyHour.message = string("Happy Hour: 2x Rates, termina as 23:00.");
	happyHour.interval = 2;
	happyHour.contador = 0;

	// happyHour finalsemana
	Event happyWeek;
	happyWeek.beginDay = 0;
	happyWeek.endDay = 31;
	happyWeek.beginHour = 16;
	happyWeek.endHour = 23;
	happyWeek.beginMinute = 0;
	happyWeek.endMinute = 0;

	happyWeek.weekRestricted = true;
	happyWeek.weekDays.push_back(0); // domingo
	happyWeek.weekDays.push_back(6); // sabado

	happyWeek.event_rate = true;
	happyWeek.core_rate = 2.0f;
	happyWeek.item_rate = 2.0f;
	happyWeek.exp_rate = 2.0f;
	happyWeek.gp_rate = 2.0f;

	happyWeek.message = string("Happy Hour: 2x Rates, termina as 23:00.");
	happyWeek.interval = 30;
	happyWeek.contador = 0;

	// adiciona eventos
	eventos.push_back(happyHour);
	eventos.push_back(happyWeek);
}

void *Start(void *args)
{
	CMemory memory;
	CPacket packet;
	time_t now;
	char buffer[128];

	


	// sleep inicial de 250 ms
	//usleep(250000);
	usleep(500);


	// set intel assembly syntax
	asm(".intel_syntax noprefix");



	printf("\n[*] VMO - VirtualMonster MOD - Version 1.0\n");
	printf("\n[*] Carregando scripts ...\n");
	//sctManager.LoadALL();

	printf("[*] Carregando Hookings ...\n\n");
	//hookManager.PlaceInitHook((int)&myInitFunc);
	hookManager.PlaceHeroSitHook((int)&myHeroSitFunction);
	hookManager.PlaceHeroChatHook((int)&myChatFunction);
	hookManager.PlaceMobDeathHook((int)&myProcDeathFunction);
	//hookManager.PlaceSendQtoZsHook((int)&myAddToZsSend);
	//hookManager.PlaceEquipHenchHook((int)&myEquipHenchFunction);
	hookManager.PlaceDropCoreHook((int)&myDropCore);
	hookManager.PlaceMixCoreHook((int)&myMixCore);
	//hookManager.PlaceSetHeroHook((int)&mySetHero);
	hookManager.PlaceMoveClientHook((int)&myMoveClient_ToZone);



	int contador1 = 0;
	int contador2 = 0;


	now = time(NULL);
	tm *tm = localtime(&now);
	InitializeEvents();

	printf("\n");

	while (true)
	{
		now = time(NULL);
		tm = localtime(&now);

		int year = tm->tm_year + 1900;
		int month = tm->tm_mon + 1;
		int day = tm->tm_mday;
		int weekDay = tm->tm_wday;
		int hour = tm->tm_hour;
		int min = tm->tm_min;
		int sec = tm->tm_sec;

		/*
		for(int i = 0; i < eventos.size(); i++)
		{
			Event evento = eventos[i];
			bool dayRange = false;
			bool hourRange = false;
			bool minuteRange = false;


			// testa o dia
			if(day >= evento.beginDay && day <= evento.endDay)
				dayRange = true;
			else
				continue;

			// testa a hora
			if(hour >= evento.beginHour && hour <= evento.endHour)
				hourRange = true;
			else
				continue;


			// testa os minutos
			if(hour == evento.beginHour && hour == evento.endHour)
			{
				if(min >= evento.beginMinute)
					minuteRange = true;
				else
					minuteRange = false;

				if(min <= evento.endHour)
					minuteRange = true;
				else
					minuteRange = false;

			}
			else if(hour == evento.beginHour)
			{
				if(min >= evento.beginMinute)
					minuteRange = true;
			}
			else if(hour == evento.endHour)
			{
				if(min <= evento.endMinute)
					minuteRange = true;
			}
			else
			{
				if(min >= evento.beginMinute && min <= evento.endMinute)
					minuteRange = true;
			}

			// testa as variaveis
			if(dayRange == false || hourRange == false || minuteRange == false)
				continue;

			// testa o dia da semana
			if(evento.weekRestricted)
			{
				bool achou = false;
				for(int j = 0; j < evento.weekDays.size(); j++)
				{
					if(evento.weekDays[j] == weekDay)
					{
						achou = true;
						break;
					}
				}

				if(!achou) continue;
			}


			// muda as rates
			if(evento.event_rate)
			{
				memory.ChangeCoreRate(evento.core_rate);
				memory.ChangeItemRate(evento.item_rate);
				memory.ChangeExpRate(evento.exp_rate);
				memory.ChangeMoneyRate(evento.gp_rate);
			}

			// verifica o intervalo
			if(evento.contador >= evento.interval)
			{
				packet.SendAnouncement(evento.message);
				printf("evento message send!\n");


				eventos[i].interval = 0;
			}
			else
			{
				printf("evento ok: %d / %d\n", evento.contador, evento.interval);
				eventos[i].contador += 1;
			}

		}*/





		if(hour >= 16 && hour < 23)
		{
			// final de semana
			if(weekDay == 0 || weekDay == 6) // sabado ou domingo
			{
				memory.ChangeCoreRate(4.0f);
				memory.ChangeItemRate(4.0f);
				memory.ChangeExpRate(4.0f);
				memory.ChangeMoneyRate(4.0f);

				if(contador1 >= 20)
				{
					sprintf(buffer, "[Evento] Happy Hour: 4x Rates até domingo 23:59.");
					packet.SendAnouncement(string(buffer));
					contador1 = 0;
				}
			}
			else
			{
				memory.ChangeCoreRate(2.0f);
				memory.ChangeItemRate(2.0f);
				memory.ChangeExpRate(2.0f);
				memory.ChangeMoneyRate(2.0f);
			}

			/*
			else
			{
				if(hour >= 19)
				{
					memory.ChangeCoreRate(2.0f);
					memory.ChangeItemRate(2.0f);
					memory.ChangeExpRate(2.0f);
					memory.ChangeMoneyRate(2.0f);

					if(contador1 >= 20)
					{
						sprintf(buffer, "Happy Hour: 2x Rates, termina as 23:00.");
						packet.SendAnouncement(string(buffer));
						contador1 = 0;
					}
				}
			}*/

			contador1++;
		}

		/*
		if(contador2 >= 30)
		{
			sprintf(buffer, "Noticia: Evento Pajiramon acaba dia 27/03.");
			packet.SendAnouncement(string(buffer));

			contador2 = 0;
		}

		contador2++;
		*/

		//printf("%d/%d/%d %d:%d:%d - %d\n", day, month, year, hour, min, sec, weekDay);

		usleep(60000000); // dorme por 1 minuto

	}
}

__attribute__((constructor)) void init(void)
{
	pthread_create(&tid, NULL, Start, NULL);
}






// callbaks
// Quando a zoneserver eh iniciada
__attribute__((naked)) void myInitFunc()
{
	// intel assembly
	asm("pusha");
	printf("Inicializando [VirtualMonster - Mod]\n");
	asm("popa");

	asm("push ebp");
	asm("mov esp, ebp");
	asm("push edi");
	asm("push esi");

	asm("jmp %0" : : "r"(0x80EA2C5));
}



// Quando um jogador sentar
int xHeroAddr = 0;
__attribute__((naked)) void myHeroSitFunction()
{
	// intel assembly
	asm("push ebp");
	asm("mov esp, ebp");
	asm("push esi");
	asm("push ebx");

	asm("mov %0, [ebp + 0x08]" : "=r"(xHeroAddr));

	asm("pusha");
	printf("O jogador sentou / levantou !!!\n");
	asm("popa");

	asm("jmp %0" : : "r"(0x80A0E95));

}

// Quando um jogador falar no speaker chat
int heroChatAddr = 0;
char* chatMessage;
__attribute__((naked)) void myChatFunction()
{
	// assembly asm
	asm("push ebp");
	asm("mov esp, ebp");
	asm("push esi");
	asm("push ebx");

	asm("mov %0, [ebp + 0x08]" : "=r"(heroChatAddr));
	asm("mov %0, [ebp + 0x0c]" : "=r"(chatMessage));

	asm("pusha");
	bool result = eventsHandler.OnHeroSpeakerChat(heroChatAddr, chatMessage);
	asm("popa");

	if(result)
	{
		asm("pop ebx");
		asm("pop esi");
		asm("pop ebp");
		asm("ret");
	}
	else
	{
		asm("jmp %0" : : "r"(0x809CC75));
	}


}
// Quando um mob do mapa morrer
int xmobAddr = 0;
__attribute__((naked)) void myProcDeathFunction()
{
	// intel assembly
	asm("push ebp");
	asm("mov esp, ebp");
	asm("push edi");
	asm("push esi");
	asm("push ebx");

	asm("mov %0, [ebp + 0x08]" : "=r"(xmobAddr));

	asm("pusha");
	printf("Mob morreu!\n");
	eventsHandler.OnMobDeath(xmobAddr);
	asm("popa");

	asm("jmp %0" : : "r"(0x80C67A6));
}


int xBattleHenchAddr = 0;
__attribute__((naked)) void myEquipHenchFunction()
{
	// intel assembly

	asm("mov esp, ebp");
	asm("pop ebp");


	asm("mov WORD PTR [edx+0xAA], ax");

	asm("pusha");
	asm("mov %0, edx" : "=r"(xBattleHenchAddr));
	//printf("Funcao chamada com sucesso! - Address: %x\n", xBattleHenchAddr);
	//eventsHandler.OnHeroEquipHench(xBattleHenchAddr);
	asm volatile("jmp %0" : : "r"(0x8099571));
	asm("popa");

}

// hook AddTo_ZC_SendQ
int AddToZSClient = 0;
int XPacketAddr = 0;

__attribute__((naked)) void myAddToZsSend()
{
	asm("push ebp");
	asm("mov esp, ebp");
	asm("push ebx");
	asm("sub esp, 0x14");

	asm("mov %0, [ebp + 0x08]" : "=r"(AddToZSClient));
	asm("mov %0, [ebp + 0x0c]" : "=r"(XPacketAddr));

	asm("pusha");
	eventsHandler.OnSendPacket(AddToZSClient, XPacketAddr);
	asm("popa");

	asm volatile("jmp %0" : : "r"(0x80E47C7));
}


int HeroDropCore = 0;
int dropCoreSrc = 0;
__attribute__((naked)) void myDropCore()
{
	// original ***
	// push ebp
	// mov ebp, esp

	// restore stack
	asm("mov esp, ebp");
	asm("pop ebp");

	// restore bytes writted
	asm("mov DWORD PTR [esp+4], 0x0");


	asm("pusha");
	asm("mov %0, [ebp + 0xc]" : "=r"(HeroDropCore));
	asm("mov %0, ecx" : "=r"(dropCoreSrc));

	eventsHandler.OnDropCore(HeroDropCore, dropCoreSrc);
	asm("popa");


	// push anything
	asm("push 5");


	//asm volatile("jmp %0" : : "r"(0x80C5553));
}


int heroMixCore = 0;
int henchMixCore = 0;
__attribute__((naked)) void myMixCore()
{


	// restore stack
	asm("add esp, 0x8");
	asm("mov esp, ebp");
	asm("pop ebp");

	// restore bytes writted
	asm("mov DWORD PTR [esp + 0x4], ebx");
	asm("mov DWORD PTR [esp], esi");

	asm("pusha");
	asm("mov %0, esi" : "=r"(heroMixCore));
	asm("mov %0, ebx" : "=r"(henchMixCore));

	eventsHandler.OnMixCore(heroMixCore, henchMixCore);
	asm("popa");

	asm volatile("jmp %0" : : "r"(0x80CBC39));

	//asm("ret");

	// push anything
	//asm("push 5");
}

int setHero_hero = 0;
__attribute__((naked)) void mySetHero()
{
	// intel assembly
	asm("push ebp");
	asm("mov esp, ebp");
	asm("push edi");
	asm("push esi");


	asm("pusha");
	asm("mov %0, [ebp + 0xC]" : "=r"(setHero_hero));

	//eventsHandler.OnHeroEnterGame(setHero_hero);

	asm("popa");


	asm volatile("jmp %0" : : "r"(0x80B4FF5));
}


short moveClient_hero_id = 0;
short moveMapTarget = 0;
__attribute__((naked)) void myMoveClient_ToZone()
{
	asm("push ebp");
	asm("mov esp, ebp");
	asm("sub esp, 0x2058");

	asm("pusha");
	asm("mov %0, [ebp + 0xC]" : "=r"(moveClient_hero_id));
	asm("mov %0, [ebp + 0x10]" : "=r"(moveMapTarget));
	eventsHandler.OnHeroChangeMap(moveClient_hero_id, moveMapTarget);
	asm("popa");

	asm volatile("jmp %0" : : "r"(0x80D4069));
}













#endif // ! VMO
