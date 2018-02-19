#include <cstdio>
#include <stack>
#include <queue>

#define MAX_K 124

using namespace std;

struct trace {
  int from;
  int to;
  trace(){ from=0, to=0; }
  trace(int _from, int _to){ from=_from, to=_to; }
};

queue<trace> traceQueue;
stack<int> stackL;
stack<int> stackR;
bool state[MAX_K];
int N, n, a, K, distTop;

int main()
{
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &a);
    stackL.push(a);
  }
  distTop = N;
  n = N;

  while (distTop != 1) {
    if (state[n]){
      // stackR
      while (stackR.top() != n) {
        traceQueue.push(trace(2, 1));
        int rTop = stackR.top(); stackR.pop();
        stackL.push(rTop);
        state[rTop] = false;
      }
      traceQueue.push(trace(2, 3));
      int rTop = stackR.top(); stackR.pop();
      distTop = rTop;
    } else {
      // stackL
      while (stackL.top() != n) {
        traceQueue.push(trace(1, 2));
        int lTop = stackL.top(); stackL.pop();
        stackR.push(lTop);
        state[lTop] = true;
      }
      traceQueue.push(trace(1, 3));
      int lTop = stackL.top(); stackL.pop();
      distTop = lTop;
    }
    n--;
  }
  if (N == 1){
    traceQueue.push(trace(1, 3));
  }

  int size = traceQueue.size();
  printf("%d\n", size);
  for (int i = 0; i < size; i++){
    trace tr = traceQueue.front(); traceQueue.pop();
    printf("%d %d\n", tr.from, tr.to);
  }
  return 0;
}