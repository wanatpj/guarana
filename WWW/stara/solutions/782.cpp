#include <cstdio>
using namespace std;
struct cs{
       char a;
       bool z;
};
cs A[1001][1001];
struct sc{
       int w,k;
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
            A[i][j++].a = x;
        }
       }
     }
}
void wyp0(){
     for(int i=1;i<=N;i++){
     for(int j=1;j<=N;j++){
             printf("%d ",A[i][j].z);
     }printf("\n");}
}
void wykonaj(){
     st = 0;
     int wi=kon.w,kol=kon.k;
     while(wi!=N || kol!=1){
                                                                                //int z = N-wi+1;printf("wi:%d kol:%d porf:%d\n",z,kol,A[wi][kol].z);
                                                                                //wyp0();
                 if(kol > 1 && A[wi][kol-1].a=='.' && A[wi][kol-1].z == false){
                                                                                //printf("1\n");
                         stos[st].w = N - wi + 1;
                         stos[st++].k = kol;
                         kol--;
                         A[wi][kol].z = true;
                         continue;
                 }
                 if(kol < N && A[wi][kol+1].a=='.' && A[wi][kol+1].z == false){
                                                                                //printf("2\n");
                         stos[st].w = N - wi + 1;
                         stos[st++].k = kol;
                         kol++;
                         A[wi][kol].z = true;
                         continue;
                 }
                 if(wi > 1 && A[wi-1][kol].a=='.' && A[wi-1][kol].z == false){
                                                                                //printf("3\n");
                         stos[st].w = N - wi + 1;
                         stos[st++].k = kol;
                         wi--;
                         A[wi][kol].z = true;
                         continue;
                 }
                 if(wi < N && A[wi+1][kol].a=='.' && A[wi+1][kol].z == false){
                                                                                //printf("4\n");
                         stos[st].w = N - wi + 1;
                         stos[st++].k = kol;
                         wi++;
                         A[wi][kol].z = true;
                         continue;
                 }
                 if(kol > 1 && A[wi][kol-1].a=='p' && A[wi][kol-1].z == false){
                                                                                //printf("1a\n");
                         stos[st].w = N - wi + 1;
                         stos[st++].k = kol;
                         kol--;
                         A[wi][kol].z = true;
                         continue;
                 }
                 if(kol < N && A[wi][kol+1].a=='l' && A[wi][kol+1].z == false){
                                                                                //printf("2a\n");
                         stos[st].w = N - wi + 1;
                         stos[st++].k = kol;
                         kol++;
                         A[wi][kol].z = true;
                         continue;
                 }
                 if(wi > 1 && A[wi-1][kol].a=='d' && A[wi-1][kol].z == false){
                                                                                //printf("3a\n");
                         stos[st].w = N - wi + 1;
                         stos[st++].k = kol;
                         wi--;
                         A[wi][kol].z = true;
                         continue;
                 }
                 if(wi < N && A[wi+1][kol].a=='g' && A[wi+1][kol].z == false){
                                                                                //printf("4a\n");
                         stos[st].w = N - wi + 1;
                         stos[st++].k = kol;
                         wi++;
                         A[wi][kol].z = true;
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
                A[N-stos[st].w+1][stos[st].k].z = false;
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
