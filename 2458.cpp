#include <cstdio>
#include <vector>

#define MAX_N 501

using namespace std;

struct edge {
  int to;
  int dir;

  edge(int _to, int _dir) {
    to = _to;
    dir = _dir;
  }
};

vector<vector<edge> > adjList(MAX_N);
bool visited[MAX_N];
int N, M, a, b, ans;

void dfs(int num, int dir)
{
  visited[num] = true;
  for (edge e : adjList[num])
    if (!visited[e.to] && dir == e.dir)
      dfs(e.to, e.dir);
}

bool checkNumIsDecided(int num)
{
  for (int i = 1; i <= N; i++)
    visited[i] = false;

  dfs(num, 1);
  dfs(num, -1);

  for (int i = 1; i <= N; i++)
    if (!visited[i])
      return false;

  return true;
}

int main()
{
  scanf("%d %d", &N, &M);
  for(int i = 0; i < M; i++)
  {
    scanf("%d %d", &a, &b);
    adjList[a].push_back(edge(b, 1));
    adjList[b].push_back(edge(a, -1));
  }

  for(int i = 1; i <= N; i++)
    if (checkNumIsDecided(i))
      ans++;
  
  printf("%d\n", ans);
  
  return 0;
}