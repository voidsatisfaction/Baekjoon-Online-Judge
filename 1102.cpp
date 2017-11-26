#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_N 16
#define INF 987654321

int N, cost[MAX_N][MAX_N], cache[MAX_N][1 << MAX_N];
int visited, visitedNum, P;

int getMinCost(int visitedNum, int visited)
{
  // 처음부터 Y의 개수가 P보다 많을 수 있음
  // 그래서 visitedNum >= P
  if (visitedNum >= P){
    return 0;
  }

  int& result = cache[visitedNum][visited];
  if (result != -1){
    return result;
  }

  // 기본적으로 전탐색
  result = INF;
  for (int i = 0; i < N; i++)
  {
    if ((visited & (1 << i)) == 0) continue;
    int cur = i;
    for (int j = 0; j < N; j++)
    {
      // i == j는 탐색하지 말아야 한다.
      if (i == j || (visited & (1 << j))) continue;
      int next = j;
      // 지금 상태에서 minCost = min(지금 상태minCost, 다음 상태 minCost)
      // 이를 현상태에서 변화할 수 있는 모든 경우의 수로 구함
      result = std::min(
        result,
        getMinCost(visitedNum + 1, (visited | (1 << next))) + cost[cur][next]
      );
    }
  }
  return result;
}

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      scanf("%d", &cost[i][j]);

  for (int i = 0; i < N; i++)
  {
    char c;
    scanf("\n%c", &c);
    if (c == 'Y'){
      visited |= 1 << i;
      visitedNum++;
    }
  }

  std::memset(cache, -1, sizeof(cache));

  scanf("%d", &P);

  int minCost = getMinCost(visitedNum, visited);
  if (minCost == INF){
    printf("%d\n", -1);
  } else {
    printf("%d\n", minCost);
  }

  return 0;
}