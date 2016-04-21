#include <iostream>
#include <cstdlib>
#include <time.h>
#include <sys/time.h>
#include <omp.h>
#include "Graph.h"

/**
 Algoritmo de Floyd para encontrar o caminho mínimo    
 entre todos os pares de vértices de um grafo.
 */
class Floyd
{
   public:
      /**
        Aplica o algoritmo de Floyd a um grafo g, produzindo um grafo s.
        Os grafos g e s são grafos orientados, acíclicos e ponderados.
        @param[out]  s   Grafo resultante.
        @param[in]   g   Grafo de origem.
        */  
       void calculate(Graph& s, const Graph& g);
     
};

void
Floyd::calculate(Graph& s, const Graph& g)
{
   int n;
   int w;
   int i;
   int j;
   int k;
   
   s = g;
   n = s.size();
   
   for (k = 0; k < n; k++)
   {
      #pragma omp parallel for private(i, j, w)
      for (i = 0; i < n; i++)
      {
         for (j = 0; j < n; j++)
         {
            if ((i != j) && s.hasEdge(i,k) && s.hasEdge(k,j))
            {
               w = s.getWeight(i,k) + s.getWeight(k,j);
               
               if (!s.hasEdge(i,j))
                  s.insertEdge(i,j,w);
               else if (w < s.getWeight(i,j))
                  s.setWeight(i,j,w);
            }
         }
      }
   }  

}

long wtime(){
   struct timeval t;
   gettimeofday(&t, NULL);
   return t.tv_sec*1000000 + t.tv_usec;
}

int main(int argc, char** argv)
{
   const int MaxWeight = 10;
   const int Density = 30;
   long start;
   long end;
   
   if (argc != 2)
   {
      std::cout << "Uso: " << argv[0] << " <tamanho do grafo>" << std::endl;
      return 1;
   }
   
   int size = atoi(argv[1]);
   
   if (size <= 0)
   {
      std::cout << "Erro: tamanho do grafo deve ser maior que zero" << std::endl;
      return 1;
   }
   
   try {   
      Graph ig;
      ig.generate(size, Density, MaxWeight); 
            
      Graph og;
      Floyd f;
      start = wtime();
      f.calculate(og, ig);
      end = wtime();

      std::cout << og << std::endl;
      std::cout << "Tempo de execucao paralelo: " << end - start << std::endl;
      // Alternativamente:
      // std::cout << DotGraphEncoder(og) << std::endl;
      // ou
      // og.writeTo("saida");         
   }
   catch (std::bad_alloc)
   {  
      std::cerr << "Erro: impossivel alocar memoria" << std::endl;
      return 1;
   }
   
   return 0;
}


