#include <cstdio>
#include <algorithm>

#define MAX_N 100001

typedef long long ll;

void init(int* segTree, int* hist, int left, int right, int node)
{
  if(left == right) {
    segTree[node] = left;
    return;
  }
  
  int mid = (left + right) / 2;

  init(segTree, hist, left, mid, 2*node);
  init(segTree, hist, mid+1, right, 2*node+1);
  if (hist[segTree[2*node]] <= hist[segTree[2*node+1]]){
    segTree[node] = segTree[2*node];
  } else {
    segTree[node] = segTree[2*node+1];
  }
}

int getMinIndex(int* segTree, int* hist, int left, int right, int targetLeft, int targetRight, int node)
{
  if (right < targetLeft || left > targetRight){
    return -1;
  }
  if (targetLeft <= left && targetRight >= right){
    return segTree[node];
  }

  int mid = (left + right) / 2;
  int min1 = getMinIndex(segTree, hist, left, mid, targetLeft, targetRight, 2*node);
  int min2 = getMinIndex(segTree, hist, mid+1, right, targetLeft, targetRight, 2*node+1);
  if (min1 == -1){
    return min2;
  } else if (min2 == -1){
    return min1;
  } else if (hist[min1] <= hist[min2]){
    return min1;
  } else {
    return min2;
  }
}

ll largestRect(int* segTree, int* hist, int left, int right, int histNum)
{
  int minIndex = getMinIndex(segTree, hist, 1, histNum, left, right, 1);
  ll rect = (ll)(right - left + 1) * (ll)hist[minIndex];
  if (left <= minIndex-1){
    ll leftRect = largestRect(segTree, hist, left, minIndex-1, histNum);
    if (leftRect > rect){
      rect = leftRect;
    }
  }
  if (right >= minIndex+1) {
    ll rightRect = largestRect(segTree, hist, minIndex+1, right, histNum);
    if (rightRect > rect){
      rect = rightRect;
    }
  }
  return rect;
}

int main()
{
  while(true)
  {
    int n, hist[MAX_N], segTree[4*MAX_N];
    scanf("%d", &n);
    if (n == 0){
      break;  
    }
    for (int i = 1; i <= n; i++)
      scanf("%d", &hist[i]);

    init(segTree, hist, 1, n, 1);
    ll largestRectArea = largestRect(segTree, hist, 1, n, n);
    
    printf("%lld\n", largestRectArea);
  }

  return 0;
}