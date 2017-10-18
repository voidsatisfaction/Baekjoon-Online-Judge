#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct segment {
  int start;
  int end;
};

vector<segment> segs;
int N;

bool comp(segment &seg1, segment &seg2)
{
  return seg1.start < seg2.start;
}

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    segment seg;
    seg.start = a;
    seg.end = b;
    segs.push_back(seg);
  }

  sort(segs.begin(), segs.end(), comp);

  int cacheEnd = segs[0].end;
  int counts = 1;
  for (int i = 1; i < N; i++)
  {
    int newEnd = segs[i].end;
    int newStart = segs[i].start;
    if (cacheEnd > newEnd){
      cacheEnd = newEnd;
    } else if (cacheEnd <= newStart){
      counts++;
      cacheEnd = newEnd;
    }
  }

  printf("%d\n", counts);
  return 0;
}