#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

string p, arrayString;
vector<int> numArray;
int T, n;

int main()
{
  scanf("%d\n", &T);
  while(T--)
  {
    numArray.clear();

    cin >> p;
    cin >> n;
    cin >> arrayString;

    int arrayStringLength = arrayString.size();

    int x = 0;
    for (int i = 1; i < arrayStringLength; i++) {
      char c = arrayString[i];
       // 숫자가 나오면 현재 수*10 한 뒤 더함
       if(c >= '0' && c <= '9')
          x = x*10 + c-'0';
       else{
         if(x > 0) numArray.push_back(x);
         x = 0;
         if(c == ']') break;
       }
    }

    bool frontActivated = true, error = false;
    int i = 0, j = numArray.size()-1;
    for (char command : p) {
      if (command == 'R') {
        frontActivated = !frontActivated;
      } else {
        if (frontActivated) {
          i++;
        } else {
          j--;
        }

        if (i >= j+2 || i >= numArray.size()+1 || j <= -2) {
          error = true;
          break;
        }
      }
    }

    string ans;
    ans.clear();

    if (error) {
      printf("error\n");
    } else {
      printf("[");
      if (frontActivated) {
        for (int k = i; k <= j; k++) {

          printf("%d", numArray[k]);
          if (k < j) {
            printf(",");
          }
        }
      } else {
        for (int k = j; k >= i; k--) {
          printf("%d", numArray[k]);
          if (k > i) {
            printf(",");
          }
        }
      }
      printf("]\n");
    }
  }
  return 0;
}
