#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

#define FOR(x,y,z) for(int x=y;x<=z;++x)
#define REP(x,y) for(int x=0;x<y;++x)

#define DBGq

const int MAX = 100000;

struct vertex {
   int v;
   int deep;
   vertex() {}
   vertex(int v1, int deep1) {
      v = v1;
      deep = deep1;
   }
   bool operator<(const vertex &q) const {
      return deep < q.deep;
   }
};

vector<int> G[MAX+1];
vector<int> C;

priority_queue<vertex> Q;

int P[MAX+1];
int size[MAX+1];
bool visited[MAX+1];
bool visited2[MAX+1];
bool finished[MAX+1];
bool onCycle[MAX+1];
bool moze[MAX+1];
bool wyc[MAX+1];

int n;
int a,b;

int wynik;

void wycTree(int c) {
     vertex v;
     while(!Q.empty())
     {
        v = Q.top();
        #ifdef DBG
        printf("V: %d wyc: %d P: %d\n",v.v,wyc[v.v],P[v.v]);
        #endif
        Q.pop();
        if(wyc[v.v])
           continue;
        if(wyc[P[v.v]])
           continue;
        /*if(P[v] == c) {
           moze[c] = true;
           continue;
        }*/
        if(size[P[v.v]] > 1) {
           ++wynik;
           if(P[v.v] != c)
              --size[P[P[v.v]]];
           --size[P[v.v]];
           wyc[v.v] = wyc[P[v.v]] = true;
           //REP(i,G[P[v.v]].size())
           //   if(G[P[v.v]][i] != P[P[v.v]])
           //      wyc[G[P[v.v]][i]] = true;
        }
        else if(size[P[v.v]] == 1) {
           if(P[v.v] == c) {
              moze[c] = true;
           }
           else {
              if(wyc[P[P[v.v]]])
                 continue;
              ++wynik;
              wyc[v.v] = wyc[P[v.v]] = wyc[P[P[v.v]]] = true;
              --size[P[v.v]];
              --size[P[P[v.v]]];
              if(P[P[v.v]] != c)
                 --size[P[P[P[v.v]]]];
           }
        }
     }
}

void dfsDeep(int v, int deep) {
     size[v] = G[v].size() - 1;
     visited2[v] = true;
     Q.push(vertex(v,deep));
     REP(i,G[v].size())
        if(!visited2[G[v][i]]) {
           P[G[v][i]] = v;
           dfsDeep(G[v][i],deep+1);
        }
}

void cykl(int v, int u) {
     while(v != u)
     {
        onCycle[v] = true;
        C.push_back(v);
        v = P[v];
     }
     onCycle[v] = true;
     C.push_back(v);
     
     #ifdef DBG
     printf("cykl\n");
     REP(i,C.size())
        printf("%d ",C[i]); printf("\n");
     #endif
     
     REP(i,C.size())
     {
        visited2[C[i]] = true;
        size[C[i]] = G[C[i]].size() - 2;
        P[C[i]] = 0;
        REP(j,G[C[i]].size())
        {
           if(!onCycle[G[C[i]][j]]) {
              P[G[C[i]][j]] = C[i];
              dfsDeep(G[C[i]][j],1);
           }
        }
        #ifdef DBG1
        printf("wycTree %d\n",C[i]);
        #endif
        wycTree(C[i]);
        #ifdef DBGa
        printf("drzewo: %d\n",C[i]);
        while(!Q.empty())
        {
           printf("  %d P: %d\n",(Q.top()).v,P[(Q.top()).v]);
           Q.pop();
        }
        #endif
     }
     #ifdef DBG
     printf("cykl:\n");
     REP(i,C.size())
        printf("%d moze: %d wyc: %d\n",C[i],moze[C[i]],wyc[C[i]]);
     #endif
     
     int iprev;
     int inext;
     
     REP(i,C.size())
     {
        iprev = i == 0 ? C.size() - 1 : i - 1;
        inext = i == C.size() - 1 ? 0 : i + 1;
        if(moze[C[i]] && !wyc[C[i]]) {
           if(!wyc[C[inext]] && !moze[C[inext]]) {
              ++wynik;
              wyc[C[i]] = wyc[C[inext]] = true;
              continue;
           }
           if(!wyc[C[iprev]] && !moze[C[iprev]]) {
              ++wynik;
              wyc[C[i]] = wyc[C[iprev]] = true;
              continue;
           }
        }
     }
     
     REP(i,C.size())
     {
        iprev = i == 0 ? C.size() - 1 : i - 1;
        inext = i == C.size() - 1 ? 0 : i + 1;
        if(!wyc[C[i]]) {
           if(!wyc[C[inext]] && !wyc[C[iprev]]) {
              ++wynik;
              wyc[C[i]] = wyc[C[inext]] = wyc[C[iprev]] = true;
           }
        }
     }
}

void dfs(int v, int p) {
     visited[v] = true;
     P[v] = p;
     REP(i,G[v].size())
     {
        if(G[v][i] == p)
           continue;
        if(!visited[G[v][i]]) {
           dfs(G[v][i],v);
        }
        else
           if(!finished[G[v][i]])
              cykl(v,G[v][i]);
     }
     finished[v] = true;
}

main() {
       scanf("%d",&n);
       REP(i,n)
       {
          scanf("%d %d",&a,&b);
          G[a].push_back(b);
          G[b].push_back(a);
       }      
       dfs(1,0);
       printf("%d\n",wynik);
       return 0;
}
       


