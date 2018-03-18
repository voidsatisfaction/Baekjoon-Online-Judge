#include <cstdio>

int n, a, ans;

int main()
{
  scanf("%d", &n);
  for(int i=0; i<5; i++) {
    scanf("%d", &a);
    if(n == a)
      ans++;
  }
  printf("%d\n", ans);
  return 0;
}