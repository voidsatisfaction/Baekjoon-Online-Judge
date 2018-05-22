#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_N 101
#define INF 1987654321

using namespace std;

vector<vector<int> > adjList(MAX_N);
int N, M, a, b, labelNum=1, labels[MAX_N], labelLevels[MAX_N], labelRepresentNode[MAX_N];

void bfs(int startNode, int label)
{
  int level = 0;
  int levelElementNums = 1;
  bool visited[MAX_N] = {false, };
  queue<int> q;

  q.push(startNode);
  visited[startNode] = true;

  while(!q.empty())
  {
    while(levelElementNums)
    {
      levelElementNums--;
      int node = q.front(); q.pop();

      for(int adjNode : adjList[node]) {
        if(!visited[adjNode]) {
          labels[adjNode] = label;

          visited[adjNode] = true;
          q.push(adjNode);
        }
      }
    }
    level++;
    levelElementNums = q.size();
  }

  if(level < labelLevels[label]) {
    labelLevels[label] = level;
    labelRepresentNode[label] = startNode;
  }
}

void putLabel()
{
  for(int i=1; i<=N; i++) {
    if(labels[i] == 0) {
      labels[i] = labelNum;
      labelNum++;
    }
    bfs(i, labels[i]);
  }
}

int main()
{
  scanf("%d", &N);
  scanf("%d", &M);
  for(int i=0; i<M; i++) {
    scanf("%d %d", &a, &b);
    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }

  for(int i=0; i<MAX_N; i++)
    labelLevels[i] = INF;

  putLabel();

  printf("%d\n", labelNum-1);
  sort(labelRepresentNode+1, labelRepresentNode + labelNum);
  for(int i=1; i<labelNum; i++)
    printf("%d\n", labelRepresentNode[i]);
  
  return 0;
}