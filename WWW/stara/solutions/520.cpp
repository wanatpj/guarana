#include<cstdio>
#include<cmath>
using namespace std;

int C,P,M,p[5000],alfa[5000];
long long int wynik,N=0,n[20002],aktn;
bool isPrime[32000];
int lista[5000];
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

int rozloz2(long long int n) {
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
        int ile = 0;
        long long int popw = 1;
        long long int czyn;
        for (int i=0; i<=P; i++) {
                if (alfa[i] != 0) {
                        czyn = p[i];
                        for (int j=1; j<=alfa[i]; j++) {
                                wynik = wynik + popw*czyn;
                                if (wynik > M)
                                        wynik %=M;
                                czyn *= p[i];
                        }
                }
                popw = wynik;
        }
}
int rozloz(long long int n) {

        long long int popw,czyn;
        for (int i=0; (i<P) && (n!=1); i++) {
                popw = wynik;
                czyn = p[i];
                while(n%p[i] == 0) {
                        wynik = wynik + popw*czyn;
                        czyn *= p[i];
                        if (wynik > M)
                                wynik %=M;
                        n /= p[i];
                }

        }
        if (n!=1)
                wynik = wynik + wynik*n;
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
                wynik = 1;
                rozloz(n[i]);     
                if (wynik > M)
                        wynik %= M;
                printf("%lld\n",wynik);
        }
}
