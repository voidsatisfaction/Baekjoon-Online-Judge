#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 100001

using namespace std;

vector<int> seq;
int N, a, dp[MAX_N][5][5];

int getStrength(int curPlace, int nextPlace)
{
  if(curPlace == 0)
    return 2;
  if(curPlace == 1 || curPlace == 3) {
    if(nextPlace == 2 || nextPlace == 4) {
      return 3;
    }
    return 4;
  }

  if(nextPlace == 1 || nextPlace == 3) {
    return 3;
  }
  return 4;
}

int minStrength(int n, int left, int right)
{
  if(seq[n] == 0)
    return 0;

  int& ret = dp[n][left][right];
  if(ret > 0)
    return ret;

  if(left == seq[n] || right == seq[n]) {
    ret = minStrength(n+1, left, right) + 1;
  } else if(left == 0 && right == 0) {
    ret = minStrength(n+1, seq[n], right) + 2;
  } else {
    ret = min(
      minStrength(n+1, left, seq[n]) + getStrength(right, seq[n]),
      minStrength(n+1, seq[n], right) + getStrength(left, seq[n])
    );
  }
  return ret;
}

int main()
{
  while(1)
  {
    scanf("%d", &a);
    seq.push_back(a);
    if(a == 0)
      break;
  }

  int ans = minStrength(0, 0, 0);
  printf("%d\n", ans);

  return 0;
}