#include <cstdio>
#include <deque>

#define MAX 5000010

using namespace std;

int N, L, a[MAX];
deque<int> dq;

int main(){
  scanf("%d %d", &N, &L);
  for(int i=0; i<N; i++) {
    scanf("%d", &a[i]);
    if(i == 0) {
      dq.push_back(a[i]);
    } else {
      while(dq.size() > 0 && a[i] < dq.back()) {
        dq.pop_back();
      }
      dq.push_back(a[i]);
    }
    if(i-L >= 0 && a[i-L] == dq.front()) {
      dq.pop_front();
    }
    printf("%d ", dq.front());
  }
}