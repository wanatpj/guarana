#include<cstdio>
#include<vector>
using namespace std;

#define FOR(x,y,z) for(int x=y;x<=z;++x)
#define REP(x,y) for(int x=0;x<y;++x)
#define FORD(x,y,z) for(int x=y;x>=z;--x)

#define PAII pair<short,short>
#define ST first
#define ND second

#define PB push_back

const int MAX = 1001;

char tab[MAX+1][MAX+1];
PAII co[MAX+1][MAX+1];
bool visited[MAX+1][MAX+1];

vector< PAII > V;

int n;

PAII idz(const short &x, const short &y) {
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
        V.PB(PAII(x,y));
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
                 prevX = x;
                 prevY = y;
                 --x;
              }
              else if(x+1 != prevX && co[x+1][y] != PAII(x,y) && (tab[co[x+1][y].ST][co[x+1][y].ND] == '.' || tab[co[x+1][y].ST][co[x+1][y].ND] == 'k')) {
                 prevX = x;
                 prevY = y;
                 ++x;
              }
              else if(y-1 != prevY && co[x][y-1] != PAII(x,y) && (tab[co[x][y-1].ST][co[x][y-1].ND] == '.' || tab[co[x][y-1].ST][co[x][y-1].ND] == 'k')) {
                 prevX = x;
                 prevY = y;
                 --y;
              }
              else if(y+1 != prevY && co[x][y+1] != PAII(x,y) && (tab[co[x][y+1].ST][co[x][y+1].ND] == '.' || tab[co[x][y+1].ST][co[x][y+1].ND] == 'k')) {
                 prevX = x;
                 prevY = y;
                 ++y;
              }
           break;
        }
     }
     V.PB(PAII(x,y));
}

main() {
       int z;
       char c;
       scanf("%d%c",&z,&c);
       while(z--)
       {
          scanf("%d%c",&n,&c);
          FOR(i,1,n)
          {
             FOR(j,1,n)
             {
                scanf("%c",&tab[i][j]);
                visited[i][j] = false;
             }
             scanf("%c",&c);
          }
          pre();
          licz();
          printf("%d\n",V.size());
          REP(i,V.size())
             printf("%hd %hd\n",V[i].ND, n - V[i].ST + 1);
          V.clear();
       }
       return 0;
}
       
