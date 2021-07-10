[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2016a) > T1

TOP500 & me: Comparativo de Arquiteturas Paralelas
--------------------------------------------------

Nome: < Maurício M. Donato >

| Característica                                            | Computador no TOP500  | Meu computador  |
| --------------------------------------------------------- | --------------------- | --------------- |
<<<<<<< HEAD
| Nome/Título                                               |    TITAN - CRAY XK7   |     Mac Air     |
| Imagem (foto, diagrama, screenshot, etc.)                 | ![](https://www.olcf.ornl.gov/wp-content/gallery/titan/titan1.jpg) | ![](http://images.apple.com/br/macbook-air/images/overview_wireless_hero_enhanced.png)|
| Classificação de Flynn                                    |          4 modos, dependendo do contexto da execução             |        MIMD       |
| Memória: compartilhada, distribuída ou ambas?             |        Ambas          |  Compartilhada  |
| Número total de núcleos de processamento                  |       560,640         |        2        |
| Fabricante e modelo do(s) processador(es)                 |     Opteron 6274      |      Intel -  Core I5 4260U    |
| Frequência do(s) processador(es)                          |      2.200GHZ         |     1,40GHZ     |
| Memória total                                             |     710,144 GB        |     8,00 GB     |
| Tipo(s) de interconexão entre os núcleos/processadores    |        Gemini         |        -        |
| Desempenho Linpack                                        |     17,590 TFlop/s    |   ~ 62 GFlop/s  |
=======
| Nome/Título                                               |                       |                 |
| Imagem (foto, diagrama, screenshot, etc.)                 | Substitua-me. <img src="http://www.top500.org/static//images/Top500_logo.png" width="48"> | |
| Classificação de Flynn                                    |                       |                 |
| Memória: compartilhada, distribuída ou ambas?             |                       |                 |
| Número total de núcleos de processamento                  |                       |                 |
| Fabricante e modelo do(s) processador(es)                 |                       |                 |
| Frequência do(s) processador(es)                          |                       |                 |
| Memória total                                             |                       |                 |
| Tipo(s) de interconexão entre os núcleos/processadores    |                       |                 |
| Desempenho Linpack                                        |                       |                 |
>>>>>>> AndreaInfUFSM/master

### Referências
- Oak Ridge National Laboratory. Titan Cray XK7. https://www.olcf.ornl.gov/computing-resources/titan-cray-xk7/
- Intel. http://ark.intel.com/pt-br/products/75030/Intel-Core-i5-4260U-Processor-3M-Cache-up-to-2_70-GHz
- Sajjan G. Computer Organization, Design, and Architecture. https://books.google.com.br/books?id=ycrMBQAAQBAJ&pg=PA559&lpg=PA559&dq=TITAN+-+CRAY+XK7+flynn+classification&source=bl&ots=u2mwM_AmH5&sig=u2yh3DJjZ6ajkL-8cgrrxGsX8bc&hl=pt-BR&sa=X&ved=0ahUKEwis6M_1pcHLAhWDTJAKHbPWBuwQ6AEIHzAA#v=onepage&q=TITAN%20-%20CRAY%20XK7%20flynn%20classification&f=false.
- Fayez Gebali. Algorithms and Parallel Computing. https://books.google.com.br/books?id=3g6lrxrd4wsC&pg=PA54&lpg=PA54&dq=multicore+processor+flynn+classification&source=bl&ots=Ng3INXzwuR&sig=4bXG7TBKotKzu2oRnFqzMnBvepQ&hl=pt-BR&sa=X&ved=0ahUKEwjHxI-8qcHLAhVEk5AKHSBGCGQQ6AEIQjAF#v=onepage&q=multicore%20processor%20flynn%20classification&f=false


### Sobre o teste de desenho:
- Versão utilizada: Intel® Math Kernel Library, com Linpack 11.3.2
- Número de equações: 8.000
- Tamanho do array: 8.000
- Data alignment value: 64 Kb
- Tentativas: 5