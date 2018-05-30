#include <cstdio>
#include <vector>
#include <algorithm>

#define INF 2147483647L * 214214214
#define MAX_N 101

using namespace std;

typedef long long ll;

struct edge {
  ll node;
  ll cost;
  edge(ll _n, ll _c) {
    node = _n;
    cost = _c;
  };
};

vector<vector<edge> > adjList(MAX_N);
ll N, M, startNode, endNode, from, to, cost, ans, profit[MAX_N], maxMoney[MAX_N];

ll bellmanFord()
{
  for(int i=0; i<N; i++)
    maxMoney[i] = -INF;
  maxMoney[startNode] = profit[startNode];

  for(int k=0; k<2; k++) {
    for(int i=0; i<N; i++) {
      for(int j=0; j<N; j++) {
        for(edge e : adjList[j]) {
          ll nextVal = maxMoney[j] - e.cost + profit[e.node];
          if(maxMoney[j] == -INF) continue;
          else if (maxMoney[j] == INF) maxMoney[e.node] = INF;
          else if (nextVal > maxMoney[e.node]) {
            maxMoney[e.node] = nextVal;
            if(k) maxMoney[e.node] = INF;
          }
        }
      }
    }
  }

  return maxMoney[endNode];
}

int main()
{
  scanf("%lld %lld %lld %lld", &N, &startNode, &endNode, &M);
  for(int i=0; i<M; i++) {
    scanf("%lld %lld %lld", &from, &to, &cost);
    adjList[from].push_back(edge(to, cost));
  }
  for(int i=0; i<N; i++)
    scanf("%lld", &profit[i]);

  ans = bellmanFord();
  if (ans == INF) {
    printf("Gee\n");
  } else if (ans == -INF) {
    printf("gg\n");
  } else {
    printf("%lld\n", ans);
  }
  return 0;
}