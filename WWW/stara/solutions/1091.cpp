#include <iostream>
#include <set>
#include <vector>
#define MAX 100010
#define INF 1000000000
using namespace std;

struct zm { int bylo, jest; } tmp;
struct wy { int co, kiedy; } ww;
struct ble { int real, ile, gdzie; };
struct cmp { bool operator()(const zm &a, const zm &b) { return a.bylo<b.bylo; } };

int zli[MAX];
ble tab[MAX];
set <zm, cmp> S;
set <zm>::iterator it;
vector <wy> V[MAX];
int kol[MAX], lis[MAX];
int stare[MAX];
int z,m,n,d,akt,poz;
long long k;
bool nie[MAX];
bool zloo[MAX];
int dupa[MAX];

bool cmmp(const wy &a, const wy &b)
{
     if(nie[a.kiedy]==nie[b.kiedy])
     {
         if(stare[a.kiedy]==stare[b.kiedy])
             return a.kiedy<b.kiedy;                      
        return stare[a.kiedy]<stare[b.kiedy];
     }
     return nie[a.kiedy]<nie[b.kiedy];    
}

int main()
{
    scanf("%d",&z);
    while(z--)
    {
        S.clear();
        scanf("%d %d %lld",&n,&m,&k); //zamienic k na long long !!!!!!!!!!!!!!!!
        for(int i=0;i<n;i++)
        {
            scanf("%d",&kol[i]);
            tmp.bylo=kol[i];
            tmp.jest=i;
            S.insert(tmp);
        }
        d=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&tmp.bylo);
            it=S.find(tmp);
            if(it==S.end()) continue;
            if(d!=0)
                if(lis[d-1]==it->jest) continue;
            lis[d]=it->jest;
            stare[d]=tmp.bylo;
            d++;
        }
        if(d==0) { printf("0\n-1\n"); continue; }
        
        //nwpr
        akt=0;
        for(int i=0;i<d;i++) V[i].clear();
        for(int i=0;i<d;i++)
        {
            poz=lower_bound(kol,kol+akt,lis[i])-kol;
            if(poz==akt) akt++;
            kol[poz]=lis[i];
            ww.co=lis[i];
            ww.kiedy=i;
            tab[i].gdzie=poz;
            V[poz].push_back(ww);
        }
        printf("%d\n",akt);
        
        //sprawdzam ktore sa dobre
        for(int i=0;i<d;i++) zloo[i]=0;
        int maxi=INF, newmax;
        for(int i=akt-1;i>=0;i--)
        {
            newmax=0;
            for(vector<wy>::iterator it=V[i].begin();it!=V[i].end();it++)
            {
               if(lis[it->kiedy]>maxi) zloo[it->kiedy]=1;
               else
               { 
                  if(lis[it->kiedy]>newmax) newmax=lis[it->kiedy];                          
               }
            }
            maxi=newmax;  
        }
         
        for(int q=0;q<d;q++) // tu sie kwadraci
        {
            for(int i=0;i<=akt;i++) zli[i]=0;
            for(int i=0;i<d;i++) tab[i].ile=0;
            for(int i=d-1;i>=0;i--)
            {
                if(zloo[i]) continue;
                if(i!=q&&lis[i]==lis[q]) continue;
                if(tab[i].gdzie==akt-1) tab[i].ile=1;
                else tab[i].ile=zli[tab[i].gdzie+1];
                zli[tab[i].gdzie]+=tab[i].ile; //dziala gdy sie nie powtarzaja           
            }
            tab[q].real=tab[q].ile;
        }
        /*for(int i=0;i<akt;i++)
        {
            printf("%d. ",i);
            for(vector<wy>::iterator it=V[i].begin();it!=V[i].end();it++)
            {
                                     if(zloo[it->kiedy]) continue;
                printf("(%d,%d,ile:%d,bylo:%d) ",it->co,it->kiedy,tab[it->kiedy].real,stare[it->kiedy]);
            }
            printf("\n");
        }*/        
        for(int i=0;i<d;i++) nie[i]=0; 
        long long zliczam=0; // long long-a dac !!!!!!!!!!!!!!!!!!
        bool ok=0;
        for(int i=0;i<d;i++) dupa[i]=-1;
        for(int p=0;p<akt;p++)
        {
                sort(V[p].begin(),V[p].end(),cmmp);
                zliczam=0;
                for(vector<wy>::iterator it=V[p].begin();it!=V[p].end();it++)
                {
                      if(zloo[it->kiedy]) continue;
                      if(dupa[it->kiedy]==-1)
                      {
                       zliczam+=tab[it->kiedy].real;
                       dupa[it->kiedy]=tab[it->kiedy].real;
                      }
                      else
                      {
                          if(dupa[it->kiedy]<tab[it->kiedy].real)
                          {
                              zliczam+=(tab[it->kiedy].real-dupa[it->kiedy]);                                  
                          } 
                      }
                      if(zliczam>=k)
                      {
                          ok=1;
                          k-=zliczam;
                          k+=tab[it->kiedy].real;
                          printf("%d ",stare[it->kiedy]);
                          for(vector<wy>::iterator it2=V[p+1].begin();it2!=V[p+1].end();it2++)
                          {
                                 if(zloo[it2->kiedy]) continue;
                                 if(it2->kiedy<it->kiedy) nie[it2->kiedy]=1;                   
                          }
                          break;        
                      }                                        
                }
                if(ok==0) { printf("-1"); break; }
        }
        printf("\n");
    }
    return 0;
}
