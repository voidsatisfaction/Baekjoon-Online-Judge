#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_N 1001

using namespace std;

int T, N, left, right, card[MAX_N], dp[MAX_N][MAX_N];

int getMaxScore(bool turn, int left, int right)
{
  if(left == right) {
    if (!turn)
      return card[left];
    return 0;
  }

  if(dp[left][right] > 0)
    return dp[left][right];

  if(!turn) {
    // kunwoo
    dp[left][right] = max(
      getMaxScore(turn^1, left+1, right) + card[left],
      getMaxScore(turn^1, left, right-1) + card[right]
    );
  } else {
    // myungwoo
    dp[left][right] = min(
      getMaxScore(turn^1, left+1, right),
      getMaxScore(turn^1, left, right-1)
    );
  }
  
  return dp[left][right];
}

int main()
{
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d", &N);
    memset(card, 0, sizeof(card));
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<N; i++)
      scanf("%d", &card[i]);
    
    left = 0;
    right = N-1;
    printf("%d\n", getMaxScore(0, left, right));
  }
  return 0;
}