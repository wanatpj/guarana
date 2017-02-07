#include <iostream>
using namespace std;

struct nub 
{
  int naw;
  int koszt;
  int dl;
};

nub tab[201][201];

int main()
{
  int z;
  scanf("%d",&z);
  for (int q=0;q<z;q++)
  {
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
      for (int j=i;j<=n;j++)
        tab[i][j].dl=tab[i][j].naw=tab[i][j].koszt=1000000000;
    for (int i=1;i<=n;i++)
    {
      scanf("%d",&tab[i][i].dl);
      tab[i][i].koszt=tab[i][i].naw=0;
    }
    for (int i=1;i<n;i++)
    {
      tab[i][i+1].dl=tab[i][i].dl+tab[i+1][i+1].dl;
      tab[i][i+1].koszt=tab[i][i+1].dl;
      tab[i][i+1].naw=0;
    }
    for (int k=2;k<n;k++)
      for (int p=1;p<=n-k;p++)
      {
        tab[p][p+k].dl=tab[p][p].dl+tab[p+1][p+k].dl;
        for (int i=p;i<p+k;i++)
	{
	  if(tab[p][i].koszt+tab[i+1][p+k].koszt+tab[p][p+k].dl<tab[p][p+k].koszt)
	  {
	    tab[p][p+k].koszt=tab[p][i].koszt+tab[i+1][p+k].koszt+tab[p][p+k].dl;
	    if(p+k>i+1)
	      tab[p][p+k].naw=tab[p][i].naw+tab[i+1][p+k].naw+1;
	    else if (p+k==i+1)
	      tab[p][p+k].naw=tab[p][i].naw+tab[i+1][p+k].naw;
	  }
	  else if(tab[p][i].koszt+tab[i+1][p+k].koszt+tab[p][p+k].dl==tab[p][p+k].koszt)
	  {
	    if(p+k>i+1 && tab[p][p+k].naw>tab[p][i].naw+tab[i+1][p+k].naw+1)
	        tab[p][p+k].naw=tab[p][i].naw+tab[i+1][p+k].naw+1;
	    else if(p+k==i+1 && tab[p][p+k].naw>tab[p][i].naw+tab[i+1][p+k].naw)
	        tab[p][p+k].naw=tab[p][i].naw+tab[i+1][p+k].naw;
	  }
	}
      }
    cout << tab[1][n].koszt << " " << tab[1][n].naw << endl;
  }
  return 0;
}
