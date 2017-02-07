#include <iostream>
using namespace std;

int n,dl;
char ciag[100];
long long suma,tmp;

main()
{     
      scanf("%d",&n);
      while(n--)
      {
                suma=0;
                scanf("%s",&ciag);
                dl=strlen(ciag);
                ciag[dl]=0;
                for(int i=0;i<dl;i+=2)
                {
                        if(ciag[i+1]=='+')
                        {
                              suma+=(ciag[i]-'0');            
                        }
                        else
                        {
                              tmp=1;
                              while(ciag[i+1]=='*'&&i<dl)
                              {
                                    tmp*=(long long)(ciag[i]-'0');
                                    i+=2;                     
                              }
                              tmp*=(long long)(ciag[i]-'0');
                              suma+=tmp;
                        }
                }
                printf("%lld\n",suma);
      }
      return 0;      
}
