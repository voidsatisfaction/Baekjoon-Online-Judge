#include <cstdio>

int a,b;
int nums[21];

void swap(int *a, int *b)
{
  *a = *b - *a;
  *b = *b - *a;
  *a = *a + *b;
}

void reverse(int nums[], int &a, int &b)
{
  while(b>a)
  {
    swap(&nums[a],&nums[b]);
    b--;
    a++;
  }
}

int main()
{
  for(int i=1; i < 21; i++)
    nums[i] = i;
  
  for(int i=0; i < 10; i++)
  {
    scanf("%d %d",&a,&b);
    reverse(nums,a,b);
  }

  for(int i=1; i < 21; i++)
    printf("%d ",nums[i]);
  return 0;
}