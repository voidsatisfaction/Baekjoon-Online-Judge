#include <cstdio>
#include <vector>

#define INF 987654321
#define MAX_K 10001

using namespace std;

vector<int> coins;
int n, k, dp[MAX_K];

int positiveMin(int a, int b)
{
  if (a < 0 && b < 0){
    return -1;
  } else if (b < 0) {
    return a;
  } else if (a < 0) {
    return b;
  } else {
    return min(a,b);
  }
}

int main()
{
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++)
  {
    int c;
    scanf("%d", &c);
    coins.push_back(c);
  }

  for (int i = 1; i <= k; i++)
    dp[i] = -1;

  for (int i = 1; i <= k; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int coin = coins[j];
      if (coin > i){
        continue;
      } else if (dp[i-coin] == -1){
        continue;
      } else {
        // dp[i] should be large number
        dp[i] = positiveMin(dp[i], dp[i-coin] + 1);
      }
    }
  }

  printf("%d\n", dp[k]);
  return 0;
}