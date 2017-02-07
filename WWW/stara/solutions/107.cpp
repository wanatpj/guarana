#include<iostream>
using namespace std;

const int N = 1000001;
int dwu[N];
int n,k,m;

void dwumian(){
  dwu[0]=dwu[1] = 1;
  for(int i=2;i<=n;i++){
    for(int j=i;j>=0;j--){
      dwu[j] += dwu[j-1];
      if(dwu[j] >= m)
         dwu[j] %= m;
    }
  }
}

main(){
  scanf("%d %d %d",&n,&k,&m);
  dwumian();
  int wyn = 0;
  for(int i=0;i<k;i++){
    wyn = 0;
    for(int j=0;j*k+i <= n;j++){
      wyn += dwu[j*k+i];
      wyn %= m;
    }
    printf("%d\n",wyn);
  }
}
