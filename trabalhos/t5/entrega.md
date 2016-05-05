[Programação Paralela - ELC 139](https://github.com/AndreaInfUFSM/elc139-2016a)

## T5: Mistério dos primos em OpenMP

##### Nome: Maurício Matter Donato - Matrícula: 201410128
##### Nome: Pedro Langbecker Lima  - Matrícula: 201410955

## Versões desenvolvidas:
- 1º versão: Como primeira abordagem, optou-se por paralelizar o lanço mais externo utilizando o pragma `parallel for`, 
mantendo as variáveis de controle do laço (`i` e `j`) além da variável `prime` como privadas para cada thread; a variável
total definida como shared, de forma que seja possível fazer a acumulação dos resultados entre todas as threads em 
execução. Utilizou-se a diretiva `omp atomic` para evitar condições de corrida sobre a variável total. </br>

<img src="http://i.imgur.com/y9sBWmU.png" width="400px" heigth="400px" /> </br>

- 2º versão. Numa segunda versão, partiu-se para a paralelização apenas do laço interno, também utilizando o pragma
`parallel for`. Nessa implementação, manteve-se a variável `i` como shared, de modo que todas as threads possam acessar
seu valor para efetuar o teste, e a variável `j` privada (variável de controle do laço). Para garantir que `prime` fosse
sempre inicializado com o valor 1, em cada thread, utilizou-se a diretiva `reduction(&& : prime)`.</br>

<img src="http://i.imgur.com/c0oW4vy.png" width="400px" heigth="400px" /> </br>

- 3º versão: Nessa última versão, optou-se por distribuir a carga do laço interno através da diretiva `task`. Assim como nas
versões anteriores, utilizou-se as diretivas `private(j, prime)` para tornas as respectivas variáveis privadas para cada thread. A variável total é compartilhada entre as threads e, para evitar condições de corrida, utilizou-se a diretiva 
`pragma omp atomic`.  </br>

<img src="http://i.imgur.com/tC2Ffna.png" width="400px" heigth="400px" /> </br>

## Resultados:
- As versões desenvolvidas foram testadas com diferentes entradas e número de threads. Para este experimento, adoutou-se
entradas com tamanhos iguais a 150.000, 200.000 e 250.000. O número de threads variou entre 1 (simular sequêncial) até 4 threads executando em paralelo. Em todos os casos, o resultado obtido (em segundos) é a média aritmética de 5 execuções. </br>

- As tabelas a seguir, demonstram os tempos de execuções, o speedup e a eficiência obtido no experimento. Destaca-se aqui, 
a 1º versão paralela, onde obteve os melhores resultado se comparada com as demais:
<img src="http://i.imgur.com/kOpfUHA.png" width="400px" heigth="400px" /> </br>
<img src="http://i.imgur.com/IfmvCCw.png" width="400px" heigth="400px" /> </br>
<img src="http://i.imgur.com/lECSWGJ.png" width="400px" heigth="400px" /> </br>

- Em relação ao `speedup`, em todos os casos testados obteu-se ganho de desempenho se comparado a sua respectiva versão
sequencial. No pior caso o speedup foi de 1,23 (2 threads, N = 200.000 para a paralela_v1), mas podende chegar até 2,36
no experimento envolvendo 4 threads, N = 250.000 na versão paralela_v3. </br>
<img src="http://i.imgur.com/BXyCXfd.png" width="400px" heigth="400px" /> </br>
<img src="http://i.imgur.com/oiazCqh.png" width="400px" heigth="400px" /> </br>
<img src="http://i.imgur.com/9z8VLDh.png" width="400px" heigth="400px" /> </br>

- O crescimento do speedup não acompanha de forma proporcial o aumento no número threads em execução, fazendo com que a
eficiência caia. Durante os testes, obteu-se pior eficiência utilizando a configuração de 4 threads e N = 200.000 para a versão paralela_v1, com 0,3714. Por outro lado, a execução mais eficiente ficou a cargo da versão paralela_v2, com 1,0025, utilizando a configuração com 2 threads e N = 250.000
