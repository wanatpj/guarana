//Wynik: multigraf eulerwski, który może zawierać pętle
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<time.h>
using namespace std;
#define MAX_V 100000
#define MAX_E 500000
struct Point{
    int a,b;
};
vector<Point> G;
int deg[100000];
int main()
{
    srand(time(NULL));
    int V,E;
    scanf("%d %d", &V, &E);
    if(V>MAX_V) return 0;
    Point tmp;
    for(int i=0;i<V;++i)
        deg[i]=0;
    while(E--){
        tmp.a = rand()%V;
        tmp.b = rand()%V;
        G.push_back(tmp);
        ++deg[tmp.a];
        ++deg[tmp.b];
    }
    for(int i=0;i<V;++i)
        if(deg[i]&1){
            tmp.a = i;
            tmp.b = rand()%(V-i-1);
            tmp.b += i+1;
            ++deg[tmp.b];//wartość oczekiwana ilości?
            G.push_back(tmp);
        }
    if(G.size()>MAX_E) return 0;
    printf("%d %d\n", V, G.size());
    for(vector<Point>::iterator i = G.begin();i!=G.end();++i)
        printf("%d %d\n", 1+i->a, 1+i->b);
    return 0;
}

