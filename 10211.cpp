#include <cstdio>

#define INF 1987654321

int T, N, sum, ans, a;

int main()
{
  scanf("%d", &T);
  while (T--)
  {
    sum = 0;
    ans = -INF;
    scanf("%d", &N);
    for(int i=0; i < N; i++) {
      scanf("%d", &a);
      sum += a;
      if (sum > ans)
        ans = sum;
      if (sum < 0)
        sum = 0;
    }
    printf("%d\n", ans);
  }
  return 0;
}