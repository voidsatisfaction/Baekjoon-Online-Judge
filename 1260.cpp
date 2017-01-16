#include <cstdio>
#include <deque>

#define MAX 1001

using namespace std;

bool G[MAX][MAX];
bool visited[MAX];
bool visited2[MAX];
deque<int> current_visit;
int temp;

void DFS(int &v)
{
  printf("%d ",v);
  visited[v] = 1;
  for(int i=0; i < MAX ; i++)
  {
    if(!visited[i] && G[v][i])
      DFS(i);
  }
  return;
}

void BFS(int &v)
{
  current_visit.push_back(v);
  printf("%d",v);
  visited2[v] = 1;
  while(1)
  {
    temp = current_visit.front();
    current_visit.pop_front();
    for(int i=1; i < MAX; i++)
    {
      if(G[temp][i] && !visited2[i])
      {
        printf(" %d",i);
        visited2[i] = 1;
        current_visit.push_back(i);
      }
    }
    if(current_visit.size() == 0)
      return;
  }
}

int main()
{
  int N, M, v, a, b;
  scanf("%d %d %d",&N,&M,&v);
  for(int i=0; i < M; i++)
  {
    scanf("%d %d",&a,&b);
    G[a][b] = G[b][a] = 1;
  }
  DFS(v);
  printf("\n");
  BFS(v);
  printf("\n");
  return 0;
}