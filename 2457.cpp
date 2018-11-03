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

  int lastTo = 301, flag = 0, currentMaxLastTo = 0, ans = 0, i = -1;
  while(lastTo <= 1130 && i < N)
  {
    flag = 0, i++;
    for(int j = i; j < N; j++)
    {
      if (flowers[j].from > lastTo) break;
      if (currentMaxLastTo < flowers[j].to) {
        currentMaxLastTo = flowers[j].to;
        flag = 1;
        i = j;
      }
    }
    
    if (flag) {
      lastTo = currentMaxLastTo;
      ans++;
    } else {
      printf("0");
      return 0;
    }
  }

  printf("%d\n", ans);

  return 0;
}