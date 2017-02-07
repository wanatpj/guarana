#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int N = 100001;
const int inf  = 2000000000;
bool zrob[N],dozrob[N];
struct kt{
  int odl, nr, skad;
  kt(){}
  kt(int a, int b, int c){nr=a; odl = b; skad = c;}
};
struct edge{
  int a,b,c;
  edge(){}
  edge(int x, int y, int z){
    a=x; b=y; c=z;
  }
};

kt tab[N];
vector<edge> za[N];
int n,m,r;

bool operator<(const kt &a, const kt &b){
  if(a.odl != b.odl) return a.odl > b.odl;
  if( a.skad != b.skad) return a.skad > b.skad;
  return a.nr > b.nr;
}

priority_queue<kt> S;
vector<int> zap;
main(){
  scanf("%d %d %d",&n,&m,&r);
  for(int i=1;i<=n;i++){
    tab[i].odl = inf; tab[i].skad = -1; tab[i].nr = i;
  }
  int y;
  for(int i=1;i<=r;i++){
    scanf("%d",&y);
    tab[y].odl = 0; tab[y].skad = y;
    S.push(tab[y]);
  }
  int a,b,c;
  for(int i=1;i<=m;i++){
    scanf("%d %d %d",&a,&b,&c);
    za[a].push_back(edge(a,b,c));
    za[b].push_back(edge(b,a,c));
  }
  int q,w;
  scanf("%d",&q);
  while(q--){
    scanf("%d",&w);
    zap.push_back(w);
    dozrob[w] = true;
  }
  kt temp;
  int ile = 0;
  while(!S.empty()){
    temp = S.top(); S.pop();
    if(temp.odl == inf) break;
    if(ile == q) break;
    if(temp.odl == tab[temp.nr].odl && temp.skad == tab[temp.nr].skad){
      if(dozrob[temp.nr] && !zrob[temp.nr]) ile++;
      zrob[temp.nr] = true;
      for(vector<edge>::iterator p = za[temp.nr].begin();p!=za[temp.nr].end();p++){
        if( tab[p->b].odl>tab[temp.nr].odl+p->c || (tab[p->b].odl == tab[temp.nr].odl+p->c && tab[temp.nr].skad < tab[p->b].skad)){
          tab[p->b].odl = tab[temp.nr].odl + p->c;
          tab[p->b].skad = tab[temp.nr].skad;
          S.push(tab[p->b]);
        }
      }
    }
  }
  for(vector<int>::iterator p=zap.begin();p!=zap.end();p++){
    if(tab[*p].odl == inf) printf("BRAK\n");
    else printf("%d %d\n",tab[*p].skad,tab[*p].odl);
  }
}
