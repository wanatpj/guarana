#include <cstdio>
using namespace std;
char A[1001][1001];
struct sc{
       short w,k;
};
sc kon,stos[1000010];
int st,C,N;
void wczytaj(){
     scanf("%d",&N);
     st = 0;
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
     int wi=kon.w,kol=kon.k;
     if(kol > 1 && A[wi][kol-1]=='.'){
     stos[st].w = N - wi + 1;
     stos[st++].k = kol;
     kol--;
     A[wi][kol] = '0';
     }
     else{
      if(kol < N && A[wi][kol+1]=='.'){
      stos[st].w = N - wi + 1;
      stos[st++].k = kol;
      kol++;
      A[wi][kol] = '0';
      }
      else{
       if(wi > 1 && A[wi-1][kol]=='.'){
       stos[st].w = N - wi + 1;
       stos[st++].k = kol;
       wi--;
       A[wi][kol] = '0';
       }
       else{
        if(wi < N && A[wi+1][kol]=='.'){
        stos[st].w = N - wi + 1;
        stos[st++].k = kol;
        wi++;
        A[wi][kol] = '0';
        }
        else{
         if(kol > 1 && A[wi][kol-1]=='p'){
         stos[st].w = N - wi + 1;
         stos[st++].k = kol;
         kol--;
         A[wi][kol] = '0';
         }
         else{
          if(kol < N && A[wi][kol+1]=='l'){
          stos[st].w = N - wi + 1;
          stos[st++].k = kol;
          kol++;
          A[wi][kol] = '0';
          }
          else{
           if(wi > 1 && A[wi-1][kol]=='d'){
           stos[st].w = N - wi + 1;
           stos[st++].k = kol;
           wi--;
           A[wi][kol] = '0';
           }
           else{
            if(wi < N && A[wi+1][kol]=='g'){
            stos[st].w = N - wi + 1;
            stos[st++].k = kol;
            wi++;
            A[wi][kol] = '0';
            }
           }
          }
         }
        }
       }
      }
     }
     while(wi!=N || kol!=1){
                                                                                //int z = N-wi+1;printf("wi:%d kol:%d porf:%d\n",z,kol,A[wi][kol].z);
                                                                                //wyp0();
                 if(kol > 1 && (A[wi][kol-1]=='p' || A[wi][kol-1]=='.')){
                         stos[st].w = N - wi + 1;
                         stos[st++].k = kol;
                         kol--;
                         A[wi][kol] = '0';
                         continue;
                 }
                 if(kol < N && (A[wi][kol+1]=='l' || A[wi][kol-1]=='.')){
                         stos[st].w = N - wi + 1;
                         stos[st++].k = kol;
                         kol++;
                         A[wi][kol] = '0';
                         continue;
                 }
                 if(wi > 1 && (A[wi-1][kol]=='d' || A[wi][kol-1]=='.')){
                         stos[st].w = N - wi + 1;
                         stos[st++].k = kol;
                         wi--;
                         A[wi][kol] = '0';
                         continue;
                 }
                 if(wi < N && (A[wi+1][kol]=='g' || A[wi][kol-1]=='.')){
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
