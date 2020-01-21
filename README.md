# MM-ZoneServer-Injection

ZoneServer Injection é um projeto com o intuito de expandir funcionalidades que naturalmente não se encontram no binário origininalmente.
É uma biblioteca dinamica, é carregada ao inicializar a ZoneServer com o uso do LD_EXPORT. Dessa forma, é criado um segmento próprio capaz de integarir com o processo. 

# Introdução
ZoneServer Injection é baseado em técnicas de injeção de código. Possibilitando o controle de fluxo em algumas funções, assim como a manipulação de dados em memória. 

Até o momento, é possível fazer chamadas de funções internas, ler e escrever dados em memória e interceptar algumas funções.

# Conteúdo
O objetivo é a expansão de funcionalidades de forma automatizada, a fim de ser gerenciavel por scripts na linguagem Lua.

Até o momento, é possível ler todos os dados dos jogadores autenticados, assim como é possível alterar o estado (variaveis) do jogador em tempo real. 

É possível enviar pacotes customizados para jogadores, ou até mesmo interceptar comandos (eventos) em tempo de execução. 

Alguns comandos de chat foram criados para fins de teste.
