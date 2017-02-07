#include <iostream>
using namespace std;

struct nub
{
  short int x;
  short int y;
};

short int tab[1001][1001];
bool odwiedzony[1001][1001];
nub kto[1001][1001];
nub wypis[1001];
bool glo;
short int n;

void zapusc(short int x, short int y,nub pom)
{
  odwiedzony[x][y]=1;
  kto[x][y]=pom;
  pom.x=x;
  pom.y=y;
  if(tab[x][y]==5 || glo)
  {
    glo=1;
    return;
  }
  else if(tab[x][y]==0)
  {
    if(x-1>0 && !odwiedzony[x-1][y]) zapusc(x-1,y,pom);
    if(y-1>0 && !odwiedzony[x][y-1]) zapusc(x,y-1,pom);
    if(x+1<=n && !odwiedzony[x+1][y]) zapusc(x+1,y,pom);
    if(y+1<=n && !odwiedzony[x][y+1]) zapusc(x,y+1,pom);
  }
  else if(tab[x][y]==1 && x-1>0 && !odwiedzony[x-1][y]) zapusc(x-1,y,pom);
  else if(tab[x][y]==2 && y-1>0 && !odwiedzony[x][y-1]) zapusc(x,y-1,pom);
  else if(tab[x][y]==3 && x+1<=n && !odwiedzony[x+1][y]) zapusc(x+1,y,pom);
  else if(tab[x][y]==4 && y+1<=n && !odwiedzony[x][y+1]) zapusc(x,y+1,pom);
}

int main()
{ 
  short int z;
  scanf("%hd",&z);
  for (int q=0;q<z;q++)
  {
    scanf("%hd",&n);
    glo=0;
    for (int i=1;i<=n;i++)
    {
      wypis[i].x=wypis[i].y=0;
      for (int j=1;j<=n;j++)
        tab[i][j]=odwiedzony[i][j]=kto[i][j].x=kto[i][j].y=0;
    }
    nub koniec;
    string napis;
    for (int i=n;i>0;i--)
    {   
      cin >> napis;
      for (int j=1;j<=n;j++)
      {
        if(napis[j-1]=='.') tab[i][j]=0;
	else if(napis[j-1]=='d') tab[i][j]=1;
	else if(napis[j-1]=='l') tab[i][j]=2;
	else if(napis[j-1]=='g') tab[i][j]=3;
	else if(napis[j-1]=='p') tab[i][j]=4;
	else if(napis[j-1]=='k') 
	{
	  tab[i][j]=5;
          koniec.x=i;
	  koniec.y=j;
	}
      }
    }
    nub pom;
    pom.x=pom.y=0;
    zapusc(1,1,pom);
    int ile=0;
    while(koniec.x!=0 && koniec.y!=0)
    {
      ile++;
      wypis[ile]=koniec;
      koniec=kto[koniec.x][koniec.y];
    }
    printf("%d\n",ile);
    for (int i=ile;i>0;i--)
      printf("%hd %hd\n",wypis[i].y,wypis[i].x);
  }
  return 0;
}
