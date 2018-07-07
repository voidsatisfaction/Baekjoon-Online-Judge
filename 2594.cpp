#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct timeScope {
  int from;
  int to;
  timeScope(int _f, int _t)
  {
    from = _f;
    to = _t;
  }
};

const int stdHour = 10;
vector<timeScope> timeTable;
int N, st, ed, absoluteSt, absoluteEd, lastAbsoluteTime, maxInterval;

int convertAbsoluteMinute(int hhmm)
{
  int minute = hhmm % 100;
  int hour = hhmm / 100;

  int absoluteHour = hour - stdHour;

  return absoluteHour * 60 + minute;
}

bool cmpFromAsc(const timeScope &t1, const timeScope &t2)
{
  return (t1.from == t2.from) ? (t1.to < t2.to) : (t1.from < t2.from);
}

int main()
{
  scanf("%d", &N);
  for(int i=0; i<N; i++) {
    scanf("%d %d", &st, &ed);
    absoluteSt = convertAbsoluteMinute(st) - 10;
    absoluteEd = convertAbsoluteMinute(ed) + 10;
    if (absoluteEd < 0 || absoluteSt > 720) {
      continue;
    }
    
    timeTable.push_back(timeScope(absoluteSt, absoluteEd));
  }
  timeTable.push_back(timeScope(720, -1));

  sort(timeTable.begin(), timeTable.end(), cmpFromAsc);

  for(timeScope ts : timeTable)
  {
    int timeDiff = ts.from - lastAbsoluteTime;
    maxInterval = max(timeDiff, maxInterval);
    if(ts.to > lastAbsoluteTime) {
      lastAbsoluteTime = ts.to;
    }
  }

  printf("%d\n", maxInterval);
  return 0;
}