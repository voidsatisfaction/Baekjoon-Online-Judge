#include <cstdio>
#include <vector>

using namespace std;

struct node {
  int n;
  int x;
  int y;
  int r;
  node(int _n, int _x, int _y, int _r)
  {
    n = _n;
    x = _x;
    y = _y;
    r = _r;
  }
};

vector<node> allNodes;
vector<vector<node> > adjList(3001);
bool visited[3001];
int T, N, x, y, r, counts;

bool isAdjacentNode(const node& node1, const node& node2)
{
  int x1 = node1.x; int y1 = node1.y; int r1 = node1.r;
  int x2 = node2.x; int y2 = node2.y; int r2 = node2.r;
  return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) <= (r1 + r2) * (r1 + r2);
}

void dfs(int i)
{
  visited[i] = true;
  for (int j = 0; j < adjList[i].size(); j++)
  {
    node nextNode = adjList[i][j];
    if (!visited[nextNode.n])
      dfs(nextNode.n);
  }
}

int floodFill()
{
  // initialize
  counts = 0;
  for(int i=0; i<N; i++)
    visited[i] = false;
  
  for(int i=0; i<N; i++) {
    if (!visited[i]) {
      dfs(i);
      counts++;
    }
  }

  return counts;
}

int main()
{
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d", &N);
    allNodes.clear();
    for(int i=0; i<N; i++)
      adjList[i].clear();
    for(int i=0; i<N; i++) {
      scanf("%d %d %d", &x, &y, &r);
      node node1 = node(i, x, y, r);
      for(int j=0; j<allNodes.size(); j++) {
        node node2 = allNodes[j];
        if (isAdjacentNode(node1, node2)) {
          adjList[i].push_back(node2);
          adjList[j].push_back(node1);
        }
      }
      allNodes.push_back(node1);
    }

    printf("%d\n", floodFill());
  }
  return 0;
}