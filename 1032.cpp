#include <cstdio>
#include <string>

using namespace std;

int main()
{
  int N, stringSize;
  char firstFile[51];
  scanf("%d",&N);
  scanf("%s",firstFile);

  string s = firstFile;
  stringSize = s.size();
  bool isRandom[51] = {0};
  char anotherFile[51];
  for(int i=0; i < N-1; i++)
  {
    scanf("%s",anotherFile);
    for(int j=0; j < stringSize; j++)
    {
      if(isRandom[j] == 1)
        continue;
      else if(firstFile[j] != anotherFile[j])
        isRandom[j] = 1;
    }
  }

  for(int i=0; i < stringSize; i++)
    printf("%c",(isRandom[i] ? '?' : firstFile[i]));
    
  return 0;
}