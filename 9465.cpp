#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 100000
int T,n;
int up[MAX], down[MAX], up_max[MAX], down_max[MAX];

int main()
{
  scanf("%d",&T);
  for(int i=0; i < T; i++)
  {
    scanf("%d",&n);
    for(int i=0; i < n; i++)
      scanf(" %d",&up[i]);
    for(int i=0; i < n; i++)
      scanf(" %d",&down[i]);
    
    if (n == 1){
      printf("%d\n",max(up[0],down[0]));
    } else if (n == 2){
      printf("%d\n",max((up[0]+down[1]),(down[0]+up[1])));
    } else {
      up_max[0] = up[0]; down_max[0] = down[0];
      up_max[1] = down[0] + up[1]; down_max[1] = up[0] + down[1];
      for(int i=2; i < n; i++)
      {
        up_max[i] = max((down_max[i-1]+up[i]), (down_max[i-2]+up[i]));
        down_max[i] = max((up_max[i-1]+down[i]), (up_max[i-2]+down[i]));
      }
      printf("%d\n",max(up_max[n-1],down_max[n-1]));
    }
  }
  return 0;
}