#include "CScriptManager.h"

// constructor
CScriptManager::CScriptManager()
{
	
}

// destructor
CScriptManager::~CScriptManager()
{
	printf("[SCRIPT] ScriptManager has realesed!\n");
}

int CScriptManager::ScriptsCount()
{
	return (int)this->scripts.size();
}


int CScriptManager::GetScriptIndex(lua_State *L)
{
	for (int i = 0; i < this->ScriptsCount(); i++)
	{
		if (this->scripts[i].GetLState() == L)
		{
			return i;
		}	
	}
	return -1;
}


void CScriptManager::Reload()
{
	this->scripts.clear();
	this->LoadALL();
}

void CScriptManager::LoadALL()
{
	DIR *dp;
	dirent *ep;
	
	int contador = 0;
	dp = opendir("./scripts/");
	
	// verifica se o diretorio foi aberto com sucesso
	if(dp == NULL)
	{
		printf("[SCRIPT] 0 scripts carregados!\n");
		return;
	}
	
	// faz a leitura de todos os elementos dentro do diretorio
	while((ep = readdir(dp)))
	{
		// checa o tipo do elemento
		if(ep->d_type != 0x08) // is not a file
		{
			continue;
		}

		
		// verifica se a extensao no arquivo eh valida
		std::string file_name(ep->d_name);
		if (file_name.substr(file_name.find_last_of(".") + 1) != "lua") 
		{
			printf("%s nao eh um arquivo lua valido!\n", ep->d_name);
			continue;
		}
		
		// buffer name
		char buffer[32];
		sprintf(buffer, "%s%s", "scripts/", ep->d_name);

		printf("%s\n", buffer);

		std::string name(buffer);
		
		
		// instace script
		Script sct((char*)buffer, &scripts);
		// coloca o script no vector
		this->scripts.push_back(sct);
		// registra as funcoes
		//RegisterFunctions(this->scripts[contador].GetLState());
		
		// carrega & roda o script
		if (!this->scripts[contador].Load())
		{
			printf("[SCRIPT] Falha ao carregar script: %s\n", ep->d_name);
	
			this->scripts.erase(this->scripts.begin() + contador);
			continue;
		}
		
		contador++;
		printf("[SCRIPT] %s foi carregado com sucesso!\n", ep->d_name);
	}
	
	// fecha o diretorio
	closedir(dp);
	printf("\n[SCRIPT] %d scripts carregados!\n", this->ScriptsCount());
}
