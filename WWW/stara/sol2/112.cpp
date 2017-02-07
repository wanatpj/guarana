#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
string s = "\"O Ty dziadzie!\"\npowiedziala wlasna dziewczyna Kalop Madzie\n\nLamana Kalopia\ni jego utopia\n\nKalop Mada\nz drzewa spada\n, kazda dziewka mu do nog upada\n, tak sie bardzo dobrze sklada\n, ze to jego najwieksza wada\n, lecz trza mu przyzanc, ze kazda dobrze wybada\ni kazde wyznanie to dla niego nie lada,\nbo Snikersa jada.\n\t    -,\nze nie przeszkldzi mu rwaca Lada,\nlecz czasem ze zmeczenia sobie siada,\npotem ze zmeczenia pada\ni mowi: \"Jam 44 ... Kalop Mada\"\n\nTak do siebie on to gada\ni tak sobie te rzecz wmawia\ni nie trudna mu tez Ada\n, bo choc nie wiem, ale pewnie z Paskalem czesto rozmawia.\n\nStop! To nie prawda! Nie ten czterdziesci i cztery\n, co jest prada, ten zdobyl wielkie gory,\njak i przezyl nowe ery\n, lecz sam nie wie, ze powinien na rowery..",
    t = "Kalop Mada\n, ale coz to cos go zjada,\nbiada mu biada.\nMoze toz to jego wada\nPrzydac tu sie by dobra rada.\nKtos kto by dobrze obada.\nCzy to Kleczek? .. - NIE!\nCzy to Kinia? .. - NIE!\n, alez ktoz to\nto cien czlowieka\nodbitego w lustrze\ntak to on, ona, to\nnie wiem znika\n, ale coz to zostal obraz w pamieci - w komputerze\n, bo tEN choc mial glowe\nw druga strone od tego .. widzial\nco prawda - obraz, a nie jadro macierzy\n, lecz ktorz w tych czasch uwierzy\nw zapis komputerowy lub w co kto cos w oczach mial\npredzej sie bedzie bal\n, lecz prawda zostanie prawda chocby przez wode\n, i ten kto to zmieni biada mu biada\n, bo go zniszczy Kalop Mada\n\nLecz tak widac na nie zmienionym\nbo ten co nie klamie temu uwierza\nchocby sie dobrze uwiarygadnial\n\nchoc ten co bedzie klamal na jeden test zawsze odpadnie\ni wpadnie\n\nlecz Ci co dosiekaniem swym beda w sobie strudzonym\nsie dowiedza\n, ze ten to swe jedyne lecz madre i smutne gdyz pijackie czasy ..\n\ni tak to ten, kto wie ten wie\nsluchaj wiec gobre,\nale nie czyn tego\ni otworz oczy, by czynic to co nie jego badz swego\nlecz pacz on je\nwiec idz i zaklep to co ....\n\nTak Kalop Mado spojrz na to\nbo bato";
char c[1000];
int len;
int main()
{
    int j=0;
    while(scanf("%c", &c[j])!=EOF) j++;
    len = min(j,(int)s.length());
    for(int i=0;i<len;i++)
	if(s[i]==c[i])
	    printf("%c", t[i]);
    return 0;
}
