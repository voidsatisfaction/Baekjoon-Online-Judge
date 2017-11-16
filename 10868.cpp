#include <cstdio>
#include <algorithm>

#define MAX_N 100001
#define MAX_M 100001
#define INF 1000000001

int N, M, a[MAX_N], segTree[4*MAX_N];

int makeMinSegTree(int left, int right, int node)
{
  if (left == right){
    segTree[node] = a[left];
    return segTree[node];
  }

  int mid = (left + right) / 2;
  segTree[node] = std::min(makeMinSegTree(left, mid, 2*node), makeMinSegTree(mid+1, right, 2*node+1));
  return segTree[node];
}

int getMinVal(int left, int right, int targetLeft, int targetRight, int node)
{
  if (right < targetLeft || left > targetRight){
    return INF;
  }
  if (targetLeft <= left && targetRight >= right){
    return segTree[node];
  }

  int mid = (left + right) / 2;

  return std::min(getMinVal(left, mid, targetLeft, targetRight, 2*node), getMinVal(mid+1, right, targetLeft, targetRight, 2*node+1));
}

int main()
{
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= N; i++)
    scanf("%d", &a[i]);

  makeMinSegTree(1, N, 1);
  
  for (int i = 1; i <= M; i++)
  {
    int a, b, m;
    scanf("%d %d", &a, &b);
    m = getMinVal(1, N, a, b, 1);
    printf("%d\n", m);
  }
  return 0;
}