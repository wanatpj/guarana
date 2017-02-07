#include <cstdio>
#include <cmath>

int macierz[200][200];
long long suma;
int m;

void search(int wartosc, int rzad, int max);
void dzielniki(int n);

int main()
{
    int c;
    scanf("%d %d", &c, &m);
    while(c--)
    {
        int n;
        scanf("%d", &n);
        suma = 0;
        dzielniki(n);
        printf("%lld\n", suma);
    }
    return 0;
}

void dzielniki(int n)
{
    int rzad = 0, kolumna = 1;
    for(int i=2; i <= n;)
    {
        if(!(n%i))
        {
            if(kolumna == 1)
                macierz[rzad][0] = 1;
            macierz[rzad][kolumna] = pow(i, kolumna);
            n /= i;
            ++kolumna;
            if(n%i)
            {
                macierz[rzad][kolumna] = 0;
                ++rzad;
            }
        }
        else
        {
            kolumna = 1;
            ++i;
        }
    }
    search(1, 0, rzad);
}

void search(int wartosc, int rzad, int max)
{
    int tmp;
    for(int i=0; macierz[rzad][i]; ++i)
    {
        if(rzad < max-1)
        {
            tmp = wartosc*macierz[rzad][i];
            search(tmp, ++rzad, max);
            --rzad;
        }
        else
        {
            suma += wartosc*macierz[rzad][i];
            if(suma > m)
                suma %= m;
        }
    }
}
