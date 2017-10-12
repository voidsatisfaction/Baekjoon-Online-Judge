#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> nums;

bool binarySearch(vector<int>* nums, int t)
{
  int left = 0;
  int right = (*nums).size() - 1;
  while(left <= right)
  {
    int mid = (left + right) / 2;
    
    if((*nums)[mid] == t)
      return true;

    if((*nums)[mid] > t) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return false;
}

int main()
{
  scanf("%d", &N);
  for(int i = 0; i < N; i++)
  {
    int t;
    scanf("%d", &t);
    nums.push_back(t);
  }

  sort(nums.begin(), nums.end());

  scanf("%d", &M);
  for(int i = 0; i < M; i++)
  {
    int t;
    scanf("%d", &t);
    if (binarySearch(&nums, t)){
      printf("%d\n", 1);
    } else {
      printf("%d\n", 0);
    }
  }

  return 0;
}