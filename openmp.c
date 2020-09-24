# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <omp.h>

int main ( );
int *prime_table ( int prime_num );

const int N = 10000000;
const int RangeSize = 1000;

int main ( )
{
  int prime_num;
  int *primes;
  int threads = omp_get_num_threads();
  int index[N/RangeSize+1];
  int i,j,t;
  double start;
  double end;
  start = omp_get_wtime();
  #pragma omp parallel for schedule(dynamic)
  for(i = 0; i < N/RangeSize; i++){
    index[i] = i * RangeSize;
  }
  #pragma omp parallel for schedule(dynamic)
  for(j = 0; j < N/RangeSize;j++){
    omp_set_num_threads(threads);
  }
  int result[N/RangeSize-1];
  #pragma omp parallel for schedule(dynamic)
  for (t = 0; t < N/RangeSize; t++) {
      primes = prime_table(prime_num);

    }

  printf ( "\n" );

  printf ("Calculating...\n" );
  printf ("It could take a while...\n" );
  prime_num = 10000;

# pragma omp parallel shared (prime_num, primes)
{
  # pragma omp sections
  {
    # pragma omp section
    {
      primes = prime_table ( prime_num );
    }
  }
}
end = omp_get_wtime();

  printf ("OpenMP ( 8 Threads)\n");
  printf("Work took %f seconds\n", end - start);
  printf ("Sum=  %d\n",(int) primes);

  free ( primes );
  return 0;
}
int *prime_table ( int prime_num )
{
  int i;
  int j;
  int p;
  int prime;
  int *primes;

  primes = ( int * ) malloc ( prime_num * sizeof ( int ) );

  i = 2;
  p = 0;

  while ( p < prime_num )
  {
    prime = 1;

    for ( j = 2; j < i; j++ )
    {
      if ( ( i % j ) == 0 )
      {
        prime = 0;
        break;
      }
    }

    if ( prime )
    {
      primes[p] = i;
      p = p + 1;
    }
    i = i + 1;
  }

  return primes;
}
