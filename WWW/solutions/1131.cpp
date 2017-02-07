#include<cstdio>
#include<set>
#include<list>
#include<algorithm>
using namespace std;
multiset<int> Graph[100000];
list<int> Euler_Cycle;
int Gtmp;
void Euler(int v){
    while(!Graph[v].empty()){
        Gtmp = *Graph[v].begin();
        Graph[v].erase(Graph[v].begin());
        Graph[Gtmp].erase(Graph[Gtmp].find(v));
        Euler(Gtmp);
    }
    Euler_Cycle.push_front(v);
}
int main(){
    int n,m,a,b;
    scanf("%d%d", &n, &m);
    while(m--){
        scanf("%d%d", &a, &b);
        --a;
        --b;
        Graph[a].insert(b);
        Graph[b].insert(a);
    }
    for(int i=0;i<n;++i)
        if(Graph[i].size()&1){
            printf("-1\n");
            return 0;
        }
    Euler(0);
    for(list<int>::iterator i = Euler_Cycle.begin();i!=Euler_Cycle.end();++i)
        printf("%d ", 1+*i);
    return 0;
}
