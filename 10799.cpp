#include <iostream>
#include <string>

using namespace std;

#define MAX_N 100001

string fields;
int stackTop, ans;

int main()
{
  cin >> fields;
  
  int i=0;
  while (i < fields.size())
  {
    if (fields[i] == '(') {
      if (fields[i+1] == ')') {
        // raser
        ans += stackTop;
        i += 2;
        continue;
      }
      // add stack
      stackTop++;
    } else {
      stackTop--;
      ans++;
    }
    i++;
  }
  cout << ans;
  return 0;
}