#include<iostream>
#include<algorithm>
using namespace std;

const int N = 10001;
const int inf = 2000000000;
int t[N];
int S1[N];
int S2[N];
int n;
int min(int a, int b){if(a<b) return a; return b;}

void wczyt(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
    scanf("%d",&t[i]);
  sort(t+1,t+n+1);
  for(int i=3;i<=n;i++)
    S1[i] = S1[i-1] + t[i];
  for(int i=n-1,k=1;i>0;i-=2,k++)
    S2[k] = t[i] + S2[k-1];
}

main(){
  int z;
  scanf("%d",&z);
  while(z--){
    wczyt();
    int naj = inf;
    int temp;
    for(int i=0;i<= (n/2) -1;i++){
      naj = min(naj, (n-2-i)*t[1] + (2*i + 1)*t[2] + S1[n] - S2[i]);
    }
    printf("%d\n",naj);
  }
}
