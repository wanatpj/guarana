#include <cstdio>
using namespace std;
char A[1001][1001];
struct sc{
       short w,k;
};
sc kon;
bool koniec;
int C,N;
void wczytaj(){
     scanf("%d",&N);
     koniec == false;
     for(int i=1;i<=N;i++){
       for(int j=1;j<=N;){
       char x;
       scanf("%c", &x);
        if(x != '\n'){
             if(x == 'k'){
                  kon.w = i;
                  kon.k = j;
             }
            A[i][j++] = x;
        }
       }
     }
}
void wyp0(){
     for(int i=1;i<=N;i++){
     for(int j=1;j<=N;j++){
             printf("%c ",A[i][j]);
     }printf("\n");}
}
int req(int wi,int kol,int st){
                                                                                //printf("st:%d wi:%d kol:%d\n",st,wi,kol);
     if(wi == N && kol == 1){
           koniec = true;
           printf("%d\n%d %d\n",st,kol,N-wi+1);
           return 1;
     }
     int licz = 0;
     int z;
     if(koniec == true){
               printf("%d %d\n",kol,N-wi+1);
               return 1;
     }
     if(kol > 1)
     if(A[wi][kol-1]=='.' || A[wi][kol-1]=='p'){
            licz++;
            st++;
            A[wi][kol-1] = '0';
            z = req(wi,kol-1,st);
            if(z == 0){
                 licz--;
                 st--;
            }
     }
     if(koniec == true){
               printf("%d %d\n",kol,N-wi+1);
               return 1;
     }
     if(kol < N )
     if(A[wi][kol+1]=='.' || A[wi][kol+1]=='l'){
            licz++;
            st++;
            A[wi][kol+1] = '0';
            z = req(wi,kol+1,st);
            if(z == 0){
                 licz--;
                 st--;
            }
     }
     if(koniec == true){
               printf("%d %d\n",kol,N-wi+1);
               return 1;
     }
     if(wi > 1)
     if(A[wi-1][kol]=='.' || A[wi-1][kol]=='d'){
           licz++;
           st++;
           A[wi-1][kol] = '0';
           z = req(wi-1,kol,st);
            if(z == 0){
                 licz--;
                 st--;
            }
     }
     if(koniec == true){
               printf("%d %d\n",kol,N-wi+1);
               return 1;
     }
     if(wi < N)
     if(A[wi+1][kol]=='.' || A[wi+1][kol]=='g'){
           licz++;
           st++;
           A[wi+1][kol] = '0';
           z = req(wi+1,kol,st);
            if(z == 0){
                 licz--;
                 st--;
            }
     }
     if(koniec == true){
               printf("%d %d\n",kol,N-wi+1);
               return 1;
     }
     if(licz == 0)
             return 0;
     return 0;
}
void wykonaj(){
     int st = 1;
     koniec = false;
                                                                                //wyp0();
     req(kon.w,kon.k,st);
                                                                                //printf("\n");
                                                                                wyp0();
                                                                                printf("koniec\n");
}
int main(){
    int C;
    scanf("%d",&C);
    while(C--){
               wczytaj();
               wykonaj();
    }
    return 0;
}
