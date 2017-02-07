#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
	int d;
	scanf("%d", &d);
	int n;
	int t[201];
	int w[201][201];
	int s[201][201];
	int na[201][201];
	while(d--){
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d", &s[i][i]);
			w[i][i]=0;
			na[i][i]=0;
			for(int j=0; j<n; j++){
				if(i!=j){
					w[i][j]=1000000000;
					na[i][j]=1000000000;
				}
			}	
		}
		
		for(int i=1; i<n; i++){
			for(int j=0; j<n-i; j++){
				s[j][i+j]=s[j][i+j-1]+s[i+j][i+j];
			}
		}
		for(int i=1; i<n; i++){
			//³¹czymy do napisow d³ugoœci i+1
			for(int j=0; j<n-i; j++){
				//o poczatku w j
				for(int k=j; k<=j+i; k++){
					//z 2 kawa³ków j do k i k+1 do i+j;
					if(w[j][j+i]>w[j][k]+w[k+1][i+j]+s[j][i+j]){
						w[j][j+i]=w[j][k]+w[k+1][i+j]+s[j][i+j];
						if(k+1==i+j) na[j][i+j]=na[j][k]; else na[j][i+j]=na[j][k]+na[k+1][i+j]+1;
					}else{
						if(w[j][j+i]==w[j][k]+w[k+1][i+j]+s[j][i+j]){							
							if(k+1==i+j) na[j][i+j]=min(na[j][i+j], na[j][k]); 
							else na[j][i+j]=min(na[j][i+j], na[j][k]+na[k+1][i+j]+1);
						}						
					}
					//printf("%d %d %d %d\n", j, j+i, k, w[j][i+j]);
				}	
			}
		}
		
		printf("%d %d\n", w[0][n-1], na[0][n-1]);
	}
	return 0;
}
