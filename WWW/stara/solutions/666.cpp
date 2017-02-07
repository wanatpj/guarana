#include<iostream>
using namespace std;

const int N = 201;
const int inf = 2000000000;
int tab[N];
int S[N];
int F1[N][N];
int F2[N][N];
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
      F1[i][k] = inf;
      for(int u=i+1;u<=k;u++){
        bool nawias = u < k;
        if(F1[i][u-1] + F1[u][k] < F1[i][k]){
          F1[i][k] = F1[i][u-1] + F1[u][k];
          F2[i][k] = F2[i][u-1] + F2[u][k]+nawias;
        }
        else if(F1[i][u-1] + F1[u][k]==F1[i][k])
          F2[i][k] = min(F2[i][k],F2[i][u-1]+F2[u][k]+nawias);
      }
      F1[i][k] += S[k] - S[i-1];
    }
  }
  printf("%d %d\n",F1[1][n],F2[1][n]);
}

main(){
  int t;
  scanf("%d",&t);
  while(t--){
    wczyt();
    dynamik();
  }
}
