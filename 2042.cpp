#include <cstdio>

#define MAX_N 1000001

typedef long long ll;

ll N, M, K, a[MAX_N], segTree[MAX_N * 4];

ll segInit(ll* segTree, ll* a, ll node, ll left, ll right)
{
  if (left == right){
    segTree[node] = a[left];
    return segTree[node];
  }
  
  ll mid = (left + right) / 2;

  segTree[node] = segInit(segTree, a, 2*node, left, mid) + segInit(segTree, a, 2*node+1, mid+1, right);
  return segTree[node];
}

void updateSeg(ll* segTree, ll* a, ll index, ll node, ll left, ll right, ll diff)
{
  if (!(index >= left && index <= right)){
    return;
  }
  
  segTree[node] += diff;

  if (left != right){
    ll mid = (left + right) / 2;
    updateSeg(segTree, a, index, 2*node, left, mid, diff);
    updateSeg(segTree, a, index, 2*node+1, mid+1, right, diff);
  }
}

ll sumSeg(ll* segTree, ll node, ll left, ll right, ll targetLeft, ll targetRight)
{
  if (targetLeft > right || targetRight < left){
    return 0;
  }

  if (targetLeft <= left && targetRight >= right){
    return segTree[node];
  }

  ll mid = (left + right) / 2;
  return sumSeg(segTree, 2*node, left, mid, targetLeft, targetRight) + sumSeg(segTree, 2*node+1, mid+1, right, targetLeft, targetRight);
}

int main()
{
  scanf("%lld %lld %lld", &N, &M, &K);
  for (ll i = 0; i < N; i++)
    scanf("%lld", &a[i]);
  
  segInit(segTree, a, 1, 0, N-1);

  for (ll i = 0; i < M+K; i++)
  {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    if (x == 1){
      updateSeg(segTree, a, y-1, 1, 0, N-1, z-a[y-1]);
      a[y-1] = z;
    } else if (x == 2){
      printf("%lld\n", sumSeg(segTree, 1, 0, N-1, y-1, z-1));
    }
  }
  return 0;
}