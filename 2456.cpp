#include <cstdio>

int scoreComposition[4][4], scoreSum[4];
int N, a, b, c;

int compareScoreComposition3(int n1, int n2, int n3)
{
  if (scoreComposition[n1][3] > scoreComposition[n2][3] && scoreComposition[n1][3] > scoreComposition[n3][3]) {
    return n1;
  } else if (scoreComposition[n2][3] > scoreComposition[n1][3] && scoreComposition[n2][3] > scoreComposition[n3][3]) {
    return n2;
  } else if (scoreComposition[n3][3] > scoreComposition[n1][3] && scoreComposition[n3][3] > scoreComposition[n2][3]) {
    return n3;
  }
  return 0;
}

int compareScoreComposition(int n1, int n2)
{
  if (scoreComposition[n1][3] > scoreComposition[n2][3])
    return n1;
  if (scoreComposition[n1][3] < scoreComposition[n2][3])
    return n2;

  if (scoreComposition[n1][2] > scoreComposition[n2][2])
    return n1;
  if (scoreComposition[n2][2] > scoreComposition[n1][2])
    return n2;

  return 0;
}

int main()
{
  scanf("%d", &N);
  for(int i = 0; i < N; i++)
  {
    scanf("%d %d %d", &a, &b, &c);
    scoreSum[1] += a;
    scoreSum[2] += b;
    scoreSum[3] += c;

    scoreComposition[1][a]++;
    scoreComposition[2][b]++;
    scoreComposition[3][c]++;
  }

  int num = 0, score = 0, cmpResult = 0;
  if (scoreSum[1] == scoreSum[2] && scoreSum[2] == scoreSum[3]) {
    num = compareScoreComposition3(1, 2, 3);
    score = scoreSum[1];
  } else if (scoreSum[1] > scoreSum[2] && scoreSum[1]> scoreSum[3]) {
    num = 1;
    score = scoreSum[1];
  } else if (scoreSum[2] > scoreSum[1] && scoreSum[2] > scoreSum[3]) {
    num = 2;
    score = scoreSum[2];
  } else if (scoreSum[3] > scoreSum[1] && scoreSum[3] > scoreSum[2]) {
    num = 3;
    score = scoreSum[3];
  } else if (scoreSum[1] == scoreSum[2] && scoreSum[1] > scoreSum[3]) {
    cmpResult = compareScoreComposition(1, 2);
    num = cmpResult;
    score = scoreSum[1];
  } else if (scoreSum[2] == scoreSum[3] && scoreSum[2] > scoreSum[1]) {
    cmpResult = compareScoreComposition(2, 3);
    num = cmpResult;
    score = scoreSum[2];
  } else if (scoreSum[3] == scoreSum[1] && scoreSum[3] > scoreSum[2]) {
    cmpResult = compareScoreComposition(1, 3);
    num = cmpResult;
    score = scoreSum[3];
  }

  printf("%d %d\n", num, score);

  return 0;
}