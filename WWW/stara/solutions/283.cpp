#include<iostream>
#include<queue>
#include<stack>
using namespace std;

/*
  0 - gora
  1 - prawo
  2 - dol
  3 - lewo
  4 - brak
  5 - koniec
*/

struct pkt{
  int x,y;
  pkt(){}
  pkt(int a, int b){x=a; y=b;}
};

const int N = 1002;
int plan[N][N];
int n;
char tab[N];
pkt par[N][N];
bool odw[N][N];
queue<pkt> S;
stack<pkt> K;
pkt pocz;
pkt koniec;

void wczyt(){
  scanf("%d",&n);
  for(int i=n;i>=1;i--){
    scanf("%s",tab+1);
    for(int j=1;j<=n;j++){
      if(tab[j] == 'g') plan[i][j] = 0;
      else if(tab[j]=='p') plan[i][j] = 1;
      else if(tab[j]=='d') plan[i][j] = 2;
      else if(tab[j]=='l') plan[i][j] = 3;
      else if(tab[j]=='.') plan[i][j] = 4;
      else{ koniec = pkt(i,j);  plan[i][j] = 5; }
    }
  }
}

bool mozna(int x, int y){
  return x>=1 && x<=n && y>=1 && y<=n && !odw[x][y];
}
int a[]={1,0,-1,0};
int b[]={0,1,0,-1};

void bfs(){
  S.push(pkt(1,1));
  odw[1][1] = true;
  par[1][1] = pkt(-1,-1);
  pkt temp;
  while(!S.empty()){
    temp = S.front(); S.pop();
    if(plan[temp.x][temp.y] == 5){ break; }
    else{
      if(plan[temp.x][temp.y] <= 3){
        int c = temp.x + a[plan[temp.x][temp.y]], d = temp.y + b[plan[temp.x][temp.y]];
        if(mozna(c,d)){
          par[c][d] = temp;
          odw[c][d] = true;
          S.push(pkt(c,d));
        }
      }
      else{//czyli moge isc w kazdym kierunku
        for(int i=0;i<=3;i++){
          int c = temp.x + a[i], d = temp.y + b[i];
          if(mozna(c,d)){
            par[c][d] = temp;
            odw[c][d] = true;
            S.push(pkt(c,d));
          }
        }
      }
    }
  }
}

void sciezka(){
  K.push(koniec);
  pkt temp;
  pocz = pkt(1,1);
  while(!(K.top().x == 1 && K.top().y==1)){
    temp = K.top();
    K.push(par[temp.x][temp.y]);
  }
  printf("%d\n",K.size());
  while(!K.empty()){
    printf("%d %d\n",K.top().y,K.top().x);
    K.pop();
  }
}

void zeruj(){
  while(!S.empty()) S.pop();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      odw[i][j] = false;
    }
  }
}

main(){
  int t;
  scanf("%d",&t);
  while(t--){
    wczyt();
    bfs();
    sciezka();
    zeruj();
  }
}
