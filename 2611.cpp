#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 1001

using namespace std;

struct edge {
  int node;
  int score;
  edge(int _n, int _s) { node = _n, score = _s; }
};

vector<vector<edge> > adjList(MAX_N);
int N, M, p, q, r, score, dp[MAX_N], route[MAX_N];

int dfs(int node, bool isFirst)
{
  if(node == 1 && isFirst == false)
    return 0;
  if(dp[node] > 0)
    return dp[node];

  for(edge adjEdge : adjList[node]) {
    int adjNode = adjEdge.node;
    int adjScore = adjEdge.score;
    int ret = dfs(adjNode, false) + adjScore;
    if(ret > dp[node]) {
      dp[node] = ret;
      route[node] = adjNode;
    }
  }
  return dp[node];
}

int main()
{
  scanf("%d", &N);
  scanf("%d", &M);
  while(M--)
  {
    scanf("%d %d %d", &p, &q, &r);
    adjList[p].push_back(edge(q, r));
  }

  dfs(1, true);

  printf("%d\n", dp[1]);
  printf("%d ", 1);
  int nodeNum = route[1];
  while(nodeNum != 1)
  {
    printf("%d ", nodeNum);
    nodeNum = route[nodeNum];
  }
  printf("%d ", 1);

  return 0;
}