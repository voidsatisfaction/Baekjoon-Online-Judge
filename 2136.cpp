#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Ant
{
  int place, direction, index;
};
bool cmpPlace(const Ant &a, const Ant &b)
{
  return a.place < b.place;
}
// vector<Ant> ant;
Ant ant[100000];
int N,L,temp,phase,lastIndex,s,e;

int main()
{
  scanf("%d %d",&N,&L);
  Ant antInput;
  for(int i=1; i < N+1; i++)
  {
    scanf("%d",&temp);
    antInput.place = abs(temp);
    antInput.direction = (temp > 0) ? 1 : -1;
    antInput.index = i;
    ant[i-1] = antInput;
  }
  sort(ant, ant+N,cmpPlace);

  e = N;
  while(s<e)
  {
    for(int i=s; i < e; i++)
    {
      ant[i].place += (ant[i].direction < 0) ? -1 : 1;
      if(i>s && ant[i].place == ant[i-1].place){
        ant[i].direction *= -1;
        ant[i-1].direction *= -1;
      }
    }
    while((ant[s].direction > 0 && ant[e].direction < 0) || e-s > 2)
    {
      if(ant[s].direction < 0)
        s++;
      if(ant[e-1].direction > 0)
        e--;
    }
    if(ant[s].place == 0)
      s++;
    if(ant[e-1].place == L)
      e--;

    if(e-s == 1)
      lastIndex = ant[s].index;

    phase++;
  }
  
  printf("%d %d\n",lastIndex,phase);
  return 0;
}