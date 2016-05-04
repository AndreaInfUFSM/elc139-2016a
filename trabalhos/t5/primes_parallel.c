#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int prime_v1(int n);
int prime_v2(int n);
int prime_v3(int n);

int main(int argc, char *argv[])
{
  int n;
  int primes, p2, p3;
  double time1;
  double time2;
  double time3;

  //n = 524288;
  n = 52428;
  printf("\n");
  printf("                                V1            V2            V3\n");
  printf("         N     Pi(N)          Time          Time          Time\n");
  printf("\n");


  time1 = omp_get_wtime();
  p2 = prime_v1(n);
  time1 = omp_get_wtime() - time1;

  time2 = omp_get_wtime();
  p3 = prime_v2(n);
  time2 = omp_get_wtime() - time2;
  
  time3 = omp_get_wtime();
  primes = prime_v3(n);
  time3 = omp_get_wtime() - time3;
  
  printf ("  %8d  %8d  %12f  %12f  %12f\n", n, primes, time1, time2, time3);
  
  return 0;
}

/******************************************************************************/
int prime_v1(int n)
/******************************************************************************/
{
  int i;
  int j;
  int prime;
  int total = 0;

  #pragma omp parallel for private(i, j, prime) shared(total)
  for (i = 2; i <= n; i++)
  {
    prime = 1;
    for (j = 2; j < i; j++)
    {
      if (i % j == 0)
      {
        prime = 0;
        break;
      }
    }
    #pragma omp atomic
    total = total + prime;
  }
  return total;
}

/******************************************************************************/
int prime_v2(int n)
/******************************************************************************/
{
  int i;
  int j;
  int prime = 1;
  int total = 0;

  for (i = 2; i <= n; i++)
  {
    #pragma omp parallel for private(j, prime) shared(total)
    for (j = 2; j < i; j++)
    {
      if (i % j == 0)
      {
        prime = 0;
      }
    }
    #pragma omp atomic
    total = total + prime;
    prime = 1;
  }
  return total;
}

/******************************************************************************/
int prime_v3(int n)
/******************************************************************************/
{
  int i;
  int j;
  int prime = 1;
  int total = 0;

  #pragma omp parallel
  {
    #pragma omp single
    {
      for(i = 2; i <= n; i++)
      {
        #pragma omp task firstprivate(i) private(j, prime) shared(total)
        {  
          prime = 1;
          for (j = 2; j < i; j++)
          {
            if (i % j == 0)
            {
              prime = 0;
            }
          }
          #pragma omp atomic
          total = total + prime;
        }
      }
    }
    #pragma omp taskwait
  }
  return total;
}


