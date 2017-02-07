#include <cstdio>

using namespace std;

int fib[3];
#define M 1000000000

int main()
{
	int a, k;
	scanf("%d", &a);
	fib[0]=1;
	fib[1]=1;
	for(int i = 0;i<100000*a;i++)
		fib[(i+2)%3]=(fib[(i+1)%3]+fib[i%3])%M;
	printf("%d\n", a);
}
