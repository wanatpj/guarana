#include <iostream>
#include <ctime>

int n,mik,a,b,c;

int main()
{
    srand(time(NULL));
    scanf("%d",&n);
    mik=(rand()%121)+80;
    printf("%d %d\n",n,mik);
    for(int i=0;i<n;i++)
    {
	a=rand()%801+50;
        b=rand()%801+50;
	c=rand()%801+50;
	printf("%d %d %d\n",a,b,c);
    }
    return 0;
}
