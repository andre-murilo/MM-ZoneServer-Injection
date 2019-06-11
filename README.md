# MM-ZoneServer-Injection

ZoneServer Injection é um projeto de extensão que adiciona funcionalidades que naturalmente não se encontra na ZoneServer originalmente.
É uma modificação única, proporcionando maneiras de criar novos mecanismos.

É uma biblioteca dinamica, que é carregada ao inicializar a ZoneServer. Dessa forma, é criado um segmento próprio com permissões especificas
para ter uma interação com outros segmentos do processo.


# Introdução
ZoneServer Injection é baseado em técnicas de injeção de código. Possibilitando o controle de fluxo dos segmentos dentro do processo, assim
como o acesso a memória. 

Até o momento, é possível fazer chamadas de funções internas, ler e escrever dados em memória e interceptar algumas funções.

# Conteúdo
O objetivo, é expandir a automatização do processo, a fim de ser totalmente gerenciado por scripts na linguagem Lua. 

Até o momento, é possível ler todos os dados dos jogadores logados, assim como é possível alterar o estado (variaveis) do jogador em tempo
real. 

É possível enviar pacotes customizados para jogadores, ou até mesmo interceptar comandos (eventos) em tempo de execução. 

Alguns comandos de chat, foram criados para fins de teste.




