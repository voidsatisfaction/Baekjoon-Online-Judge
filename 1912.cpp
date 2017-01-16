#include <cstdio>

int n, max, sequalSum;
int nums[100000];

int largest(int nums[])
{
  int start = -1;
  max = -1000;
  for(int i=0; i < n; i++)
  {
    if(nums[i] > 0){
      start = i;
      break;
    }
    if(nums[i] > max){
      max = nums[i]; 
    }
  }
  if(start == -1){ return max; }
  sequalSum = nums[start];
  max = nums[start];
  for(int i=(start + 1); i < n ; i++)
  {
    sequalSum += nums[i];
    if(nums[i] < 0 && sequalSum >= 0){
      continue;
    } else if(sequalSum < 0){
      sequalSum = 0;
    } else if (nums[i] >= 0 && sequalSum >= max){
      max = sequalSum;
    } else {
      continue;
    }
  }
  return max;
}

int main()
{
  scanf("%d",&n);
  for(int i=0; i < n; i++)
    scanf(" %d",&nums[i]);
  
  printf("%d",largest(nums));
  return 0;
}

10
10 -4 3 1 5 6 -35 12 21 -1