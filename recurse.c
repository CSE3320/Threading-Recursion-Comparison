#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

struct timeval begin;
struct timeval end;

float f(float start, int n);

int main( int argc, char * argv[] )
{
  gettimeofday( &begin, NULL );

  float input = atof( argv[1] );
   
  f(input, 10000);

  gettimeofday( &end, NULL );

  long long duration = ( end.tv_sec * 1000000 + end.tv_usec ) - 
                       ( begin.tv_sec * 1000000 + begin.tv_usec );

  printf("Duration: %ld microseconds\n", duration );

  return 0;
}

float f(float start, int n)
{
  float out = 0;
  if (n != 0)
  {
    out = f(start, n-1) * 1.0001 + 3;
    printf("f(%d) = %f\n", n, out);
    return out;
  }
 
  else
  {
    printf("f(%d) = %f\n", n, start);
    return start;
  }
}

