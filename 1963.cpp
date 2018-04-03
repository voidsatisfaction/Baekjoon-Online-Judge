#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

#define MAX_N 10000

using namespace std;

vector<vector<int> > adjList(MAX_N);
vector<int> primes;
int T, s, d;

bool isPrime(int num)
{
  if (num == 1)
    return false;

  for(int i=2; i*i <= num; i++) {
    if(num % i == 0) {
      return false;
    }
  }
  return true;
}

bool differentOnlyOneDigit(int a, int b)
{
  int same = 0;
  for(int i=0; i<4; i++) {
    if((a % 10) == (b % 10)) {
      same++;
    }
    a /= 10;
    b /= 10;
  }

  if (same == 3)
    return true;
  
  return false;
}

int bfs(int s, int d)
{
  int lv = 0;
  if (s == d)
    return lv;
  bool marked[MAX_N];
  memset(marked, 0, sizeof(marked));
  queue<int> q;

  q.push(s);
  marked[s] = true;

  while (!q.empty())
  {
    int size = q.size();
    while (size--)
    {
      int prime = q.front(); q.pop();
      for (int nextPrime : adjList[prime])
      {
        if (!marked[nextPrime])
        {
          if (nextPrime == d)
            return ++lv;
          marked[nextPrime] = true;
          q.push(nextPrime);
        }
      }
    }
    lv++;
  }
  return -1;
}

int main()
{
  for(int i=1000; i<MAX_N; i++) {
    if (isPrime(i)) {
      primes.push_back(i);
    }
  }

  for(int i=1; i<primes.size(); i++) {
    for(int j=i-1; j>=0; j--) {
      if (differentOnlyOneDigit(primes[i], primes[j])) {
        adjList[primes[i]].push_back(primes[j]);
        adjList[primes[j]].push_back(primes[i]);
      }
    }
  }

  scanf("%d", &T);
  while(T--)
  {
    scanf("%d %d", &s, &d);
    int ans = bfs(s, d);
    
    if (ans >= 0) {
      printf("%d\n", ans);
    } else {
      printf("Impossible\n");
    }
  }
  return 0;
}