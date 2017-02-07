//test limitow czasu
#include <iostream>

main()
{
    int a;
    long long result=1;
    scanf("%d",&a);
    for(int i=1;i<=a;i++) result+=i;
    printf("%lld",result);
    return 0;
}
