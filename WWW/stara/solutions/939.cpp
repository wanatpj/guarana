/*************************************************************************
 *                                                                       *
 *                    XI Olimpiada Informatyczna                         *
 *                                                                       *
 *   Rozwizanie zadania: Most                                           *
 *   Plik:                mos.cpp                                        *
 *   Autor:               Micha Adamaszek                               *
 *************************************************************************/

#include <cstdio>
#include <algorithm>
using namespace std;
int t[1000008];
/* Program glowny */
int main() {
    int d;
    scanf("%d",&d);
    while(d--)
    {
    int n;
    int tx, ty;		/* Czasy dla A_1, A_2 oraz dwoch wczytanych */
    int wynik;
    int ile;			/* Ile osob wczytano */

    scanf("%d", &n);
    for(int i=1;i<=n;++i)
     	scanf("%d",&t[i]);
    sort(t+1,t+n+1);
    /* Przypadek szczegolny n==1 */
    wynik = t[1];
    if (n >= 2) {
	wynik = t[2];  /* Ostatnie przejscie A_1 i A_2 */
	ile = 2;
	/* Jezeli n nieparzyste, to wczytamy A_3, ktore na pewno idzie pojedynczo */
	if (n % 2 == 1) {
	    tx=t[++ile];
	    wynik += tx + t[1];
	}
	/* Wczytujemy po 2... */
	while (ile < n) {
	    tx=t[++ile], ty=t[++ile];
	    /* ... i patrzymy co wybrac */
	    if (tx <= 2 * t[2] - t[1])
		wynik += tx + ty + 2 * t[1]; /* kazde pojedynczo */
	    else wynik += ty + 2 * t[2] + t[1]; /* podwojnie */
	}
    }
    
    /* Koniec */
    printf("%d\n", wynik);
    }
    return 0;
}