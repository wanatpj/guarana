#include<iostream>
using namespace std;

const int N = 5;
int tab[N][N],bity[N][N],temp[N][N];

bool mozna(int a, int b){
  return a>=1 && a<=4 && b>=1 && b<=4;
}
int krolx[]={0,1,1, 1, 0,-1,-1,-1,0};
int kroly[]={1,1,0,-1,-1,-1, 0, 1,0};
int czarx, czary;
int szachx, szachy;

inline void wczyt(){
  string a;
  for(int i=1;i<=4;i++){
    cin >> a;
    for(int j=0;j<4;j++){
      if(a[j]=='B'){        tab[i][j+1] = 1; }
      else if(a[j] == 'b'){ tab[i][j+1] = 2; }
      else if(a[j] == 'C'){ czarx = i; czary = j+1; tab[i][j+1] = 3; }
      else if(a[j] == 'c'){ tab[i][j+1] = 4; }
      else tab[i][j+1] = 0;
    }
  }
}
inline void zeruj(){
  for(int i=1;i<=4;i++)
    for(int j=1;j<=4;j++)
      bity[i][j]=false;
}

bool mat(){
  // teraz ustalam ktore pola ja bije
  for(int i=1;i<=4;i++)
    for(int j=1;j<=4;j++){
      if(temp[i][j]==1){
        for(int k=0;k<8;k++){
          if(mozna(i+krolx[k],j+kroly[k]))
            bity[i+krolx[k]][j+kroly[k]] = true;
        }
      }
      else if(temp[i][j] == 2){
        if(mozna(i-1,j-1)){
          bity[i-1][j-1] = true;
          if(i-1 == czarx && j-1 == czary){
            szachx = i; szachy = j;
          }
        }
        if(mozna(i-1,j+1)){
          bity[i-1][j+1] = true;
          if(i-1 == czarx && j+1 == czary){
            szachx = i; szachy = j;
          }
        }
      }
    }
/*  for(int i=1;i<=4;i++){
    for(int j=1;j<=4;j++)
      printf("%d ",bity[i][j]);
    printf("\n");
  }
  printf("\n");*/
  // teraz ustale ktore miejsca sa bite przec czarne pionki
//  printf("szachuje pion na miejscu : %d,%d\n",szachx,szachy);
  if(mozna(szachx-1,szachy-1) && temp[szachx-1][szachy-1]==4) return false;
  if(mozna(szachx-1,szachy+1) && temp[szachx-1][szachy+1]==4) return false;
  for(int i=0;i<9;i++)
    if(mozna(czarx+krolx[i],czary+kroly[i]) && !bity[czarx+krolx[i]][czary+kroly[i]] && temp[czarx+krolx[i]][czary+kroly[i]]!=4) 
       return false;
  return true;
//  printf(" --- po zestawie ---\n");
}

void przepisz(){
  for(int i=1;i<=4;i++)
    for(int j=1;j<=4;j++)
      temp[i][j] = tab[i][j];
}

main(){
   int t;
   scanf("%d",&t);
   while(t--){
     wczyt();
     bool wszyst = false;
     int f;
     zeruj();
   for(int i=1;i<=4;i++)
     for(int j=1;j<=4;j++){
       if(tab[i][j] == 2){
       int x = i, y= j;
 //      printf("mam teraz piona : %d,%d\n",x,y);
       if( mozna(x-1,y) && tab[x-1][y]==0 ){// teraz rozpatruje ruch do gory
         przepisz();
         temp[x-1][y] = 2;
         temp[x][y] = 0;
         if(mat()) wszyst = true;
         zeruj();
       }
       if(mozna(x-1,y-1) && tab[x-1][y-1]==4){ // teraz zbijam piona gora-lewo
         przepisz();
         temp[x-1][y-1] = 2;
         temp[x][y] = 0;
         if(mat()) wszyst = true;
         zeruj();
       }
       if(mozna(x-1,y+1) && tab[x-1][y+1]==4){
         przepisz();
         temp[x-1][y+1] = 2;
         temp[x][y] = 0;
         if(mat()) wszyst = true;
         zeruj();
       }
       }
    }
     if(wszyst) printf("TAK\n");
     else printf("NIE\n");
     for(int i=0;i<5;i++) for(int j=0;j<5;j++) tab[i][j]=bity[i][j]=0;
 }
}
