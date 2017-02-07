#include<cstdio>
#include<algorithm>
using namespace std;

double abs(double x) {
   return x < 0 ? -x : x;
}

struct pkt {
   double x,y;
   pkt() {}
   pkt(double X, double Y) {
      x = X;
      y = Y;
   }
   bool operator==(const pkt &P) {
      return x == P.x && y == P.y;
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
      a = pkt(ax,ay);
      b = pkt(bx,by);
      c = pkt(cx,cy);
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
    return pkt((l.C*k.B - k.C*l.B)/(k.A*l.B - l.A*k.B),
               -((k.A*k.B*l.C - k.A*l.B*k.C) / (k.A*k.B*l.B - l.A*k.B*k.B)) - k.C/k.B);
}

int x1,x2,x3,x4,x5,x6;
int y1,y2,y3,y4,y5,y6;

trojkat A,B;

bool przecin(prosta,prosta);
bool on(pkt,pkt,pkt);
double iloczyn(pkt,pkt,pkt);

int ile;

main() {
       scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
       scanf("%d %d %d %d %d %d",&x4,&y4,&x5,&y5,&x6,&y6);
       A = trojkat((double)x1,(double)y1,(double)x2,(double)y2,(double)x3,(double)y3);
       B = trojkat((double)x4,(double)y4,(double)x5,(double)y5,(double)x6,(double)y6);
       
       if(isTrojInTroj(A,B) || isTrojInTroj(B,A)) {
          printf("%.5lf",max(pole(A),pole(B)));
          return 0;
       }
       
       ile = 0;
       if(isPktIn(A,B.a))
          ++ile;
       if(isPktIn(A,B.b))
          ++ile;
       if(isPktIn(A,B.c))
          ++ile;
       
       if(ile == 1) {
          pkt ktory,drugi,trzeci;
          if(isPktIn(A,B.a)) {
             ktory = B.a;
             drugi = B.b;
             trzeci = B.c;
          }
          if(isPktIn(A,B.b)) {
             ktory = B.b;
             drugi = B.a;
             trzeci = B.c;
          }
          if(isPktIn(A,B.c)) {
             ktory = B.c;
             drugi = B.b;
             trzeci = B.a;
          }
          
          prosta jeden,dwa;
          if(przecin(prosta(ktory,drugi),prosta(A.a,A.b))) {
             jeden = prosta(A.a,A.b);
          }
          if(przecin(prosta(ktory,drugi),prosta(A.a,A.c))) {
             jeden = prosta(A.a,A.c);
          }
          if(przecin(prosta(ktory,drugi),prosta(A.b,A.c))) {
             jeden = prosta(A.b,A.c);
          }
          
          if(przecin(prosta(ktory,trzeci),prosta(A.a,A.b))) {
             dwa = prosta(A.a,A.b);
          }
          if(przecin(prosta(ktory,trzeci),prosta(A.a,A.c))) {
             dwa = prosta(A.a,A.c);
          }
          if(przecin(prosta(ktory,trzeci),prosta(A.b,A.c))) {
             dwa = prosta(A.b,A.c);
          }
          
          if(jeden == dwa) {
             double wynik = pole(
                          ktory,
                          pktPrzeciecia(jeden,prosta(ktory,drugi)),
                          pktPrzeciecia(jeden,prosta(ktory,trzeci))
                          );
             printf("%.5lf",pole(A)+pole(B) - wynik);
             return 0;
          }
          double wynik;
          if(!przecin(jeden,prosta(ktory,drugi))) {
             swap(drugi,trzeci);
          }
          
          pkt wsrodku;
          if(isPktIn(B,A.a))
             wsrodku = A.a;
          if(isPktIn(B,A.b))
             wsrodku = A.b;
          if(isPktIn(B,A.c))
             wsrodku = A.c;
          
          wynik = pole(pktPrzeciecia(jeden,prosta(ktory,drugi)),pktPrzeciecia(dwa,prosta(ktory,trzeci)),ktory);
          wynik += pole(pktPrzeciecia(jeden,prosta(ktory,drugi)),pktPrzeciecia(dwa,prosta(ktory,trzeci)),wsrodku);
          printf("%.5lf",pole(A)+pole(B) - wynik);
          return 0;
       }
       
       if(ile == 2) {
          pkt ktory1,ktory2,trzeci;
          if(!isPktIn(A,B.a)) {
             trzeci = B.a;
             ktory1 = B.b;
             ktory2 = B.c;
          }
          if(!isPktIn(A,B.b)) {
             trzeci = B.b;
             ktory1 = B.a;
             ktory2 = B.c;
          }
          if(!isPktIn(A,B.c)) {
             trzeci = B.c;
             ktory1 = B.b;
             ktory2 = B.a;
          }
          
          prosta prze,prze2;
          
          if(przecin(prosta(ktory1,trzeci),prosta(A.a,A.b))) {
             prze = prosta(A.a,A.b);
          }
          if(przecin(prosta(ktory1,trzeci),prosta(A.c,A.b))) {
             prze = prosta(A.c,A.b);
          }
          if(przecin(prosta(ktory1,trzeci),prosta(A.a,A.c))) {
             prze = prosta(A.a,A.c);
          }
          
          if(przecin(prosta(ktory2,trzeci),prosta(A.a,A.b))) {
             prze2 = prosta(A.a,A.b);
          }
          if(przecin(prosta(ktory2,trzeci),prosta(A.c,A.b))) {
             prze2 = prosta(A.c,A.b);
          }
          if(przecin(prosta(ktory2,trzeci),prosta(A.a,A.c))) {
             prze2 = prosta(A.a,A.c);
          }
          
          if(prze == prze2) {
             double wynik;
             
             wynik = pole(ktory1,ktory2,pktPrzeciecia(prze,prosta(ktory1,trzeci)));
             wynik += pole(ktory2,pktPrzeciecia(prze,prosta(ktory2,trzeci)),pktPrzeciecia(prze,prosta(ktory1,trzeci)));
             printf("%.5lf",pole(A)+pole(B) - wynik);
             return 0;
          }
          
          double wynik;
          
          if(!przecin(prosta(ktory1,trzeci),prze)) {
             swap(ktory1,ktory2);
          }
          
          pkt wsrodku;
          if(isPktIn(B,A.a))
             wsrodku = A.a;
          if(isPktIn(B,A.b))
             wsrodku = A.b;
          if(isPktIn(B,A.c))
             wsrodku = A.c;
          
          wynik = pole(ktory1,pktPrzeciecia(prosta(ktory1,trzeci),prze),wsrodku);
          wynik += pole(ktory1,ktory2,wsrodku);
          wynik += pole(ktory2,pktPrzeciecia(prosta(ktory2,trzeci),prze2),wsrodku);
          
          printf("%.5lf",pole(A)+pole(B) - wynik);
          return 0;
       }
       
       
       ile = 0;
       if(isPktIn(B,A.a))
          ++ile;
       if(isPktIn(B,A.b))
          ++ile;
       if(isPktIn(B,A.c))
          ++ile;
       
       if(ile == 1) {
          pkt ktory,drugi,trzeci;
          if(isPktIn(B,A.a)) {
             ktory = A.a;
             drugi = A.b;
             trzeci = A.c;
          }
          if(isPktIn(B,A.b)) {
             ktory = A.b;
             drugi = A.a;
             trzeci = A.c;
          }
          if(isPktIn(B,A.c)) {
             ktory = A.c;
             drugi = A.b;
             trzeci = A.a;
          }
          
          prosta jeden,dwa;
          if(przecin(prosta(ktory,drugi),prosta(B.a,B.b))) {
             jeden = prosta(B.a,B.b);
          }
          if(przecin(prosta(ktory,drugi),prosta(B.a,B.c))) {
             jeden = prosta(B.a,B.c);
          }
          if(przecin(prosta(ktory,drugi),prosta(B.b,B.c))) {
             jeden = prosta(B.b,B.c);
          }
          
          if(przecin(prosta(ktory,trzeci),prosta(B.a,B.b))) {
             dwa = prosta(B.a,B.b);
          }
          if(przecin(prosta(ktory,trzeci),prosta(B.a,B.c))) {
             dwa = prosta(B.a,B.c);
          }
          if(przecin(prosta(ktory,trzeci),prosta(B.b,B.c))) {
             dwa = prosta(B.b,B.c);
          }
          
          if(jeden == dwa) {
             double wynik = pole(
                          ktory,
                          pktPrzeciecia(jeden,prosta(ktory,drugi)),
                          pktPrzeciecia(jeden,prosta(ktory,trzeci))
                          );
             printf("%.5lf",pole(A)+pole(B) - wynik);
             return 0;
          }
          
          double wynik;
          if(!przecin(jeden,prosta(ktory,drugi))) {
             swap(drugi,trzeci);
          }
          
          pkt wsrodku;
          if(isPktIn(A,B.a))
             wsrodku = B.a;
          if(isPktIn(A,B.b))
             wsrodku = B.b;
          if(isPktIn(A,B.c))
             wsrodku = B.c;
          
          wynik = pole(pktPrzeciecia(jeden,prosta(ktory,drugi)),pktPrzeciecia(dwa,prosta(ktory,trzeci)),ktory);
          wynik += pole(pktPrzeciecia(jeden,prosta(ktory,drugi)),pktPrzeciecia(dwa,prosta(ktory,trzeci)),wsrodku);
          printf("%.5lf",pole(A)+pole(B) - wynik);
          return 0;
       }
       
       if(ile == 2) {
          pkt ktory1,ktory2,trzeci;
          if(!isPktIn(B,A.a)) {
             trzeci = A.a;
             ktory1 = A.b;
             ktory2 = A.c;
          }
          if(!isPktIn(B,A.b)) {
             trzeci = A.b;
             ktory1 = A.a;
             ktory2 = A.c;
          }
          if(!isPktIn(B,A.c)) {
             trzeci = A.c;
             ktory1 = A.b;
             ktory2 = A.a;
          }
          
          prosta prze,prze2;
          
          if(przecin(prosta(ktory1,trzeci),prosta(B.a,B.b))) {
             prze = prosta(B.a,B.b);
          }
          if(przecin(prosta(ktory1,trzeci),prosta(B.c,B.b))) {
             prze = prosta(B.c,B.b);
          }
          if(przecin(prosta(ktory1,trzeci),prosta(B.a,B.c))) {
             prze = prosta(B.a,B.c);
          }
          
          if(przecin(prosta(ktory2,trzeci),prosta(B.a,B.b))) {
             prze2 = prosta(B.a,B.b);
          }
          if(przecin(prosta(ktory2,trzeci),prosta(B.c,B.b))) {
             prze2 = prosta(B.c,B.b);
          }
          if(przecin(prosta(ktory2,trzeci),prosta(B.a,B.c))) {
             prze2 = prosta(B.a,B.c);
          }
          
          if(prze == prze2) {
             double wynik;
             
             wynik = pole(ktory1,ktory2,pktPrzeciecia(prze,prosta(ktory1,trzeci)));
             wynik += pole(ktory2,pktPrzeciecia(prze,prosta(ktory2,trzeci)),pktPrzeciecia(prze,prosta(ktory1,trzeci)));
             printf("%.5lf",pole(A)+pole(B) - wynik);
             return 0;
          }
          
          double wynik;
          
          if(!przecin(prosta(ktory1,trzeci),prze)) {
             swap(ktory1,ktory2);
          }
          
          pkt wsrodku;
          if(isPktIn(B,A.a))
             wsrodku = A.a;
          if(isPktIn(B,A.b))
             wsrodku = A.b;
          if(isPktIn(B,A.c))
             wsrodku = A.c;
          
          wynik = pole(ktory1,pktPrzeciecia(prosta(ktory1,trzeci),prze),wsrodku);
          wynik += pole(ktory1,ktory2,wsrodku);
          wynik += pole(ktory2,pktPrzeciecia(prosta(ktory2,trzeci),prze2),wsrodku);
          
          printf("%.5lf",pole(A)+pole(B) - wynik);
          return 0;
       }
       
       printf("%.5lf",pole(A)+pole(B));
       
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
