#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 1001
#define INF 1987654321

using namespace std;

struct student {
  int classNum;
  int value;

  student(int _classNum, int _value) {
    classNum = _classNum;
    value = _value;
  }
};

int N, M, val, counts[MAX_N], p1, p2, minDiff = INF;
vector<student> students;

bool sortByValue(const student& s1, const student& s2)
{
  return s1.value < s2.value;
}

bool includeAllClass()
{
  for(int i = 1; i <= N; i++)
    if (counts[i] == 0)
      return false;
  
  return true;
}

int main()
{
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      scanf("%d", &val);
      students.push_back(student(i+1, val));
    }
  }

  sort(students.begin(), students.end(), sortByValue);

  counts[students[p1].classNum]++;
  while (p2 <= p1)
  {
    student s1 = students[p1];
    student s2 = students[p2];

    if (!includeAllClass()) {
      p1++;
      if (p1 >= students.size())
        break;
      
      student s3 = students[p1];
      counts[s3.classNum]++;
      continue;
    }

    if (s1.value - s2.value < minDiff) {
      minDiff = s1.value - s2.value;
      if (minDiff == 0)
        break;
    }

    counts[s2.classNum]--;
    p2++;
  }

  printf("%d\n", minDiff);
  
  return 0;
}