#include<cstdio>
#include<vector>
using namespace std;

#define FOR(x,y,z) for(int x=y;x<=z;++x)
#define REP(x,y) for(int x=0;x<y;++x)
#define FORD(x,y,z) for(int x=y;x>=z;--x)

#define wsp(X, Y) ((X) >= 1 && (X) <= n && (Y) >= 1 && (Y) <= n)

const int MAX = 1000;

char tab[MAX+2][MAX+2];
bool visited[MAX+2][MAX+2];

int n;

bool obczaj(int x, int y, int X, int Y) {
     while(tab[x][y] != 'k' && tab[x][y] != '.')
     {
        if(visited[x][y])
           return false;
        visited[x][y] = true;
        if(tab[x][y] == 'g')
           --x;
        else if(tab[x][y] == 'd')
           ++x;
        else if(tab[x][y] == 'l')
           --y;
        else if(tab[x][y] == 'p')
           ++y;
     }
     return X != x || Y != y;
}

void licz() {
     int x = n, y = 1;
     int ile = 1;
     while(tab[x][y] != 'k')
     {
        visited[x][y] = true;
        if(tab[x][y] == 'g')
           --x;
        else if(tab[x][y] == 'd')
           ++x;
        else if(tab[x][y] == 'l')
           --y;
        else if(tab[x][y] == 'p')
           ++y;
        else if(tab[x][y] == '.') {
           if(wsp(x-1,y) && !visited[x-1][y] && obczaj(x-1, y, x, y))
              tab[x--][y] = 'g';
           else if(wsp(x+1,y) && !visited[x+1][y] && obczaj(x+1, y, x, y))
              tab[x++][y] = 'd';
           else if(wsp(x,y-1) && !visited[x][y-1] && obczaj(x, y-1, x, y))
              tab[x][y--] = 'l';
           else if(wsp(x,y+1) && !visited[x][y+1] && obczaj(x, y+1, x, y))
              tab[x][y++] = 'p';
        }
        ++ile;
     }
     printf("%d\n",ile);
}

void idz() {
     int x = n, y = 1;
     while(tab[x][y] != 'k')
     {
        if(tab[x][y] == 'g')
           printf("%d %d\n",y, n - (x--) + 1);
        else if(tab[x][y] == 'd')
           printf("%d %d\n",y, n - (x++) + 1);
        else if(tab[x][y] == 'l')
           printf("%d %d\n",y--, n - x + 1);
        else if(tab[x][y] == 'p')
           printf("%d %d\n",y++, n - x + 1);
     }
     printf("%d %d\n",y, n - x + 1);
}

main() {
       int z;
       scanf("%d",&z);
       while(z--)
       {
          scanf("%d\n",&n);
          FOR(i,1,n)
          {
             FOR(j,1,n)
             {
                scanf("%c",&tab[i][j]);
                visited[i][j] = false;
             }
             scanf("\n");
          }
          licz();
          idz();
       }
       return 0;
}
       
