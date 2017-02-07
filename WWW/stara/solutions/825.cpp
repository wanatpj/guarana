#include <iostream>
#include <cmath>
#define MAX 100000
using namespace std;

struct roz { long long p; int il; } pp[MAX];

bool p[MAX];
int pierwsze[MAX];
int ilosc;

void sito()
{
    for(int i=0;i<MAX;i++) p[i]=1;
    for(int i=2;i<MAX;i++)
    {
            if(p[i]==0) continue;
            for(int j=i+i;j<MAX;j+=i) p[j]=0;
    }
    ilosc=0;
    for(int i=2;i<MAX;i++)
    {
       if(p[i])
       {
               pierwsze[ilosc]=i;
               ilosc++;
       }
    }
}

int n,z,k,w,m,sq;
long long wynik,pot;

int main()
{
      sito();
      scanf("%d %d",&k,&m);
      while(k--)
      {
            pp[0].il=0;
            z=w=0;
            scanf("%d",&n);
            while(n>1)
            {
                if(n%pierwsze[z]==0)
                {
                     n/=pierwsze[z];
                     pp[w].il++;
                     pp[w].p=pierwsze[z];
                }
                else
                {
                    z++;
                    if(pp[w].il!=0)
                    {
                        w++;
                        pp[w].il=0;
                    }
                }
                if(z==ilosc||pierwsze[z]*pierwsze[z]>n)
                {
                     pp[w].p=n;
                     pp[w].il=1;
                     break;
                }
            }
            wynik=1;
            for(int i=0;i<=w;i++)
            {
                 pot=1;
                 for(int j=0;j<=pp[i].il;j++)
                 {
                      pot*=pp[i].p;
                 }
                 wynik*=((pot-1)/(pp[i].p-1));
                 wynik%=m;
            }
            printf("%lld\n",wynik);
      }
      return 0;
}
