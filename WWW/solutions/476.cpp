#include<cstdio>
#include<queue>
using namespace std;
struct qe {
    int x,y;
    char typ;
    qe(int a, int b, char t) {
        x = a;
        y = b;
        typ = t;   
    }   
};
queue< qe* > Q;
char plansza[1003][1003];
int c,n;

int bfs() {
    qe* tmp;
    while(!Q.empty()) {
        tmp = Q.front();
        Q.pop();
        if (plansza[tmp->x][tmp->y] == '.') 
            plansza[tmp->x][tmp->y] = tmp->typ;
        if (plansza[tmp->x][tmp->y] != tmp->typ)
            continue;
                
            
        Q.push(new qe(tmp->x-1,tmp->y,'d'));
        Q.push(new qe(tmp->x+1,tmp->y,'g'));
        Q.push(new qe(tmp->x,tmp->y-1,'p'));
        Q.push(new qe(tmp->x,tmp->y+1,'l'));            
        delete tmp;
    }
}

void sciezka() {
    int x,y;
    x = n;
    y = 1;
    int l = 0;
    while(1) {
        l++;
        switch(plansza[x][y]) {
            case 'k': goto koniec;
            case 'p': y++;
                      break;   
            case 'l': y--;
                      break;
            case 'g': x--;
                      break;
            case 'd': x++;
                      break;
        }
    }    
koniec:;    
    x = n;
    y = 1;
    printf("%d\n",l);
    while(1) {
        printf("%d %d\n",y,n-x+1);
        switch(plansza[x][y]) {
            case 'k': return;
            case 'p': y++;
                      break;   
            case 'l': y--;
                      break;
            case 'g': x--;
                      break;
            case 'd': x++;
                      break;
        }
    }
}
int main() {
    scanf("%d",&c);
    while (c--) {   
        scanf("%d",&n);
        for (int i=1; i<=n; i++)
            scanf("%s",plansza[i]+1);
        for (int i=0; i<=n+1; i++)
            plansza[i][0] = plansza[0][i] = plansza[i][n+1] = plansza[n+1][i] = 0;
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                if (plansza[i][j] == 'k') {
                    Q.push(new qe(i,j,'k'));
                    bfs();
                }
        sciezka();
    }
}
