#include <cstdio>
#include <algorithm>

#define MAX_N 16
#define MAX_tsp 987654321 // 여기가 INT_MAX이면 26번째 줄에서 오류가 날 수 있다.

int N, w[MAX_N][MAX_N], cache[MAX_N][1 << MAX_N];

int tsp(int cur, int visited)
{
  if (visited == (1 << N) - 1)
    return w[cur][0];
  
  int& result = cache[cur][visited];
  if (result != 0)
    return result;

  result = MAX_tsp;
  for (int next = 0; next < N; next++)
  {
    if (visited&(1 << next))
      continue;
    if (w[cur][next] == 0)
      continue;
    
    result = std::min(result, tsp(next, visited | (1 << next)) + w[cur][next]);
  }
  return result;
}

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      scanf("%d", &w[i][j]);

  printf("%d\n", tsp(0, 1));
  return 0;
}