#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 1001
#define MAX_TIME 1000000

using namespace std;

struct adjNode {
  adjNode(int a, int b) {
    num = a;
    times = b;
  }
  int num, times;
};

struct comp {
  bool operator()(const adjNode &a, const adjNode &b) {
    return a.times > b.times;
  }
};

int N, M, X;
vector<vector<adjNode> > adjList(MAX);
vector<int> totalTimes;

int dijkstra(int from, int to) {
  int timeToNode[MAX];
  for (int i = 1; i < MAX; i++)
    timeToNode[i] = MAX_TIME;
  timeToNode[from] = 0;

  priority_queue<adjNode, vector<adjNode>, comp> pq;
  pq.push(adjNode(from, 0));

  while(!pq.empty()) {
    int nodeNum = pq.top().num;
    int times = pq.top().times; pq.pop();
    if (times > timeToNode[nodeNum]) continue;
    for (int i = 0; i < adjList[nodeNum].size(); i++)
    {
      int adjNodeNum = adjList[nodeNum][i].num;
      int adjTimes = adjList[nodeNum][i].times;
      if (timeToNode[nodeNum] + adjTimes < timeToNode[adjNodeNum]){
        timeToNode[adjNodeNum] = timeToNode[nodeNum] + adjTimes;
        pq.push(adjNode(adjNodeNum, adjTimes));
      }
    }
  }

  return timeToNode[to];
}

int main() {
  scanf("%d %d %d", &N, &M, &X);
  for (int i = 0; i < M; i++)
  {
    int from, to, times;
    scanf("%d %d %d", &from, &to, &times);
    adjList[from].push_back(adjNode(to, times));
  }

  for (int i = 1; i < N+1; i++)
  {
    int totalTime = dijkstra(i, X) + dijkstra(X, i);
    totalTimes.push_back(totalTime);
  }
  printf("%d\n", *max_element(totalTimes.begin(), totalTimes.end()));

  return 0;
}