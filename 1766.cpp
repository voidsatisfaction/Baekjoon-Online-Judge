#include <cstdio>
#include <vector>
#include <queue>

#define MAX_N 32001

using namespace std;

vector<vector<int> > adjList(MAX_N);
vector<int> ans;
int inDegree[MAX_N];
int N, M;

void tpSort()
{
  bool marked[N+1];
  priority_queue<int, vector<int>, greater<int> > pq;
  // insert all indegree 0 vertexes to ans
  for (int i = 1; i < N + 1; i++)
  {
    if (inDegree[i] == 0) {
      pq.push(i);
    }
  }
  // indegree bfs
  while(!pq.empty())
  {
    int n = pq.top(); pq.pop();
    ans.push_back(n);

    for (int adjNode : adjList[n])
    {
      inDegree[adjNode]--;
      if (inDegree[adjNode] == 0) {
        pq.push(adjNode);
      }
    }
  }
}

int main()
{
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; i++)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    inDegree[b]++;
    adjList[a].push_back(b);
  }

  tpSort();

  // minheap
  for (int i = 0; i < N; i++)
    printf("%d ", ans[i]);

  return 0;
}