#include<iostream>
#include<set>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;

const int N = 100001;
ll za[60];
bool ok[16777217];
int stopnie[N];
int n;
int best1, best2,sum;
int maks(int a, int b){if(a>b) return a; return b;}
int mdeg;
ll pot[70];

struct vert{
   int deg;
   set<int> ad;
};

struct para{
  ll zb;
  ll za;
  para(){}
  para(ll a, ll b){zb=a;za=b;}
};

vert tab[N];
struct Cmp{
  bool operator()(const int &a, const int &b){
    if(tab[a].deg != tab[b].deg)
      return tab[a].deg < tab[b].deg;
    return a < b;
  }
};

const int M = 470;
vector<para> ytu[470];
priority_queue<int,vector<int>, Cmp> kol;
vector<int> zbior;
vector<int>::iterator p;
set<int>::iterator q;

void bin(ll a){
  if(a==0) return;
  bin(a>>1);
  printf("%d",a&1);
}

bool operator<(para a, para b){
  while(a.zb && b.zb){
    if((a.zb&1) != (b.zb&1))
      return (a.zb&1) > (b.zb&1);
    a.zb>>=1; b.zb>>=1;
  }
}

void wypisz(ll opt){
  int i=1;
  while(opt){
    if(opt&(1LL)) printf("%d ",i);
    opt>>=1;
    i++;
  }
  printf("\n");
}
void prog2(){
  for(int i=0;i<n;i++){
    ytu[1].push_back(para(1LL<<i,za[i]));
  }
  bool pop = true;
  int d = 1;
  pot[0] = 1;
  for(int i=1;i<63;i++)
    pot[i] = (pot[i-1]<<1);
  for(int j=2;pop;j++){
    pop = false;
    int ile = 0;
    for(vector<para>::iterator p = ytu[j-1].begin();p!=ytu[j-1].end();p++){
//      printf("zbior : "); bin(p->zb); printf(" , za : "); bin(p->za); printf("\n");
      for(int i=0;i<n;i++){
        if((((p->zb)&(1LL<<i)) == 0) && (p->za)&(1LL<<i)){
          pop = true;
          ile++;
          d=j;
          ytu[j].push_back(para(p->zb|(1LL<<i),(p->za)&(za[i])));
        }
      }
    }
  }
  para naj;
  naj.zb = (pot[n]);
  printf("%d\n",d);
  for(vector<para>::iterator p = ytu[d].begin();p!=ytu[d].end();p++){
    if(*p < naj){
      naj = *p;
    }
  }
  wypisz(naj.zb);
}

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

void wczyt(){
  int a,b;
  for(int i=0;i<n;i++) za[i]=0;
  za[0] = 1;
  for(int i=1;i<n;i++){
    za[i] |= (1LL<<i);
    scanf("%d",&a);
    for(int j=1;j<=a;j++){
      scanf("%d",&b);
      za[i] |= (1LL<<(b-1));
      za[b-1] |= (1LL<<i);
    }
  }
}

main(){
  int t;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
if(n<=24){
    wczyt();
    int opt = 0;
    for(int i=1;i<(1LL<<n);i++){
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
else if(n >60){
  wczyt1();
  if(sum == n-1){
    printf("2\n");
    printf("%d %d\n",best1,best2);
  }
  else{
    prog();
  }
}
else{
  wczyt();
  prog2();
}
  }
}
