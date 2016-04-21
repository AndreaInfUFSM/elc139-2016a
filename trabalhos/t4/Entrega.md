[Programação Paralela - ELC 139](https://github.com/AndreaInfUFSM/elc139-2016a)

## T4: Algoritmo de Floyd Paralelo

##### Nome: Maurício Matter Donato
##### Matrícula: 201410128

- Programa desenvolvido: [floyd parallel](https://github.com/mauriciomd/elc139-2016a/tree/master/trabalhos/t4/floyd_parallel), baseado no código original (versão sequencial).

- xxxx

#####Tempo de execução: 
- A tabela e o gráfico abaixo ilustram os tempos de execuções obtidos, em µsegundos, para cada experimento. O tempo resultando é formado pela média aritmética de 5 execuções por experimento.
<TABLE>
        <TR>
          <TD>Tamanho da Entrada</TD>
          <TD>Tempo: Sequencial</TD>
          <TD>Tempo: 2 Threads</TD>
          <TD>Tempo: 4 Threads</TD>
          <TD>Tempo: 8 Threads</TD>
        </TR>
        <TR>
        	<TD>300</TD>
        	<TD>1.838.836</TD>
        	<TD>1.062.140</TD>
          <TD>1.039.231</TD>
          <TD>994.776</TD>
        </TR>
        <TR>
          <TD>400</TD>
          <TD>4.420.444</TD>
          <TD>2.437.783</TD>
          <TD>2.354.861</TD>
          <TD>2.329.756</TD>
        </TR>
        <TR>
        	<TD>500</TD>
          <TD>8.699.671</TD>
          <TD>4.710.499</TD>
          <TD>4.597.033</TD>
          <TD>4.519.587</TD>
        </TR>
</TABLE>

Gráfico ilustrando os tempos obtidos: </br>
<img src="http://i.imgur.com/EX4utg3.png"/> </br>

##### Speedup:
- O Speedup é calculado a partir da equação: S = TSequencial / TParalelo. Para o experimento em questão, obteu-se um speedups variados, dependendo do tamanho da entrada e do número de Threads em execução. No melhor caso, conseguiu-se um speedup de 1.92, utilizando uma entrada de tamanho 500 e 8 Threads em execução. Abaixo, encontra-se os gráfico demonstrando o speedup em relação a entrada e ao número de Threads. </br>

Speedups obtidos: </br>
<img src="http://i.imgur.com/HnnuKsl.png" /> </br>
