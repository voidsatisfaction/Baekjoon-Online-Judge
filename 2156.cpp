#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_N 10001
#define CONSEQUENT 3

using namespace std;

int n, p, dp[MAX_N][CONSEQUENT];

int getMax(int num) {
  return max(max(dp[num][0], dp[num][1]), dp[num][2]);
}

int main()
{
  scanf("%d", &n);
  memset(dp, 0, sizeof(dp));

  for(int i=1; i<=n; i++) {
    scanf("%d", &p);
    for(int j=0; j<CONSEQUENT; j++) {
      if(j == 0) {
        dp[i][j] = getMax(i-1);
      } else if(j == 1) {
        dp[i][j] = dp[i-1][0] + p;
      } else if (j == 2) {
        dp[i][j] = dp[i-1][1] + p;
      }
    }
  }

  printf("%d\n", getMax(n));

  return 0;
}