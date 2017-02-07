#include <iostream>
using namespace std;

int n, k, suma;
int tab[100001];

main()
{
int z;
cin>>z;
for(int ii=0; ii<z; ii++)
{
   cin>>n;
   k=0;
   for(int i=1; i<=n; i++)
   cin>>tab[i];
   sort(tab+1, tab+n+1);
   for(int i=1; 2*i<=n; i++)
   {
      if(2*tab[2]-tab[1]<tab[n-2*i+1])
      k=i;
   }   
   suma=(n-k-2)*tab[1]+(2*k+1)*tab[2];
   for(int i=3; i<=n-2*k; i++)
   suma+=tab[i];
   for(int i=0; i<=k-1; i++)
   suma+=tab[n-2*i];
   cout<<suma<<endl;
}
}
