#include <iostream>
#include <cstdio>
using namespace std;

struct wspol{
  int a;
  int b;
};

struct aaa{
  char x;
  bool m;
};

aaa tab[1002][1002];
int n;
wspol kk;
wspol wynik[1100000];

int main()
{
  int z;
  scanf("%d", &z);
  while(z--)
  {
    int licznik = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n;)
      {
        char c;
        scanf("%c", &c);
        if(c == 'k') 
        {
          kk.a = i;
          kk.b = j;
        }
        if(c != '\n')
        {
          tab[i][j].m = false;
          tab[i][j++].x = c;
        }
      }
    }
    wynik[licznik].a = kk.a;
    wynik[licznik++].b = kk.b;
    tab[kk.a][kk.b].m = true;
    if(tab[kk.a+1][kk.b].x == '.' && kk.a+1 <= n-1)
    {
      kk.a += 1;
        tab[kk.a][kk.b].m = true;
        wynik[licznik].a = kk.a;
        wynik[licznik++].b = kk.b;
    }
    if(tab[kk.a-1][kk.b].x == '.' && kk.a-1 >= 0)
    {
      kk.a -= 1;
      tab[kk.a][kk.b].m = true;
      wynik[licznik].a = kk.a;
      wynik[licznik++].b = kk.b;
    }
    if(tab[kk.a][kk.b+1].x == '.' && kk.b+1 <= n-1)
    {
      kk.b += 1;
      tab[kk.a][kk.b].m = true;
      wynik[licznik].a = kk.a;
      wynik[licznik++].b = kk.b;
    }
    if(tab[kk.a][kk.b-1].x == '.' && kk.b-1 >= 0)
    {
      kk.b -= 1;
      tab[kk.a][kk.b].m = true;
      wynik[licznik].a = kk.a;
      wynik[licznik++].b = kk.b;
    }
    while(kk.a != n-1 || kk.b != 0)
    {
      if((tab[kk.a+1][kk.b].x == 'g' || tab[kk.a+1][kk.b].x == '.') && kk.a+1 <= n-1 && tab[kk.a+1][kk.b].m == false)
      {
        kk.a += 1;
        tab[kk.a][kk.b].m = true;
        wynik[licznik].a = kk.a;
        wynik[licznik++].b = kk.b;
      }
      else if((tab[kk.a-1][kk.b].x == 'd' || tab[kk.a-1][kk.b].x == '.') && kk.a-1 >= 0 && tab[kk.a-1][kk.b].m == false)
      {
        kk.a -= 1;
        tab[kk.a][kk.b].m = true;
        wynik[licznik].a = kk.a;
        wynik[licznik++].b = kk.b;
      }
      else if((tab[kk.a][kk.b+1].x == 'l' || tab[kk.a][kk.b+1].x == '.') && kk.b+1 <= n-1 && tab[kk.a][kk.b+1].m == false)
      {
        kk.b += 1;
        tab[kk.a][kk.b].m = true;
        wynik[licznik].a = kk.a;
        wynik[licznik++].b = kk.b;
      }
      else if((tab[kk.a][kk.b-1].x == 'p' || tab[kk.a][kk.b-1].x == '.') && kk.b-1 >= 0 && tab[kk.a][kk.b-1].m == false)
      {
        kk.b -= 1;
        tab[kk.a][kk.b].m = true;
        wynik[licznik].a = kk.a;
        wynik[licznik++].b = kk.b;
      }
    }
    printf("%d\n", licznik);
    for(int i = licznik-1; i >= 0; i--)
    printf("%d %d\n", wynik[i].b+1, abs(wynik[i].a-n));
  }
  return 0;
}
