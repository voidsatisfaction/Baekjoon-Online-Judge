#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
int low,high,counts,N,X,temp,sum;

int main()
{
  scanf("%d",&N);
  for(int i=0; i < N; i++)
  {
    scanf(" %d",&temp);
    nums.push_back(temp);
  }
  scanf("%d",&X);
  
  sort(nums.begin(),nums.end());

  high = nums.size() - 1;
  while(low < high)
  {
    sum = nums[low] + nums[high];
    if(sum == X){
      counts++;
      low++;
      high--;
    } else if(sum > X){
      high--;
    } else {
      low++;
    }
  }
  
  printf("%d\n",counts);
  return 0;
}