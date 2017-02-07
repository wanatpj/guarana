#include<iostream>
#include<set>
#include<queue>
#include<vector>
using namespace std;

const int N = 100001;
int za[30];
bool ok[16777217];
int n;
int best1, best2,sum;

struct vert{
   int deg;
   set<int> ad;
};
vert tab[N];
struct Cmp{
  bool operator()(const int &a, const int &b){
    if(tab[a].deg != tab[b].deg)
      return tab[a].deg < tab[b].deg;
    return a < b;
  }
};

priority_queue<int,vector<int>, Cmp> kol;
vector<int> zbior;
vector<int>::iterator p;
set<int>::iterator q;

void zeruj(){
  for(int i=1;i<=n;i++){
    tab[i].deg = 0;
    tab[i].ad.clear();
  }
  zbior.clear();
}

void prog(){
  zbior.push_back(kol.top());
  kol.pop();
  while(!kol.empty()){
    int w = kol.top(); kol.pop();
    bool ok = true;
    for(p=zbior.begin();p!=zbior.end();p++){
      if(tab[w].ad.find(*p) == tab[w].ad.end()){ ok =false; break;}
    }
    if(ok) zbior.push_back(w);
  }
  sort(zbior.begin(),zbior.end());
  printf("%d\n",zbior.size());
  for(p=zbior.begin();p!=zbior.end();p++)
    printf("%d ",*p);
  printf("\n");
  zeruj();
}

void wczyt1(){
  scanf("%d",&n);
  int a,b;
  sum = 0;
  best1 = 1000000;
  best2 = 1000000;
  for(int i=2;i<=n;i++){
    scanf("%d",&a);
    for(int j=1;j<=a;j++){
      scanf("%d",&b);
      if((b < best1) || (b==best1 && i<best2)){
        best1 = b; best2 = i;
      }
      sum++;
      tab[i].ad.insert(b);
      tab[b].ad.insert(i);
      tab[i].deg++;
      tab[b].deg++;
    }
  }
  for(int i=1;i<=n;i++) kol.push(i);
}

int ile(unsigned int n) {
   register unsigned int tmp;
   tmp = n - ((n >> 1) & 033333333333) - ((n >> 2) & 011111111111);
   return ((tmp + (tmp >> 3)) & 030707070707) % 63;
}

void bin(int a){
  if(a==0) return;
  bin(a>>1);
  printf("%d",a&1);
}

void wypisz(int opt){
  int i=1;
  while(opt){
    if(opt&1) printf("%d ",i);
    opt>>=1;
    i++;
  }
  printf("\n");
}

void wczyt(){
  int a,b;
  scanf("%d",&n);
  for(int i=0;i<n;i++) za[i]=0;
  za[0] = 1;
  for(int i=1;i<n;i++){
    za[i] |= (1<<i);
    scanf("%d",&a);
    for(int j=1;j<=a;j++){
      scanf("%d",&b);
      za[i] |= (1<<(b-1));
      za[b-1] |= (1<<i);
    }
  }
}

main(){
  int t;
  scanf("%d",&t);
  while(t--){
if(n<=24){
    wczyt();
    int opt = 0;
    for(int i=1;i<(1<<n);i++){
      int wyn = i;
      int ind = 0;
      int temp = i;
      while(temp){
        if(temp&1){
           wyn &= (za[ind]);
        }
        temp>>=1;
        ind++;
      }
      ok[i] = wyn >= i;
      if(ok[i]){
        int b = ile(i);
        int w = opt;
        int z = i;
        if(b > ile(w))
          opt = z;
        else if(b == ile(opt)){
          bool lep=false;
          while(z && w){
            if((z&1) != (w&1)){
              if((z&1))lep =true;
              else     lep = false;
              break;
            }
            z>>=1; w>>=1;
          }
          if(lep) opt= i;
        }
      }
    }
    printf("%d\n",ile(opt));
    wypisz(opt);
}
else{
  wczyt1();
  if(sum == n-1){
    printf("2\n");
    printf("%d %d\n",best1,best2);
  }
  else 
    prog();
}
  }
}
