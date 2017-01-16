// 배운점
// 1. string s,e,ans; 이렇게 하나로 줄일 수 있음
// 2. vector로 하면 string보다 공간은 적게 사용하나 시간은 느림
// 3. 스택문제라고 굳이 스택을 할 필요는 없다.

#include <iostream>
#include <string>

using namespace std;
string s,e,ans;

bool is_explode(string &ans, string &e)
{
  if(ans[ans.size()-e.size()] != e[0])
    return false;
  
  for(unsigned int i=1; i < e.size(); i++)
  {
    if(e[i] != ans[(ans.size()-e.size()+i)])
      return false;
  }
  return true;
}

int main()
{
  cin >> s;
  cin >> e;
  for(unsigned int i=0; i < s.size(); i++)
  {
    ans.push_back(s[i]);
    if(ans.size() >= e.size() && is_explode(ans,e)){
      for(unsigned int i=0; i < e.size(); i++)
        ans.pop_back();
    }
  }
  if(ans.size() == 0){
    cout << "FRULA";
  } else {
    cout << ans;
  }
  return 0;
}