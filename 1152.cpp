#include <iostream>
#include <string>

using namespace std;

int main(){
  string str;
  int n = 0;
  bool s = true;
  getline(cin, str);
  for(int i=0; i < str.size(); i++)
  {
    char c = str[i];
    if(c == ' ')
      s = true;
    else if(c != ' ' && s)
    {
      ++n;
      s = false;
    }
  }
  cout << n << endl;
  return 0;
}