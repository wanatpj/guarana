#include <iostream>

main()
{
    int a;
    unsigned long long tab[65], tmp=2;
    for(int i=1;i<=64;i++)
    {
        tab[i]=tmp;
        tmp*=2;
    }
    scanf("%d",&a);
    printf("%llu",tab[a]-1);
    return 0;
}
