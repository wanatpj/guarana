#include<cstdio>
#include<algorithm>

using namespace std;

int d, n, t;
int L[10000];
int Sumy[5000];

long long int Sumuj(int n, int k)
{
 long long int s=0;
 s=((n-k-2)*L[1] + (2*k+1)*L[2]);
 for(int i=3; i<=(n-2*k); i++)
  s=s+L[i];
 for(int i=0; i<=k-1; i++)
  s=s+(L[n]-2*L[i]);
 return s;
}

int main()
{
 scanf("%d\n", &d);
 for(int f=0; f<d; f++)
 {
  scanf("%d\n", &n);
  for(int g=1; g<=n; g++)
  {
   scanf("%d", &t);
   L[g]=t;
  }
  sort(L+1, L+n+1);
 // for(int i=0; i<=n; i++)//debugg
   //printf("%d ", L[i]);//debugg
  for(int k=0; k<=n/2-1; k++)
   Sumy[k]=Sumuj(n, k);
  sort(Sumy, Sumy+(n/2-1));
  if(n==2 || n==3)
   printf("%d\n", Sumy[0]) ;
  else
   printf("%d\n", Sumy[1]);
 }
 return 0;
}