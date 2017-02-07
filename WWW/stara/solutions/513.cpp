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

int rozloz(long long int n) {
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
        for (int i=0; i<=P; i++)
                if (alfa[i] != 0) {
                        for (int j=1; j<=alfa[i]; j++) {
                                wynik = wynik + wynik*p[i];
                                if (wynik > M)
                                        wynik %=M;
                }

//                        lista[ile] = p[i];

  //                      alfa[ile] = alfa[i];
    //                    ile++;
                }
 //       long long int tmp;
//        for (int i=0; i<ile; i++) {
//                tmp = p[i];
  /*              for (int j=1; j<=alfa[i]; j++) {
                        wynik = wynik + wynik*lista[i];
                        if (wynik > M)
                                wynik %=M;
                }
        }*/
//  printf("%lld\n",wynik);      
//        return ile;
}

void dodaj(int nr, long long int iloczyn, int maxP) {
        if (maxP == 0) {
                wynik += iloczyn;
                if (wynik>1000000000)
                        wynik %= M;
                return;
        } else {
                maxP--;
                for (int i=0; i<alfa[nr]; i++) {
                        dodaj(nr+1,iloczyn,maxP);
                        iloczyn *= lista[nr];       
                }
                dodaj(nr+1,iloczyn,maxP);
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
                wynik = 1;
                rozloz(n[i]);     
                if (wynik > M)
                        wynik %= M;
                printf("%lld\n",wynik);
        }
}