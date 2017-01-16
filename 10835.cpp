#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 2001

int N;
int left[MAX], right[MAX];
int dp[MAX][MAX] = {0};

int main()
{
  scanf("%d", &N);
  for(int i=0; i < N; i++)
    scanf(" %d", &left[i])
    ;
  for(int i=0; i < N; i++)
    scanf(" %d", &right[i]);

  for(int i=0; i < N ; i++)
  {
    if(right[i] < left[0]) {
      dp[0][i+1] = dp[0][i] + right[i];
    } else {
      break;
    }
  }

  for(int l=1; l <= N ; l++)
  {
    for(int r=1; r <= N ; r++)
    {
      if(l == N && r == N){
        dp[l][r] = dp[l-1][r-1];
      } else if(r == N && right[r-1] < left[l]){
        dp[l][r] = dp[l][r-1] + right[r-1];
      } else if(r == N){
        dp[l][r] = dp[l-1][r-1];
      } else if(l == N){
        dp[l][r] = max(dp[l-1][r-1],dp[l-1][r]);
      } else if(right[r-1] < left[l]){
        dp[l][r] = max(dp[l][r-1]+right[r-1],dp[l-1][r]);
      } else {
        dp[l][r] = max(dp[l-1][r-1],dp[l-1][r]);
      }
    }
  }

  int max = 0;
  for(int l=0; l <= N ; l++)
  {
    if(dp[l][N] > max){
      max = dp[l][N];
    }
  }
  for(int r=0; r <= N; r++)
  {
    if(dp[N][r] > max){
      max = dp[N][r];
    }
  }
  
  printf("%d",max);
  return 0;
}

3
3 2 5
2 4 1

4
1 2 3 4
4 1 2 3

4
1 2 4 6
3 7 8 5