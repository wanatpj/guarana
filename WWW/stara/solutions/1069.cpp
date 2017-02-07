#include <iostream>
#include <set>
#include <vector>
#define MAX 100010
using namespace std;

struct zm { int bylo, jest; } tmp;
struct wy { int co, kiedy; } ww;
struct ble { int zaw, ile, gdzie; };
struct cmp { bool operator()(const zm &a, const zm &b) { return a.bylo<b.bylo; } };

int zli[MAX];
ble tab[MAX];
set <zm, cmp> S;
set <zm>::iterator it;
vector <wy> V[MAX];
int kol[MAX], lis[MAX];
int stare[MAX];
int z,m,n,d,akt,poz;
bool juz[MAX], nie[MAX];
long long k;

bool cmmp(const wy &a, const wy &b)
{
     if(nie[a.kiedy]==nie[b.kiedy]) return stare[a.kiedy]<stare[b.kiedy];
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
            juz[i]=0;
        }
        d=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&tmp.bylo);
            it=S.find(tmp);
            if(it==S.end()) continue;
            if(juz[it->jest]==1) continue;
            juz[it->jest]=1;
            lis[d]=it->jest;
            stare[d]=tmp.bylo;
            d++;
        }
        if(d==0) { printf("0\n-1\n"); continue; }

        //for(int i=0;i<d;i++) printf("%d ",lis[i]); printf("\n");

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

        for(int i=0;i<=akt;i++) zli[i]=0;
        for(int i=0;i<d;i++) tab[i].ile=0;
        for(int i=d-1;i>=0;i--)
        {
                if(tab[i].gdzie==akt-1) tab[i].ile=1;
                else tab[i].ile=zli[tab[i].gdzie+1];
                zli[tab[i].gdzie]+=tab[i].ile;
        }

        long long tmp=0; //long long-a dac!!!!!!!!!!!!!!!!!!!!!!!!!
        for(vector<wy>::iterator it=V[0].begin();it!=V[0].end();it++) if(tmp<k) tmp+=tab[it->kiedy].ile;
        if(tmp<k)
        {
            printf("-1\n");
            continue;
        }

        for(int i=0;i<d;i++) nie[i]=0;

        long long zliczam=0; // long long-a dac !!!!!!!!!!!!!!!!!!
        //int p=0;
        for(int p=0;p<akt;p++)
        {
                sort(V[p].begin(),V[p].end(),cmmp);
                zliczam=0;
                for(vector<wy>::iterator it=V[p].begin();it!=V[p].end();it++)
                {
                      zliczam+=tab[it->kiedy].ile;
                      if(zliczam>=k)
                      {
                          k-=zliczam;
                          k+=tab[it->kiedy].ile;
                          printf("%d ",stare[it->kiedy]);
                          for(vector<wy>::iterator it2=V[p+1].begin();it2!=V[p+1].end();it2++)
                          {
                                 if(it2->kiedy<it->kiedy) nie[it2->kiedy]=1;
                          }
                          break;
                      }
                }
        }

        printf("\n");

       /* for(int i=0;i<akt;i++)
        {
            printf("%d. ",i);
            for(vector<wy>::iterator it=V[i].begin();it!=V[i].end();it++)
            {
                printf("(%d,%d,ile:%d,bylo:%d) ",it->co,it->kiedy,tab[it->kiedy].ile,stare[it->kiedy]);
            }
            printf("\n");
        }*/

    }
    return 0;
}
