#include <cstdio>

typedef long long ll;

#define MAX_M 1001
#define MAX_N 1000001

ll N, M, a[MAX_N], sum_cache[MAX_M], ans;

int main()
{
  scanf("%lld %lld", &N, &M);
  for (int i = 0; i < N; i++)
    scanf("%lld", &a[i]);
  
  ll sum = 0;
  for (int i = 0; i < N; i++)
  {
    sum += (a[i] % M);
    sum %= M;
    sum_cache[sum]++;
  }

  ans = sum_cache[0];
  for (int i = 0; i < M; i++)
  {
    ll s = sum_cache[i];
    ans += ((s * (s - 1)) / 2);
  }

  printf("%lld\n", ans);
  return 0;
}