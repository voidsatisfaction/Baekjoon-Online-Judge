#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> pos;

int main()
{
  scanf("%d %d", &N, &C);
  for (int i = 0; i < N; i++)
  {
    int x;
    scanf("%d", &x);
    pos.push_back(x);
  }

  sort(pos.begin(), pos.end());

  int left = 1;
  int right = pos[N-1] - pos[0];
  int ans;
  while(left <= right)
  {
    int mid = (left + right) / 2;
    int start = pos[0];
    int counts = 1;
    for (int i = 1; i < N; i++)
    {
      if(pos[i] - start >= mid) {
        counts++;
        start = pos[i];
      }
    }

    if(counts >= C) {
      ans = mid;
      left = mid + 1;
    } else {
      right = mid -1;
    }
  }

  printf("%d\n", ans);
  return 0;
}