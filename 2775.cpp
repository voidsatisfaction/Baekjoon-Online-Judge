#include <cstdio>

int apartment[15][15];
int T, k, n;

int main()
{
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d", &k);
    scanf("%d", &n);

    for (int i=1; i < 15; i++) {
      for (int j=1; j < 15; j++) {
        apartment[i][j] = 0;
      }
    }

    for (int i = 1; i < 15; i++) {
      apartment[0][i] = i;
    }

    // solution 1
    for (int i = 1; i <= 14; i++) {
      for (int j = 1; j <= 14; j++) {
        for (int k = 1; k <= j; k++) {
          apartment[i][j] += apartment[i-1][k];
        }
      }
    }

    // solution 2 => dynamic programming

    printf("%d\n", apartment[k][n]);
  }
  return 0;
}
