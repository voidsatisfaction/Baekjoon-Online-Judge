#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// #define MAX 2000000002
// #define INDEXIZE 1000000001

int N,K,t;

int main()
{
  scanf("%d %d",&N,&K);

  vector<int> nums(N);
  
  for(int i=0; i < N; i++)
  {
    scanf("%d",&nums[i]);
  }

  nth_element(nums.begin(),nums.begin()+K-1,nums.end());
  printf("%d\n",nums[K-1]);
  return 0;
}