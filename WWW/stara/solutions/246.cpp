#define DBiG
// autor programu: Grzegorz Guspiel
// V LO im. Augusta Witkowskiego w Krakowie

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#ifdef DBG
#define REPORT(x) cout<<x<<endl
#else
#define REPORT(x)
#endif

#define fore(i) for(int i=0; i<adj.size(); i++) if(adj[i]!=p)
#define foret(i) for(int i=0; i<adj.size(); i++) if(adj[i]!=p && adj[i]->nr!=zly)
/////////////////////////////////////////////////////////

int n;
const int maxv=100100;
typedef pair<int,int> pii;
vector<pii> kand;
pii luka;
const int minf=-10000000;

struct node {
	bool v;
	int nr;
	vector<node*> adj;
	node* p;
	int w[3];
	node(): v(0) {}
	// sciaga:
	// 0: this jest raczej zajety
	// 1: this jest wolny
	// 2: this + jeszcze jeden poziom nizej wolny
	void cykl(node* from) {
		REPORT("dfs "<<nr);
		p=from;
		if(v) {
			kand.push_back(pii(nr, p->nr));
			kand.push_back(pii(p->nr, p->p->nr));
			kand.push_back(pii(p->p->nr, p->p->p->nr));
			for(int i=0; i<3; i++)
				if(kand[i].first>kand[i].second) swap(kand[i].first,kand[i].second);
			return;
		}
		v=1;
		fore(i) adj[i]->cykl(this);		
	}
	void licz(node* from) {
		p=from;
		int zly=0;
		if(nr==luka.first) zly=luka.second;
		if(nr==luka.second) zly=luka.first;
		foret(i) adj[i]->licz(this);
		int suma=0;
		foret(i) suma+=adj[i]->w[0];
		{ // w[2]
			w[2]=minf;
			foret(i) w[2]=max(w[2],suma-adj[i]->w[0]+adj[i]->w[1]);
		}
		{ // w[1]
			w[1]=max(w[2],suma);
		}
		{ // w[0]
			w[0]=w[1];
			foret(i) w[0]=max(w[0],suma-adj[i]->w[0]+adj[i]->w[2]+1);
			pii best; best.first=minf; best.second=minf;
			foret(i) if(adj[i]->w[1]-adj[i]->w[0]>best.second) {
				best.second=adj[i]->w[1]-adj[i]->w[0];
				if(best.second>best.first) swap(best.second,best.first);
			}
			w[0]=max(w[0],suma+best.first+best.second+1);
		}

	}
};
node t[maxv];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		int a,b; scanf("%d%d", &a, &b);
		t[a].adj.push_back(t+b);
		t[b].adj.push_back(t+a);
	}
	for(int i=0; i<=n; i++) t[i].nr=i;
	t[1].cykl(0);	
#ifdef DBG 
	for(int i=0; i<3; i++) REPORT("kand "<<i<<" : "<<kand[i].first<<"<->"<<kand[i].second);
#endif
	int best=0;
	for(int i=0; i<3; i++) {
		luka=kand[i];
		t[1].licz(0);
		best=max(best,t[1].w[0]);
	}
	printf("%d\n", best);
	return 0;
}


