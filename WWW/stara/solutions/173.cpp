//Czesc kodu zaczerpnieta z "Algorytmika praktyczna w konkursach Informatycznych" Piotra Stanczyka
#include <iostream>
#include <vector>
#define LD long double
#define COLD const LD &
#define COP const point &
using namespace std;

const LD EPS = 10e-9;
struct point { LD x,y; };
struct tro { point p[3]; } a,b;
vector <point> V;

inline bool isZero(COLD a)
{
       return a >= -EPS && a <= EPS;
}

inline int sgn(COLD a)
{
       if(a>0||isZero(a)) return 1;
       return (-1);
}

inline LD abs(COLD a)
{
       if(a>0||isZero(a)) return a;
       return (-a);
}

inline LD det(COP p1, COP p2, COP p3)
{
   return p1.x*p2.y+p2.x*p3.y+p3.x*p1.y-p1.y*p2.x-p2.y*p3.x-p3.y*p1.x;
}

bool cmp(COP a, COP b)
{
     if(sgn(det(V[0],a,b))==1) return false;
     return true;
}

inline LD pole(COP p1, COP p2, COP p3)
{
   return abs(det(p1,p2,p3))/(LD)2;
}

inline bool inside(const tro &aa, COP ba)
{
       int det1, det2,tempy;
       LD d1, d2;
       d1=det(aa.p[0],aa.p[1],ba);
       d2=det(aa.p[1],aa.p[2],ba);
       det1=sgn(d1);
       det2=sgn(d2);
       if(isZero(d1)&&isZero(d2)) return true;
       if(isZero(d1))
       {
            tempy=det2;
       }
       else
       {
            tempy=det1;
       }
       if(det1*det2>0||isZero(d1)||isZero(d2))
       {
            d2=det(aa.p[2],aa.p[0],ba);
            det2=sgn(d2);
            if(isZero(d2)) return true;
            if(tempy*det2>0) return true;
       }
       return false;
}

bool prze(COP a1, COP a2, COP b1, COP b2, point &res)
{
      LD tmp,tmp2;
      int s1,s2;

      tmp=det(a1,a2,b1);
      tmp2=det(a1,a2,b2);
      s1=sgn(tmp);
      s2=sgn(tmp2);
      if(isZero(tmp)||isZero(tmp2)) return false;
      if(s1*s2>0) return false;

      tmp=det(b1,b2,a1);
      tmp2=det(b1,b2,a2);
      s1=sgn(tmp);
      s2=sgn(tmp2);
      if(isZero(tmp)||isZero(tmp2)) return false;
      if(s1*s2>0) return false;

      LD t=(LD)((b2.x-a2.x)*(b1.y-b2.y)-(b2.y-a2.y)*(b1.x-b2.x))/
         (LD)((a1.x-a2.x)*(b1.y-b2.y)-(a1.y-a2.y)*(b1.x-b2.x));
      res.x=(t*a1.x+(1.0-t)*a2.x);
      res.y=(t*a1.y+(1.0-t)*a2.y);
      return true;
}

LD otoczka()
{
       LD res=0;
       if(V.size()<3) return res;
       point tt=V[0];
       int nr=0;
       for(int i=1;i<V.size();i++)
       {
               if(tt.x>V[i].x)
               {
                   tt=V[i];
                   nr=i;
               }
       }
       V[nr]=V[0];
       V[0]=tt;
       vector<point>::iterator it=V.begin();
       it++;
       sort(it,V.end(),cmp);
       for(int i=2;i<V.size();i++) res+=abs(det(V[0],V[i-1],V[i]));
       res/=(LD)(2.0);
       return res;
}

int main()
{
      cin >> a.p[0].x >> a.p[0].y >> a.p[1].x >> a.p[1].y >> a.p[2].x >> a.p[2].y;
      cin >> b.p[0].x >> b.p[0].y >> b.p[1].x >> b.p[1].y >> b.p[2].x >> b.p[2].y;

      bool ws=1;
      for(int i=0;i<3;i++)
      {
             if(inside(a,b.p[i])==0) ws=0;
      }
      if(ws==1)
      {
               printf("%.5Lf\n",pole(a.p[0],a.p[1],a.p[2]));
      }
      else
      {
          ws=1;
          for(int i=0;i<3;i++)
          {
             if(inside(b,a.p[i])==0) ws=0;
          }
          if(ws==1)
          {
               printf("%.5Lf\n",pole(b.p[0],b.p[1],b.p[2]));
          }
          else
          {
              point res;
              LD wyn=0;
              int t[3]={0,1,2};
              for(int i=0;i<3;i++)
              {
                  if(inside(a,b.p[i])==true)  V.push_back(b.p[i]);
                  if(inside(b,a.p[i])==true)  V.push_back(a.p[i]);
                  for(int j=0;j<3;j++)
                  {
                          if(prze(a.p[i],a.p[(i+1)%3],b.p[j],b.p[(j+1)%3],res)==true)
                          {
                                  V.push_back(res);
                          }
                  }
              }
              wyn-=otoczka();
              wyn+=(pole(b.p[0],b.p[1],b.p[2])+pole(a.p[0],a.p[1],a.p[2]));
              printf("%.5Lf\n",wyn);
          }
      }
      return 0;
}
