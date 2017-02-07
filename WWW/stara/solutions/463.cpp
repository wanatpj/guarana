#include<cstdio>
#include<cmath>
using namespace std;

int C,P,M,p[5000],alfa[5000];
long long int wynik,N=0,n[20002],aktn;
bool isPrime[32000];

void sito(long long int N) {
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

long long int rozloz(long long int n) {
        for (int i=0; i<P; i++)
                alfa[i] = 0;
        for (int i=0; (i<P) && (n!=1); i++) {
                while(n%p[i] == 0) {
                        n /= p[i];
                        alfa[i]++;
                }
        }
        if (n!=1)
                alfa[P] = 1;
        else
                alfa[P] = 0;
        p[P] = n;
}

void dodaj(int nr, long long int iloczyn) {
        if (nr > P) {
                wynik += iloczyn;
                if (wynik>M)
                        wynik %= M;
                return;
        } else {
                for (int i=0; i<=alfa[nr]; i++) {
                        dodaj(nr+1,iloczyn);
                        iloczyn *= p[nr];       
                }
        }
}

int main() {
        scanf("%d%d",&C,&M);        
        for (int i=0; i<C; i++) {
                scanf("%lld",&n[i]);
                if (n[i] > N)
                        N = n[i];
        }
        sito(N);
        for (int i=0; i<C; i++) {
                rozloz(n[i]);
                wynik = 0;
                dodaj(0,1);        
                printf("%lld\n",wynik);
        }
}
