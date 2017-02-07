#include<iostream>
#include<cstdio>
using namespace std;
const int rozmiar=10001;
int T[rozmiar];
int licz(int min1, int max1, int n)
{ 
    int ile=0, min2=10001, suma=0;
    bool tmp=false;
    T[min1]--;
    for(int i=max1; i>min1 && ile<n-1; i--)
    {
            while(T[i]>0 && ile<n-1)
            {
                  if(ile==n-2)
                  {
                          min2=i;
                          T[i]--;    
                          ile++;
                  }
                  else 
                  {      
                          if(tmp==false) 
                          { 
                              suma+=i; 
                              tmp=true; 
                              T[i]--;
                              ile++;
                          }
                          else if(tmp==true)
                          {
                              T[i]--;
                              tmp=false;
                              ile++;
                          }
                  }          
            }
    }
    suma+=(n*min2 + n*min1/2 - min2);
    if(n%2==0) suma-=min1;
    return suma;
}
int main()
{
    int zestawy;
    scanf("%d", &zestawy);
    while(zestawy--)
    {
         int n, min1=10001, max1=0, suma=0, wyn1=0, wyn2=0;           
         scanf("%d", &n);
         for(int i=0; i<n; i++)
         {
                 int a;
                 scanf("%d", &a);
                 T[a]++;
                 if(a>max1) max1=a;
                 if(a<min1) min1=a;
                 suma+=a;
         }
         wyn1 = licz(min1, max1, n);
         wyn2 = suma+min1*(n-3);
         
         if(wyn1<wyn2) printf("%d", wyn1);
         else printf("%d", wyn2);
         printf("\n");
    }       
    return 0;
}
