#include<cstdio>
int main()
{
int n;
scanf("%d", &n);
printf("%llu", (unsigned long long)(1<<n) -1);
return 0;
}
