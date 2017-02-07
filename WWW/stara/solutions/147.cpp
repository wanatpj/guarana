
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int RM=100009;

class droga
{
    public:
    int skad, dokad, koszt, stacja;
    void Wczytaj()
    {
        scanf("%d%d", &dokad, &koszt);
        dokad--;
    }
    bool operator < (const droga & A) const
    {
        if(koszt!=A.koszt)
            return koszt>A.koszt;
        else return stacja>A.stacja;
    }
};

class odp
{
    public:
    int odl, stacja;
    void Wypisz()
    {
        if(odl>-1)
            printf("%d %d\n", stacja+1, odl);
        else printf("BRAK\n");
    }
};

odp Wyn[RM];
vector<droga> Graf[RM];
priority_queue<droga> Przeg;
vector<int> Stacje;

int main()
{
    int n,m,r;
    scanf("%d%d%d", &n, &m, &r);
    while(!Stacje.empty())
        Stacje.pop_back();
    for(int i=0; i<r; i++)
    {
        int temp;
        scanf("%d", &temp);
        temp--;
        Stacje.push_back(temp);
    }
    for(int i=0; i<m; i++)
    {
        int temp;
        scanf("%d", &temp);
        temp--;
        droga t;
        t.Wczytaj();
        t.skad=temp;
        Graf[temp].push_back(t);
        temp=t.skad;
        t.skad=t.dokad;
        t.dokad=temp;
        Graf[t.skad].push_back(t);
    }
//    printf("koniecvc wczytywanie\n");

    for(int i=0; i<n; i++)
    {
        odp temp; temp.odl=temp.stacja=-1; Wyn[i]=temp;
    }
    while(!Przeg.empty())
        Przeg.pop();
    for(int i=0; i<r; i++)
    {
        odp temp;
        temp.odl=0;
        temp.stacja=Stacje[i];
        Wyn[Stacje[i]]=temp;

        int s = Graf[Stacje[i]].size();
        for(int j=0; j<s; j++)
        {
            droga t = Graf[Stacje[i]][j];
            t.stacja=Stacje[i];
            Przeg.push(t);
        }
    }
    while(!Przeg.empty())
    {
//      printf("whileeee\n");

        droga act = Przeg.top();
        Przeg.pop();
        if(Wyn[act.dokad].stacja==-1)
        {
//          printf("ifffffff\n");

            odp ODP;
            ODP.odl=act.koszt;
            ODP.stacja=act.stacja;
            Wyn[act.dokad]=ODP;

            int s = Graf[act.dokad].size();
            for(int i=0; i<s; i++)
            {
                droga t = Graf[act.dokad][i];
                if(Wyn[t.dokad].stacja==-1)
                {
                    t.koszt+=act.koszt;
                    t.stacja=act.stacja;
                    Przeg.push(t);
                }
            }
        }
    }
    int q;
    scanf("%d", &q);
    for(int i=0; i<q; i++)
    {
        int t;
        scanf("%d", &t);
        t--;
        Wyn[t].Wypisz();
    }

    return 0;
}