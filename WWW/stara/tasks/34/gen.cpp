#include <iostream>
#include <ctime>
using namespace std;

int n,z;

main()
{
    scanf("%d",&z);
    scanf("%d",&n);
    printf("%d\n",z);
    srand(time(NULL));
    while(z--)
    {
	printf("%d\n",n);
        for(int i=0;i<n;i++) printf("%d ",rand()%10000+1);
	printf("\n");
    }
    return 0;
}
