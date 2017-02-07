fdsg
#include<cstdio>
int main()
{
int n;
scanf("%d", &n);
unsigned long long t = 1;
while(n--) t*=2;
printf("%llu", t-1);
return 0;
}
