#include<iostream>
using namespace std;

struct msc{
  int ile; // ile czasu
  int naw; // ile nawiasow
};

const int N = 201;
const int inf = 2000000000;
int tab[N];
int S[N];
msc F[N][N];
int n;
int min(int a, int b){if(a<b) return a; return b;}

inline void wczyt(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&tab[i]);
    S[i] = S[i-1] + tab[i];
  }
}

inline void dynamik(){
  for(int j=1;j<n;j++){
    for(int i=1;i+j<=n;i++){
      int k = i+j;
      F[i][k].ile = inf;
      F[i][k].naw = 0;
      for(int u=i+1;u<=k;u++){
        int s1 = S[u-1] - S[i-1];
        int s2 = S[k] - S[u-1];
        int f1 = F[i][u-1].ile + s1;
        int f2 = F[u][k].ile   + s2;
        bool nawias = u < k;
        if(f1+f2 < F[i][k].ile){
          F[i][k].ile = f1+f2;
          F[i][k].naw = F[i][u-1].naw + F[u][k].naw + nawias;
        }
        else if(f1 + f2==F[i][k].ile)
          F[i][k].naw = min(F[i][k].naw,F[i][u-1].naw+F[u][k].naw+nawias);
      }
    }
  }
  printf("%d %d\n",F[1][n].ile,F[1][n].naw);
}

main(){
  int t;
  scanf("%d",&t);
  while(t--){
    wczyt();
    dynamik();
  }
}
