#include <cstdio>
#include <cstdlib>
#include <cmath>

int T;
double px1, py1, px2, py2, r1, r2;

double distance(double px1, double py1, double px2, double py2)
{
  return sqrt(pow(px1 - px2, 2) + pow(py1 - py2, 2));
}

int intersectionPointNums()
{
  if (px1 == px2 && py1 == py2) {
    if (r1 == r2) {
      return -1;
    }
    return 0;
  }

  double d = distance(px1, py1, px2, py2);

  if (d < abs(r1 - r2) || d > r1 + r2) {
    return 0;
  }

  if (d == abs(r1 - r2) || d == r1 + r2) {
    return 1;
  }

  if (d < r1 + r2) {
    return 2;
  }
}

int main()
{
  scanf("%d", &T);
  while(T--)
  {
    scanf("%lf %lf %lf %lf %lf %lf", &px1, &py1, &r1, &px2, &py2, &r2);
    printf("%d\n", intersectionPointNums());
  }

  return 0;
}
