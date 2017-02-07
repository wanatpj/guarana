#include <iostream>
#include <cstdio>
#include <vector>

typedef long long LL;

// == il na LL ========
#define DET(a,b,c) (LL(b.x-a.x)*LL(c.y-a.y)-LL(b.y-a.y)*(c.x-a.x))

using namespace std;

struct point{
    double x, y;
    point(){};
    point(LL xx, LL yy) : x(xx), y(yy) {};
    point(double xx, double yy) : x(xx), y(yy) {};
    bool operator == (point & a){
        return a.x == x && a.y == y;
    }
};

bool cmp( point a, point b ){
    if ( a.x == b.x ) return a.y < b.y;
    return a.x < b.x;
}

inline int sgn(double a){
    if ( a < 0 ) return -1;
    if ( a == 0 ) return 0;
    if ( a > 0 ) return 1;
}

inline bool samesig(double a, double b){
    if (a >= 0 && b >= 0) return true;
    if (a < 0 && b < 0) return true;
return false;
}

vector< point > P;
vector< point > T1, T2;

// Ponizsza funkcja pochodzi z ACMowej biblioteczki algorytmicznej.
inline bool SegmentCrossPoint( point p1, point p2, point l1, point l2, vector<point> &r ){
    int w1 = sgn(DET(p1, p2, l1) ), w2 = sgn(DET(p1, p2, l2)),
        v1 = sgn(DET(l1, l2, p1) ), v2 = sgn(DET(l1, l2, p2));
    if ( w1*w2 > 0 || v1*v2 > 0 ) return false;
    if ( ! w1 && ! w2 ){
        if ( cmp(p2, p1) ) swap(p1, p2);
        if ( cmp(l2, l1) ) swap(l1, l2);
        if ( cmp(p2, l1) || cmp(l2, p1) ) return false;
        if ( p2 == l1 ) r.push_back( point(p2.x, p2.y) );
        else if ( p1 == l2 ) r.push_back( point(l2.x, l2.y) );
        else {
            r.push_back( cmp(p1, l1) ? l1 : p1 );
            r.push_back( cmp(p2, l2) ? p2 : l2 );
        }
    }
    else {
        double t = double( LL(l2.x-p2.x) * LL(l1.y-l2.y) - LL(l2.y-p2.y) * LL(l1.x-l2.x) ) / double(LL(p1.x-p2.x) * LL(l1.y-l2.y) - LL(p1.y-p2.y) * LL(l1.x-l2.x) );
        r.push_back( point( t*p1.x + (1.0-t)*p2.x, t*p1.y + (1.0-t)*p2.y ) );
    }
}

inline void przetnij(int i, int j){
    // przeciecie odcinkow (T1[i], T1[i+1]) i (T2[j], T2[j+1])
    SegmentCrossPoint( T1[i], T1[ (i+1)%3], T2[j], T2[ (j+1)%3 ], P );                                                                                                                                                                                      
}

inline double absol(double a){
    if ( a >= 0 ) return a;
    return a * (-1.0);
}

double pole(  vector<point> &a ){
    double ret = 0;
    int ss = a.size();
    for (int x=0; x<ss; ++x) ret += ( a[x].x + a[ (x+1)%ss ].x ) * ( a[x].y - a[ (x+1)%ss ].y );
    return absol(ret) / 2.0;
}

// ==== il. na doublach =====
inline double il_wek_wsp(double x1, double y1, double x2, double y2){return x1*y2-x2*y1;}

inline double il_wek(point p1, point p2, point p3){
    return il_wek_wsp(p2.x-p1.x, p2.y-p1.y, p3.x-p1.x, p3.y-p1.y);
}

void nalezenie_do_1(int i){
    // czy T2[i] nalezy do T1
    if ( T2[i] == T1[0] || T2[i] == T1[1] || T2[i] == T1[2] ){
        P.push_back( T2[i] ); return;
    }
    point a = T1[0], b = T1[1], c = T1[2];
    if (  samesig( il_wek( a, b, T2[i] ) , il_wek( a, T2[i], c ) ) &&
          samesig( il_wek( b, a, T2[i] ) , il_wek( b, T2[i], c ) ) &&
          samesig( il_wek( c, b, T2[i] ) , il_wek( c, T2[i], a ) )    ) {
            P.push_back( T2[i] );
          }
}

void nalezenie_do_2(int i){
    // czy T1[i] nalezy do T2
    if ( T1[i] == T2[0] || T1[i] == T2[1] || T1[i] == T2[2] ){
        P.push_back( T1[i] ); return;
    }
    point a = T2[0], b = T2[1], c = T2[2];
    if (  samesig( il_wek( a, b, T1[i] ) , il_wek( a, T1[i], c ) ) &&
          samesig( il_wek( b, a, T1[i] ) , il_wek( b, T1[i], c ) ) &&
          samesig( il_wek( c, b, T1[i] ) , il_wek( c, T1[i], a ) )    ) {
            P.push_back( T1[i] );
          }
}

int main(){
long long x, y;
T1.resize(3); T2.resize(3);

for (int i=0; i<3; ++i) scanf("%lf%lf", &T1[i].x, &T1[i].y);
for (int i=0; i<3; ++i) scanf("%lf%lf", &T2[i].x, &T2[i].y);
for ( int i=0; i<3; ++i ){
    for ( int j=0; j<3; ++j ){
        przetnij(i, j);
    }
}

for ( int i=0; i<3; ++i ){
    nalezenie_do_1( i );
    nalezenie_do_2( i );
}

sort( P.begin(), P.end(), cmp );

P.resize( unique(P.begin(), P.end()) - P.begin() );

if ( P.size() > 0 ){

//    for ( int i=0; i<P.size(); ++i ) cout << "( " << P[i].x << ", " << P[i].y << " )" << endl;

    point center; int ss = P.size();
/*for ( int i=0; i<ss; ++i ){
    center.x += P[i].x;
    center.y += P[i].y;
}

center.x = center.x / double(ss); center.y = center.y / double(ss);
*/

    center.x = P[0].x; center.y = P[0].y;

// waskie gardlo: sortowanie n^2 xD.
    for ( int a=0; a<ss; ++a ){
        for ( int b=1; b<ss; ++b ){
                if ( ( il_wek( center, P[b-1], P[b] ) ) < 0 ) swap( P[b-1], P[b] );
        }
    }

}

double pierwszy = pole( T1 );
double drugi = pole( T2 );
double przeciecie = pole( P );

//cout << "1: " << pierwszy << endl;
//cout << "2: " << drugi << endl;
//cout << "p: " << przeciecie << endl;

double wynik = pierwszy + drugi - przeciecie;

printf("%.5lf\n", wynik);
return 0;
}
