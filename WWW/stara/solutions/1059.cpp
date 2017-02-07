#include <iostream>
#include <cstdio>
using namespace std;

int tab [10003];

int main ()
{
  int z;
  scanf("%d", &z);
  while(z--)
  {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
      scanf("%d", &tab[i]);
    }
    sort(tab, tab+n);
    long long int czas;
    int k;
    if(n == 1)
    {
      czas = tab[0];
      k = 1;
    }
    else
    {
      czas = tab[1];
      k = 2;
    }
    if (n % 2 == 1) 
    {
	    czas += tab[2] + tab[0];
	    k++;
    }
    while (k < n) 
    {
	    if (tab[k] <= 2 * tab[1] - tab[0])
	    {
		    czas += tab[k] + tab[k+1] + 2 * tab[0];
      }
	    else
      {
        czas += tab[k+1] + 2 * tab[1] + tab[0];
      }
	    k += 2;
	 }
	 printf("%lld\n", czas);
  }
  system("pause");
  return 0;
}
