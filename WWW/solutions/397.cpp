#include<cstdio>
using namespace std;
int p;
int P[6000];
bool prime[50000];
//const int duzo = 1000000000;
int sito(){
    int M=50000;
    for(int i=2;i<=M;++i) prime[i]=true;
    int i=2;
    while(i*i<=M){
       for(int k=i*i;k<=M;k+=i) prime[k]=false;
       ++i;
       while(!prime[i]) ++i;
    }
    p=0;
    for(int i=2;i<=M;++i){
       if(prime[i]) P[p++]=i;
    }
}

main(){
       int C,M;
       scanf("%d %d", &C,&M);
       int naj;
       sito();
       int x;
       for(int i=0;i<C;++i){
         scanf("%d", &x);
          long long SumDz=1;
         for(int k=0;k<p && x>1; ++k){
            if(x%P[k]==0){
              long long HelpSum=1;
              long long Pow=1;
              while(x%P[k]==0){
                 Pow = (Pow * ((P[k])%M))%M ; 
                 HelpSum+=Pow;
                 HelpSum%=M;
                 x/=P[k];
              }
             SumDz = (SumDz*HelpSum)%M;
            }
            if(SumDz==1)
             SumDz = (1 + x)%M;
         }
        printf("%d\n",SumDz);
       }
      
}
