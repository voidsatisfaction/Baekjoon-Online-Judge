#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100001
#define MAX_MIN 2000000001

vector<int> a;
int N, minVal=MAX_MIN, ans[2];

int abs(int a)
{
  return a < 0 ? -a : a;
}

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    int t;
    scanf("%d", &t);
    a.push_back(t);
  }

  sort(a.begin(), a.end());

  int i = 0;
  int j = N-1;
  bool stop = false;
  while(i < j)
  {
    int v = a[i] + a[j];

    if(abs(v) < minVal) {
      minVal = abs(v);
      ans[0] = a[i];
      ans[1] = a[j];
    }

    if(v > 0) {
      j--;
    } else if(v < 0) {
      i++;
    } else {
      stop = true;
    }

    if(stop)
      break;
  }
  printf("%d %d\n", ans[0], ans[1]);
  return 0;
}