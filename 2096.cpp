#include <cstdio>
#include <algorithm>

using namespace std;

struct value {
  int max;
  int min;
};

int N, x, y, z;
value a[3];

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    scanf("%d %d %d", &x, &y, &z);
    int firstMax = max(a[0].max, a[1].max) + x;
    int firstMin = min(a[0].min, a[1].min) + x;

    int secondMax = max(max(a[0].max, a[1].max), a[2].max) + y;
    int secondMin = min(min(a[0].min, a[1].min), a[2].min) + y;

    int thirdMax = max(a[1].max, a[2].max) + z;
    int thirdMin = min(a[1].min, a[2].min) + z;
    
    a[0].max = firstMax; a[0].min = firstMin;
    a[1].max = secondMax; a[1].min = secondMin;
    a[2].max = thirdMax; a[2].min = thirdMin;
  }

  int maxValue = max(max(a[0].max, a[1].max), a[2].max);
  int minValue = min(min(a[0].min, a[1].min), a[2].min);

  printf("%d %d\n", maxValue, minValue);
  return 0;
}