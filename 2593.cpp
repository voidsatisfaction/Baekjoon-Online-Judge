#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_M 101
#define INF 987654321

using namespace std;

struct indeterminate {
  int a;
  int b;
  indeterminate(int _a, int _b) {
    a = _a;
    b = _b;
  };
};

vector<indeterminate> allIndeterminate;
vector<vector<int> > adjList(MAX_M);
bool endNodes[MAX_M], adjMatrix[MAX_M][MAX_M];
int N, M, a, b, A, B, nextNodes[MAX_M], dp[MAX_M], visited[MAX_M], ansStartNode, ansNums = INF;

bool hasFloor(int n, int a, int b)
{
  int diff = n - b;
  if (diff < 0 || diff % a != 0)
    return false;

  return true;
}

int dfs(int startNode)
{
  if(endNodes[startNode])
    return 0;
  if(dp[startNode] != INF)
    return dp[startNode];

  visited[startNode] = true;

  for(int nextNode : adjList[startNode]) {
    if(!visited[nextNode]) {
      int temp = dfs(nextNode) + 1;
      if (temp < dp[startNode]){
        dp[startNode] = temp;
        nextNodes[startNode] = nextNode;
      }
    }
  }

  visited[startNode] = false;
  return dp[startNode];
}

int main()
{
  scanf("%d %d", &N, &M);
  for(int i=0; i<M; i++) {
    scanf("%d %d", &a, &b);
    allIndeterminate.push_back(indeterminate(b, a));
  }
  scanf("%d %d", &A, &B);

  for(int i=1; i<=N; i++) {
    vector<int> thisFloor;
    for(int j=1; j<=M; j++) {
      indeterminate idt = allIndeterminate[j-1];
      if(hasFloor(i, idt.a, idt.b)) {
        if(i == B) endNodes[j] = true;
        for(int n : thisFloor) {
          if(!adjMatrix[n][j]) {
            adjList[j].push_back(n);
            adjList[n].push_back(j);
            adjMatrix[j][n] = true;
            adjMatrix[n][j] = true;
          }
        }
        thisFloor.push_back(j);
      }
    }
    thisFloor.clear();
  } 

  for(int i=1; i<=M; i++)
    dp[i] = INF;

  for (int i = 1; i <= M; i++){
    indeterminate idt = allIndeterminate[i-1];
    for(int j=1; j<=M; j++) {
      visited[j] = false;
      nextNodes[j] = 0;
    }
    if(hasFloor(A, idt.a, idt.b)) {
      int temp = dfs(i);
      if(temp < ansNums) {
        ansNums = temp;
        ansStartNode = i;
      }
    }
  }

  for (int j = 1; j <= M; j++){
    dp[j] = INF;
    visited[j] = false;
    nextNodes[j] = 0;
  }
  dfs(ansStartNode);

  if(ansNums == INF) {
    printf("-1\n");
  } else {
    printf("%d\n", ansNums + 1);
    while (ansStartNode > 0)
    {
      printf("%d\n", ansStartNode);
      ansStartNode = nextNodes[ansStartNode];
    }
  }
    
  return 0;
}