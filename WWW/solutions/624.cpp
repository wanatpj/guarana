#include<iostream>
using namespace std;

int N,M;
int K,O,D;

int main(){
	scanf("%d%d",&N,&M);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d%d%d",&K,&O,&D);
		if(M < K){
			printf("komin\n");
		}
		else if(M < O){
			printf("okno\n");
		}
		else if(M < D){
			printf("drzwi\n");
		}
		else
			printf("brak\n");
	}
	return 0;
}

