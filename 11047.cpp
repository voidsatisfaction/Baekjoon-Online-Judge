#include <cstdio>
#include <vector>

using namespace std;

int N, K, counts;
vector<int> coins;

int main()
{
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; i++)
  {
    int c;
    scanf("%d", &c);
    coins.push_back(c);
  }

  for (int i = coins.size() - 1; i >= 0; i--)
  {
    int c = coins[i];
    counts += K / c;
    K %= c;
  }

  printf("%d\n", counts);
  return 0;
}