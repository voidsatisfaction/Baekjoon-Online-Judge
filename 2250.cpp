#include <cstdio>
#include <vector>
#define MAX 10001

using namespace std;

struct node {
  int left;
  int right;
};

vector<vector<int> > levelNodes(MAX);
node tree[MAX];
int place[MAX];
bool checker[MAX];
int N, globalIndex = 1;

void inorderSearch(int nodeNum, int level)
{
  levelNodes[level].push_back(nodeNum);
  level++;
  if(tree[nodeNum].left != -1) {
    inorderSearch(tree[nodeNum].left, level);
  }
  place[nodeNum] = globalIndex;
  globalIndex++;
  if(tree[nodeNum].right != -1) {
    inorderSearch(tree[nodeNum].right, level);
  }
  return;
}

int main()
{
  scanf("%d", &N);
  int x, y, z;
  for (int i = 0; i < N; i++)
  {
    scanf("%d %d %d", &x, &y, &z);
    node newNode;
    newNode.left = y;
    newNode.right = z;
    if(y != -1)
      checker[y] = true;
    if(z != -1)
      checker[z] = true;
    tree[x] = newNode;
  }

  int root = 1;
  for(int i = 1; i < N + 1; i++)
  {
    if(!checker[i]) {
      root = i;
      break;
    }
  }

  inorderSearch(root,1);

  int width = 0;
  int level = 0;
  for (int i = 1; levelNodes[i].size() > 0; i++)
  {
    int levelNodeNum = levelNodes[i].size();
    int levelFirstNode = levelNodes[i][0];
    int levelLastNode = levelNodes[i][levelNodeNum - 1];

    int levelWidth = place[levelLastNode] - place[levelFirstNode] + 1;
    if (levelWidth > width){
      width = levelWidth;
      level = i;
    }
  }

  printf("%d %d\n", level, width);
  return 0;
}