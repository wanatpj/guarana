#include<cstdio>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
struct Point{
    int x,y;
    Point(){}
    Point(int x, int y){
        this->x=x;
        this->y=y;
    }
    bool operator<(const Point &B) const{
        return x<B.x;
    }
};
vector<Point> Graph[100000];
vector<Point>::iterator Its[100000];
bool color[500000];
list<int> Euler_Cycle;
void Euler(int v){
    while(!color[Its[v]->y])
        ++Its[v];
    color[Its[v]->y]=0;
    Euler(Its[v]->x);
    Euler_Cycle.push_front(v);
}
int main(){
    int n,m,a,b;
    scanf("%d%d", &n, &m);
    for(int i=0;i<m;++i)
        color[i]=1;
    while(m--){
        scanf("%d%d", &a, &b);
        --a;
        --b;
        Graph[a].push_back(Point(b,m));
        Graph[b].push_back(Point(a,m));
    }
    for(int i=0;i<n;++i)
        if(Graph[i].size()&1){
            printf("-1\n");
            return 0;
        }
    for(int i=0;i<n;++i)
        sort(Graph[i].begin(),Graph[i].end());
    for(int i=0;i<n;++i)
        Its[i]=Graph[i].begin();
    Euler(0);
    for(list<int>::iterator i = Euler_Cycle.begin();i!=Euler_Cycle.end();++i)
        printf("%d ", 1+*i);
    return 0;
}
