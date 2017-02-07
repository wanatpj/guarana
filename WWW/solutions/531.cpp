#include<cstdio>
#include<cmath>
using namespace std;

int C,P,M,p[5000];
int wynik,N=0,n[20002],aktn;
bool isPrime[32000];
void sito(int N) {
        P = 0;
        N = sqrt(N);
        isPrime[0] = isPrime[1] = 0;
        for (int i=2; i<=N; i++)
                isPrime[i] = 1;
        for (int i=2; i<=N; i++)
                if (isPrime[i]) {
                        p[P++] = i;
                        for (int j = i*i; j<=N; j+=i)
                                isPrime[j] = 0;
                }
}

int rozloz(int n) {
        int popw,czyn;
        for (int i=0; i<P; i++) {
                popw = wynik;
                czyn = p[i];
                while(n%p[i] == 0) {
                        wynik = wynik + popw*czyn;
                        czyn *= p[i];
                        n /= p[i];
                }
                        if (wynik > M)
                                wynik %=M;
        }
        if (n!=1)
                wynik = wynik + wynik*n;
        if (wynik > M)
                wynik %= M;
}

int main() {
        scanf("%d%d",&C,&M);        
        for (int i=0; i<C; i++) {
                scanf("%d",&n[i]);
                if (n[i] > N)
                        N = n[i];
        }
        sito(N);
        for (int i=0; i<C; i++) {
                wynik = 1;
                rozloz(n[i]);     
                printf("%d\n",wynik);
        }
}
