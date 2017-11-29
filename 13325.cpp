#include <cstdio>

#define TOTAL_NODE_NUM ((1 << 21) - 1)

int k, ans;
int tree[TOTAL_NODE_NUM], dp[TOTAL_NODE_NUM];

void makeSameDistTree(int index)
{
  if (index >= ((1 << k) - 1) && index <= ((1 << (k+1)) - 1)) {
    return;
  }
  int leftIndex = 2*index + 1;
  int rightIndex = 2*index + 2;
  makeSameDistTree(leftIndex);
  makeSameDistTree(rightIndex);

  int leftVal = dp[leftIndex] + tree[leftIndex];
  int rightVal = dp[rightIndex] + tree[rightIndex];
  if (rightVal > leftVal){
    int diff = rightVal - leftVal;
    tree[leftIndex] += diff;
  } else {
    int diff = leftVal - rightVal;
    tree[rightIndex] += diff;
  }
  dp[index] = dp[leftIndex] + tree[leftIndex];
  ans = ans + tree[leftIndex] + tree[rightIndex];
}

int main()
{
  scanf("%d", &k);
  int totalNodes = (1 << (k+1)) - 1;
  for (int i = 1; i <= totalNodes-1; i++)
    scanf("%d", &tree[i]);

  makeSameDistTree(0);
  
  printf("%d\n", ans);
  return 0;
}