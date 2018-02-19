#include <cstdio>
#include <vector>

#define MAX_V 20001

using namespace std;

vector<vector<int> > adjList(MAX_V);
int colored[MAX_V];
int K, V, E;

// color is 0, 1, 2
bool isBipartite(int v, int color)
{
  bool ans = true;
  colored[v] = color;
  for (int i = 0; i < adjList[v].size(); i++){
    int w = adjList[v][i];
    if (color == colored[w]){
      return false;
    } else if (colored[w] == 0){
      ans = (color == 1) ? isBipartite(w, 2) : isBipartite(w, 1);
      if (!ans) {
        return ans;
      }
    }
  }
  return ans;
}

int main()
{
  scanf("%d", &K);
  while (K--){
    scanf("%d %d", &V, &E);
    for (int i = 0; i < MAX_V; i++)
      adjList[i].clear();
    for (int i = 0; i < MAX_V; i++)
      colored[i] = 0;
    for (int i = 0; i < E; i++){
      int a, b;
      scanf("%d %d", &a, &b);
      adjList[a].push_back(b);
      adjList[b].push_back(a);
    }

    bool ans = true;
    for (int i = 0; i < V; i++){
      if (!colored[i]) {
        ans = isBipartite(i, 1);
        if (!ans) break;
      }
    }
    if (ans){
      printf("%s\n", "YES");
    } else {
      printf("%s\n", "NO");
    }
  }
  return 0;
}