#include<iostream>
using namespace std;

const int N = 5;
int tab[N][N],bity[N][N];

bool mozna(int a, int b){
  return a>=1 && a<=4 && b>=1 && b<=4;
}
int krolx[]={0,1,1,1,0,-1,-1,-1};
int kroly[]={1,1,0,-1,-1,-1,0,1};
int c,d;
int pionx[3],piony[3]; // biale pionki
int piocx[3],piocy[3];
int bialx, bialy;
int czarx, czary;

inline void wczyt(){
  string a;
  c=d=0;
  for(int i=1;i<=4;i++){
    cin >> a;
    for(int j=0;j<4;j++){
      if(a[j]=='B'){        bialx = i; bialy = j+1; tab[i][j+1] = 1; }
      else if(a[j] == 'b'){ pionx[c]=i; piony[c]=j+1; c++; tab[i][j+1] = 2; }
      else if(a[j] == 'C'){ czarx = i; czary = j+1; tab[i][j+1] = 3; }
      else if(a[j] == 'c'){ piocx[d]=i; piocy[d]=j+1; d++; tab[i][j+1] = 4; }
      else tab[i][j+1] = 0;
    }
  }
}
inline void zeruj(){
  for(int i=1;i<=4;i++)
    for(int j=1;j<=4;j++)
      bity[i][j] = false;
}

inline bool ruch(int x, int y, int i, int f){ // i-ty pionek, na pozycji teraz x,y i zbile pionka f;
  bool ok = true;
  if((mozna(x-1,y-1) && tab[x-1][y-1] == 3) || (mozna(x-1,y+1) && tab[x-1][y+1] == 3)){ // tzn. ze szachuje krola
    for(int j=0;j<d;j++){ // sprawdzam czy czarny pion bije moje miejsce
      if(j==f) continue;
      if(mozna(piocx[j]+1,piocy[j]-1) && piocx[j]+1==x && piocy[j]-1==y) ok = false;
      if(mozna(piocx[j]+1,piocy[j]+1) && piocx[j]+1==x && piocy[j]+1==y) ok = false;
    }
    if(!ok){ return false; }
    for(int j=0;j<c;j++){
        if(j==i) continue;
        else{
          if(mozna(pionx[j]-1,piony[j]-1))
            bity[pionx[j]-1][piony[j]-1] = true; 
          if(mozna(pionx[j]-1,piony[j]+1))
            bity[pionx[j]-1][piony[j]+1] = true;
        }
    }
    for(int j=0;j<8;j++)
      if(mozna(bialx+krolx[j],bialy+kroly[j]))
         bity[bialx+krolx[j]][bialy+kroly[j]] = true;
    if(!bity[x][y]){ zeruj(); return false; }
    for(int j=0;j<8;j++){
      if(mozna(czarx+krolx[j],czary+kroly[j]) && !bity[czarx+krolx[j]][czary+kroly[j]] && tab[czarx+krolx[j]][czary+kroly[j]] != 4){
        zeruj();
        return false;
      }
    }
  zeruj();
  return true;
  }
  else
    return false;
}

main(){
   int t;
   scanf("%d",&t);
   while(t--){
     wczyt();
     bool wszyst = false;;
     for(int i=0;i<c && !wszyst;i++){
       if( mozna(pionx[i]-1,piony[i]) && tab[pionx[i]-1][piony[i]]==0 ){// teraz rozpatruje ruch do gory
         if(ruch(pionx[i]-1,piony[i],i,-1))
           wszyst = true;
       }
       if(!wszyst && mozna(pionx[i]-1,piony[i]-1) && tab[pionx[i]-1][piony[i]-1]==4){ // teraz zbijam piona gora-lewo
         int f;// musze nalezc ktory pion zbilem
         for(int j=0;j<d;j++) if(piocx[j]==pionx[i]-1 && piocy[j]==piony[i]-1) f=j;
         if(ruch(pionx[i]-1,piony[i]-1,i,f))
           wszyst = true;
       }
       if(!wszyst && mozna(pionx[i]-1,piony[i]+1) && tab[pionx[i]-1][piony[i]+1]==4){
         int f;// musze nalezc ktory pion zbilem
         for(int j=0;j<d;j++) if(piocx[j]==pionx[i]-1 && piocy[j]==piony[i]+1) f=j;
         if(ruch(pionx[i]-1,piony[i]+1,i,f))
           wszyst = true;
       }
     }
     if(wszyst) printf("TAK\n");
     else printf("NIE\n");
   }
}