#include <cstdio>

#define MOD 1000000007

typedef long long ll;

int N, K;
ll dp[11][100001], sum[11];

int main()
{
  scanf("%d %d", &N, &K);
  for (int i = 1; i <= K; i++)
    dp[1][i] = 1;
  
  sum[1] = K;

  for (int i = 2; i <= N; i++)
  {
    for (int j = 1; j <= K; j++)
    {
      ll temp = 0;
      for (int k = j+j; k <= K; k += j)
        temp += dp[i-1][k];
      if (sum[i-1] - temp < 0){
        dp[i][j] = (sum[i-1] - temp + MOD) % MOD;
      } else {
        dp[i][j] = (sum[i-1] - temp) % MOD;
      }
      sum[i] = (sum[i] + dp[i][j]) % MOD;
    }
  }

  printf("%lld\n", sum[N]);
  return 0;
}