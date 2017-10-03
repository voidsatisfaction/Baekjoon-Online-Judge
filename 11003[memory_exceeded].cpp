#include <cstdio>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int N, L;
priority_queue<int, vector<int>, greater<int> > pq;
queue<int> q;
map<int, int> willDelete;

int main() {
  scanf("%d %d", &N, &L);
  vector<int> ans;
  int n;

  for(int i=0; i<N; i++) {
    scanf("%d", &n);
    if (q.size() == L) {
      int k = q.front(); q.pop();
      while(true) {
        if (k == pq.top()) {
          pq.pop();
          break;
        } else if (willDelete.find(pq.top()) != willDelete.end() && willDelete[pq.top()] > 0) {
          willDelete[pq.top()]--;
          if (willDelete[pq.top()] == 0)
            willDelete.erase(pq.top());
          pq.pop();
        } else {
          if (willDelete.find(k) == willDelete.end()) {
            willDelete[k] = 1;
          } else {
            willDelete[k]++;
          }
          break;
        }
      }
    }
    q.push(n); pq.push(n);
    ans.push_back(pq.top());
  }

  for(int i=0; i < ans.size(); i++)
    printf("%d ", ans[i]);

  return 0;
}