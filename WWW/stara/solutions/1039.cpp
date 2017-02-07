#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int rozmiar=10001;
int T[rozmiar];
int licz(int n)
{ 
      int a, b, min1=T[0], min2=T[1], suma=0;
      bool B;
      for(int i=n-1; i>1; i--)
      {
              if(B==false){ b=T[i]; B=true; }
              else
              {
                  a=T[i];
                  if(2*min1+a+b<2*min2+min1+b) suma+=(2*min1+a+b);
                  else suma+=(2*min2+min1+b);
                  B=false;
              }
                  
      }
      if(B) suma+=(b+T[0]);
      suma+=T[1];
      return suma;
}
int main()
{
    int zestawy;
    scanf("%d", &zestawy);
    while(zestawy--)
    {
         int n;           
         scanf("%d", &n);
         for(int i=0; i<n; i++)
         {
                 int a;
                 scanf("%d", &a);
                 T[i]=a;
         }
         if(n==1) printf("%d\n", T[0]);
         else
         {
             sort(T, T+n); 
             printf("%d\n", licz(n));
         }
    }       
    return 0;
}
