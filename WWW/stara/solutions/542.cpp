#include <iostream>
#include <vector>
using namespace std;

#define INF 1000000001

int A[201];
int T[201][201];
int S[201][201];
int B[201][201];
int exp;

int main(){
int d; scanf("%d", &d);
while(d--){
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i){
		scanf("%d", &A[i]);
	}
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
		T[i][j] = B[i][j] = ( (i==j) ? 0 : INF);
	}
	
	for (int a=0; a<n; ++a) {
		S[a][a] = A[a];
		for (int b=a+1; b<n; ++b)  S[a][b] = S[a][b-1] + A[b];
	}
	
	for (int len=1; len<n; ++len){
		for (int a=0; a+len<n; ++a){
			
			int b = a + len;
			
			for (int c=a;c<b; ++c){
				exp = T[a][c] + T[c+1][b] + S[a][c] + S[c+1][b];
				if ( T[a][b] >= exp ) {
					if ( T[a][b] == exp) {
						B[a][b] = min( B[a][b],  B[a][c] + B[c+1][b] + ( (c+1==b) ? 0 : 1 ) );
					} else B[a][b] = B[a][c] + B[c+1][b] + ( (c+1==b) ? 0 : 1 );
					
					T[a][b] = exp;
				}
			}
			
		}
	}

	printf("%d %d\n", T[0][n-1], B[0][n-1]);
}

return 0;
}

