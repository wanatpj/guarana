#include <iostream>
#define MAX 100000
using namespace std;

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

int n,z,k,w,m;
long long wynik,pot;

int main()
{
      sito();
      scanf("%d %d",&k,&m);
      while(k--)
      {
            z=w=0;
            pot=wynik=1;
            scanf("%d",&n);
            while(pierwsze[z]*pierwsze[z]<=n)
            {
                while(n%pierwsze[z]==0)
                {
                     n/=pierwsze[z];
                     pot*=pierwsze[z];
                }
                if(pot!=1)
                {
                    pot*=pierwsze[z];
                    pot--;
                    wynik*=pot/(pierwsze[z]-1);
                    if(wynik>m) wynik%=m;
                    pot=1;
                }
                z++;
            }
            if(n>1)
            {
                pot=n;
                wynik*=(pot*pot-1)/(pot-1);
            }
            printf("%lld\n",wynik%m);
      }
      return 0;
}
