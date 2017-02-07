#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

#define REP(x,y) for(int x=0;x<y;++x)

#define DBG


struct pkt {
   double x,y;
   int TR;
   pkt() {}
   pkt(double X, double Y, int czyTR) {
      x = X;
      y = Y;
      TR = czyTR;
   }
   bool operator==(const pkt &P) const {
      return x == P.x && y == P.y;
   }
   bool operator!=(const pkt &P) const {
      return !( *(this) == P);
   }
};


struct prosta {
   pkt a,b;
   double A,B,C;
   prosta() {}
   prosta(pkt q, pkt w) {
      a = q;
      b = w;
      A = w.y - q.y;
      B = q.x - w.x;
      C = w.x*q.y - q.x*w.y;
   }
   bool operator==(const prosta &P) {
      return a == P.a && b == P.b;
   }
};

struct trojkat {
   pkt a,b,c;
   trojkat() {}
   trojkat(pkt t1, pkt t2, pkt t3) {
      a = t1;
      b = t2;
      c = t3;
   }
   trojkat(double ax, double ay, double bx, double by, double cx, double cy) {
      a = pkt(ax,ay,0);
      b = pkt(bx,by,0);
      c = pkt(cx,cy,0);
   }
};

double pole(trojkat T) {
   return abs((T.b.x-T.a.x)*(T.c.y-T.a.y) - (T.b.y-T.a.y)*(T.c.x-T.a.x))/2;
}
double pole(pkt a, pkt b, pkt c) {
   return pole(trojkat(a,b,c));
}

bool isPktIn(trojkat T, pkt Q) {
   return pole(T) == pole(trojkat(T.a,T.b,Q)) + pole(trojkat(T.a,T.c,Q)) + pole(trojkat(T.b,T.c,Q));
}

bool isTrojInTroj(trojkat T, trojkat R) {
   return isPktIn(T,R.a) && isPktIn(T,R.b) && isPktIn(T,R.c);
}

pkt pktPrzeciecia(prosta k, prosta l) {
    if(k.B == 0) {
       return pkt(k.a.x,-((l.A*k.a.x)/l.B) - l.C/l.B,0);
    }
    if(l.B == 0) {
       return pkt(l.a.x,-((k.A*l.a.x)/k.B) - k.C/k.B,0);
    }
    return pkt((l.C*k.B - k.C*l.B)/(k.A*l.B - l.A*k.B),
               -((k.A*k.B*l.C - k.A*l.B*k.C) / (k.A*k.B*l.B - l.A*k.B*k.B)) - k.C/k.B,
               0);
}

pkt p0;

int cwiartka(pkt P) {
    if(P.x >= 0 && P.y >= 0)
       return 1;
    if(P.x < 0 && P.y >= 0)
       return 2;
    if(P.x < 0 && P.y < 0)
       return 3;
    if(P.x >= 0 && P.y < 0)
       return 4;
}

bool operator<(const pkt &P, const pkt &R) {
   //if(P == p0)
   //   return 1;
   //if(R == p0)
   //   return 0;
   if(cwiartka(P) != cwiartka(R)) {
      return cwiartka(P) < cwiartka(R);
   }
   if(((P.x-p0.x)*(R.y-p0.y))-((R.x-p0.x)*(P.y-p0.y)) == 0)
      return P.y < R.y;
   return ((P.x-p0.x)*(R.y-p0.y))-((R.x-p0.x)*(P.y-p0.y)) > 0;
}

int x1,x2,x3,x4,x5,x6;
int yy1,y2,y3,y4,y5,y6;

trojkat A,B;

vector<pkt> V;

bool przecin(prosta,prosta);
bool on(pkt,pkt,pkt);
double iloczyn(pkt,pkt,pkt);

int ile;

bool niema(pkt P) {
     REP(i,V.size())
        if(V[i] == P)
           return false;
     return true;
}

bool niewlewo(pkt a, pkt b, pkt c) {
   return ((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y)) <= 0;
}

double kwa(double a) {
   return a*a;
}

double odl(pkt P, pkt R) {
   return sqrt(kwa(P.x-R.x) + kwa(P.y-R.y));
}

