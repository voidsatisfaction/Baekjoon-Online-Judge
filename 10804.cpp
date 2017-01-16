#include <cstdio>

int a,b;
int nums[21];
int pibot;

void swap(int *a, int *b)
{
  *a = *b - *a;
  *b = *b - *a;
  *a = *a + *b;
}

void reverse(int nums[], int &a, int &b)
{
  if(a == b) {
    return;
  } else if(b-a == 1) {
    swap(&nums[a],&nums[b]);
  } else if((a+b) % 2 == 0) {
    pibot = (a+b)/2;
    for(int i=pibot+1; i < (b+1); i++)
      swap(&nums[2*pibot-i],&nums[i]);
  } else {
    pibot = (a+b)/2;
    for(int i=pibot+1; i < (b+1); i++)
      swap(&nums[2*pibot-i+1],&nums[i]);
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