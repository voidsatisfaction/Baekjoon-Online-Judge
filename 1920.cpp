#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector<int> A;
// bool checker[100001]; 이거도

bool binary_search(int &m)
{
  int low = 0;
  int high = A.size() - 1;
  int target = (low + high) / 2;
  while(low <= high)
  {
    if(m == A[target])
    {
      // checker[m] = true;
      return true;
    }
    else if(m > A[target])
      low = target + 1;
    else
      high = target; // 이 부분 설명을 들어보자.

    target = (low + high) / 2;
    if(low == high && m != A[target])
      return false;
  }
}

int main()
{
  scanf("%d",&N);
  int temp;
  for(int i=0; i < N; i++)
  {
    scanf("%d",&temp);
    A.push_back(temp);
  }
  sort(A.begin(), A.end());
  scanf("%d",&M);
  int m;
  for(int i=0; i < M; i++)
  {
    scanf("%d",&m);
    if(binary_search(m))
      printf("%d\n",1);
    else
      printf("%d\n",0);
  }
  return 0;
}