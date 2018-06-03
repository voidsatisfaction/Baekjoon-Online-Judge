#include <iostream>
#include <string>

#define MAX_N 41

using namespace std;

typedef long long ll;

string cards;
int N;
ll dp[MAX_N];

bool isPossible(int n, int l)
{
  if (cards[n] == '0')
    return false;
    
  if (l == 2 && cards[n] >= '4')
    return false;

  if (l == 2 && cards[n] == '3' && cards[n+1] >= '5')
    return false;

  return true;
}

ll getNums(int n)
{
  if (n >= N)
    return 1;

  if (dp[n] >= 0)
    return dp[n];

  if (n == N-1 && cards[n] > '0') {
    dp[n] = 1;
  } else if (n == N-1) {
    dp[n] = 0;
  } else {
    if(isPossible(n, 1) && isPossible(n, 2)) {
      dp[n] = getNums(n+1) + getNums(n+2);
    } else if(isPossible(n, 1)) {
      dp[n] = getNums(n+1);
    } else {
      dp[n] = 0;
    }
  }

  return dp[n];
}

int main()
{
  cin >> cards;

  N = cards.length();
  for(int i=0; i<=N; i++)
    dp[i] = -1;

  ll ans = getNums(0);

  cout << ans << endl;
  return 0;
}