#include<cstdio>
using namespace std;

const int N=201;
int val[N];
int op[N][N];
int na[N][N];
int sum[N];
int n;
int M(int a,int b){
    if(a<b) return a;
    return b;
}

void wczyt(){
     scanf("%d", &n);
     for(int i=0;i<n;++i) scanf("%d", &val[i]);
     for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
          op[i][j]=-1;
     }
     op[0][0]=0;
     sum[0]=val[0];
     for(int i=1;i<n;++i){ 
        op[i][i]=0;
        sum[i] = (sum[i-1] + val[i]);
     }
}
int Op(int i,int j){
    if(op[i][j]==-1){
       int t=Op(i,j-1);
       na[i][j]=na[i][j-1];
       for(int k=j-2;k>=i;--k){
         int l=Op(i,k)+ Op(k+1,j);
         if(t>l){
           t=l;
           na[i][j] = na[i][k] + na[k+1][j]+1;
         }
       }
       op[i][j]= t + sum[j]-sum[i]+val[i];
    }
    return op[i][j];
}
main(){
       int C;
       scanf("%d", &C);
       while(C--){
       wczyt();
       Op(0,n-1);
       printf("%d %d\n", op[0][n-1],na[0][n-1]);
       }
}

