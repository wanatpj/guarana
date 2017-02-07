//karol  banys
#include<cstdio>
using namespace std;
int T[10001],N,zos,ost,min1,min2;
long long czas;
void wczyt(){
   scanf("%d",&N);
    for(int i=0;i<N;i++)
            scanf("%d",&T[i]);
    zos = N;
    ost = N-1;
    min1 = T[0];
    min2 = T[1];
    czas = 0;
}
void jeden(){
     czas += zos*min1;
     while(zos > 0){
               czas += T[ost--];
               zos--;
     }
}
void dwa(){
     if(N == 1){
          czas = min1;
          return;
     }
     czas += min2;
     zos -= 2;
     while(zos > 1){
              if((min1+T[ost]+2*min2) > (2*min1+T[ost]+T[ost-1])) break;
               czas += (min1 + T[ost] + (2*min2));
               zos -= 2;
               ost -= 2;
     }
     jeden();
}
int main(){
    int D;
    scanf("%d",&D);
    while(D--){
               wczyt();
               dwa();
               printf("%lld\n",czas);
    }
}
