#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

#define FOR(x,y,z) for(int x=y;x<=z;++x)
#define REP(x,y) for(int x=0;x<y;++x)

#define DBGasd

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

int wynik,wynik2;

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
     
     #ifdef DBGw
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
     printf("cykl(%d):\n",wynik);
     REP(i,C.size())
        printf("%d moze: %d wyc: %d\n",C[i],moze[C[i]],wyc[C[i]]);
     #endif
     
     int iprev;
     int inext;
     
     
     vector<int> V;
     REP(i,C.size())
        if(wyc[C[i]])
           V.push_back(i);
     
     int vi;
     int vinext,viprev;
     while(!V.empty())
     {
        vi = *V.begin();
        V.erase(V.begin());
        iprev = vi == 0 ? C.size() - 1 : vi - 1;
        inext = vi == C.size() - 1 ? 0 : vi + 1;
        
        viprev = iprev == 0 ? C.size() - 1 : iprev - 1;
        vinext = inext == C.size() - 1 ? 0 : inext + 1;
        
        if(!wyc[C[inext]] && moze[C[inext]] && !wyc[C[vinext]]) {
           #ifdef DBG
           printf("vi %d iprev %d inext %d viprev %d vinext %d\n",vi,iprev,inext,viprev,vinext);
           #endif
           ++wynik;
           wyc[C[inext]] = wyc[C[vinext]] = true;
           V.push_back(vinext);
        }
        if(!wyc[C[iprev]] && moze[C[iprev]] && !wyc[C[viprev]]) {
           ++wynik;
           wyc[C[iprev]] = wyc[C[viprev]] = true;
           V.push_back(viprev);
        }
     }
     #ifdef DBG
     printf("wynik: %d\n",wynik);
     #endif
     
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
     
     #ifdef DBG
     printf("wynik: %d\n",wynik);
     #endif
     REP(i,C.size())
     {
        iprev = i == 0 ? C.size() - 1 : i - 1;
        inext = i == C.size() - 1 ? 0 : i + 1;
        if(!wyc[C[i]]) {
           if(!wyc[C[inext]] && moze[C[inext]]) {
              ++wynik;
              wyc[C[i]] = wyc[C[inext]] = true;
              continue;
           }
           if(!wyc[C[iprev]] && moze[C[iprev]]) {
              ++wynik;
              wyc[C[i]] = wyc[C[iprev]] = true;
              continue;
           }
           if(!wyc[C[inext]] && !wyc[C[iprev]]) {
              ++wynik;
              wyc[C[i]] = wyc[C[inext]] = wyc[C[iprev]] = true;
           }
        }
     }
     
     
     
     
     
     
     wynik2 = wynik;
     wynik = 0;
     reverse(C.begin(),C.end());
     FOR(i,1,n)
     {
        P[i] = size[i] = 0;
        visited[i] = visited2[i] = finished[i] = moze[i] = wyc[i] = false;
     }
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
     printf("cykl(%d):\n",wynik);
     REP(i,C.size())
        printf("%d moze: %d wyc: %d\n",C[i],moze[C[i]],wyc[C[i]]);
     #endif
     
     
     REP(i,C.size())
        if(wyc[C[i]])
           V.push_back(i);
     
     while(!V.empty())
     {
        vi = *V.begin();
        V.erase(V.begin());
        iprev = vi == 0 ? C.size() - 1 : vi - 1;
        inext = vi == C.size() - 1 ? 0 : vi + 1;
        
        viprev = iprev == 0 ? C.size() - 1 : iprev - 1;
        vinext = inext == C.size() - 1 ? 0 : inext + 1;
        
        if(!wyc[C[inext]] && moze[C[inext]] && !wyc[C[vinext]]) {
           #ifdef DBG
           printf("vi %d iprev %d inext %d viprev %d vinext %d\n",vi,iprev,inext,viprev,vinext);
           #endif
           ++wynik;
           wyc[C[inext]] = wyc[C[vinext]] = true;
           V.push_back(vinext);
        }
        if(!wyc[C[iprev]] && moze[C[iprev]] && !wyc[C[viprev]]) {
           ++wynik;
           wyc[C[iprev]] = wyc[C[viprev]] = true;
           V.push_back(viprev);
        }
     }
     #ifdef DBG
     printf("wynik: %d\n",wynik);
     #endif
     
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
     
     #ifdef DBG
     printf("wynik: %d\n",wynik);
     #endif
     REP(i,C.size())
     {
        iprev = i == 0 ? C.size() - 1 : i - 1;
        inext = i == C.size() - 1 ? 0 : i + 1;
        if(!wyc[C[i]]) {
           if(!wyc[C[inext]] && moze[C[inext]]) {
              ++wynik;
              wyc[C[i]] = wyc[C[inext]] = true;
              continue;
           }
           if(!wyc[C[iprev]] && moze[C[iprev]]) {
              ++wynik;
              wyc[C[i]] = wyc[C[iprev]] = true;
              continue;
           }
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
       srand(time(0));
       scanf("%d",&n);
       REP(i,n)
       {
          scanf("%d %d",&a,&b);
          G[a].push_back(b);
          G[b].push_back(a);
       }
       #ifdef DBGw
       REP(j,n)
       {
       wynik = 0;
       C.clear();
       FOR(i,0,n)
       {
          visited[i] = visited2[i] = moze[i] = wyc[i] = onCycle[i] = finished[i] = false;
          P[i] = size[i] = 0;
       }
       dfs(j+1,0);
       printf("pro %d\n",wynik);
       }
       #endif
       dfs(1,0);
       
       printf("%d\n",max(wynik,wynik2));
       return 0;
}
       


