#include <cstdio>

#define MAX 1000001

struct node {
  int left;
  int right;
};

node tree[MAX];
int nodeNum, treeRoot;

void postSearch(int node)
{
  if(tree[node].left != 0) {
    postSearch(tree[node].left);
  }
  if(tree[node].right != 0) {
    postSearch(tree[node].right);
  }
  printf("%d\n", node);
  return;
}

int main()
{
  scanf("%d", &treeRoot);
  while(scanf("%d", &nodeNum) == 1)
  {
    int searcher = treeRoot;
    while(1)
    {
      if(nodeNum > searcher && tree[searcher].right == 0) {
        tree[searcher].right = nodeNum;
        break;
      } else if(nodeNum > searcher) {
        searcher = tree[searcher].right;
      } else if(nodeNum < searcher && tree[searcher].left == 0) {
        tree[searcher].left = nodeNum;
        break;
      } else {
        searcher = tree[searcher].left;
      }
    }
  }

  postSearch(treeRoot);
  return 0;
}