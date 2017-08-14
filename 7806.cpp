#include <cstdio>
#include <map>
#include <math.h>

using namespace std;

int n, k, ans;

map<int, int> decomp(int n) {
  map<int, int> result;
  int d = 2;
  double sqrtN = sqrt(n);
  while(n>1)
  {
    if(n % d == 0) {
      n = n/d;
      if(result.find(d) != result.end())
        result[d]++;
      else
        result[d] = 1;
    } else {
      d++;
    }
    if (d > sqrtN){
      result[n] = 1;
      break;
    }
  }
  return result;
}

int num_of_p(int n, int p, int comp)
{
  int i=1, t=0;
  while (p*i < n){
    t += (n / (p*i));
    i *= p;
    if (t >= comp)
      return comp;
  }
  return t;
}

int main()
{
  while(scanf("%d %d",&n,&k) != EOF){
    ans = 1;
    map<int, int> decompK = decomp(k);
    for (map<int, int>::iterator i = decompK.begin(); i != decompK.end(); i++)
      if (i->first <= n)
        ans *= pow(i->first, num_of_p(n, i->first, i->second)); 
    printf("%d\n",ans);
  }
  return 0;
}
