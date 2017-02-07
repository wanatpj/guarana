#include <iostream>
using namespace std;

int tab[10001];
int dyn[10001];

int main()
{
  int z;
  scanf("%d",&z);
  for (int q=0;q<z;q++)
  {
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
      scanf("%d",&tab[i]);
    sort(tab+1,tab+1+n);
    dyn[1]=tab[1];
    dyn[2]=tab[2];
    dyn[3]=tab[1]+tab[2]+tab[3];
    for (int i=4;i<=n;i++)
      dyn[i]=min(dyn[i-2]+tab[1]+2*tab[2]+tab[i],dyn[i-1]+tab[1]+tab[i]);
    printf("%d\n",dyn[n]);
  }
  return 0;
}
