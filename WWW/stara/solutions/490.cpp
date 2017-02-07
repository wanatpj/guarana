#include<cstdio>
#include<algorithm>
using namespace std;

struct zez {
    int kto;
    int kogo;
    bool winny;
    bool podwojne;
} zeznanie[20002];

struct pod {
    int oskarza,uniewinnia;
    bool klamie;
    int wynik;
} podejrzany[10002];

bool por(const zez &a, const zez &b) {
    if (a.kto < b.kto)
        return 1;
    if (a.kto > b.kto)
        return 0;
    if (a.kogo < b.kogo)
        return 1;
    return 0;
}


int main() {
    int d,n,z,p,k,tmp;
    char c;
    scanf("%d",&d);
    zeznanie[0].kto = zeznanie[0].kogo = -1;
    while(d--) {
        scanf("%d %d\n",&n,&z);

//oczyszczamy podejrzanych z poprzednich zarzutow
        for (int i=1; i<=n; i++) {
            podejrzany[i].oskarza = podejrzany[i].uniewinnia = 0;
            podejrzany[i].klamie = podejrzany[i].wynik = 0;
        }

//tworzymy liste zeznan
        for (int i=1; i<=z; i++) {
            zeznanie[i].podwojne = 0;
            scanf("%d %c %d\n",&p,&c,&k);
            zeznanie[i].kto = p;   
            if (c == 'W') {
                zeznanie[i].winny = true;
                zeznanie[i].kogo = k;
            } else if (c == 'P') {
                zeznanie[i].winny = zeznanie[k].winny;
                zeznanie[i].kogo = zeznanie[k].kogo;   
            } else if (c == 'F') {
                zeznanie[i].winny = !zeznanie[k].winny;
                zeznanie[i].kogo = zeznanie[k].kogo;   
            }
        }

//sortujemy zeznania zeby wykluczyc podwojne        
        sort(zeznanie+1,zeznanie+z+1,por);

//wykluczamy podwojne i sprzeczne        
        for (int i=2; i<=z; i++)
            if ((zeznanie[i-1].kto == zeznanie[i].kto) && (zeznanie[i-1].kogo == zeznanie[i].kogo)) {
                if (zeznanie[i-1].winny != zeznanie[i].winny) //sprzeczne -> klamie
                    podejrzany[zeznanie[i].kto].klamie = true;
                zeznanie[i].podwojne = true;
            }
            
        int ile = 0;
        for (int i=1,j=1; i<=z; i++) {
            if (zeznanie[i].podwojne) //usuwamy podwojne zeznania
                ile++;
            else {
                zeznanie[j].kto = zeznanie[i].kto;
                zeznanie[j].kogo = zeznanie[i].kogo;
                zeznanie[j].winny = zeznanie[i].winny;
                j++;
            }
        }
        z -= ile;        

//sumujemy oskarzenia i uniewinnienia
        for (int i=1; i<=z; i++) {
            if (zeznanie[i].winny)
                podejrzany[zeznanie[i].kto].oskarza++;   
            else
                podejrzany[zeznanie[i].kto].uniewinnia++;
        }
        
        for (int i=1; i<=n; i++)
            if (podejrzany[i].oskarza>1)
                podejrzany[i].klamie = true;
            else if (podejrzany[i].uniewinnia == n) 
                podejrzany[i].klamie = true;

        ile = 0;
        for (int i=1; i<=n; i++)
            if (podejrzany[i].oskarza)
                ile++;
        for (int i=1; i<=n; i++)
            podejrzany[i].wynik = ile;
            
        for (int i=1; i<=z; i++) 
            if (!podejrzany[zeznanie[i].kto].klamie) {
                if (zeznanie[i].winny)   
                    podejrzany[zeznanie[i].kogo].wynik--;
                else if (!podejrzany[zeznanie[i].kto].oskarza)   
                    podejrzany[zeznanie[i].kogo].wynik++;
            }

        ile = podejrzany[1].wynik;
        for (int i=1; i<=n; i++)
            if (ile > podejrzany[i].wynik) 
                ile = podejrzany[i].wynik;
        for (int i=1; i<=n; i++)
            if (ile == podejrzany[i].wynik)
                printf("%d ",i);
        printf("\n");
             
    }
}
