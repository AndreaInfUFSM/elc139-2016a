[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2016a) > Trabalhos

# T3: Programação Paralela Multithread 

##### Nome: Maurício Matter Donato
##### Matrícula: 201410128

## Parte 1: PThreads
	-- (1). 

	-- (2). Durante o experimento com a configuração de 1 Thread, tamanho = 1.000.000 e repetições = 2.000, obteu-se um tempo médio* de 8738260 usec. Já para a versão paralela, rodando com a configuração de 1 Thread, tamanho = 1.000.000 e repetições = 2.000, obteu-se uma média* de 8104305 usec. Portanto, com um speedup aproximadamente igual a 1,08.
		* Média de 5 execuções para cada versão.

	-- (3). 

	-- (4). A tabela abaixo, ilustra o tempo de execução e sua respectiva configuração de alguns experimentos:
	<TABLE>
          <TR>
            <TD>Tamanho dos Vetores</TD>
            <TD>Repetições</TD>
            <TD>Nº de Threads</TD>
            <TD>Tempo de execução (usec)</TD>
          </TR>
          <TR>
          	<TD> 1.000.000 </TD>
          	<TD> 2.0000 </TD>
          	<TD> 1 </TD>
          	<TD> 8051078 </TD>
          </TR>
          <TR>
          	<TD> 1.000.000 </TD>
          	<TD> 2.000 </TD>
          	<TD> 2 </TD>
          	<TD> 8156359 </TD>
          </TR>
          <TR>
          	<TD> 1.000.000 </TD>
          	<TD> 5.000 </TD>
          	<TD> 1 </TD>
          	<TD> 20990081 </TD>
          </TR>
          <TR>
          	<TD> 1.000.000 </TD>
          	<TD> 5.000 </TD>
          	<TD> 2 </TD>
          	<TD> 20365911 </TD>
          </TR>
          <TR>
          	<TD> 1.000.000 </TD>
          	<TD> 5.000 </TD>
          	<TD> 4 </TD>
          	<TD> 30502507 </TD>
          </TR>
          <TR>
          	<TD> 5.000.000 </TD>
          	<TD> 2.000 </TD>
          	<TD> 1 </TD>
          	<TD> 43207630 </TD>
          </TR>
          <TR>
          	<TD> 5.000.000 </TD>
          	<TD> 2.000 </TD>
          	<TD> 2 </TD>
          	<TD> 40603254 </TD>
          </TR>
          <TR>
          	<TD> 5.000.000 </TD>
          	<TD> 2.000 </TD>
          	<TD> 4 </TD>
          	<TD> 61029029 </TD>
          </TR>
        </TABLE>

        Em todos os casos, o tempo apresentado é a média aritimética de 4 execuções.

	-- (5). A versão pthreads_dotprod2 não possui as linhas 'pthread_mutex_lock (&mutexsum);' e 'pthread_mutex_unlock (&mutexsum);'. A remoção dessas linhas gera uma condição de corrida na variável compartilhada 'dotdata.c' responsável por acumular os resultados calculados. Tal condição pode gerar inconsistência/erro no resultado final, alterando para mais ou para menos o valor final.