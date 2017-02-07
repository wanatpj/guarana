#define DBiG
// autor programu: Grzegorz Guspiel
// 2e, V LO Krakow

#ifdef DBG
#define REP(x) cout<<x<<endl;
#else
#define REP(x)
#endif

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
using namespace std;

// =====================================================

const int inf=1000000000;
const int maxv=100100;
struct cVertex {
	int id;
	int layer;
	void initSearch() {
		layer=inf;
	}
};

typedef pair<int,int> cEdge;
typedef pair<int,int> pii;
struct cResult {
	vector<int> r;
	int minimum;
	cResult(): minimum(inf) {}
	void push(int i) { r.push_back(i); minimum=min(minimum,i); }
	bool operator<(const cResult& rhs) const {
		// must be sorted (both)
		if(r.size()==rhs.r.size()) {
			for(int i=0; i<r.size(); i++) if(r[i]!=rhs.r[i]) return r[i]<rhs.r[i];
			return 0;
		} else return r.size()>rhs.r.size();
	}
	void dodaj(cResult& rhs) {
		minimum=min(minimum,rhs.minimum);
		r.insert(r.end(), rhs.r.begin(), rhs.r.end());
	}
	void dDescribe(string name="") {
#ifdef DBG
		REP("RESULT "<<name.c_str()<<": "<<r.size());
		for(int i=0; i<r.size(); i++) cout<<r[i]<<" ";
		cout<<endl;
#endif
	}
};
int mapv[maxv];
struct cGraph {
	vector<cVertex> v;
	vector<cEdge> adj;
	void init() {
		v.clear();
		adj.clear();
	}
	int begin(int w) {
		return lower_bound(adj.begin(), adj.end(), cEdge(w,-1))-adj.begin();
	}
	int end(int w) {
		return upper_bound(adj.begin(), adj.end(),cEdge(w,inf))-adj.begin();
	}
	int vertexDegree(int vrt) {
		return end(vrt)-begin(vrt);
	}
	bool isEdge(int a, int b) {
		return binary_search(adj.begin(),adj.end(),cEdge(a,b));
	}
	bool isClique() {
		bool isc=1;
		for(int i=0; i<v.size(); i++) if(vertexDegree(i)<v.size()-1) { isc=0; break; }
		return isc;
	}
	bool isConnected() {
		bool isc=1;
		for(int i=0; i<v.size(); i++) if(v[i].layer==inf) { isc=0; break; }
		return isc;
	}
	void initVerticies() {
		for(int i=0; i<v.size(); i++) v[i].initSearch();
	}
	void bfs(int s) {
		v[s].layer=0;
		queue<int> q; q.push(s);
		while(!q.empty()) {
			int act = q.front(); q.pop();
			for(int i=begin(act); i<end(act); i++) if(v[adj[i].second].layer==inf) {
				v[adj[i].second].layer=v[act].layer+1;
				q.push(adj[i].second);
			}
		}
	} // UWAGA: ZMIANY BFS<=>BFSV
	vector<int> bfsv(int s) {
		v[s].layer=0;
		queue<int> q; q.push(s);
		vector<int> r;
		while(!q.empty()) {
			int act = q.front(); q.pop();
			r.push_back(act);
			for(int i=begin(act); i<end(act); i++) if(v[adj[i].second].layer==inf) {
				v[adj[i].second].layer=v[act].layer+1;
				q.push(adj[i].second);
			}
		}
		return r;
	}
	cGraph subGraph(vector<int> grv) {
		cGraph gr;
		gr.v.resize(grv.size());
		sort(grv.begin(), grv.end());
		for(int i=0; i<grv.size(); i++) {
			mapv[grv[i]]=i;
			gr.v[i].id=v[grv[i]].id;
		}
		for(int i=0; i<adj.size(); i++) if(binary_search(grv.begin(),grv.end(),adj[i].first)&&binary_search(grv.begin(),grv.end(),adj[i].second))
			gr.adj.push_back(adj[i]);
		for(int i=0; i<gr.adj.size(); i++) {
			gr.adj[i].first=mapv[gr.adj[i].first];
			gr.adj[i].second=mapv[gr.adj[i].second];
		}
		return gr;
	}
	struct cClass {
		vector<int> up,down;
		int downCount;
		void dDescribe(vector<cVertex>& context) {
#ifdef DBG
			REP("PROBLEM ");
			cout<<"up: ";
			for(int i=0; i<up.size(); i++) cout<<context[up[i]].id<<" ";
			cout<<endl;
			cout<<"dn: ";
			for(int i=0; i<down.size(); i++) cout<<context[down[i]].id<<" ";
			cout<<endl;
#endif
		}
	};
	cResult finalClique(int root) {
		REP("FINALclique running from "<<v[root].id);
		initVerticies()	;
		bfs(root);
		vector<cClass> problems;
		vector<pii> firstLayer;
		for(int i=0; i<v.size(); i++) if(v[i].layer==1) {
			int cnt=0;
			for(int j=begin(i); j<end(i); j++) if(v[adj[j].second].layer==2) cnt++;
			firstLayer.push_back(pii(cnt,i));
		}
		sort(firstLayer.begin(), firstLayer.end());
		int act=-1;
		REP("firstl "<<firstLayer.size());
		for(int i=0; i<firstLayer.size(); i++) {
			if(firstLayer[i].first!=act) {
				problems.push_back(cClass());
				problems[problems.size()-1].downCount=act=firstLayer[i].first;
			}
			problems[problems.size()-1].up.push_back(firstLayer[i].second);
		}
		set<int> s;
		for(int i=0; i<problems.size(); i++) 
			for(int j=begin(problems[i].up[0]); j<end(problems[i].up[0]); j++)
				if(v[adj[j].second].layer==2&&s.find(adj[j].second)==s.end()) {
					problems[i].down.push_back(adj[j].second);
					s.insert(adj[j].second);
				}
#ifdef DBG
		REP("list of problems, count: "<<problems.size());
		for(int i=0; i<problems.size(); i++) problems[i].dDescribe(v);
#endif
		cResult bestResult;
		set<int> sumka;
		for(int i=problems.size()-1; i>=0; i--) {
			cResult curUp=subGraph(problems[i].up).bestClique();
			cResult curDn=subGraph(problems[i].down).bestClique();
			for(int i=0; i<curUp.r.size(); i++) sumka.insert(curUp.r[i]);
			for(int i=0; i<curDn.r.size(); i++) sumka.insert(curDn.r[i]);
			bool remAdd=0;
			if(sumka.size()>bestResult.r.size()) remAdd=1;
			if(sumka.size()==bestResult.r.size()) {
				int i=0;
				set<int>::iterator is=sumka.begin();
				remAdd=1;
				for(; i<sumka.size(); i++, is++) if(*is>bestResult.r[i]) { remAdd=0; break; }
			}
			if(remAdd) {
				bestResult.r.clear();
				for(set<int>::iterator i=sumka.begin(); i!=sumka.end(); i++) {
					bestResult.r.push_back(*i);
					bestResult.minimum=min(bestResult.minimum,*i);
				}
				sort(bestResult.r.begin(),bestResult.r.end());
			}
			for(int i=0; i<curDn.r.size(); i++) sumka.erase(curDn.r[i]);
		}
		bestResult.dDescribe("FINAL");
		return bestResult;
	}
	cResult bestClique() {
		REP("BESTCLIQUE running on...");
		dDescribe();
		if(isClique()) {
			cResult r;
			for(int i=0; i<v.size(); i++) r.push(v[i].id);
			sort(r.r.begin(),r.r.end());
			REP("FINISH - it is a clique");
			r.dDescribe();
			return r;
		}
		// wiemy ze nie jest klika
		initVerticies();
		bfs(0);
		if(!isConnected()) {
			initVerticies();
			cResult bestr;
			for(int i=0; i<v.size(); i++) {
				if(v[i].layer!=inf) continue;
				vector<int> grv = bfsv(i);	
				cResult r = subGraph(grv).bestClique();
				if(r<bestr) bestr=r;
			}
			REP("FINISH - chosen the best component");
			bestr.dDescribe();
			return bestr;	
		}
		// wybierz dowolny brak krawedzi
		int root1=0;
	       	for(int i=v.size()-1; i>=0; i--) if(vertexDegree(i)<v.size()-1) root1=i;
		int root2=v.size()-1;
		for(int i=0; i<v.size(); i++) if(root1!=i&&!isEdge(root1,i)) { root2=i; break; }
		REP("found two: "<<v[root1].id<<" "<<v[root2].id);
		cResult res1=finalClique(root1);
		cResult res2=finalClique(root2);
		cResult* solution=&res1;
		if(res2<res1) solution=&res2;
		REP("FINISH - algorithm performed");
		solution->dDescribe("one of two");
		return *solution;
	}

