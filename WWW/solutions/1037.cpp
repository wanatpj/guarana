#include<iostream>
#include<set>
#include<vector>
using namespace std;

const int N = 1001;
struct ciag{
  int t[N];
};


int min(int a, int b){if(a<b) return a; return b;}
int maks(int a, int b){if(a>b) return a; return b;}
vector<vector<int> > nwp;
vector<int> t1, t2, k1,k2;
int n,m,kty, naj;
set<int> wyst;
set<int>::iterator p;
ciag wynik[N];

bool operator<(const ciag &a, const ciag &b){
  for(int i=1;i<=naj;i++)
    if(a.t[i] != b.t[i])
      return a.t[i] < b.t[i];
  return false;
}

void wczyt(){
  int a,b;
  scanf("%d %d %d",&n,&m,&kty);
  t1.push_back(-1);
  t2.push_back(-2);
  for(int i=0;i<n;i++){
    scanf("%d",&a);
    t1.push_back(a);
  }
  for(int i=0;i<m;i++){
    scanf("%d",&a);
    t2.push_back(a);
  }
}

void zmniejsz(){
  for(int i=1;i<=n;i++){
    p = wyst.find(t1[i]);
    if(p == wyst.end()) wyst.insert(t1[i]);
  }
  vector<int>::iterator q = t2.begin(); q++;
  for( ; q!=t2.end();q++){
    p = wyst.find(*q);
    if(p == wyst.end()){
      t2.erase(q);
      q--;
      if(q == t2.end()) break;
    }
  }
  wyst.clear();
  q = t2.begin(); q++;
  for( ; q!=t2.end();q++){
    p = wyst.find(*q);
    if(p == wyst.end()){ 
      wyst.insert(*q); 
    }
  }
  q = t1.begin(); q++;
  for( ; q!=t1.end();q++){
    p = wyst.find(*q);
    if(p == wyst.end()){ 
      t1.erase(q); 
      q--;
      if(q == t1.end()) break; 
    }
  }
  n = t1.size()-1;
  m = t2.size()-1;
  int k=0,l=0;
  k1.push_back(-1);
  k2.push_back(-2);
  for(int i=1;i<=n;i++)
    if(t1[i] != k1[k]){
      k1.push_back(t1[i]);
      k++;
    }
  for(int i=1;i<=m;i++){
    if(t2[i] != k2[l]){
      k2.push_back(t2[i]);
      l++;
    }
  }
  n = k;
  m = l;
}

void oblicz(){
  nwp.assign(n+1,0);
  for(int i=0;i<=n;i++)
    nwp[i].assign(m+1,0);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      nwp[i][j] = maks(nwp[i-1][j-1] + (k1[i] == k2[j]),maks(nwp[i][j-1],nwp[i-1][j]));
  naj = nwp[n][m];
}

void zeruj(){
  t1.clear(); t2.clear();
  k1.clear(); k2.clear();
  nwp.clear();
}
int ind;
void generuj(int *tab, int w, int k, int szuk){
  if(szuk == 0){
    ind++;
    for(int i=1;i<=naj;i++)
      wynik[ind].t[i] = tab[i];
    return;
  }
  for(int i=w-1;i>=1;i--){
    for(int j=k-1;j>=1;j--){
      if(nwp[i][j] < szuk) break;
      if(nwp[i][j] == szuk && k1[i]==k2[j]){
        tab[szuk] = k1[i];
        generuj(tab,i,j,szuk-1);
      }
    }
  }
}

main(){
  int t;
  scanf("%d",&t);
  while(t--){
    wczyt();
    zmniejsz();
    oblicz();
  if(nwp[n][m] > 0){
    int tab[N];
    ind = 0;
    generuj(tab,n+1,m+1,nwp[n][m]);
    sort(wynik+1,wynik+1+ind);
    printf("%d\n",naj);
    if(kty > ind) printf("-1\n");
    else{
      for(int i=1;i<=naj;i++)
        printf("%d ",wynik[kty].t[i]);
      printf("\n");
    }
  }
  else{
    printf("0\n");
    printf("-1\n");
  }
    zeruj();
  }
}
