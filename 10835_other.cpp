#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 2000

int N;
int left[MAX], right[MAX];
int dp[MAX][MAX];

int solve(int i, int j)
{
  if(i == N || j == N)
    return 0;

  if(dp[i][j] != -1)
    return dp[i][j];

  if(left[i] > right[j]){
    dp[i][j] = solve(i, j+1) + right[j];
  } else {
    dp[i][j] = max(solve(i+1,j),solve(i+1,j+1));
  }

  return dp[i][j];
}

int main()
{
  scanf("%d", &N);
  for(int i=0; i < N; i++)
    scanf(" %d", &left[i]);
  for(int i=0; i < N; i++)
    scanf(" %d", &right[i]);
  
  for(int i=0; i < N; i++)
    for(int j=0; j < N; j++)
      dp[i][j] = -1;
  
  printf("%d\n",solve(0,0));
  return 0;
}