#include <cstdio>

#define MAX_N 101

int T, dp_f[MAX_N][MAX_N], dp_g[MAX_N][MAX_N];

int f(int n, int k);
int g(int n, int k);

int f(int n, int k)
{
  if (n <= k){
    return 0;
  } else if (dp_f[n][k] > 0){
    return dp_f[n][k];
  } else {
    dp_f[n][k] = f(n-1, k) + g(n-1, k);
    return dp_f[n][k];
  }
}

int g(int n, int k)
{
  if (n < k){
    return 0;
  } else if (n == k){
    return 1;
  } else if (dp_g[n][k] > 0){
    return dp_g[n][k];
  } else {
    dp_g[n][k] = f(n-1, k) + g(n-1, k-1);
    return dp_g[n][k];
  }
}

int main()
{
  scanf("%d", &T);
  dp_g[1][0] = 1;
  dp_g[2][0] = 2;
  for (int i = 3; i < MAX_N; i++)
    dp_g[i][0] = dp_g[i-1][0] + dp_g[i-2][0];
  while (T--)
  {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", f(n, k));
  }
  return 0;
}