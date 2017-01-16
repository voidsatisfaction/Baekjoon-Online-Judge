#include <cstdio>
#include <algorithm>

using namespace std;

int dp[3];

int main()
{
  int N,r,g,b,r_min,g_min,b_min,ans;
  scanf("%d",&N);
  for(int i=0; i < N; i++)
  {
    scanf("%d %d %d",&r,&g,&b);
    r_min = r + min(dp[1],dp[2]);
    g_min = g + min(dp[0],dp[2]);
    b_min = b + min(dp[0],dp[1]);
    dp[0] = r_min;
    dp[1] = g_min;
    dp[2] = b_min;
  }
  ans = min(dp[0],min(dp[1],dp[2]));
  printf("%d\n",ans);
  return 0;
}