#include <cstdio>
#include <vector>

typedef long long ll;

using namespace std;

vector<ll> trees;

ll height;
int N, M, low=0, high=2000000000;

bool needMoreTree(int cutHeight)
{
  ll heightSum = 0;
  for (ll tree : trees) {
    if (tree > cutHeight) {
      heightSum += (tree - cutHeight);
    }
  }

  return heightSum < M;
}

int main()
{
  scanf("%d %d", &N, &M);

  for (int i = 0; i < N; i++) {
    scanf("%lld", &height);
    trees.push_back(height);
  }

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (needMoreTree(mid)) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  printf("%d\n", high);

  return 0;
}
