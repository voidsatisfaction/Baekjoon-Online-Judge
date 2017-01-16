#include <cstdio>

#define MAX 10001

int nums[MAX];
int N,t;

int main()
{
  scanf("%d",&N);
  for(int i=0; i < N; i++)
  {
    scanf("%d",&t);
    nums[t] += 1;
  }
  for(int i=1; i < MAX ; i++)
    for(int j=0; j < nums[i]; j++)
      printf("%d\n",i);
  
  return 0;
}