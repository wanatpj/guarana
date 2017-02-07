#include <iostream>
using namespace std;

long long n, k, m;
long long licz, mian;
long long tab[1000000];
long long tab2[1000000];


long long silnia(int x)
{
    long long w=1;
    for(int i=2; i<=x; i++)
    w*=i;
    w%=m;
    if(w<1)
    w=1;
    return w;
}

main()
{
      cin>>n>>k>>m;
      tab[0]=1;
      tab[1]=0;
      for(int i=1; i<=n; i++)
      {
         tab2[0]=1;
         for(long long j=1; j<=i; j++)
         tab2[j]=tab[j-1]+tab[j];
         for(long long j=0; j<=i; j++)
         tab[j]=tab2[j];
         tab[i+1]=0;
      }
for(long long i=0; i<k; i++)
{
   long long p=0;
   long long j=0;
   while((j*k+i)<=n)
   {
      long long q=j*k+i;
      if(silnia(q)*silnia(n-q)!=0)
      p+=(silnia(n)/(silnia(q)*silnia(n-q)));
      j++;
   }
p%=m;
cout<<p<<endl;
}
//system("pause");
}
