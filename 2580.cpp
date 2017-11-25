#include <cstdio>
#include <vector>

using namespace std;

#define N 9

struct noNum {
  int i;
  int j;
};

int sudoku[N][N];
vector<noNum> noNumList;
bool stop;

bool checkHorizon(int num, int i, int j)
{
  for (int k = 0; k < 9; k++)
  {
    if (sudoku[i][k] == num){
      return false;
    }
  }
  return true;
}

bool checkVertical(int num, int i, int j)
{
  for (int k = 0; k < 9; k++)
  {
    if (sudoku[k][j] == num){
      return false;
    }
  }
  return true;
}

bool checkBox(int num, int i, int j)
{
  int boxStartI = (i / 3) * 3;
  int boxStartJ = (j / 3) * 3;
  for (int l = boxStartI; l < boxStartI + 3; l++)
  {
    for (int m = boxStartJ; m < boxStartJ + 3; m++)
    {
      if (sudoku[l][m] == num){
        return false;
      }
    }
  }
  return true;
}

void backTrack(int depth, int fromI, int fromJ)
{
  if (depth == noNumList.size()){
    stop = true;
    return;
  }

  for (int i = 1; i <= 9; i++)
  {
    if (checkHorizon(i, fromI, fromJ) && checkVertical(i, fromI, fromJ) && checkBox(i, fromI, fromJ)){
      sudoku[fromI][fromJ] = i;
      int nextI = noNumList[depth+1].i;
      int nextJ = noNumList[depth+1].j;
      backTrack(depth + 1, nextI, nextJ);
      if (stop) return;
      sudoku[fromI][fromJ] = 0;
    }
  }
}

int main()
{
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      scanf("%d", &sudoku[i][j]);
      if (sudoku[i][j] == 0){
        noNum nn; nn.i = i; nn.j = j;
        noNumList.push_back(nn);
      }
    }
  }

  int startI = noNumList[0].i;
  int startJ = noNumList[0].j;
  backTrack(0, startI, startJ);

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      printf("%d ", sudoku[i][j]);
    }
    printf("\n");
  }
}
