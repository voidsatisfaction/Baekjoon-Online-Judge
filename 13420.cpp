#include <cstdio>

typedef long long ll;

ll N, a, b, ans, checkAns;
char x,y;

int main()
{
  scanf("%lld",&N);
  for(int i=0; i < N; i++)
  {
    scanf("%lld %c %lld %c %lld",&a,&x,&b,&y,&ans);
    switch(x){
      case '+':
        checkAns = a + b;
        break;
      case '-':
        checkAns = a - b;
        break;
      case '*':
        checkAns = a * b;
        break;
      case '/':
        checkAns = a / b;
      default:
        break;
    }
    printf("%s\n",(ans == checkAns) ? "correct" : "wrong answer");
  }
  return 0;
}