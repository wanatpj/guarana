#include <cstdio>
using namespace std;


int n,m;
int a,b,c,f1,f2;
int sum=0;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d%d%d",&a,&b,&c,&f1,&f2);
		if(f1==0&&f2==1)
			sum++;
	}
	printf("%d",sum);
	return 0;
}