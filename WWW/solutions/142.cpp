#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 100100
#define INF  200100009

struct v{
    int id; long long w;
    v(){};
    v( int ii, long long ww ) : id(ii), w(ww) {};
};

bool operator<( v a, v b ){
    if ( a.w == b.w ) return a.id > b.id;
    return a.w > b.w;
}

bool stacja[MAXN];
bool visited[MAXN];
int ans[MAXN];
int p[MAXN];
long long d[MAXN];
vector< v > G[MAXN];
vector< int > T[MAXN];

int main(){
int n, m, r; scanf("%d%d%d", &n, &m, &r);

for ( int i=0; i<=n; ++i ) {
    stacja[i] = visited[i] = 0;
    d[i] = INF;
    p[i] = -1;
}

for ( int i=1; i<=r; ++i ){
    int a; scanf("%d", &a); stacja[a] = 1;
}

for ( int i=0; i<m; ++i ){
    int a, b, c; scanf("%d%d%d", &a, &b, &c);
    G[a].push_back( v(b, c) );
    G[b].push_back( v(a, c) );
}

for ( int i=1; i<=n; ++i ){
    if ( stacja[i] ) G[0].push_back( v(i, 0) );
}

priority_queue< v > Q;
Q.push( v(0, 0) ); visited[0] = 0; d[0] = 0;

while( ! Q.empty() ){
    v cur = Q.top();
    Q.pop();

    if (  d[ cur.id ] < cur.w  ) continue;

    visited[ cur.id ] = 1;

    for ( vector<v>::iterator i=G[cur.id].begin(); i!=G[cur.id].end(); ++i ){
        if ( ! visited[ i->id ] && (cur.w + i->w) < d[ i->id ] ) {
            d[ i->id ] = cur.w + i->w;
            p[ i->id ] = cur.id;
            Q.push( v(i->id, d[ i->id ]) );
        }
    }

}

for ( int i=0; i<=n; ++i ){
    if ( p[i] > 0 ) {
        T[ p[i] ].push_back( i );
    }
    ans[i] = -1;
}

for ( int root=1; root<=n; ++root ){
    if ( stacja[root] ){

        queue<int> Q;
        Q.push( root );
        while( ! Q.empty() ){
            int cur = Q.front(); Q.pop();
            ans[cur] = root;
            for ( vector<int>::iterator i=T[cur].begin(); i!=T[cur].end(); ++i ){
                Q.push( *i );
            }
        }

    }
}

int q; scanf("%d", &q);
while(q--){
    int a; scanf("%d", &a);
    if ( ans[a] < 0 ){
        printf("BRAK\n");
    } else {
        printf("%d %d\n", ans[a], d[a]);
    }
}

return 0;
}
