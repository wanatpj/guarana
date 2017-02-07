#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;

const int MAX = 1000000;

char A[MAX+3];

int R[MAX+3];

int n;

void manacher() {
	int j = 0;
	for(int i=1;i<n;++i)
	{
		R[i] = min(R[j-(i-j)], j + R[j] - i);
		while(A[i+R[i]+1] == A[i-R[i]-1])
		{
			++R[i];
			j = i;
		}
		printf("%d ", R[i]);
	}
}

main() {
	A[0] = '#';
	scanf("%s", &A[1]);
	n = strlen(A);
	A[n] = '$';
	manacher();
}
