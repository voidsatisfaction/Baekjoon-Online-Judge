#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX_N 10001

using namespace std;

vector<vector<int> > adjList(MAX_N);
vector<int> canGoNodeNums(MAX_N);
bool visited[MAX_N];
int N, M, A, B, maxNodeNums;

void dfs(int st, int n) {
  visited[n] = true;
  canGoNodeNums[st]++;
  for(int adjNode : adjList[n]) {
    if (!visited[adjNode])
      dfs(st, adjNode);
  }
}

int main()
{
  scanf("%d %d", &N, &M);
  for(int i=0; i<M; i++) {
    scanf("%d %d", &A, &B);
    adjList[B].push_back(A);
  }

  for(int i=1; i<=N; i++) {
    memset(visited, false, sizeof(visited));
    dfs(i, i);
    maxNodeNums = max(maxNodeNums, canGoNodeNums[i]);
  }

  for(int i=1; i<=N; i++)
    if(canGoNodeNums[i] == maxNodeNums)
      printf("%d ", i);

  return 0;
}