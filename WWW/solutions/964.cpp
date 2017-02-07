#include<cstdio>
#include<algorithm>

using namespace std;

int d, n, t;
int L[10000];
int Sumy[10000];

int min(int l, int p)
{
 while(p!=1)
 {
  int s=(l+p)/2;
  min(l, s-1);
  min(s, p);
  if(min(l, s-1)<min(s, p))
   p=s-1;
  else
   l=s;
 }
 if(l<p)
 return l;
 else
 return p; 
}

int S(int n, int k)
{
 int s=0;
 s=(n-k-2)*L[1] + (2*k+1)*L[2];
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
  sort(L, L+n);
  for(int k=0; k<=(n/2-1); k++)
   Sumy[k]=S(n, k);
  int s=min(0, (n/2-1));
  printf("%d\n", s);
 }
 return 0;
}