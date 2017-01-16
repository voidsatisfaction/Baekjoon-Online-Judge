#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string s;

int nextSum(int n)
{
  int t = 0;
  while(n)
  {
    t += (n % 10);
    n /= 10;
  }
  return t;
}

void getDegitalRoot(string s)
{
  int N = 0;
  for(int i=0; i < s.size(); i++)
  {
    N += (s[i] - '0');
  }
  while(N >= 10)
  {
    N = nextSum(N);
  }
  printf("%d\n",N);
}

int main()
{
  while(1)
  {
    cin >> s;
    if(s.size() == 1 && s[0] == '0') {
      break;
    }
    getDegitalRoot(s);
  }
  return 0;
}