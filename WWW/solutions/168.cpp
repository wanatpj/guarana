#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define Ld long double

bool debug=false;

Ld sgn(Ld A) // zwraca mi znak, tj dodatnie, zero, ujemne
{
    if(A>0) return 1;
    if(A<0) return -1;
    return 0;
}
class pkt
{
    public:
    Ld x,y;
    void Wczytaj() 
    {
        scanf("%Lf%Lf", &x, &y);
    }
    void Wypisz()     {
        printf("%.5Lf %.5Lf\n", x, y);
    }
};

class odcinek1 
{
    public:
    pkt one,two;
};
class odcinek2 {
    public:
    Ld a,b,x1,x2;

    void Wyznacz(pkt A, pkt B)
    {
        if(A.x>B.x)
        {
            pkt t=A;    A=B;    B=t;
        }
        a=(A.y-B.y)/(A.x-B.x);
        b=A.y-a*A.x;
        x1=A.x;
        x2=B.x;
    }
};


const int mRM=6;
const int RM=100;
pkt tab[mRM]; 
vector<odcinek1> bokiT1; 
vector<odcinek1> bokiT2; 
vector<pkt> przeciecia; 
pkt doCzego; 

bool czyPionowy(odcinek1 A) 
{
    if(A.one.x==A.two.x) return true;
    return false;
}

Ld bez(Ld a) // wartosc bezwzgledna
{
    if(a<0) a*=-1;
    return a;
}

Ld det(pkt A, pkt B, pkt C) 
{
    return A.x*B.y + B.x*C.y + C.x*A.y - A.x*C.y - B.x*A.y - C.x*B.y;
}
Ld det2(pkt A, pkt B)
{
    return A.x*B.y - B.x*A.y;
}

Ld pole(int a, int b) 
{
    Ld wyn=0;
    for(int i=a; i<b; i++) 
    {
        wyn+=det2(tab[i],tab[i+1]);
if(debug)       printf("%d %d %.5Lf\n", a, b, wyn);
    }
    wyn+=det2(tab[b],tab[a]);
if(debug)    printf("wyn: %Lf\n", wyn);
    wyn/=2;
if(debug)    printf("wyn: %Lf\n", wyn);
    return bez(wyn);
}
bool naOdc(pkt A, pkt B, pkt C) 
{
    if(min(A.x,B.x)<=C.x && max(A.x, B.x)>=C.x && min(A.y,B.y)<=C.y && max(A.y,B.y)>=C.y)
        return true;
    return false;
}
bool CzyPrzecinaja(odcinek1 A, odcinek1 B) 
{
    Ld d1,d2,d3,d4;
    d1=det(B.one, B.two, A.one);
    d2=det(B.one, B.two, A.two);
    d3=det(A.one, A.two, B.one);
    d4=det(A.one, A.two, B.two);
    if(sgn(d1)*sgn(d2)<0 && sgn(d3)*sgn(d4)<0) return true; //leza para po przeciwnych stronach
    if(d1==0 && d2==0) return false;
    if(d3==0 && d4==0) return false;
    if(d1==0 && naOdc(B.one, B.two, A.one)) return true;
    if(d2==0 && naOdc(B.one, B.two, A.two)) return true;
    if(d3==0 && naOdc(A.one, A.two, B.one)) return true;
    if(d4==0 && naOdc(A.one, A.two, B.two)) return true;
    return false;
}

