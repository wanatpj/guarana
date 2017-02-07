//Na podstawie Niebieskiej Ksiazeczki z XI OI - zadanie Most
#include <iostream>
#define MAX 10010
using namespace std;

int t[MAX];
int n,z;
int t1, t2, tx, ty;		/* Czasy dla A_1, A_2 oraz dwoch wczytanych */
int wynik;
int ile;			/* Ile osob wczytano */

int main()
{
    scanf("%d",&z);
    while(z--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&t[i]);
        sort(t,t+n);
        if(n==1)
        {
            printf("%d\n",t[0]);
            continue;
        }
        t1=t[0];
        t2=t[1];
        wynik = t2;  /* Ostatnie przejscie A_1 i A_2 */
        ile = 2;
        /* Jezeli n nieparzyste, to wczytamy A_3, ktore na pewno idzie pojedynczo */
        if (n % 2 == 1)
        {
            tx=t[2];
            wynik += tx + t1;
            ile++;
        }
        /* Wczytujemy po 2... */
        while(ile<n)
        {
            tx=t[ile];
            ty=t[ile+1];
            if (tx <= 2 * t2 - t1)
            wynik += tx + ty + 2 * t1; /* kazde pojedynczo */
            else wynik += ty + 2 * t2 + t1; /* podwojnie */
            ile += 2;
        }
        printf("%d\n",wynik);
    }
    return 0;
}
