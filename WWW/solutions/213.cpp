#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct vert{
  int nr, wys,father;
  vector<int> za,child;
  bool stan;
  int pod[3], ile;
};

const int N = 100010;
vert tab[N];
bool cykl[N];
int par[N];
int n;

void wczyt(){
  int x,y;
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d %d",&x,&y);
    tab[i].pod[0] = 1;
    tab[i].pod[1] = tab[i].pod[2] = 0;
    tab[x].za.push_back(y);
    tab[y].za.push_back(x);
  }
}
int pocz, kon;
bool found;
void visit(int v, int oj){
  if(!found){ 
    par[v] = oj;
    for(vector<int>::iterator p = tab[v].za.begin();p!=tab[v].za.end();p++){ 
      if(*p!=oj && par[*p] && par[*p]!=-1){ 
        found = true;
	pocz = v; kon = *p;
        return;
      } 
      else if(*p != oj)
        visit(*p,v);
    }
  }
}

vector<int> ver;
queue<int> liscie;
int suma;
struct pkt{
  int nr, gl;
  pkt(){}
  pkt(int a, int b){nr=a; gl = b;}
};

queue<pkt> S;
vector<int> wys[N];

void bfs(int c){  
  tab[c].father = -1;
  S.push(pkt(c,0));
  pkt temp;
  int maks_gl = 0;
  while(!S.empty()){
    temp = S.front(); S.pop();
    if(temp.gl > maks_gl) maks_gl = temp.gl;
    wys[temp.gl].push_back(temp.nr);
    for(vector<int>::iterator p = tab[temp.nr].za.begin();p!=tab[temp.nr].za.end();p++){
      if((*p) != tab[temp.nr].father && !cykl[*p]){
        tab[*p].father = temp.nr;
	S.push(pkt(*p,temp.gl+1));
      }
    }
  }
  for(int i=maks_gl;i>=0;i--){
    for(vector<int>::iterator p = wys[i].begin();p!=wys[i].end();p++){
      if(tab[*p].stan) continue;
      else{
        int ile=0;
	for(int i=0;i<=2;i++) ile += tab[*p].pod[i];
	if(ile >= 3){
	  tab[*p].stan = true;
	  suma++;
	}
	else{
	  tab[tab[*p].father].pod[1]++;
	  tab[tab[*p].father].pod[2] += tab[*p].pod[1];
	}
      }
    }
    wys[i].clear();
  }
  wys[0].clear();
}
int g;
int dyn[3][N];
int m(int a, int b){if(a>b) return a; return b;}
int best(int kt, int ind){
  int naj = dyn[kt][(ind-1)%g];
  if(ind - kt == 1){ // czy na pierwszych 2 moze byc juz trojka
    if(tab[ver[ind-1]].ile + tab[ver[ind]].ile >= 3) naj = m(naj,1);
  }
  else{
    if(!tab[ver[(ind-1)%g]].stan && !tab[ver[ind%g]].stan)
       naj = m(dyn[kt][ind-2] + ((tab[ver[(ind-1)%g]].ile + tab[ver[ind%g]].ile) >= 3),naj);
    if(!tab[ver[(ind-2)%g]].stan && !tab[ver[(ind-1)%g]].stan && !tab[ver[ind%g]].stan)
       naj = m(dyn[kt][ind-3] + 1,naj);
  }
  return naj;
}

main(){
  wczyt();
  found = false;
  visit(1,-1);
  cykl[pocz]=cykl[kon]=true;
  while(pocz!=kon){
    ver.push_back(kon);
    cykl[kon] =  true;
    kon = par[kon];
  }
  ver.push_back(pocz);
  cykl[pocz] = true;
  suma= 0;
  for(vector<int>::iterator p = ver.begin();p!=ver.end();p++){
    bfs(*p);
    if(tab[*p].stan) tab[*p].ile = 0;
    else
      tab[*p].ile = tab[*p].pod[0]+tab[*p].pod[1];
  }
  g = ver.size();
  for(int i=1;i<g;i++){
    dyn[0][i] = best(0,i);
    dyn[1][i+1] = best(1,i+1);
    dyn[2][i+2] = best(2,i+2);
  }
  suma += m(m(dyn[2][g+1],dyn[1][g]),dyn[0][g-1]);
  printf("%d\n",suma);
}
