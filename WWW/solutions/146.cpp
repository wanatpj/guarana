#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define INF 1000000000
struct Point{
    int x,y;
    Point(){}
    Point(int x, int y){
        this->x=x;
        this->y=y;
    }
};
struct Cmp{
    bool operator()(Point A, Point B){
        return A.y>B.y;
    }
};
priority_queue<Point, vector<Point>, Cmp> Q;
vector<Point> Graph[100000];
int d[100000],from[100000];
int main()
{
    int n,m,r,a,b,c;
    scanf("%d%d%d", &n, &m, &r);
    Point P;
    for(int i=0;i<100000;i++)
        d[i]=INF;
    while(r--){
        scanf("%d", &a);
        --a;
        d[a]=0;
        from[a]=a;
        Q.push(Point(a,0));
    }
    while(m--){
        scanf("%d%d%d", &a, &b, &c);
        --a;
        --b;
        Graph[a].push_back(Point(b,c));
        Graph[b].push_back(Point(a,c));
    }
    while(!Q.empty()){
        P=Q.top();
        Q.pop();
        if(P.y!=d[P.x]) continue;
        for(vector<Point>::iterator i = Graph[P.x].begin(); i!=Graph[P.x].end();i++)
            if(d[i->x]>d[P.x]+i->y){
                d[i->x]=d[P.x]+i->y;
                Q.push(Point(i->x,d[i->x]));
                from[i->x]=from[P.x];
            }
            else if(d[i->x]==d[P.x]+i->y&&from[i->x]>from[P.x])
                from[i->x]=from[P.x];
    }
    scanf("%d", &m);
    while(m--){
        scanf("%d", &a);
        --a;
        if(d[a]==INF)
            {printf("BRAK\n"); continue;}
        printf("%d %d\n", from[a]+1, d[a]);
    }
    return 0;
}
