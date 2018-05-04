#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

string target, word;
int targetCharTable[129], wordCharTable[129];
int N, ans;

int getEntropy()
{
  int entropy = 0;
  for(int i=0; i<129; i++)
    entropy += abs(targetCharTable[i] - wordCharTable[i]);
  return entropy;
}

int main()
{
  cin >> N;
  cin >> target;
  for(char c : target)
    targetCharTable[c]++;
  int targetLength = target.length();

  for(int i=0; i<N-1; i++) {
    cin >> word;
    memset(wordCharTable, 0, sizeof(wordCharTable));
    int wordLength = word.length();

    for(char c : word)
      wordCharTable[c]++;

    int entropy = getEntropy();

    if (targetLength == wordLength){
      if(entropy == 0 || entropy == 2)
        ans++;
    } else if (targetLength - wordLength == 1){
      if(entropy == 1)
        ans++;
    } else if (wordLength - targetLength == 1){
      if(entropy == 1)
        ans++;
    }
  }

  cout << ans << endl;

  return 0;
}