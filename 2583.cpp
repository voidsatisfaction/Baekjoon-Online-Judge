#include <cstdio>
#include <queue>
#include <algorithm>

#define MAX_N 102
#define INF 1987654321

std::queue <std::pair<int, int> > que;
int graph[MAX_N][MAX_N], size[MAX_N];
int M, N, K, x1, y1, x2, y2, id=1;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y)
{
  graph[y][x] = id;
  size[id]++;
  for(int i = 0; i < 4; i++) {
    int nextX = x + dx[i];
    int nextY = y + dy[i];
    if (graph[nextY][nextX] == 0) {
      dfs(nextX, nextY);
    }
  }
}

void bfs(int x, int y)
{
  graph[y][x] = id;
  size[id]++;
  que.push(std::make_pair(x, y));
  while(!que.empty())
  {
    int currX = que.front().first;
    int currY = que.front().second;
    que.pop();
    for(int i=0; i<4; i++) {
      int nextX = currX + dx[i];
      int nextY = currY + dy[i];
      if (graph[nextY][nextX] == 0) {
        graph[nextY][nextX] = id;
        size[id]++;
        que.push(std::make_pair(nextX, nextY));
      }
    }
  }
}

void floodFill()
{
  for(int y=1; y<M+1; y++) {
    for(int x=1; x<N+1; x++) {
      if (graph[y][x] == 0) {
        size[id] = 0;
        bfs(x, y);
        id++;
      }
    }
  }
}

int main()
{
  scanf("%d %d %d", &M, &N, &K);
  for(int y = 0; y <= M+1; y++) {
    graph[y][0] = -1;
    graph[y][N+1] = -1;
  }
  for(int x = 0; x <= N+1; x++) {
    graph[0][x] = -1;
    graph[M+1][x] = -1;
  }
  for(int i = 0; i < MAX_N; i++)
    size[i] = INF;

  for(int i = 0; i < K; i++) {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    for(int x = x1+1; x < x2+1; x++) {
      for(int y = y1+1; y < y2+1; y++) {
        graph[y][x] = -1;
      }
    }
  }

  floodFill();

  printf("%d\n", id-1);

  std::sort(size, size + MAX_N);

  for(int i=0; i<id-1; i++) {
    printf("%d ", size[i]);
  }
  
  return 0;
}