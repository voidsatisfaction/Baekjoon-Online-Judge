#include <cstdio>
#include <string>

using namespace std;

#define mod 1000000

int main()
{
  char input[5001];
  int dp[5001] = {};
  int inputSize;
  scanf("%s", input);
  string s = input;
  inputSize = s.size();
  
  dp[0] = 1;
  dp[1] = 1;
  int j, f;
  for(int i=2; i <= inputSize; i++)
  {
    j = i - 1;
    if(input[j] > '0')
      dp[i] = dp[i-1];
    
    f = (input[j-1] - '0') * 10 + (input[j] - '0');

    if(10 <= f && f <= 26)
      dp[i] = (dp[i] + dp[i-2]) % mod;
  }

  printf("%d\n", dp[inputSize]);
  return 0;
}