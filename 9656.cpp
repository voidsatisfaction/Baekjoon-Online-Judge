#include <cstdio>

int N;

int main()
{
  scanf("%d", &N);
  if (N % 2 == 0) {
    printf("SK\n");
  } else {
    printf("CY\n");
  }
  return 0;
}