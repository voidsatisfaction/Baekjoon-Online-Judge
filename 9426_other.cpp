#include <iostream>
#include <algorithm>
// 세그먼트 트리사용
using namespace std;
typedef long long ll;

#define MAX_N 250001
#define MAX 65536

ll seg[4 * MAX_N], arr[MAX_N], N, K, sum; // 위치를 기준으로 값을 저장

ll update(ll pos, ll val, ll node, ll x, ll y)
{ // 노드와 노드의 범위
  if (pos < x || pos > y)
    return seg[node];
  if (x == y)
    return seg[node] += val;
  ll mid = (x + y) >> 1; // 한비트를 당김 즉 (x + y) / 2와 같음
  return seg[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node * 2 + 1, mid + 1, y);
}

ll query(ll pos, ll node, ll x, ll y)
{
  if (x == y)
    return x; // 해당값을 찾았을경우 그값을 리턴

  ll mid = (x + y) >> 1;
  if (pos <= seg[2 * node])
    return query(pos, 2 * node, x, mid); // 상대적인 위치를 찾음
  else
    return query(pos - seg[2 * node], 2 * node + 1, mid + 1, y);
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin >> N >> K;
  ll answer = 0;

  for (int i = 0; i < N; ++i)
  {
    cin >> arr[i];
  }

  for (int i = 0; i < K; ++i)
  {
    update(arr[i], 1, 1, 0, MAX_N - 1);
  }

  ll mid = (K + 1) / 2;
  for (int i = 0; i < N - K + 1; ++i)
  {
    answer += query(mid, 1, 0, MAX_N - 1);
    update(arr[i], -1, 1, 0, MAX_N - 1);
    if (i == N - K)
      break; // 업데이트 할필요가 없음
    update(arr[i + K], 1, 1, 0, MAX_N - 1);
  }

  cout << answer << endl;
  return 0;
}