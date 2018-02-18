#include <cstdio>
#include <algorithm>

#define MAX_N 17
#define INF 1987654321

int W[MAX_N][MAX_N], dp[1<<MAX_N][MAX_N];
int N, ans;

int dfs(int marked, int v)
{
  marked = marked | (1 << (v-1));
  if (dp[marked][v] > 0)
    return dp[marked][v];

  int& DP = dp[marked][v];
  if (marked == (1 << N) - 1) {
    if (W[v][1]){
      return DP = W[v][1];
    }
    return DP = INF;
  }

  DP = INF;
  for (int i = 1; i <= N; i++)
  {
    if (!W[v][i] || (marked & (1 << (i-1))))
      continue;
    DP = std::min(DP, dfs(marked, i) + W[v][i]);
  }
  return DP;
}

int main()
{
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      scanf("%d", &W[i][j]);
  
  ans = dfs(0, 1);
  printf("%d\n", ans);
  return 0;
}