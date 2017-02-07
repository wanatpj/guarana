#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct edge{
    int v,d;
    int w;
    edge(){}
    edge(int v, int d){
        this->v=v;
        this->d=d;
    }
    edge(int v, int w, int d){
        this->v=v;
        this->w=w;
        this->d=d;
    }
};
vector<edge> Graph[10000];
vector<edge> container;
int n,m;
int gb,gd;
int nb[1001];
bool color[10000];
bool visit(int a, bool b){
    color[a]=0;
    if(a==gb) return b;
    for(vector<edge>::iterator i=Graph[a].begin();i!=Graph[a].end();++i)
        if(color[i->v]){
        if(i->d==gd)
            if(visit(i->v,true)) return true;
        else if(visit(i->v,b)) return true;
    }
    return false;
}
bool DFS(int a, int b, int d){
    gb=b;
    gd=d;
    for(int i=0;i<10000;i++)
        color[i]=true;
    return visit(a,0);
}
int main()
{
    for(int i=0;i<1001;++i)
        nb[i]=0;
    scanf("%d%d", &n, &m);
    int a,b,c,f1,f2;
    int mnb=0;
    while(m--){
        scanf("%d%d%d%d%d", &a, &b, &c, &f1, &f2);
        --a;
        --b;
        if(f2) ++nb[c];
        if(f1) --nb[c];
        if(f2==1&&f1==0) {++mnb; container.push_back(edge(a,b,c));}
        if(f1==1){
            Graph[a].push_back(edge(b,c));
            Graph[b].push_back(edge(a,c));
        }
    }
    for(int i=0;i<1001;++i)
        if(nb[i]!=0)
            {printf("NIE\n"); return 0;}
    random_shuffle(container.begin(),container.end());
    int x=min(500,(int)container.size());
    for(int i=0;i<x;i++)
        if(!DFS(container[i].v,container[i].w,container[i].d))
            {printf("NIE\n"); return 0;}
    printf("%d\n", mnb);
    return 0;
}
