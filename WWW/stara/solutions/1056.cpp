#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

typedef long long LL;

#define FOR(x,y,z) for(int x=y;x<=z;++x)
#define REP(x,y) for(int x=0;x<y;++x)
#define FORD(x,y,z) for(int x=y;x>=z;--x)

#define PB push_back

#define det(P,R) (P.x*R.y - P.y*R.x)
#define det2(Q,P,R) (LL(P.x-Q.x)*LL(R.y-Q.y) - LL(P.y-Q.y)*LL(R.x-Q.x))
#define cross(P,Q,R,S) ( ((det2(P,Q,R) < 0 && det2(P,Q,S) > 0) || (det2(P,Q,R) > 0 && det2(P,Q,S) < 0)) && ((det2(R,S,Q) < 0 && det2(R,S,P) > 0) || (det2(R,S,Q) > 0 && det2(R,S,P) < 0)) )


#define DBGa

/*#ifdef DBG
   #define debug(fmt, ...) fprintf(stderr, fmt, ## __VA_ARGS__ )
#else
   #define debug(fmt, ...)
#endif*/

const int MAXD = 16;
const int MAXS = 4096;
const int MAXV = 23000;
const LL INF = 2000000001;

struct pkt {
   int x, y;
   int time;
   int value;
   pkt() {}
   pkt(int x1, int y1) {
      x = x1;
      y = y1;
   }
   pkt(int x1, int y1, int time1, int value1) {
      x = x1;
      y = y1;
      time = time1;
      value = value1;
   }
};

struct wyspa {
   vector<pkt> brzeg;
   vector<pkt> skarby;
   int time;
   int value;
   void policz() {
        time = value = 0;
        REP(i,skarby.size())
        {
           time += skarby[i].time;
           value += skarby[i].value;
        }
        value += (value * skarby.size()) / 100 + ((value * skarby.size()) % 100 != 0);
        //debug("Wyspa time %d value %d\n",time, value);
   }
   bool nalezy(pkt P) {
        bool czy = false;
        REP(i,brzeg.size()-1)
        {
           czy ^= (cross(P,pkt(INF,P.y-1),brzeg[i],brzeg[i+1]));
           //debug("brzeg: %d %d  %d %d -> %d\n", brzeg[i].x, brzeg[i].y, brzeg[i+1].x, brzeg[i+1].y, cross(P,pkt(INF,P.y+1),brzeg[i],brzeg[i+1]));
           //debug("%lld %lld   %lld %lld\n",det2(P,pkt(INF,P.y-1),brzeg[i+1]),det2(P,pkt(INF,P.y-1),brzeg[i]), det2(brzeg[i],brzeg[i+1],P), det2(brzeg[i],brzeg[i+1],pkt(INF,P.y-1)));
        }
        return czy;
   }
};

wyspa W[MAXD+1];
pkt SK[MAXS];

vector<pkt> Z;

int tab[MAXV];

int D, S, T;

int maxValue = MAXV - 10;

int wynik;

inline void umiesc(int X, int Y, int C, int V) {
       REP(i,D)
       {
          //debug("sprawdzane P %d %d W %d\n",X, Y, i);
          if(W[i].skarby.size() == 32)
             continue;
          if(W[i].nalezy(pkt(X, Y))) {
             W[i].skarby.PB(pkt(X, Y, C, V));
             //debug("umieszczono %d %d w %d\n", X, Y, i);
             return;
          }
       }
       //debug("umieszczono %d %d poza\n", X, Y);
       W[D].skarby.PB(pkt(X, Y, C, V));
}

inline void zlicz() {
     FOR(i,1,maxValue)
        tab[i] = 1000000001;
     tab[0] = 0;
     REP(i,Z.size())
     {
        //debug("   %d %d\n",Z[i].time, Z[i].value);
        FORD(j,maxValue,0)
        {
           tab[j+Z[i].value] = min(tab[j+Z[i].value], tab[j] + Z[i].time);
        }
     }
     FORD(i,maxValue,0)
        if(tab[i] <= T) {
           wynik = max(wynik, i);
           return;
        }
}

inline void licz() {
     wynik = 0;
     REP(i,(1<<D))
     {
        Z.clear();
        //debug("rozklad %d\n",i);
        FOR(j,0,D)
        {
           if((i>>j)&1) { // wyspe traktuje jako punkt
              //debug("       %d %d\n",W[j].time, W[j].value);
              Z.PB(pkt(0, 0, W[j].time, W[j].value));
           }
           else {
              REP(k,W[j].skarby.size())
                 if(W[j].skarby[k].value > 0)
                    Z.PB(W[j].skarby[k]);
           }
        }
        zlicz();
     }
     printf("%d\n",wynik);
}

int x;
int a, b, c, d;

inline void okreslMaxValue() {
       maxValue = 5;
       int temp;
       REP(i,D)
       {
          temp = 0;
          REP(j,W[i].skarby.size())
             if(W[i].skarby[j].value > 0)
                temp += W[i].skarby[j].value;
          maxValue += max(temp, W[i].value);
       }
       REP(j,W[D].skarby.size())
          if(W[D].skarby[j].value > 0)
             maxValue += W[D].skarby[j].value;
}

inline void vanish() {
     REP(i,D)
     {
        W[i].brzeg.clear();
        W[i].skarby.clear();
     }
}

main() {
       int z;
       scanf("%d",&z);
       while(z--)
       {
          scanf("%d %d", &D, &S);
          vanish();
          REP(i,D)
          {
             scanf("%d", &x);
             while(x--)
             {
                scanf("%d %d", &a, &b);
                //debug("brzeg %d %d\n",a,b);
                W[i].brzeg.PB(pkt(a,b));
                //debug("%d %d\n",W[i].brzeg.back().x,W[i].brzeg.back().y);
             }
             W[i].brzeg.PB(W[i].brzeg[0]);
          }
          REP(i,S)
          {
             scanf("%d %d %d %d", &a, &b, &c, &d);
             umiesc(a, b, c, d);
          }
          REP(i,D)
             W[i].policz();
          scanf("%d", &T);
          okreslMaxValue();
          licz();
       }
       return 0;
}
       
