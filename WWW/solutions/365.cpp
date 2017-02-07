#include <cstdio>
using namespace std;

int main(){
    int D;
    scanf("%d",&D);
    while(D--){
               int N,wynik=0,hk,tk=0,C;
               scanf("%d",&N);
               while(tk < N){
                        scanf("%d",&hk);
                        tk++;
                        wynik += hk;
               }
               scanf("%d",&C);
               if(wynik == 0)
                        printf("%d\n",C);
               else{
               wynik = C % wynik;
               printf("%d\n",wynik);
               }
    }
    return 0;
}
