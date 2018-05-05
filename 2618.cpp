#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

#define INF 1987654321
#define MAX_W 1001

using namespace std;

struct place {
  int y;
  int x;
  place(int _y, int _x) {
    y = _y;
    x = _x;
  }
};

vector<place> places;
vector<int> trace;
int N, W, y, x, dp[MAX_W][MAX_W];

int getDist(place p1, place p2)
{
  return abs(p1.y - p2.y) + abs(p1.x - p2.x);
}

int getMinDist(int p1, int p2)
{
  int w = max(p1, p2) - 1;
  if (w == W) {
    return 0;
  }

  if(dp[p1][p2] != INF)
    return dp[p1][p2];

  place place1 = places[p1];
  place place2 = places[p2];
  place newPlace = places[w+2];

  int minDist1 = getMinDist(w+2, p2) + getDist(place1, newPlace);
  int minDist2 = getMinDist(p1, w+2) + getDist(place2, newPlace);

  dp[p1][p2] = min(
    minDist1,
    minDist2
  );

  return dp[p1][p2];
}

void getTrace(int p1, int p2)
{
  int w = max(p1, p2) - 1;
  if (w == W)
    return;

  place place1 = places[p1];
  place place2 = places[p2];
  place newPlace = places[w + 2];

  int minDist1 = getMinDist(w+2, p2) + getDist(place1, newPlace);
  int minDist2 = getMinDist(p1, w+2) + getDist(place2, newPlace);
  if (minDist1 < minDist2) {
    trace.push_back(1);
    getTrace(w+2, p2);
  } else {
    trace.push_back(2);
    getTrace(p1, w+2);
  }
}

int main()
{
  scanf("%d", &N);
  scanf("%d", &W);
  places.push_back(place(1, 1));
  places.push_back(place(N, N));
  for(int i=0; i<W; i++) {
    scanf("%d %d", &y, &x);
    places.push_back(place(y, x));
  }

  for(int i=0; i<MAX_W; i++)
    for(int j=0; j<MAX_W; j++)
      dp[i][j] = INF;

  int ans = getMinDist(0, 1);

  printf("%d\n", ans);

  getTrace(0, 1);

  for(int t : trace) {
    printf("%d\n", t);
  }
  return 0;
}