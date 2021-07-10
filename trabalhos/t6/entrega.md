[Programação Paralela - ELC 139](https://github.com/AndreaInfUFSM/elc139-2016a)

## T6: Ray Tracing em MPI

##### Nome: Maurício Matter Donato - Matrícula: 201410128

## Versão desenvolvida:
- Para este trabalho desenvolveu-se uma versão do algortimo Ray Tracing em paralelo, utilizando arquitetura distribuída. Baseando-se na sua versão sequencial, a versão desenvolvida trabalha da seguinte maneira: o processo de rank 0 atua como pivô da comunicação, aguardando que os n-1 processos enviam seus respectivos dados. A distribuição da carga de trabalho é dada baseando-se no número de processos que irão processar os dados (n-1 processos). Uma vez recebido os dados, o processo pivô armazenas-os em um buffer. Após receber os dados de todos os processos 'trabalhadores', o processo rank 0 escreve o resultado na saída informada. 

## Resultados:
- Para a coleta de resultados, executou-se nos seguites modos: </br>
  (a) Sequencial, sem nenhum tipo de paralelismo </br>
  (b) Com MPI, executando em Localhost </br>
  (c) Com MPI, executando no EC2 da Amazon </br> 

- Para os casos utilizando MPI o número de processos foi fixado em 3 (n = 3), utilizando 2 processos para realizar o processamento dos dados e 1 processo de pivo. Em todos os casos, o tempo executado é a média aritmética de 5 execuções. Para os resultados abaixo, desconsidera-se o tempo necessário para efetuar I/O.

##### Sequencia Vs MPI (EC2)
- A versão distribuída, executando sobre instâncias de EC2 (cluster Amazon), não conseguiu obter ganhos de desempenho quando comparada com sua versão sequencia nos experimentos realizados. O tempo gasto durante a comunicação entre as instâncias (uma vez que a mesma é realizada sobre uma rede, "custando caro"), pode ter sido um fator determinante para não ganhar desempenho. </br>

<img src="http://i.imgur.com/tJqoh7I.png" width="400px" heigth="400px" /> </br>

- Tabela ilustrando os tempos de execuções médios: </br>

<img src="http://i.imgur.com/PRcisXg.png" width="500px" heigth="200px" /> </br>

##### Sequencial Vs MPI (localhost)
- Em seguida, comparou-se a versão sequencial com a versão distribuída novamente, mas executando em localhost. Durante este experimento, conseguiu-se obter desempenho, isto é, o tempo de execução da aplicação diminuiu. Executando em localhost, o tempo gasto em comunicação é bastante reduzido, uma vez que não há necessidade de utilizar a rede.<br>

<img src="http://i.imgur.com/tvH0SMq.png" width="400px" heigth="400px" /> </br>

- Nese caso, obteu-se um SpeedUp de até 1.206, conforme ilustra o gráfico abaixo. </br>

<img src="http://i.imgur.com/AYLysrS.png" width="400px" heigth="400px" /> </br>

- Tabela ilustrando os tempos de execuções médios: </br>

<img src="http://i.imgur.com/YRNYouI.png" width="500px" heigth="200px" /> </br>

#### Sequencial Vs MPI (EC2) Vs MPI (localhost)
- Comparando as 3 versões, lada a lado, fica evidente que a versão MPI executando em localhost conseguiu obter o melhor resultado nos testes. Em seguida, a versão sequencial e por último, a versão executando sobre as instâncias EC2 da Amazon. 

<img src="http://i.imgur.com/JCrvqjN.png" width="400px" heigth="400px" /> </br>

- Tabela ilustrando os tempos de execuções médios: </br>

<img src="http://i.imgur.com/xRoCbwK.png" width="500px" heigth="200px" /> </br>
