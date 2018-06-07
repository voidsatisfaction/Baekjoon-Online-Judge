#include <cstdio>

#define MAX_K 10001

typedef long long ll;

ll N, K, lenLines[MAX_K];

ll getLenLineNums(ll length)
{
  ll nums = 0;
  for(int i=0; i<K; i++) {
    nums += (lenLines[i] / length);
  }
  return nums;
}

ll findMaxLenLine()
{
  ll left = 1;
  ll right = (1 << 31) - 1;

  while (left <= right)
  {
    ll mid = (left + right) / 2;
    ll lenLineNums = getLenLineNums(mid);
    if (lenLineNums < N) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return right;
}

int main()
{
  scanf("%lld %lld", &K, &N);
  for(int i=0; i<K; i++)
    scanf("%lld", &lenLines[i]);

  ll ans = findMaxLenLine();

  printf("%lld\n", ans);
  return 0;
}