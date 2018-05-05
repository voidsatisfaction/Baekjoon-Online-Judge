#include <cstdio>
#include <cstring>

#define MAX_K 501
#define INF 1987654321

int T, K, num, ans, sizeSum[MAX_K], size[MAX_K], dp[MAX_K][MAX_K];

int getSegmentSizeSum(int left, int right)
{
  return sizeSum[right] - sizeSum[left-1];
}

int getMinSize(int left, int right)
{
  if(dp[left][right] != INF)
    return dp[left][right];
  
  if(left == right) {
    return size[left];
  } else if(right - left == 1) {
    dp[left][right] = size[left] + size[right];
    return dp[left][right];
  }
  for(int mid=left; mid<right; mid++) {
    int ret;
    if(mid == left) {
      ret = getMinSize(left, mid) + getMinSize(mid+1, right) + getSegmentSizeSum(mid+1, right);
    } else if(mid == right-1) {
      ret = getMinSize(left, mid) + getMinSize(mid+1, right) + getSegmentSizeSum(left, mid);
    } else {
      ret = getMinSize(left, mid) + getMinSize(mid + 1, right) + getSegmentSizeSum(left, mid) + getSegmentSizeSum(mid+1, right);
    }

    if(ret < dp[left][right])
      dp[left][right] = ret;
  }
  return dp[left][right];
}

int main()
{
  scanf("%d", &T);
  while(T--)
  {
    memset(size, 0, sizeof(size));
    for(int i=1; i<MAX_K; i++)
      for(int j=1; j<MAX_K; j++)
        dp[i][j] = INF;

    scanf("%d", &K);
    for(int i=1; i<=K; i++) {
      scanf("%d", &size[i]);
      sizeSum[i] = sizeSum[i-1] + size[i];
    }

    ans = getMinSize(1, K);
    printf("%d\n", ans);
  }
  return 0;
}