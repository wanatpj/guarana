#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long LL;
int sgn(LL a){
  if(a>0) return 1;
  else if(a==0) return 0;
  else return -1;
}
#define Det(a,b,c) (LL(b.x-a.x)*LL(c.y-a.y)-LL(b.y-a.y)*(c.x-a.x))
#define PointRect(p1,p2,p3) ((p1.x<?p2.x)<p3.x && (p1.y<?p2.y)<p3.y && (p1.x>?p2.x)>p3.x && (p1.y>?p2.y)>p3.y)
#define PointInsideRect(p1,p2,p3) (p1.x<=p3.x && p1.y<=p3.y && p2.x>=p3.x && p2.y>=p3.y)
#define PointSeg(p1,p2,l) (Det(p1,p2,l)==0 && PointRect(p1,p2,l))
#define Cross(p1,p2,l1,l2) ((sgn(Det(p1,p2,l1))*sgn(Det(p1,p2,l2)) == -1) && (sgn(Det(l1,l2,p1))*sgn(Det(l1,l2,p2))==-1))

struct pkt{
  int x,y;
  pkt(){}
  pkt(int a, int b){x=a; y=b;}
};
LL abs(LL a){if(a>0) return a; return -a;}
void swap(int &a, int &b){
  int c=a;
  a=b;
  b=c;
}
int maks(int a, int b){if(a>b) return a; return b;}
int min(int a, int b){if(a<b) return a; return b;}

const int N = 17;
const int K = 4097;
const int inf = 1000000001;
vector<pkt> dzialki[N];
vector<int> gdzie[N];
vector<pkt> skarb;
int sum_val[N];
int sum_czas[N];
int x_maks[N], x_min[N], y_maks[N], y_min[N];
vector<int> val;
vector<int> weight;
int d,s; // ile dzialek,ile skarbow
int czas;
int A[K], B[K], C[K];

/*bool inside(vector<pkt> &l, pkt p){
  int a = 1, b=l.size()-1,c;
  if(Det(l[0],l[a],l[b]) > 0) swap(a,b);
  if(Det(l[0],l[a],p) >= 0 || Det(l[0],l[b],p)<=0) return false;
  while(abs(a-b) > 1){
    c = (a+b)/2;
    if(Det(l[0],l[c],p) > 0) b=c;
    else a=c;
  }
  return Det(l[a],l[b],p) < 0;
}*/

bool inside(vector<pkt> &l, pkt p){
  int v = 0, s = l.size();
  pkt d(inf,p.y + 1);
  for(int i=0;i<s;i++){
    if(PointSeg(l[i],l[(i+1) %s],p))
      return false;
  }
  for(int i=0;i<s;i++){
    v += Cross(p,d,l[i],l[(i+1)%s]);
  }
  return v&1;
}
bool ust[N];
void wczyt(){
  int a,b,c,e;
  scanf("%d %d",&d,&s);
  for(int i=0;i<d;i++){
    x_min[i] = y_min[i] = inf;
    x_maks[i] = y_maks[i] = 0;
    scanf("%d",&a);
    for(int j=1;j<=a;j++){
      scanf("%d %d",&b,&c);
      x_min[i] = min(x_min[i],b);
      x_maks[i] = maks(x_maks[i],b);
      y_min[i] = min(y_min[i],c);
      y_maks[i] = maks(y_maks[i],c);
      dzialki[i].push_back(pkt(b,c));
    }
  }
  for(int i=0;i<s;i++){
    scanf("%d %d %d %d",&a,&b,&c,&e);
    skarb.push_back(pkt(a,b));
    weight.push_back(c);
    val.push_back(e);
  }
  scanf("%d",&czas);
}

void ustal_przynaleznosc(){
  for(int i=0;i<s;i++){
    bool found = false;
    for(int j=0;j<d;j++){
      if(PointInsideRect(pkt(x_min[j],y_min[j]),pkt(x_maks[j],y_maks[j]),skarb[i]) && inside(dzialki[j],skarb[i])){
        gdzie[j].push_back(i);
        found = true;
        break;
      }
    }
    if(!found){ gdzie[d].push_back(i); }
  }
}

void przygotuj(){
  for(int i=0;i<d;i++){
    for(vector<int>::iterator p = gdzie[i].begin();p!=gdzie[i].end();p++){
      sum_val[i] += val[*p];
      sum_czas[i]+= weight[*p];
    }
    sum_val[i] *= (100 + gdzie[i].size());
    sum_val[i] = int(ceil(double(sum_val[i])/100));
  }
}

void dynamik(){
  for(int i=0;i<=czas;i++) A[i]=B[i]=C[i]=0;
  for(int i=0;i<=d;i++){
    if(i<d){
      for(int k=0;k<=czas;k++){
        if(k - sum_czas[i] >= 0)
          C[k] = maks(A[k],A[k - sum_czas[i]] + sum_val[i]);
      }
    }
    for(vector<int>::iterator p = gdzie[i].begin();p!=gdzie[i].end();p++){
      for(int k=0;k<=czas;k++){
        if(k - weight[*p] >= 0)
          B[k] = maks(A[k],A[k - weight[*p]] + val[*p]);
      }
      for(int k=0;k<=czas;k++)
        A[k] = B[k];
    }
    for(int k=0;k<=czas;k++)
      A[k] = maks(A[k],C[k]);
  }
  printf("%d\n",A[czas]);
}

void zeruj(){
  for(int i=0;i<=d;i++){
    dzialki[i].clear();
    gdzie[i].clear();
    sum_val[i] = sum_czas[i] = 0;
  }
  val.clear();
  weight.clear();
  skarb.clear();
}

main(){
  int t;
  scanf("%d",&t);
  while(t--){
    wczyt();
    ustal_przynaleznosc();
    przygotuj();
    dynamik();
    zeruj();
  }
}
