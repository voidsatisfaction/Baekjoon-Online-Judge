#include <cstdio>

struct score {
  int y;
  int k;
};

int T;

int main()
{
  scanf("%d", &T);
  for(int i=0; i < T; i++) {
    score s;
    s.y = 0;
    s.k = 0;
    for(int j=0; j < 9; j++) {
      int a, b;
      scanf("%d %d", &a, &b);
      s.y += a;
      s.k += b;
    }
    if(s.y == s.k) {
      printf("Draw\n");
    } else if(s.y > s.k) {
      printf("Yonsei\n");
    } else {
      printf("Korea\n");
    }
  }
  return 0;
}
