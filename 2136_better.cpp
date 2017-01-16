#include <cstdio>
#include <stdlib.h>
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
Ant ant[100000];
int N,L,temp,phase,lastIndex,leftEdge,rightEdge,standard,numLeft,numRight,dirReverse;

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

  for(int i=0; i < N; i++)
  {
    if(ant[i].direction > 0){
      leftEdge = L - ant[i].place;
      numLeft = i;
      break;
    }
  }
  for(int i=N-1; i >= 0; i--)
  {
    if(ant[i].direction < 0){
      rightEdge = ant[i].place;
      numRight = i;
      break;
    }
  }
  phase = max(leftEdge,rightEdge);
  standard = (leftEdge > rightEdge) ? -1 : 1;
  if(standard < 0){
    for(int i=numLeft+1; i < N; i++)
    {
      if(ant[i].direction == standard)
        dirReverse++;
    }
    lastIndex = ant[numLeft + dirReverse].index;
  } else {
    for(int i=numRight-1; i >= 0; i--)
    {
      if(ant[i].direction == standard)
        dirReverse++;
    }
    lastIndex = ant[numRight - dirReverse].index;
  }

  printf("%d %d\n",lastIndex,phase);
  return 0;
}