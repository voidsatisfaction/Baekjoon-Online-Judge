#include <cstdio>
#include <math.h>

typedef long long ll;

long double result;
ll X;
int N;

int main()
{ 
  scanf("%d",&N);
  for(int i=0; i < N; i++)
  {
    scanf(" %lld",&X);
    result = sqrt((long double)X);
    printf("%d ", (ceil(result) == floor(result)) ? 1 : 0);
  }
  return 0;
}