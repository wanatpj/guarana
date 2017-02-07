#include <iostream>
using namespace std;

const int MAXN=205;
int t[MAXN][MAXN];
int d[MAXN][MAXN];
int ile[MAXN][MAXN];
int in[MAXN];
int z,n,x;

int main() {
	int j;
	scanf("%d", &z);
	while(z--) {
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				t[i][j]=ile[i][j]=2000000000;
			}
		}
		for(int i=0; i<n; i++) {
			scanf("%d", &in[i]);
		}
		for(int i=0; i<n; i++) {t[i][i]=ile[i][i]=0; d[i][i]=in[i];}
		for(int i=0; i<n-1; i++) {
            ile[i][i+1]=0;
			t[i][i+1]=in[i]+in[i+1];
			d[i][i+1]=in[i]+in[i+1];
		}
		for(int k=2; k<n; k++) {
			for(int i=0; i<n-k; i++) {
				for(int j=i+k-1; j>=i; j--) {
					if(t[i][i+k]>=t[i][j]+t[j+1][i+k]+d[i][j]+d[j+1][i+k]) {//zlozenie dwoch ciagow
						if(t[i][i+k]==t[i][j]+t[j+1][i+k]+d[i][j]+d[j+1][i+k]) {
                            d[i][i+k]=d[i][j]+d[j+1][i+k];
                            if(j+1!=i+k && ile[i][j]+ile[j+1][i+k]+1<ile[i][i+k])
                                ile[i][i+k]=ile[i][j]+ile[j+1][i+k]+1;
                            else if(j+1==i+k && ile[i][j]+ile[j+1][i+k]<ile[i][i+k])
                                ile[i][i+k]=ile[i][j]+ile[j+1][i+k];
                        }
                        else {
                            t[i][i+k]=t[i][j]+t[j+1][i+k]+d[i][j]+d[j+1][i+k];
						    d[i][i+k]=d[i][j]+d[j+1][i+k];
						    if(j+1!=i+k)
                                ile[i][i+k]=ile[i][j]+ile[j+1][i+k]+1;
                            else if(j+1==i+k)
                                ile[i][i+k]=ile[i][j]+ile[j+1][i+k];
                        }
					}
				}
			}
		}
		printf("%d %d\n", t[0][n-1], ile[0][n-1]);
	}
	return 0;
}
