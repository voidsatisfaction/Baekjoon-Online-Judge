#include <cstdio>

int T,P,M,F,C,moreChicken,coupons;

int main()
{
  scanf("%d",&T);
  for(int i=0; i < T; i++)
  {
    scanf("%d %d %d %d",&P,&M,&F,&C);
    moreChicken = 0;
    coupons = (M / P) * C;
    do
    {
      coupons = (coupons / F) * C + (coupons % F);
      moreChicken += (coupons / F);
    } while (coupons >= F);
    printf("%d\n",moreChicken);
  }
  return 0;
}