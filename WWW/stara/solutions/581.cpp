#include <iostream>
#include <vector>
using namespace std;

#define INF 1000000001

int A[201];
int T[201][201];
int S[201];
int B[201][201];
int exp;

int main(){
int d; scanf("%d", &d);
while(d--){
	int n; scanf("%d", &n);
	for (int i=1; i<=n; ++i){
		scanf("%d", &A[i]);
	}
	for (int i=1; i<=n; ++i) for (int j=1; j<=n; ++j) {
		T[i][j] = B[i][j] = ( (i==j) ? 0 : INF);
	}
	
	S[0] = 0; for (int a=1; a<=n; ++a) S[a] = A[a] + S[a-1];
	int b, exp2;
	
	for (int len=1; len<n; ++len){
		for (int a=1; a+len<=n; ++a){
			
			b = a + len;
			
			for (int c=a;c<b; ++c){
				exp = T[a][c] + T[c+1][b] + S[b] - S[a-1];
				if ( T[a][b] >= exp ) {
					if ( T[a][b] == exp) {
						//B[a][b] = min( B[a][b],  B[a][c] + B[c+1][b] + ( (c+1==b) ? 0 : 1 ) );
						exp2 = B[a][c] + B[c+1][b] + ( (c+1==b) ? 0 : 1 );
						if ( B[a][b] > exp2 ) B[a][b] = exp2;
						
					} else B[a][b] = B[a][c] + B[c+1][b] + ( (c+1==b) ? 0 : 1 );
					
					T[a][b] = exp;
				}
			}
			
		}
	}

	printf("%d %d\n", T[1][n], B[1][n]);
}

return 0;
}

