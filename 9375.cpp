#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> clothCategoryNums;
string word, category;
int t, n, ans;

int main()
{
  cin >> t;
  while(t--)
  {
    cin >> n;
    clothCategoryNums.clear();
    ans = 1;
    
    for(int i=0; i<n; i++) {
      cin >> word;
      cin >> category;
      clothCategoryNums[category]++;
    }

    for(auto itr = clothCategoryNums.begin(); itr != clothCategoryNums.end(); itr++) {
      int nums = itr->second;
      ans *= (nums + 1);
    }
    ans--;

    printf("%d\n", ans);
  }
  return 0;
}