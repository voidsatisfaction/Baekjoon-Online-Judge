#include <cstdio>
#include <vector>

using namespace std;

#define MAX_K 10001

vector<int> coins;
int n, k, val[MAX_K];

int main()
{
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++)
  {
    int c;
    scanf("%d", &c);
    coins.push_back(c);
  }

  val[0] = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= k; j++)
    {
      int coin = coins[i];
      if (coin <= j){
        val[j] += val[j-coin];
      }
    }
  }

  printf("%d\n", val[k]);
  return 0;
}