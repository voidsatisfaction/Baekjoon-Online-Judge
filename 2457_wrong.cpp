#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct flower {
  int from;
  int to;

  flower(int _from, int _to) {
    from = _from;
    to = _to;
  };
};

vector<flower> flowers;
int N, fromMonth, fromDate, toMonth, toDate, finishLastTo, lastTo, currentMaxLastTo, num;

bool compareByFrom(const flower &f1, const flower &f2)
{
  return f1.from < f2.from;
}

int monthDayToNumber(int month, int day)
{
  return 100 * month + day;
}

int main()
{
  scanf("%d", &N);
  for(int i = 0; i < N; i++)
  {
    scanf("%d %d %d %d", &fromMonth, &fromDate, &toMonth, &toDate);
    int fromNumber = monthDayToNumber(fromMonth, fromDate);
    int toNumber = monthDayToNumber(toMonth, toDate);

    flowers.push_back(flower(fromNumber, toNumber));
  }

  sort(flowers.begin(), flowers.end(), compareByFrom);

  lastTo = 301;
  currentMaxLastTo = 301;
  bool possible = false;
  for (flower f : flowers)
  {
    if (f.from >= lastTo && f.from <= currentMaxLastTo && lastTo != currentMaxLastTo) {
      num++;
      lastTo = currentMaxLastTo;
    } else if (f.from > currentMaxLastTo) {
      break;
    }

    if (f.to > currentMaxLastTo) {
      currentMaxLastTo = f.to;
      if (currentMaxLastTo > 1130) {
        num++;
        possible = true;
        break;
      }
    }
  }

  
  if (possible) {
    printf("%d\n", num);
  } else {
    printf("%d\n", 0);
  }

  return 0;
}