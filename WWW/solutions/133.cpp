#include <iostream>
using namespace std;

int n, k, m;
int licz, mian;
int tab[1000000];
int tab2[1000000];


int silnia(int x)
{
    int w=1;
    for(int i=2; i<=x; i++)
    w*=i;
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
         for(int j=1; j<=i; j++)
         tab2[j]=tab[j-1]+tab[j];
         for(int j=0; j<=i; j++)
         tab[j]=tab2[j];
         tab[i+1]=0;
      }
for(int i=0; i<k; i++)
{
   int p=0;
   int j=0;
   while((j*k+i)<=n)
   {
      int q=j*k+i;
      p+=(silnia(n)/(silnia(q)*silnia(n-q)));
      j++;
   }
p%=m;
cout<<p<<endl;
}
//system("pause");
}
