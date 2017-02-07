#include<iostream>

using namespace std;

int d,n;
int cia;
int osoby;
int main(){
	scanf("%d",&d);
	for(int i = 0 ; i < d ; ++i){
		scanf("%d",&n);
		osoby = 0;
		int tmp;
		for(int i = 0 ; i < n ; ++i){
			scanf("%d",&tmp);
			osoby+=tmp;
		}
		scanf("%d",&cia);
		if(osoby)
			printf("%d\n",cia%osoby);
		else
			printf("%d\n",cia);
	}
	return 0;
}

