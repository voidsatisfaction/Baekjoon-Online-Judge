#include <cstdio>
#include <vector>

using namespace std;

#define PAIR pair<int, int>

bool maps[101][101];
vector<PAIR> routes{ {1,1} } ;
int N,M,x,y;

void findPath(int phase, vector<PAIR> routes)
{
  vector<PAIR> nextRoutes;
  int num_routes = routes.size();
  for(int i=0; i < num_routes; i++)
  {
    x = routes[i].first;
    y = routes[i].second;
    if(x-1 >= 1 && maps[x-1][y]){
      nextRoutes.push_back(PAIR {x-1,y} );
    } else if(x+1 <= N && maps[x+1][y]){
      nextRoutes.push_back(PAIR {x+1,y});
      if(x+1 == N && y == M){
        printf("%d",phase + 1);
        return;
      }
    } else if(y-1 >= 1 && maps[x][y-1]){
      nextRoutes.push_back(PAIR {x,y-1});
    } else if(y+1 <= M && maps[x][y+1]){
      nextRoutes.push_back(PAIR {x,y+1});
      if(x == N && y+1 == M){
        printf("%d",phase + 1);
        return;
      }
    }
    maps[x][y] = 0;
  }
  phase++;
  findPath(phase,nextRoutes);
}

int main()
{
  int N,M,temp;
  scanf("%d %d",&N,&M);
  for(int i=1; i <= N; i++)
  {
    scanf("%d",&temp);
    for(int j=M; j >= 1; j--)
    {
      maps[i][j] = temp % 10;
      temp /= 10;
    }
  }
  findPath(1,routes);
  return 0;
}

4 6
101111
101010
101011
111011