#include <cstdio>
#include <vector>

#define MAX_N 10

using namespace std;

struct node {
  int n;
  int dist;
};

vector<vector <node> > adjList(MAX_N);
int N;

void dfs(int n, int val, vector<int> path, vector<int>* ans, vector<bool> visited)
{
  if (n == 0 && path.size() == N){
    (*ans).push_back(val);
    return;
  }

  visited[n] = true;
  path.push_back(n);

  for (int next = 0; next < adjList[n].size(); next++)
  {
    int nextNode = adjList[n][next].n;
    int nextDist = adjList[n][next].dist;
    if (visited[nextNode] && path.size() != N) continue;

    dfs(nextNode, val + nextDist, path, ans, visited);
  }
}

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      int d;
      scanf("%d", &d);
      if (d == 0){
        continue;
      }
      node input;
      input.n = j;
      input.dist = d;
      adjList[i].push_back(input);
    }
  }

  vector<bool> visited(MAX_N);
  vector<int> ans, path;

  dfs(0, 0, path, &ans, visited);

  int c = 987654321;
  for (int i = 0; i < ans.size(); i++)
    c = min(c, ans[i]);

  printf("%d\n", c);

  return 0;
}