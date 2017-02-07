#include<cstdio>

using namespace std;

#define min(a, b) (a>b?a:b)
int d, n, t;
int L[10000];

int najkrotszy(int x)
{
 int a=0;
 if(x==2) a=L[2];
 else if(x==3) a =(L[1]+L[2]+L[3]);
 else a = min((najkrotszy(x-2)+L[1]+2*L[2]+L[x]), (najkrotszy(x-1)+L[1]+L[x]));
 return a;
}

int main()
{
 scanf("%d\n", &d);
 for(int f=0; f<d; f++)
 {
  scanf("%d\n", &n);
  for(int g=0; g<=n; g++)
   L[g]=0;
  for(int g=1; g<=n; g++)
  {
   scanf("%d", &t);
   L[g]=t;
  }
  int y=najkrotszy(n);
  printf("%d\n", y);
 }
 return 0;
}