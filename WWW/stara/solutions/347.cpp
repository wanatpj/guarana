#include<cstdio>
#include<vector>
using namespace std;

#define FOR(x,y,z) for(int x=y;x<=z;++x)
#define REP(x,y) for(int x=0;x<y;++x)
#define FORD(x,y,z) for(int x=y;x>=z;--x)

#define PAII pair<short,short>
#define ST first
#define ND second


const int MAX = 1005;

char tab[MAX+1][MAX+1];
char tab2[MAX+1][MAX+1];
PAII co[MAX+1][MAX+1];
bool visited[MAX+1][MAX+1];

int n;

PAII idz(short x, short y) {
     if(x == 0 || y == 0 || x == n+1 || y == n+1)
        return PAII(x,y);
     visited[x][y] = true;
     if(tab[x][y] == '.' || tab[x][y] == 'k') {
        co[x][y] = PAII(x,y);
        return co[x][y];
     }
     switch(tab[x][y])
     {
        case 'g':
           if(visited[x-1][y])
              co[x][y] = co[x-1][y];
           else
              co[x][y] = idz(x-1, y);
        break;
        case 'd':
           if(visited[x+1][y])
              co[x][y] = co[x+1][y];
           else
              co[x][y] = idz(x+1, y);
        break;
        case 'p':
           if(visited[x][y+1])
              co[x][y] = co[x][y+1];
           else
              co[x][y] = idz(x, y+1);
        break;
        case 'l':
           if(visited[x][y-1])
              co[x][y] = co[x][y-1];
           else
              co[x][y] = idz(x, y-1);
        break;
     }
     return co[x][y];
}

void pre() {
     FOR(i,1,n)
        FOR(j,1,n)
           if(!visited[i][j])
              co[i][j] = idz(i, j);
}

void licz() {
     short x = n, y = 1;
     short prevX = n, prevY = 1;
     while(tab[x][y] != 'k')
     {
        switch(tab[x][y])
        {
           case 'g':
              prevX = x;
              prevY = y;
              --x;
           break;
           case 'd':
              prevX = x;
              prevY = y;
              ++x;
           break;
           case 'p':
              prevX = x;
              prevY = y;
              ++y;
           break;
           case 'l':
              prevX = x;
              prevY = y;
              --y;
           break;
           case '.':
              if(x-1 != prevX && co[x-1][y] != PAII(x,y) && (tab[co[x-1][y].ST][co[x-1][y].ND] == '.' || tab[co[x-1][y].ST][co[x-1][y].ND] == 'k')) {
                 tab2[x][y] = 'g';
                 prevX = x--;
                 prevY = y;
              }
              else if(x+1 != prevX && co[x+1][y] != PAII(x,y) && (tab[co[x+1][y].ST][co[x+1][y].ND] == '.' || tab[co[x+1][y].ST][co[x+1][y].ND] == 'k')) {
                 tab2[x][y] = 'd';
                 prevX = x++;
                 prevY = y;
              }
              else if(y-1 != prevY && co[x][y-1] != PAII(x,y) && (tab[co[x][y-1].ST][co[x][y-1].ND] == '.' || tab[co[x][y-1].ST][co[x][y-1].ND] == 'k')) {
                 tab2[x][y] = 'l';
                 prevX = x;
                 prevY = y--;
              }
              else if(y+1 != prevY && co[x][y+1] != PAII(x,y) && (tab[co[x][y+1].ST][co[x][y+1].ND] == '.' || tab[co[x][y+1].ST][co[x][y+1].ND] == 'k')) {
                 tab2[x][y] = 'p';
                 prevX = x;
                 prevY = y++;
              }
           break;
        }
     }
}

void lec() {
     short x = n, y = 1;
     int ile = 1;
     while(tab[x][y] != 'k')
     {
        if(tab[x][y] == '.')
           tab[x][y] = tab2[x][y];
        if(tab[x][y] == 'p')
           ++y;
        else if(tab[x][y] == 'l')
           --y;
        else if(tab[x][y] == 'g')
           --x;
        else if(tab[x][y] == 'd')
           ++x;
        ++ile;
     }
     printf("%d\n",ile);
}

void pojdz() {
     short x = n, y = 1;
     while(tab[x][y] != 'k')
     {
        if(tab[x][y] == 'p')
           printf("%hd %hd\n",y++, n - x + 1);
        else if(tab[x][y] == 'l')
           printf("%hd %hd\n",y--, n - x + 1);
        else if(tab[x][y] == 'g')
           printf("%hd %hd\n",y, n - (x--) + 1);
        else if(tab[x][y] == 'd')
           printf("%hd %hd\n",y, n - (x++) + 1);
     }
     printf("%hd %hd\n",y, n - x + 1);
}

main() {
       int z;
       char c;
       scanf("%d\n",&z);
       while(z--)
       {
          scanf("%hd\n",&n);
          FOR(i,1,n)
          {
             FOR(j,1,n)
             {
                scanf("%c",&tab[i][j]);
                visited[i][j] = false;
             }
             scanf("\n");
          }
          //printf("%c %c\n",tab[999][1],tab[1000][1]);
          pre();
          //printf("a\n");
          //printf("%c %c\n",tab[999][1],tab[1000][1]);
          licz();
          lec();
          pojdz();
       }
       return 0;
}
       
