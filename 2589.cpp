#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define MAX_N_M 52

using namespace std;

struct node {
  int x, y;
  node(int _x, int _y) {
    x = _x;
    y = _y;
  };
};

node dir[4] = {node(0, 1), node(0, -1), node(1, 0), node(-1, 0)};
char map[MAX_N_M][MAX_N_M];
bool visited[MAX_N_M][MAX_N_M];
int N, M, longestShortestTime;

int bfs(int x, int y)
{
  if(map[y][x] == 'W') return 0;
  for(int i=1; i<=N; i++)
    for(int j=1; j<=M; j++)
      visited[i][j] = false;

  queue<node> q;
  int dist = -1;
  visited[y][x] = true;

  q.push(node(x, y));
  while(!q.empty())
  {
    dist++;
    int size = q.size();
    for(int s=0; s<size; s++) {
      node currentNode = q.front(); q.pop();
      for(int i = 0; i < 4; i++) {
        node direction = dir[i];
        int nextX = currentNode.x + direction.x;
        int nextY = currentNode.y + direction.y;
        if(map[nextY][nextX] == 'L' && !visited[nextY][nextX])
        {
          visited[nextY][nextX] = true;
          q.push(node(nextX, nextY));
        }
      }
    }
  }

  return dist;
}

int main()
{
  cin >> N >> M;

  for(int i=1; i<=N; i++)
    for(int j=1; j<=M; j++)
      cin >> map[i][j];

  for(int i=1; i<=N; i++)
    for (int j=1; j <= M; j++)
      longestShortestTime = max(longestShortestTime, bfs(j, i));

  cout << longestShortestTime << endl;

  return 0;
}