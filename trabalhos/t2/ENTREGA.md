[Programação Paralela - ELC 139](https://github.com/AndreaInfUFSM/elc139-2016a)

## T2: Experiências com Profilers

##### Nome: Maurício Matter Donato
##### Matrícula: 201410128

## Parte 1:
- (a) Foram testados 3 casos para a execução, conforme ilustra a tabela a seguir: 
        <TABLE>
          <TR>
            <TD>Tamanho dos Vetores</TD>
            <TD>Repetições</TD>
          </TR>
          <TR>
            <TD>3.000</TD>
            <TD>10</TD>
          </TR>
          <TR>
            <TD>300.000</TD>
            <TD>10</TD>
          </TR>
          <TR>
            <TD>30.000.000</TD>
            <TD>10</TD>
          </TR>
        </TABLE>
  
  Durante os teste com as entradas avaliadas, em todos os casos ocorreram uma chamada de função para inicialização do vetor; uma chamada de função para realização do cálculo do prouto escalar; duas chamadas de função para o cálculo estimado do tempo gasto durante a execução da aplicação. A diferença entre as execuções ficou a cargo dass variações no tempo de execução de cada chamada de função, como demonstram as imagens abaixo. 

- Tamanho = 3.000 </br>
<img src="http://i.imgur.com/0dz26B0.png" width="300px" heigth="400px" />

</br>
- Tamanho = 300.000 </br>
<img src="http://i.imgur.com/gB8NPJz.png" width="300px" heigth="400px" />

</br>
- Tamanho = 30.000.000 </br>
<img src="http://i.imgur.com/hJISo53.png" width="300px" heigth="400px" />
  
- (b) Pelo perfil de execução gerado, a função que realiza o cálculo do produto escalar (dot_product) sugere ser uma boa opção de paralelização, umas vez que esta função consome a maior parte do tempo total de execução do programa. Durante o teste com array de tamanho 30.000.000, observou-se que tal função chegou a utilizar mais de 85% do tempo de execução total.
  
  
## Parte 2

#### 1º profiler escolhido: Apple Instruments </br>
- (a) Conjunto de ferramentos incluso no Ambiente de Desenvolvimento Integrado (IDE) fornecido gratuitamente pela Apple, o xCode. Apresenta diversos templates para análise dos mais variados aspectos do programa, como por exemplo estimativa de uso energético da aplicação, monitoramento das atividades, tempo e execução, dentre outras coisas. Em relação a instalação, bastar fazer o download da IDE diretamente da Store, que todas ferramentas estarão inclusas. </br>

Templates disponíveis </br>
<img src="http://i.imgur.com/DINw8gW.png" width="300px" heigth="400px" />

- (b) Para o teste de 'time profiler', utilizou-se a aplicação dotProduct_seq com tamanho do array setado em 300000000 com 20 repetições. O profiler demonstra a utilização de CPU durante a execução, bem como o tempo de execução de cada função e sua porcentagem de tempo em relação ao total.</br>
<img src="http://i.imgur.com/EhzFOhN.png" width="300px" heigth="400px" /> </br>

- (c) Apesar de apresentar uma interface relativamente "clear", foi necessário pesquisar o que cada informação demonstrada representa.


#### 2º profiler escolhido: JProfiler </br>
- (a) Jprofiler da ej-Technologies apresenta uma instalação fácil, sendo que no meu caso, baixei uma imagem DMG e segui uma espécie de instalador deles. O software funciona em forma de avaliação por 10 dias. A aplicação apresenta uma visão sobre memória, CPU, Threads e afins durante a execução. Há várias formas de "buscar" a aplicação que deseja fazer profiler. Permite também que seja configurado a forma que será feito. </br>

- (b) Durante os tester, utilizou-se uma implementação do dotProduct_seq em Java, com o acrescimento de um loop, para garantir que "houvesse tempo" do JProfiler se conectar a aplicação. O tamanho do array foi setado em torno dos 7.000.000 com 20 repetições. Abaixo, uma imagem exemplificando a execução do profiler. </b> 
<img src="http://i.imgur.com/7AM6fmg.png" width="300px" heigth="400px" /> </br>

- (c) Das ferramentas testas por mim, com certeza a JProfiler foi a mais complicada de ser usada. Foi necessário passar um bom tempinho "fuçando" no programa, bem como lendo tutoriais na internet. Não achei muito intuitivo a utilização e demora até entender a quantidade de informação apresentada. 
