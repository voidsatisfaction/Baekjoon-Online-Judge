#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, ans;
vector<int> a;

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    int m;
    scanf("%d", &m);
    a.push_back(m);
  }

  sort(a.begin(), a.end());

  for (int i = 0; i < a.size(); i++)
  {
    ans += a[i] * (N - i);
  }

  printf("%d\n", ans);
  return 0;
}