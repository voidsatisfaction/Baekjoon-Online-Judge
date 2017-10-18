#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> subSeqMax;
vector<int> subSeqNum;
int N;

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    int n, subSeqNumMax=0, subSeqNumMaxIndex=0;
    scanf("%d", &n);
    for (int j = 0; j < subSeqMax.size(); j++)
    {
      if (n > subSeqMax[j]){
        if (subSeqNum[j] > subSeqNumMax) {
          subSeqNumMax = subSeqNum[j];
          subSeqNumMaxIndex = j;
        }
      }
    }
    subSeqMax.push_back(n);
    if (subSeqNumMax > 0) {
      subSeqNum.push_back(subSeqNum[subSeqNumMaxIndex] + 1);
    } else {
      subSeqNum.push_back(1); 
    }
  }

  int length;
  for (int i = 0; i < subSeqNum.size(); i++)
    length = max(length, subSeqNum[i]);

  printf("%d\n", length);
  return 0;
}