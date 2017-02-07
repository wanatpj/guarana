#include <iostream>
using namespace std;

int main()
{
  int n,m,a,b,w,t,p,suma1=0,suma2=0;
  scanf("%d%d",&n,&m);
  for(int i=0;i<m;i++)
  {
    scanf("%d%d%d%d%d",&a,&b,&w,&t,&p);
    if(t==1 && p==0)
      suma1++;
    if(p==1 && t==0)
      suma2++;
  }
  if(suma1==suma2)
    printf("%d\n",suma1);
  else
    printf("NIE\n");
  return 0;
}