#include <iostream>
#include <queue>
#include <vector>
#define MAX 100010
#define INF 2000000000
using namespace std;

int n,m,r,tmp,a,b,q;
int odl[MAX], w[MAX];

struct kraw { int to, w, s; } kr, ed;
struct cmp 
{ 
       bool operator()(const kraw &a, const kraw &b) 
       { 
            if(a.w==b.w) return a.s>b.s;
            return a.w>b.w;      
       } 
};

vector <kraw> V[MAX];
priority_queue <kraw, vector<kraw>, cmp> Q;

int main()
{
      scanf("%d %d %d",&n,&m,&r);
      for(int i=1;i<=n;i++) { odl[i]=INF; }
      kr.w=0;
      for(int i=0;i<r;i++) 
      {
              scanf("%d",&tmp);
              w[tmp]=tmp;
              kr.to=tmp;
              kr.s=tmp;
              Q.push(kr);        
      }
      for(int i=0;i<m;i++)
      {
              scanf("%d %d %d",&a,&b,&kr.w);
              kr.to=b;        
              V[a].push_back(kr);
              kr.to=a;
              V[b].push_back(kr);
      }
      while(!Q.empty())
      {
            kr=Q.top();
            Q.pop();
            if(odl[kr.to]!=INF) continue;
            odl[kr.to]=kr.w;
            w[kr.to]=kr.s;
            for(vector<kraw>::iterator it=V[kr.to].begin();it!=V[kr.to].end();it++)
            {
                   if(odl[it->to]==INF)
                   {                           
                          ed.to=it->to;
                          ed.w=it->w+odl[kr.to];
                          ed.s=kr.s;                     
                          Q.push(ed);
                   }   
            }
      }
      scanf("%d",&q);
      for(int i=0;i<q;i++)
      {
              scanf("%d",&a);
              if(odl[a]==INF) printf("BRAK\n");
              else printf("%d %d\n",w[a],odl[a]);        
      }
      return 0;      
}
      
