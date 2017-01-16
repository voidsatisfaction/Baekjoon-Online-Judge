#include <cstdio>
#include <math.h>

using namespace std;
typedef long long ll;

bool check[1000001];

bool is_prime(ll num)
{
  int sqrtNum = sqrt(num); 
  if(num == 2)
    return true;
  for(int i=3; i <= sqrtNum; i+=2)
  {
    if(num % i == 0)
      return false;
  }
  return true;
}

ll devide_ceil(ll a,ll b)
{
  return ((a % b == 0) ? a/b : a/b + 1);
}

int main()
{
  ll MIN, MAX;
  scanf("%lld %lld",&MIN,&MAX);
  ll cnt = MAX - MIN + 1;

  double sqrtMax = sqrt(MAX);
  for(ll i=2; i <= sqrtMax; i+=1)
  {
    if(is_prime(i))
    {
      ll sqPrime = i*i;
      ll sq_num = sqPrime * devide_ceil(MIN,sqPrime); 
      ll check_index = sq_num - MIN;
      while(sq_num <= MAX)
      {
        if(!check[check_index])
        {
          cnt--;
          check[check_index] = !check[check_index];
        }
        sq_num += sqPrime;
        check_index += sqPrime;
      }
    }
  }
  printf("%lld",cnt);

  return 0;
}