pkt Przeciecie(odcinek1 A, odcinek1 B) // punkt przecieciu
{

if(debug)    printf("HELLO\n");
if(debug)    A.one.Wypisz();
if(debug)    A.two.Wypisz();
if(debug)    B.one.Wypisz();
if(debug)    B.two.Wypisz();
if(debug)    printf("MOTO\n");
    pkt t;
    if((!czyPionowy(A)) &&(!(czyPionowy(B))))
    {
        odcinek2 A2; A2.Wyznacz(A.one, A.two);
        odcinek2 B2; B2.Wyznacz(B.one, B.two);
        t.x=(B2.b-A2.b)/(A2.a-B2.a);
        t.y=A2.a*t.x+A2.b;
    }
    else if(czyPionowy(A))
    {
        odcinek2 B2; B2.Wyznacz(B.one, B.two);
        t.x=A.one.x;
        t.y=B2.a*t.x+B2.b;
    }
    else
    {
        odcinek2 A2; A2.Wyznacz(A.one, A.two);
        t.x=B.one.x;
        t.y=A2.a*t.x+A2.b;
    }
if(debug)       t.Wypisz();
if(debug)       printf("I oto byl on\n");


    return t;
}
Ld dis(pkt A, pkt B) // odleglosc w metryce kartezjanskiej
{
    Ld dx = A.x-B.x;
    Ld dy = A.y-B.y;
    return sqrt(dx*dx + dy*dy);
}

bool Cmp(pkt A, pkt B) // czy pkt A mniejszy katowo od pkt B
{
    if(det(doCzego, A, B)<0) return false;
    else if(det(doCzego, A, B)>0) return true;
    else return dis(doCzego, A)<dis(doCzego, B);
}

Ld polePrze() // pole przeciecia
{
if(debug) printf("aaaa\n");

    //na vectorze przeciecia mam pkty, obliczyc ich pole
    if(przeciecia.size()==0) return 0;
    doCzego=przeciecia[0];
    for(int i=0; i<przeciecia.size(); i++) // wybieram pkt do ktorego bede porownywac
    {
        if(doCzego.y>przeciecia[i].y) doCzego=przeciecia[i];
        else if(doCzego.x>przeciecia[i].x) doCzego=przeciecia[i];
    }
    sort(przeciecia.begin(), przeciecia.end(), Cmp); // przesortowac zawsze dobrze

    przeciecia.push_back(przeciecia[0]);

    Ld wyn=0;

if(debug)    printf("mamy liczbe??? %Lf\n", wyn);

    for(int i=0; i<przeciecia.size()-1; i++) // dalej znow liczymy wektorowo pole...
    {
if(debug)       printf("%d %d : %Lf  ||| %Lf  |||  %Lf ||| %Lf\n", i, i+1, przeciecia[i].x, przeciecia[i].y, przeciecia[i+1].x, przeciecia[i+1].y);

        wyn+=det2(przeciecia[i],przeciecia[i+1]);
//      printf("%d %d %.5Lf\n", a, b, wyn);
if(debug)       printf("mamy liczbe? %Lf\n",wyn);
    }
    wyn/=2;
if(debug)       printf("mamy liczbe? %Lf\n",wyn);
    return bez(wyn);

}

int main()
{
    for(int i=0; i<mRM; i++) // wczytaj pkty
        tab[i].Wczytaj();
    for(int i=0; i<mRM/2; i++) //wrzuc wszystkie boki trojkata 1
        for(int j=i+1; j<mRM/2; j++)
        {
            odcinek1 t;
            t.one=tab[i]; t.two=tab[j];
            bokiT1.push_back(t);
        }
    for(int i=mRM/2; i<mRM; i++) // -||- trojkata 2
        for(int j=i+1; j<mRM; j++)
        {
            odcinek1 t;
            t.one=tab[i]; t.two=tab[j];
            bokiT2.push_back(t);
        }
    while(!przeciecia.empty())
        przeciecia.pop_back();
    for(int i=0; i<3; i++) // wrzucaj przeciecia
        for(int j=0; j<3; j++)
        {
            if(CzyPrzecinaja(bokiT1[i], bokiT2[j])) // jesli sie przecinaja
                przeciecia.push_back(Przeciecie(bokiT1[i], bokiT2[j])); // to wrzuc
        }

    Ld P1 = pole(0,2); // liczymy pole pierwszego trojkata
    Ld P2 = pole(3,5); // drugiegi
    Ld P3 = polePrze(); // przeciecia

    printf("%.5Lf", P1+P2-P3);
    return 0;
}                           