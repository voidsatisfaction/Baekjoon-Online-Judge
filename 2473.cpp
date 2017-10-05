#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long ll;

#define MAX_VAL 3000000010

using namespace std;

int N;
ll minVal = MAX_VAL;
vector<ll> a;

ll abss(ll n) {
  return n < 0 ? -n : n;
}

int main(){
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    ll j;
    scanf("%lld", &j);
    a.push_back(j);
  }
  
  sort(a.begin(), a.end());

  int x,y,z;
  for(int i = 0; i < N-2; i++)
  {
    int j = i+1;
    int k = N-1;
    while(j < k)
    {
      ll v = a[i]+a[j]+a[k];
      if(abss(v) < minVal){
        minVal = abss(v);
        x = i; y = j; z = k;
      }

      if(v <= 0) {
        j++;
      } else {
        k--;
      }
    }
  }

  printf("%lld %lld %lld\n", a[x], a[y], a[z]);
  return 0;
}