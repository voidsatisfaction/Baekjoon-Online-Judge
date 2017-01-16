#include <cstdio>
#include <algorithm>
#define MAX 200001

using namespace std;

struct Ball
{
  int color, size, index, sum;
};
bool cmpSize(const Ball &a, const Ball &b)
{
  return a.size < b.size;
}
Ball ball[MAX];
int colorSum[MAX];
int sums[MAX];
int N, totalSum;

int main()
{
  scanf("%d",&N);
  for(int i=1; i < N+1; i++)
  {
    scanf("%d %d",&ball[i].color,&ball[i].size);
    ball[i].index = i;
    ball[i].sum = 0;
  }
  sort(ball+1, ball+N+1, cmpSize);

  for(int i=1; i < N+1; i++)
  {
    ball[i].sum = totalSum - colorSum[ball[i].color];
    for(int j=i-1; ball[i].size == ball[j].size && i > 1 ; j--)
    {
      if(ball[i].color != ball[j].color){
        ball[i].sum -= ball[j].size;
      }
    }
    totalSum += ball[i].size;
    colorSum[ball[i].color] += ball[i].size;
    sums[ball[i].index] = ball[i].sum;
  }
  for(int i=1; i < N+1; i++)
    printf("%d\n",sums[i]);

  return 0;
}