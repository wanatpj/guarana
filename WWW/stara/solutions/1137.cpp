#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n, u;
	scanf("%d", &n);
	long long wynik=0, temp=0;
	for(int i = 0;i<n;i++)
	{
		scanf("%d", &u);
		if(u>temp+u)
			temp=u;
		else
			temp+=u;
		wynik=max(wynik,temp);
	}
	printf("%lld\n", wynik);
	return 0;
}
