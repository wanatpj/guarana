//wiem, że będe miał buga na ostatnim teście, ale to jest dziwne, bo t == 1?!
#include<cstdio>
int main()
{
int n;
scanf("%d", &n);
unsigned long long t = 1;
t<<=n;
printf("%llu", t-1);
return 0;
}