pkt atacz(pkt P, pkt R) {
       pkt wyn = pkt(10000.0,10000.0,0);
       
       if(P != (A.a) && P != A.b && P != A.c) {
         swap(P,R);
       }
       
       prosta prze = prosta(P,A.b);
       pkt przec;
       
       if(przecin(prze,prosta(R,B.b))) {
          przec = pktPrzeciecia(prze,prosta(R,B.b));
          if(odl(P,przec) + odl(R,przec) < odl(P,wyn) + odl(R,wyn))
             wyn = przec;
       }
       if(przecin(prze,prosta(B.a,R))) {
          przec = pktPrzeciecia(prze,prosta(B.a,R));
          if(odl(P,przec) + odl(R,przec) < odl(P,wyn) + odl(R,wyn))
             wyn = przec;
       }
       if(przecin(prze,prosta(B.c,R))) {
          przec = pktPrzeciecia(prze,prosta(B.c,R));
          if(odl(P,przec) + odl(R,przec) < odl(P,wyn) + odl(R,wyn))
             wyn = przec;
       }
       
       prze = prosta(P,A.c);
       if(przecin(prze,prosta(R,B.b))) {
          przec = pktPrzeciecia(prze,prosta(R,B.b));
          if(odl(P,przec) + odl(R,przec) < odl(P,wyn) + odl(R,wyn))
             wyn = przec;
       }
       if(przecin(prze,prosta(B.a,R))) {
          przec = pktPrzeciecia(prze,prosta(B.a,R));
          if(odl(P,przec) + odl(R,przec) < odl(P,wyn) + odl(R,wyn))
             wyn = przec;
       }
       if(przecin(prze,prosta(B.c,R))) {
          przec = pktPrzeciecia(prze,prosta(B.c,R));
          if(odl(P,przec) + odl(R,przec) < odl(P,wyn) + odl(R,wyn))
             wyn = przec;
       }
       
       prze = prosta(P,A.a);
       if(przecin(prze,prosta(R,B.b))) {
          przec = pktPrzeciecia(prze,prosta(R,B.b));
          if(odl(P,przec) + odl(R,przec) < odl(P,wyn) + odl(R,wyn))
             wyn = przec;
       }
       if(przecin(prze,prosta(B.a,R))) {
          przec = pktPrzeciecia(prze,prosta(B.a,R));
          if(odl(P,przec) + odl(R,przec) < odl(P,wyn) + odl(R,wyn))
             wyn = przec;
       }
       if(przecin(prze,prosta(B.c,R))) {
          przec = pktPrzeciecia(prze,prosta(B.c,R));
          if(odl(P,przec) + odl(R,przec) < odl(P,wyn) + odl(R,wyn))
             wyn = przec;
       }
       return wyn;
}

void wrzuc(prosta z, prosta x) {
     if((z.A != x.A || z.B != x.B) && przecin(z,x)) {
          pkt przec = pktPrzeciecia(z,x);
          if(niema(przec))
             V.push_back(przec);
     }
}

