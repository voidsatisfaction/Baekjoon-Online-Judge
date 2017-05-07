#include <cstdio>
#include <algorithm>

#define MAX 500001

using namespace std;

struct Bus
{
  int from,to,index;
};
Bus segs[MAX];
Bus stdSeg, seg;
bool ans[MAX];
int lowestA,N,M,a,b;

int cmpFunc(const Bus &bus1, const Bus &bus2)
{
  return !(bus1.from == bus2.from) ? bus1.from < bus2.from : bus1.to > bus2.to;
}

int main()
{
  scanf("%d",&N);
  scanf("%d",&M);
  lowestA = N;
  for(int i=0; i<M; i++)
  {
    scanf("%d %d",&a,&b);
    if(a > b) {
      if(a < lowestA) 
        lowestA = a;
      a = a - N;
    }
    segs[i].from = a;
    segs[i].to = b;
    segs[i].index = i+1;
  }

  sort(segs,segs + M,cmpFunc);

  stdSeg = segs[0];
  ans[stdSeg.index] = 1;

  for(int i=1; i<M; i++)
  {
    seg = segs[i];
    if (seg.from >= lowestA)
      break;
    if (stdSeg.to < seg.to) {
      ans[seg.index] = 1;
      stdSeg = seg;
    }
  }

  for(int i=1; i<M+1; i++)
  {
    if(ans[i])
      printf("%d ",i);
  }

  return 0;
}