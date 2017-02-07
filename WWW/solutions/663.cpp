#include<cstdio>
#include<cmath>
using namespace std;
const int duzo = 1000000000;
int D,N,q;
int nawiasy[202][202];
int m[202][202];
int suma[202][202];
int main() {
        scanf("%d",&D);
        while(D--) {
                scanf("%d",&N);
                for (int i=1; i<=N; i++)
                        nawiasy[i][i] = m[i][i] = 0;

                for (int i=1; i<=N; i++)
                        scanf("%d",&suma[i][i]);

                for (int i=1; i<=N; i++) {
                         for(int j=1; j+i<=N; j++)
                                suma[j][j+i] = suma[j][j+i-1] + suma[j+i][j+i];
                }
                               
                int j;                               
                for (int l = 2; l<=N; l++) 
                        for (int i=1; i<=N-l+1; i++) {
                                j = i+l-1;
                                m[i][j] = duzo;       
                                for (int k=i; k<=j-1; k++) {
                                        q = m[i][k]+m[k+1][j]+suma[i][k]+suma[k+1][j];
                                        if (q<m[i][j]) {
                                                m[i][j] = q;
                                                if (j-k-1!=0)
                                                        nawiasy[i][j] = nawiasy[i][k]+nawiasy[k+1][j]+1;
                                                else
                                                        nawiasy[i][j] = nawiasy[i][k]+nawiasy[k+1][j];
                                        }              
                                }
                                
                        }
                printf("%d %d\n",m[1][N],nawiasy[1][N]);
        }
}