main() {
       scanf("%d %d %d %d %d %d",&x1,&yy1,&x2,&y2,&x3,&y3);
       scanf("%d %d %d %d %d %d",&x4,&y4,&x5,&y5,&x6,&y6);
       A = trojkat((double)x1,(double)yy1,(double)x2,(double)y2,(double)x3,(double)y3);
       B = trojkat((double)x4,(double)y4,(double)x5,(double)y5,(double)x6,(double)y6);
       
       if(isTrojInTroj(A,B) || isTrojInTroj(B,A)) {
          printf("%.5lf",max(pole(A),pole(B)));
          return 0;
       }
       
       if(!isPktIn(B,pkt((double)x1,(double)yy1,1)))
          V.push_back(pkt((double)x1,(double)yy1,1));
       if(!isPktIn(B,pkt((double)x2,(double)y2,1)))
          V.push_back(pkt((double)x2,(double)y2,1));
       if(!isPktIn(B,pkt((double)x3,(double)y3,1)))
          V.push_back(pkt((double)x3,(double)y3,1));
       
       if(!isPktIn(A,pkt((double)x4,(double)y4,1)))
          if(niema(pkt((double)x4,(double)y4,1)))
             V.push_back(pkt((double)x4,(double)y4,2));
       if(!isPktIn(A,pkt((double)x5,(double)y5,1)))
          if(niema(pkt((double)x5,(double)y5,1)))
             V.push_back(pkt((double)x5,(double)y5,2));
       if(!isPktIn(A,pkt((double)x6,(double)y6,1)))
          if(niema(pkt((double)x6,(double)y6,1)))
             V.push_back(pkt((double)x6,(double)y6,2));
       
       int ile = V.size();
       
       prosta prze = prosta(A.a,A.b);
       pkt przec;
       
       wrzuc(prze,prosta(B.a,B.b));
       wrzuc(prze,prosta(B.a,B.c));
       wrzuc(prze,prosta(B.b,B.c));
       
       prze = prosta(A.b,A.c);
       wrzuc(prze,prosta(B.a,B.b));
       wrzuc(prze,prosta(B.a,B.c));
       wrzuc(prze,prosta(B.b,B.c));
       
       prze = prosta(A.a,A.c);
       wrzuc(prze,prosta(B.a,B.b));
       wrzuc(prze,prosta(B.a,B.c));
       wrzuc(prze,prosta(B.b,B.c));
       
       if(ile == V.size()) {
          printf("%.5lf",pole(A)+pole(B));
          return 0;
       }
       /*if((prze.A != prosta(B.a,B.b).A || prze.B != prosta(B.a,B.b).B) && przecin(prze,prosta(B.a,B.b))) {
          przec = pktPrzeciecia(prze,prosta(B.a,B.b));
          if(niema(przec))
          printf("A");
             V.push_back(przec);
       }
       if(przecin(prze,prosta(B.a,B.c))) {
          przec = pktPrzeciecia(prze,prosta(B.a,B.c));
          if(niema(przec))
             V.push_back(przec);
       }
       if(przecin(prze,prosta(B.c,B.b))) {
          przec = pktPrzeciecia(prze,prosta(B.c,B.b));
          if(niema(przec))
             V.push_back(przec);
       }
       
       prze = prosta(A.a,A.c);
       if(przecin(prze,prosta(B.a,B.b))) {
          przec = pktPrzeciecia(prze,prosta(B.a,B.b));
          if(niema(przec))
             V.push_back(przec);
       }
       if(przecin(prze,prosta(B.a,B.c))) {
          przec = pktPrzeciecia(prze,prosta(B.a,B.c));
          if(niema(przec))
             V.push_back(przec);
       }
       if(przecin(prze,prosta(B.c,B.b))) {
          przec = pktPrzeciecia(prze,prosta(B.c,B.b));
          if(niema(przec))
             V.push_back(przec);
       }
       
       prze = prosta(A.b,A.c);
       if(przecin(prze,prosta(B.a,B.b))) {
          przec = pktPrzeciecia(prze,prosta(B.a,B.b));
          if(niema(przec))
             V.push_back(przec);
       }
       if(przecin(prze,prosta(B.a,B.c))) {
          przec = pktPrzeciecia(prze,prosta(B.a,B.c));
          if(niema(przec))
             V.push_back(przec);
       }
       if(przecin(prze,prosta(B.c,B.b))) {
          przec = pktPrzeciecia(prze,prosta(B.c,B.b));
          if(niema(przec))
             V.push_back(przec);
       }*/
       
       double wynik = 0.0;
       p0 = pkt(10000.0,-10000.0,0);
       REP(i,V.size())
          if(V[i].y > p0.y)
             p0 = V[i];
          else if(V[i].y == p0.y && V[i].x < p0.x)
             p0 = V[i];
       //p0 = pkt(0.0,0.0,0);
       sort(V.begin(),V.end());
       #ifdef DBG
       printf("p0: %.5lf %.5lf\n",p0.x,p0.y);
       REP(i,V.size())
          printf("V[%d] %.5lf %.5lf\n",i,V[i].x,V[i].y);
       
       #endif
       REP(i,V.size())
       {
          wynik += iloczyn(p0,V[i],V[(i+1)%V.size()]);
          #ifdef DBG
          printf("i: %d %.5lf %.5lf %.5lf %.5lf\n",i,V[i].x,V[i].y,V[(i+1)%V.size()].x,V[(i+1)%V.size()].y);
          
          printf("%.5lf\n",wynik);
          #endif
       }
       
       printf("%.5lf",abs(wynik/2));
       return 0;
}
       
bool on(pkt a, pkt b, pkt c) {
   if(min(a.x,b.x) <= c.x && c.x <= max(a.x,b.x) &&
      min(a.y,b.y) <= c.y && c.y <= max(a.y,b.y)) {
      return true;
   }
   else {
      return false;
   }
}

double iloczyn(pkt a, pkt b, pkt c) {
   return (c.x-a.x)*(b.y-a.y)-(c.y-a.y)*(b.x-a.x);
}

bool przecin(prosta a, prosta b) {
   double d1 = iloczyn(b.a,b.b,a.a);
   double d2 = iloczyn(b.a,b.b,a.b);
   double d3 = iloczyn(a.a,a.b,b.a);
   double d4 = iloczyn(a.a,a.b,b.b);
   if( d1*d2 < 0 && d3*d4 < 0) {
      return true;
   }
   else if(d1 == 0 && on(b.a,b.b,a.a)) {
      return true;
   }
   else if(d2 == 0 && on(b.a,b.b,a.b)) {
      return true;
   }
   else if(d3 == 0 && on(a.a,a.b,b.a)) {
      return true;
   }
   else if(d4 == 0 && on(a.a,a.b,b.a)) {
      return true;
   }
   else {
      return false;
   }
}

