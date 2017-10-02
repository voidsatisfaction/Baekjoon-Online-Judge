#include <cstdio>
#include <vector>

#define INF 100000000
#define MINUS_INF -INF
#define MAX_N 501

using namespace std;

struct adjNode {
  int num, times;
  adjNode(int n, int t) {
    num = n;
    times = t;
  }
};
int T, N, M, W;

int bellmanFord(int from, int to, vector<vector<adjNode> > adjList) {
  bool isInfinite = false;

  int takingTimes[N+1];
  for(int i=0; i < N+1; i++)
    takingTimes[i] = INF;
  takingTimes[from] = 0;

  for(int i=1; i < N+1; i++) {
    for(int j=1; j < N+1; j++) {
      for(int k=0; k < adjList[j].size(); k++) {
        int adjNodeNum = adjList[j][k].num;
        int adjNodeTimes = adjList[j][k].times;
        if (takingTimes[j] != INF && takingTimes[adjNodeNum] > takingTimes[j] + adjNodeTimes) {
          takingTimes[adjNodeNum] = takingTimes[j] + adjNodeTimes;
          if (i == N)
            isInfinite = true;
        }
      }
    }
  }

  if(isInfinite) {
    return MINUS_INF;
  }
  return takingTimes[to];
}

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d %d", &N, &M, &W);

    vector<vector<adjNode> > adjList(N+1);
    for(int i=0; i < M; i++) {
      int from, to, times;
      scanf("%d %d %d", &from, &to, &times);
      adjList[from].push_back(adjNode(to, times));
      adjList[to].push_back(adjNode(from, times));
    }
    for(int i=0; i < W; i++) {
      int from, to, times;
      scanf("%d %d %d", &from, &to, &times);
      adjList[from].push_back(adjNode(to, -times));
    }

    int minDist = bellmanFord(1, 2, adjList);

    if (minDist == MINUS_INF) {
      printf("%s\n", "YES");
    } else {
      printf("%s\n", "NO");
    }
  }
  return 0;
}