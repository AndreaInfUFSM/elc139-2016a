#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

long wtime(){
   struct timeval t;
   gettimeofday(&t, NULL);
   return t.tv_sec*1000000 + t.tv_usec;
}

int main(int argc, char *argv[]){
	int size;
	int repeat;
	int i;
	int j;
	double *a = NULL;
	double *b = NULL;
	double c;
	long start;
	long end;
	//double sum;

	// Dados da linha de comando
	if(argc != 3){
		printf("Execução: <tamanho do array> <repetições>\n");
		exit(-1);
	}

	size = atoi(argv[1]);
	repeat = atoi(argv[2]);

	a = (double *) malloc(size * sizeof(double));
	b = (double *) malloc(size * sizeof(double));

	// Preenche os arrays 
	for(i = 0; i < size; i++){
		a[i] = 0.01;
		b[i] = 1;
	}

	// Calcula C = a . b, marcando seu tempo de execução
	start = wtime();
	for(j = 0; j < repeat; j++){
		c = 0.0;
		#pragma omp parallel for shared(a, b) private(i) reduction(+:c)
		for(i = 0; i < size; i++){
			c += (a[i] * b[i]);
		}
	}
	end = wtime();

	// Exibe o tempo de execução e o resultado
	printf("%lf usec \n", c);
	printf("Tempo: %ld\n", end - start);

  return 0;
}

