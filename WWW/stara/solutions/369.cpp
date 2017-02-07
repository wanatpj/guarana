#include <cstdio>
using namespace std;
int main(){
    int N,M;
    scanf("%d%d",&N,&M);
    int k,o,d;
    for(int i=0;i<N;i++){
            scanf("%d%d%d",&k,&o,&d);
            if(M < k)
            printf("komin\n");
            else{
             if(M < o)
             printf("okno\n");
             else{
              if(M < d)
              printf("drzwi\n");
              else{
               if(M > d)
               printf("brak\n");
              }
             }
            }
    }
    return 0;
}
