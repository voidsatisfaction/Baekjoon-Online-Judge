#include <cstdio>
#include <algorithm>
#define MAX 200001

using namespace std;

struct Ball
{
  int color, size, index;
};
bool cmpSize(const Ball &a, const Ball &b)
{
  return a.size < b.size;
}
Ball ball[MAX];
int colorSum[MAX];
int sums[MAX];
int N, totalSum, j=1;

int main()
{
  scanf("%d",&N);
  for(int i=1; i < N+1; i++)
  {
    scanf("%d %d",&ball[i].color,&ball[i].size);
    ball[i].index = i;
  }
  sort(ball+1, ball+N+1, cmpSize);

  for(int i=1; i < N+1; i++)
  {
    for(; ball[i].size != ball[j].size; j++)
    {
      totalSum += ball[j].size;
      colorSum[ball[j].color] += ball[j].size;
    }
    sums[ball[i].index] = totalSum - colorSum[ball[i].color];
  }
  for(int i=1; i < N+1; i++)
    printf("%d\n",sums[i]);

  return 0;
}