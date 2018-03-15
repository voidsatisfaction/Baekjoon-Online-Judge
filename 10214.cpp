#include <cstdio>
#include <vector>
#include <queue>

#define INF 1987654321

using namespace std;

struct node
{
  int n;
  int c;
  int d;
  node(int _n, int _c, int _d)
  {
    n = _n;
    c = _c;
    d = _d;
  }
};

struct comp
{
  bool operator()(const node &n1, const node &n2)
  {
    return n1.d > n2.d;
  }
};

vector<vector<node> > adjList(101);
int dp[101][10001];
int T, N, M, K;

int dajikstra(int from, int to, int M)
{
  priority_queue<node, vector<node>, comp> pq;
  pq.push(node(from, 0, 0));
  for (int i = 0; i < 101; i++)
    for (int j = 0; j < 10001; j++)
      dp[i][j] = INF;

  dp[1][0] = 0;
  while (!pq.empty())
  {
    node currentState = pq.top(); pq.pop();

    if (currentState.n == to) return currentState.d;
    if (dp[currentState.n][currentState.c] < currentState.d) continue;

    for (int i = 0; i < adjList[currentState.n].size(); i++)
    {
      node nextEdge = adjList[currentState.n][i];
      int nextCost = currentState.c + nextEdge.c;
      int nextDist = dp[currentState.n][currentState.c] + nextEdge.d;

      if (nextCost <= M && nextDist < dp[nextEdge.n][nextCost]){
        dp[nextEdge.n][nextCost] = nextDist;
        node nextState = node(nextEdge.n, nextCost, nextDist);
        pq.push(nextState);
      }
    }
  }
  return -1;
}

int main()
{
  scanf("%d", &T);
  for (int i = 0; i < T; i++)
  {
    scanf("%d %d %d", &N, &M, &K);

    for (int j = 0; j < 101; j++) adjList[j].clear();

    int u, v, c, d;
    for (int j = 0; j < K; j++)
    {
      scanf("%d %d %d %d", &u, &v, &c, &d);
      adjList[u].push_back(node(v, c, d));
    }

    // add dajikstra
    int minDist = dajikstra(1, N, M);
    if (minDist == -1)
    {
      printf("Poor KCM\n");
    }
    else
    {
      printf("%d\n", minDist);
    }
  }
  return 0;
}
