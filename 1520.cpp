#include <cstdio>
#include <vector>

#define MAX_M_N 501

using namespace std;

vector<int> stack;
int M, N, map[MAX_M_N][MAX_M_N], dp[MAX_M_N][MAX_M_N];
bool visited[MAX_M_N][MAX_M_N];

int dfs(int m, int n, bool visited[MAX_M_N][MAX_M_N], int lastNum)
{
  if (m > M || m < 1 || n > N || n < 1){
    return 0;
  }

  if (m == M && n == N){
    return 1;
  } else if (map[m][n] >= lastNum){
    return 0;
  } else if (dp[m][n] >= 0){
    return dp[m][n];
  } else {
    visited[m][n] = true;
    dp[m][n] = dfs(m-1, n, visited, map[m][n])
    + dfs(m+1, n, visited, map[m][n])
    + dfs(m, n-1, visited, map[m][n])
    + dfs(m, n+1, visited, map[m][n]);

    return dp[m][n];
  }
}

int main()
{
  scanf("%d %d", &M, &N);
  for (int i = 1; i <= M; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      scanf("%d", &map[i][j]);
      dp[i][j] = -1;
    }
  }

  dfs(1, 1, visited, 100000);

  printf("%d\n", dp[1][1]);
  
  return 0;
}