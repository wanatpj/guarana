#include <iostream>

int ile,mod;
 
int main()
{
    srand(time(NULL));
    scanf("%d %d",&ile,&mod);
    printf("%d %d\n",ile,mod);
    while(ile--)
    {
	printf("%d\n",rand()%100);
    }
    return 0;
}
