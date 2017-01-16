#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
typedef long long ll;

struct Query
{
  int low, high, index;
};
vector<Query> queries;

Query query;
ll array_power,ans[1000001];
int N,T,sq,block1,block2,A[1000001],subA[1000001];

int cmpFunc(const Query &query1, const Query &query2)
{
  sq = sqrt(T);
  block1 = query1.low / sq;
  block2 = query2.low / sq;
  return (block1 == block2) ? query1.high < query2.high : block1 < block2;
}

void add(int num)
{
  array_power += 1ll * (2*subA[num] + 1)*num;
  ++subA[num];
}

void subtract(int num)
{
  array_power -= 1ll * (2*subA[num] - 1)*num;
  --subA[num];
}

int main()
{
  scanf("%d %d",&N,&T);
  for(int i=1; i <= N; i++)
    scanf(" %d",&A[i]);

  for(int i=1; i <= T; i++)
  {
    scanf("%d %d",&query.low,&query.high);
    query.index = i;
    queries.push_back(query);
  }

  sort(queries.begin(),queries.end(),cmpFunc);

  int low_iter = 0;
  int high_iter = 0;
  int low_target, high_target;
  for(int i=0; i < queries.size(); i++)
  {
    query = queries[i];

    low_target = query.low;
    high_target = query.high;

    for(int j=high_iter; j > high_target; --j)
      subtract(A[j]);

    for(int j=high_iter + 1; j <= high_target; ++j)
      add(A[j]);

    for(int j=low_iter - 1; j >= low_target; --j)
      add(A[j]);
    
    for(int j=low_iter; j < low_target; ++j)
      subtract(A[j]);

    ans[query.index] = array_power;

    low_iter = low_target;
    high_iter = high_target;
  }
  
  for(int i=1; i <= T; i++)
    printf("%lld\n",ans[i]);

  return 0;
}