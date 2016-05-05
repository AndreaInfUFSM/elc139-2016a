[Programação Paralela - ELC 139](https://github.com/AndreaInfUFSM/elc139-2016a)

## T5: Mistério dos primos em OpenMP

##### Nome: Maurício Matter Donato - Matrícula: 201410128
##### Nome: Pedro Langbecker Lima  - Matrícula:201410955

## Versões desenvolvidas:
- 1º versão: Como primeira abordagem, optou-se por paralelizar o lanço mais externo utilizando o pragma `parallel for`, 
mantendo as variáveis de controle do laço (`i` e `j`) além da variável `prime` como privadas para cada thread; a variável
total definida como shared, de forma que seja possível fazer a acumulação dos resultados entre todas as threads em 
execução. Utilizou-se a diretiva `omp atomic` para evitar condições de corrida sobre a variável total. </br>

<img src=" " width="" heigth="" /> </br>

- 2º versão. Numa segunda versão, partiu-se para a paralelização apenas do laço interno, também utilizando o pragma
`parallel for`. Nessa implementação, manteve-se a variável `i` como shared, de modo que todas as threads possam acessar
seu valor para efetuar o teste, e a variável `j` privada (variável de controle do laço). Para garantir que `prime` fosse
sempre inicializado com o valor 1, em cada thread, utilizou-se a diretiva `reduction(&& : prime)`.</br>

<img src=" " width="" heigth="" /> </br>

- 3º versão: Nessa última versão, optou-se por distribuir a carga do laço interno através da diretiva `task`. Assim como nas
versões anteriores, utilizou-se as diretivas `private(j, prime)` para tornas as respectivas variáveis privadas para cada thread. A variável total é compartilhada entre as threads e, para evitar condições de corrida, utilizou-se a diretiva 
`pragma omp atomic`.  </br>

<img src=" " width="" heigth="" /> </br>
