#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_M 1001
#define N 10

int cache[MAX_M], sum, n, maxFreq, maxFreqNum;

int main()
{
  for(int i=0; i<N; i++) {
    scanf("%d", &n);
    sum += n;
    cache[n]++;
  }

  for(int i=0; i<MAX_M; i++) {
    if (cache[i] > maxFreq) {
      maxFreq = cache[i];
      maxFreqNum = i;
    }
  }

  printf("%d\n", sum / N);
  printf("%d\n", maxFreqNum);
  return 0;
}