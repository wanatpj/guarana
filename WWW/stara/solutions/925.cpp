#include<iostream>
#include<algorithm>
using namespace std;
const int SIZE = 10010;
int n,d;
int t[SIZE];
int c[SIZE];
int main(){
	scanf("%d\n",&d);
	while(d--){
		scanf("%d\n",&n);
		for(int i = 0 ; i < n ; ++i)
			scanf("%d",&t[i]);
		sort(t,t+n);
		if(n == 1){
			printf("%d\n",t[0]);
			continue;
		}
		if(n == 2){
			printf("%d\n",t[1]);
		}
	/*	for(int i = 0 ; i < n ; ++i)
			printf("%d ",t[i]);
		printf("\n");//*/
		c[0] = t[0];
		c[1] = t[1];
		c[2] = t[0]+t[1]+t[2];
		for(int i = 3 ; i < n ; ++i){
			c[i] = min(c[i-2]+t[0]+2*t[1]+t[i],c[i-1]+t[0]+t[i]);
			//printf("c[%d]: %d\n",i,c[i]);
		}
		printf("%d\n",c[n-1]);
	}
	return 0;
}

