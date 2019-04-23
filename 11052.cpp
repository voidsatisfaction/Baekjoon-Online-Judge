#include <cstdio>
#include <algorithm>

#define MAX_N 1001

using namespace std;

int values[MAX_N], dp[MAX_N];
int N, num;

int main()
{
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &values[i]);
    dp[i] = values[i];
  }

  for (int i = 1; i < N; i++) {
    for (int j = 1; j < N; j++) {
      if (i+j > N) {
        break;
      }
      dp[i+j] = max(dp[i+j], dp[i] + values[j]);
    }
  }

  printf("%d\n", dp[N]);
  return 0;
}
