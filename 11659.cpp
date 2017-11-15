#include <cstdio>

#define N_MAX 100001

using namespace std;

int N, M, sums[N_MAX];

int main()
{
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++)
  {
    int n;
    scanf("%d", &n);
    if (i == 0){
      sums[i] = n;
    }
    sums[i] = sums[i-1] + n;
  }

  for (int i = 0; i < M; i++)
  {
    int from, to, val=0;
    scanf("%d %d", &from, &to);
    if (from == 1){
      val = sums[to-1];
    } else {
      val = sums[to-1] - sums[from-2];
    }
    printf("%d\n", val);
  }
  return 0;
}