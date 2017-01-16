#include <cstdio>
typedef long long ll;

ll max_val;

ll knapsack(int N, ll W, ll price[], ll weight[])
{
  ll K[N+1][W+1];
  
  for(int i=0; i <= N; i++)
    K[i][0] = 0;

  for(ll w=0; w <= W; w++)
    K[0][w] = 0;

  for(int i=1; i <= N; i++)
  {
    for(ll w=1; w <= W; w++)
    {
      if(weight[i] > w)
        K[i][w] = K[i-1][w];
      else
      {
        ll selected = K[i-1][w-weight[i]] + price[i];
        ll unselected = K[i-1][w];
        K[i][w] = (selected > unselected) ? selected : unselected;
      }
    }
  }
  return K[N][W];
}

int main()
{
  int N;
  scanf("%d\n", &N);
  ll price[51];
  ll weight[51];
  ll W;
  for(int i=1; i <= N; i++)
    scanf("%lld %lld", &weight[i], &price[i]);
  
  
  scanf("%lld", &W);

    
  max_val = knapsack(N, W, price, weight);
  printf("%lld\n",max_val);
  
  return 0;
}