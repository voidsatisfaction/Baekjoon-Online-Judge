#include <cstdio>

int N;
int a[300], m[300];
int result;

void in()
{
  scanf("%d", &N);
  for(int i=0; i < N; i++)
    scanf("%d", &a[i]);
}

void sol()
{ 
  if(N<=2){
    for(int i=0; i < N; i++)
      result += a[i];
    printf("%d\n",result);
    return;
  }

  m[0] = a[0];
  m[1] = a[1] + a[0];
  int m1, m2;
  for(int i=2; i < N; i++)
  {
    m1 = m[i-2];
    m2 = ((i-3 >= 0) ? m[i-3] : 0) + a[i-1];
    m[i] = ((m2 > m1) ? m2 : m1) + a[i];
  }
  
  printf("%d\n",m[N-1]);
}

int main()
{
  in();
  sol();
  return 0;
}