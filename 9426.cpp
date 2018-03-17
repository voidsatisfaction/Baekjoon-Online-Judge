#include <cstdio>

#define MAX_N 250001
#define MAX_TEMP_VAL 65536

typedef long long ll;

using namespace std;

ll N, K, a[MAX_N], seg[4 * MAX_TEMP_VAL], sum;

ll update(ll posVal, ll val, ll node, ll from, ll to)
{
  if (posVal > to || posVal < from)
    return seg[node];

  if (from == to)
    return seg[node] += val;
  
  ll mid = (from + to) / 2;

  return seg[node] = update(posVal, val, 2*node, from, mid) + update(posVal, val, 2*node+1, mid+1, to);
}

ll query(ll pos, ll node, ll from, ll to)
{
  if (from == to)
    return from;

  ll mid = (from + to) / 2;

  if (pos <= seg[2*node])
    return query(pos, 2*node, from, mid);
  else
    return query(pos - seg[2*node], 2*node+1, mid+1, to);
}

int main()
{
  scanf("%lld %lld", &N, &K);
  for(int i=0; i<N; i++)
    scanf("%lld", &a[i]);

  for(int i=0; i<K; i++)
    update(a[i], 1, 1, 0, MAX_TEMP_VAL);

  ll mid = (K+1)/2;
  for(int i=0; i<N-K+1; i++) {
    sum += query(mid, 1, 0, MAX_TEMP_VAL);
    if(i == N-K) break;
    update(a[i], -1, 1, 0, MAX_TEMP_VAL);
    update(a[i+K], 1, 1, 0, MAX_TEMP_VAL);
  }

  printf("%lld\n", sum);
  return 0;
}