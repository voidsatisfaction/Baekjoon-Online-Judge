#include <cstdio>

typedef long long ll;

ll N, k;

ll llMin(ll a, ll b)
{
  return a < b ? a : b;
}

int main()
{
  scanf("%lld", &N);
  scanf("%lld", &k);
  ll left = 1, right = N * N;
  ll ans;
  while(left <= right)
  {
    ll mid = (left + right) / 2;
    ll mk = 0;

    for (int i = 1; i <= N; i++)
      mk += llMin(mid / i, N);

    if(mk < k) {
      left = mid + 1;
    } else {
      right = mid - 1;
      ans = mid;
    }
  }

  printf("%lld\n", ans);
  
  return 0;
}