[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2016a) > Trabalhos

# T3: Programação Paralela Multithread 

##### Nome: Maurício Matter Donato
##### Matrícula: 201410128

## Parte 1: PThreads

- (1). O particionamento/aglomeração e mapeamento é feito através do cálculo: <br/>
        <p>int wsize = dotdata.wsize; <br/>
        int start = offset*wsize;<br/>
        int end = start + wsize;<br/> </p>
      Onde offset é o argumento passado ao inici ar a pthread_join (Thread 1 -> offset = 0; Thread 2 -> offset = 1; etc etc).<br/>
      Desse modo, cada thread consegue cálcular o seu tamanho de array para processamento. Por exemplo, ao iniciar o programa com 2 threads e tamanho do array = N, o progamada aloca memória para 2*N posições, de tal modo que a Threa 1 fique responsável pelos elementos 0...N-1 e a Thread 2, pelos elementos de N..2*N-1<br/>
 
A comunicação é feita através da variável compartilhada pelas threads. Cada thread guarda seu resultado parcial em mysum e, ao final da sua execução, adiciona seu resultado a variável dotdata.c,como ilustra o código abaixo:<br/>
     <p>pthread_mutex_lock (&mutexsum);<br/>
        dotdata.c += mysum;<br/>
        pthread_mutex_unlock (&mutexsum);<br/> </p>


- (2). Durante o experimento com a configuração de 1 Thread, tamanho = 1.000.000 e repetições = 2.000, obteu-se um tempo médio de 8738260 usec. Já para a versão paralela, rodando com a configuração de 1 Thread, tamanho = 1.000.000 e repetições = 2.000, obteu-se uma média de 8104305 usec. Portanto, com um speedup aproximadamente igual a 1.08.
  -> Média de 5 execuções para cada versão.

- (3). Ao adicionar mais threads do que o número máximo de núcles físicos, é constada uma queda de desempenho. No experimento testado, a execução com 4 threads foi a mais lenta, se comparada com sua respectiva configuração usando 1 ou 2 threads. Por outro lado, ao aumentar o tamanho do vetor de entrada, bem como o número de repetições, constatou-se que o speedup manteve-se 1 <= speedup <= 1.08

- (4). A tabela abaixo, ilustra o tempo de execução e sua respectiva configuração de alguns experimentos:
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
        	<TD> 8037419 </TD>
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

- (5). A versão pthreads_dotprod2 não possui as linhas `pthread_mutex_lock (&mutexsum);` e `pthread_mutex_unlock (&mutexsum);`. A remoção dessas linhas gera uma condição de corrida na variável compartilhada dotdata.c responsável por acumular os resultados calculados. Tal condição pode gerar inconsistência/erro no resultado final, alterando para mais ou para menos o valor final.

## Parte 2: OpenMP

- Comparação entre PThreads e OpenMP: Média de 3 execuções por configuração.
<TABLE>
        <TR>
          <TD>Tamanho dos Vetores</TD>
          <TD>Repetições</TD>
          <TD>Nº de Threads</TD>
          <TD>Tempo de execução PThreads (usec)</TD>
          <TD>Tempo de execução OpenMP (usec)</TD>
        </TR>
        <TR>
            <TD> 1.000.000 </TD>
            <TD> 2.000 </TD>
            <TD> 1 </TD>
            <TD> 8051078 </TD>
            <TD> 8838086 </TD>
        </TR>
        <TR>
            <TD> 1.000.000 </TD>
            <TD> 2.000 </TD>
            <TD> 2 </TD>
            <TD> 8037419</TD>
            <TD> 4912483 </TD>
        </TR>
        <TR>
            <TD> 1.000.000 </TD>
            <TD> 5.000 </TD>
            <TD> 1 </TD>
            <TD> 20990081 </TD>
            <TD> 21745580 </TD>
        </TR>
        <TR>
            <TD> 1.000.000 </TD>
            <TD> 5.000 </TD>
            <TD> 2 </TD>
            <TD> 20365911 </TD>
            <TD> 12336983 </TD>
        </TR>
        <TR>
            <TD> 1.000.000 </TD>
            <TD> 5.000 </TD>
            <TD> 4 </TD>
            <TD> 30502507 </TD>
            <TD> 12043718 </TD>
        </TR>
        <TR>
            <TD> 5.000.000 </TD>
            <TD> 2.000 </TD>
            <TD> 1 </TD>
            <TD> 43207630 </TD>
            <TD> 54968879 </TD>
        </TR>
        <TR>
            <TD> 5.000.000 </TD>
            <TD> 2.000 </TD>
            <TD> 2 </TD>
            <TD> 40603254 </TD>
            <TD> 24742737 </TD>
        </TR>
        <TR>
            <TD> 5.000.000 </TD>
            <TD> 2.000 </TD>
            <TD> 4 </TD>
            <TD> 61029029 </TD>
            <TD> 23871081 </TD>
        </TR>
</TABLE>
