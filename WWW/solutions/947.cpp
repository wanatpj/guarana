#include <cstdio>
using namespace std;
char A[1001][1001];
struct sc{
       short w,k;
};
sc kon,stos[1002050];
int st,C,N;
void wczytaj(){
     scanf("%d",&N);
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
             printf("%d ",A[i][j]);
     }printf("\n");}
}
void wykonaj(){
     st = 0;
     int wi=kon.w,kol=kon.k;
     while(wi!=N || kol!=1){
                                                                                //int z = N-wi+1;printf("wi:%d kol:%d porf:%d\n",z,kol,A[wi][kol].z);
                                                                                //wyp0();
                 if(kol > 1 && A[wi][kol-1]=='.'){
                                                                                //printf("1\n");
                         stos[st].w = N - wi + 1;
                         stos[st++].k = kol;
                         kol--;
                         A[wi][kol] = '0';
                         continue;
                 }
                 if(kol < N && A[wi][kol+1]=='.'){
                                                                                //printf("2\n");
                         stos[st].w = N - wi + 1;
                         stos[st++].k = kol;
                         kol++;
                         A[wi][kol] = '0';
                         continue;
                 }
                 if(wi > 1 && A[wi-1][kol]=='.'){
                                                                                //printf("3\n");
                         stos[st].w = N - wi + 1;
                         stos[st++].k = kol;
                         wi--;
                         A[wi][kol] = '0';
                         continue;
                 }
                 if(wi < N && A[wi+1][kol]=='.'){
                                                                                //printf("4\n");
                         stos[st].w = N - wi + 1;
                         stos[st++].k = kol;
                         wi++;
                         A[wi][kol] = '0';
                         continue;
                 }
                 if(kol > 1 && A[wi][kol-1]=='p'){
                                                                                //printf("1a\n");
                         stos[st].w = N - wi + 1;
                         stos[st++].k = kol;
                         kol--;
                         A[wi][kol] = '0';
                         continue;
                 }
                 if(kol < N && A[wi][kol+1]=='l'){
                                                                                //printf("2a\n");
                         stos[st].w = N - wi + 1;
                         stos[st++].k = kol;
                         kol++;
                         A[wi][kol] = '0';
                         continue;
                 }
                 if(wi > 1 && A[wi-1][kol]=='d'){
                                                                                //printf("3a\n");
                         stos[st].w = N - wi + 1;
                         stos[st++].k = kol;
                         wi--;
                         A[wi][kol] = '0';
                         continue;
                 }
                 if(wi < N && A[wi+1][kol]=='g'){
                                                                                //printf("4a\n");
                         stos[st].w = N - wi + 1;
                         stos[st++].k = kol;
                         wi++;
                         A[wi][kol] = '0';
                         continue;
                 }
     }
     stos[st].w = N - wi + 1;
     stos[st++].k = kol;
}
void wypisz(){
     printf("%d\n",st);
     while(st--){
                printf("%d %d\n",stos[st].k,stos[st].w);
                                                                                //wyp0();
     }
}
int main(){
    int C;
    scanf("%d",&C);
    while(C--){
               wczytaj();
               wykonaj();
               wypisz();
    }
    return 0;
}
