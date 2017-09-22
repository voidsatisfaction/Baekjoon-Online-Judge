#include <cstdio>
#include <queue>
#define MAX 501

using namespace std;

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    int N, M;
    int input[MAX]={0}, inDegree[MAX]={0}, ans[MAX]={0};
    bool adjMatrix[MAX][MAX]={false}; // 초기화 필수!!

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
      scanf("%d", &input[i]);
    
    for(int i = 0; i < N; i++) {
      for(int j = i+1; j < N; j++) {
        adjMatrix[input[i]][input[j]] = true;
        inDegree[input[j]]++;
      }
    }

    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      if(adjMatrix[a][b]) {
        adjMatrix[a][b] = false;
        adjMatrix[b][a] = true;
        inDegree[a]++;
        inDegree[b]--;
      } else {
        adjMatrix[a][b] = true;
        adjMatrix[b][a] = false;
        inDegree[a]--;
        inDegree[b]++; 
      }
    }

    queue<int> que;
    
    for(int i = 1; i < N+1; i++)
      if(inDegree[i] == 0)
        que.push(i);

    bool flag = true;
    for(int i = 0; i < N; i++)
    {
      if(que.empty()) {
        flag = false;
        printf("%s\n", "IMPOSSIBLE");
        break;
      }
      if(que.size() > 1) {
        flag = false;
        printf("%s\n", "?");
        break;
      }

      int x = que.front();
      que.pop();
      ans[i] = x;
      for(int j = 1; j < N+1; j++)
      {
        if(adjMatrix[x][j]) {
          inDegree[j]--;
          adjMatrix[x][j] = false;
          if (inDegree[j] == 0){
            que.push(j);
          }
        }
      }
    }

    if(flag) {
      for(int i = 0; i < N; i++) {
        printf("%d ", ans[i]);
      }
      printf("\n");
    }
  }
  return 0;
}