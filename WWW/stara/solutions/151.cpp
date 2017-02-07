#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define FOR(x,y,z) for(int x=y;x<=z;++x)
#define REP(x,y) for(int x=0;x<y;++x)

#define DBGa

const int MAX = 100000;
const int INF = 1100000000;

struct edge {
   int v;
   int w;
   edge(int q, int e) {
      v = q;
      w = e;
   }
};

struct vertex {
   int v;
   int d;
   int p;
   vertex() {}
   vertex(int q, int e,int f) {
      v = q;
      d = e;
      p = f;
   }
   bool operator<(const vertex &z) const {
        if(d != z.d)
           return d > z.d;
        return p > z.p;
   }
};

int D[MAX+1];
int P[MAX+1];

vector<edge> G[MAX+1];
priority_queue<vertex> Q;

bool visited[MAX+1];

int n,m,r;
int a,b,c;
int q;

void dijkstra() {
     vertex v;
     
     while(!Q.empty())
     {
        v = Q.top();
        Q.pop();
        if(visited[v.v])
           continue;
        visited[v.v] = true;
        D[v.v] = v.d;
        P[v.v] = v.p;
        REP(i,(int)G[v.v].size())
           if(!visited[G[v.v][i].v])
              Q.push(vertex(G[v.v][i].v,v.d+G[v.v][i].w,v.p));
     }
}

main() {
       scanf("%d %d %d",&n,&m,&r);
       FOR(i,1,n)
          D[i] = INF;
       REP(i,r)
       {
          scanf("%d",&a);
          Q.push(vertex(a,0,a));
       }
       while(m--)
       {
          scanf("%d %d %d",&a,&b,&c);
          G[a].push_back(edge(b,c));
          G[b].push_back(edge(a,c));
       }
       dijkstra();
       scanf("%d",&q);
       while(q--)
       {
          scanf("%d",&a);
          if(D[a] == INF)
             printf("BRAK\n");
          else
             printf("%d %d\n",P[a],D[a]);
       }
       return 0;
}
       
