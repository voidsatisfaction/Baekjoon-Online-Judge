#include <cstdio>

#define MAX 300001

struct node {
  int left;
  int right;
};

node tree[MAX];
int N, root, counts;

void insertNode(int nodeNum)
{
  int start = root;
  while(true)
  {
    counts++;
    if (nodeNum == start) return;
    if (nodeNum > start) {
      if (tree[start].right > 0) {
        start = tree[start].right;
      } else {
        tree[start].right = nodeNum;
        printf("%d\n", counts);
        break;
      }
    } else {
      if (tree[start].left > 0) {
        start = tree[start].left;
      } else {
        tree[start].left = nodeNum;
        printf("%d\n", counts);
        break;
      }
    }
  }
}

int main()
{
  scanf("%d", &N);
  scanf("%d", &root);
  printf("%d\n", counts);
  for (int i = 0; i < N-1; i++)
  {
    int nodeNum;
    scanf("%d", &nodeNum);
    insertNode(nodeNum);
  }
  return 0;
}