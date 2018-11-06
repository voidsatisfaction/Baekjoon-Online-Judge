#include <cstdio>

typedef long long ll;

ll dp[101][21], ans;
int N, nums[101];

int main()
{
  scanf("%d", &N);
  for(int i = 1; i <= N; i++)
    scanf("%d", &nums[i]);
  
  int firstNum = nums[1];
  int lastNum = nums[N];
  dp[1][firstNum] = 1;
  
  for(int i = 2; i < N; i++) {
    for(int j = 0; j <= 20; j++) {
      if (dp[i-1][j] > 0) {
        int targetNum = nums[i];
        if (j + targetNum <= 20) {
          dp[i][j + targetNum] += dp[i-1][j];
        }
        if (j - targetNum >= 0) {
          dp[i][j - targetNum] += dp[i-1][j];
        }
      }
    }
  }
  
  printf("%lld\n", dp[N-1][lastNum]);

  return 0;
}