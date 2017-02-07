#include <iostream>

main()
{
unsigned long long n,res;
scanf("%llu",&n);
if(n&1) res=((n+1)/2)*(n+2);
else res=((n+2)/2)*(n+1);
printf("%llu\n",res);
return 0;
}