	void dDescribe(string name="") {
#ifdef DBG
		REP("GRAPH "<<name.c_str()<<" V="<<v.size()<<" E="<<adj.size());
		cout<<"V: ";
		for(int i=0; i<v.size(); i++) cout<<v[i].id<<" ";
		cout<<endl;
		cout<<"E: ";
		for(int i=0; i<adj.size(); i++) if(v[adj[i].first].id<v[adj[i].second].id) cout<<v[adj[i].first].id<<"->"<<v[adj[i].second].id<<",";
		cout<<endl;
		cout<<"F: ";
		for(int i=0; i<adj.size(); i++) cout<<v[adj[i].first].id<<"->"<<v[adj[i].second].id<<",";
		cout<<endl;
#endif
	}
};


cGraph inputData;
int n;

int main() {
	int z; scanf("%d", &z);
	while(z--) {
		REP("===============================================================================");
		inputData.init();
		scanf("%d", &n);
		for(int i=1; i<n; i++) {
			int edgeCnt; scanf("%d", &edgeCnt);
			for(int j=0; j<edgeCnt; j++) {
				int a; scanf("%d", &a); 
				inputData.adj.push_back(cEdge(a-1,i));
				inputData.adj.push_back(cEdge(i,a-1));
			}
		}
		sort(inputData.adj.begin(), inputData.adj.end());
		inputData.v.resize(n);
		for(int i=0; i<n; i++) inputData.v[i].id=i;
		inputData.dDescribe("inputData");
		cResult result = inputData.bestClique();
		printf("%d\n", result.r.size());
		for(int i=0; i<result.r.size(); i++) printf("%d ",result.r[i]+1);
		printf("\n");
	}
	return 0;

}
