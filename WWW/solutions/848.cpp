#include <iostream>
#include <cmath>
using namespace std;

int pier[33000];
int ile[33000];
int z, l, point, m;
long long suma;

bool pierwsza(int x)
{
   for(int i=2; i*i<=x; i++)
   if(x%i==0)
   return false;
   return true;
}

long long poteg(long long x, long long n)
{
   long long a;
   if(n==0)
   return 1;
   if(n%2)
   return(x*poteg(x, n-1));
   else
   a=poteg(x, n/2);
   return a*a;
}

int main()
{
ios_base::sync_with_stdio(0);
   int licz=1;
   for(int i=2; i<33000; i++)
   {
      if(pierwsza(i))
      {
         pier[licz]=i;
         licz++;
      }
   }   
  // for(int i=0; i<licz; i++) cout<<pier[i]<<endl;
   cin>>z>>m;
   for(int ii=0; ii<z; ii++)
   {
      cin>>l;
      point=0;
      suma=1;
      pier[0]=0;
      for(int a=1; pier[a]*pier[a]<=l; a++)
      {
     //    cout<<l<<endl;
         if(l%pier[a]==0)
         {
            int s=0;
            while(l%pier[a]==0)
            {
               s++;
               l/=pier[a];
            }
            ile[a]=s;
         }
     }
         if(l>1)
         {
         pier[0]=l;
         ile[0]=1;
         }
      for(int i=0; i<=3600; i++)
      if(ile[i]>0)  
      suma*=(poteg(pier[i], ile[i]+1)-1)/(pier[i]-1);
      cout<<suma%m<<endl;  
      for(int i=0; i<3600; i++)
      ile[i]=0;
   }
}
