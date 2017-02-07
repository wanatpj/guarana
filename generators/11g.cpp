#include<cstdio>
#include<cstdlib>
#include<time.h>
int main()
{
    srand(time(NULL));
    printf("1000000\n");
    for(int i=0;i<1000000;i++)
	printf("%d ", rand()%1000000000-500000000);
    return 0;
}
