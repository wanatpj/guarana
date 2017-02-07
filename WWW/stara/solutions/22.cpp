#include <cstdio>

using namespace std;

const int RM = 4;

class sza
{
    public:

    int pla[RM][RM];
    int xc,yc;

    void Wczytaj()
    {
        char c;
        for(int j=0; j<RM; j++)
            for(int i=0; i<RM; i++)
            {
                c=getchar();
                while(c!='b' && c!='B' && c!='c' && c!='C' && c!='.')
                    c=getchar();
                if(c=='b')
                    pla[i][j]=1;
                else if(c=='c')
                    pla[i][j]=2;
                else if(c=='B')
                    pla[i][j]=3;
                else if(c=='C')
                {    pla[i][j]=4; xc=i; yc=j;}
                else if(c=='.')
                    pla[i][j]=0;
            }
    }
    void Wypisz()
    {
        for(int j=0; j<RM; j++)
        {
            for(int i=0; i<RM; i++)
                printf("%d", pla[i][j]);
            printf("\n");
        }
    }
};

bool czyMat(sza A)
{
    int x=A.xc;
    int y=A.yc;

    for(int a=-1; a<=1; a++)
        for(int b=-1; b<=1; b++)
        {
            if(x+b<RM && x+b>=0 && y+a<RM && y+a>=0 && A.pla[x+b][y+a]==3)
                return true;
        }
    for(int a=-1; a<=1; a+=2)
        {
            int b=1;
            if(x+a<RM && x+a>=0 && y+b<RM && y+b>=0 && A.pla[x+a][y+b]==1)
                return true;
        }
    return false;
}

bool czyPlansza(sza A)
{
    bool ruchPiona=false;
    sza tA=A;
    //dla kazdego ruchu czarnego, jesli !mat return false
    for(int j=0; j<RM; j++)
        for(int i=0; i<RM; i++)
        {
            tA=A;
            if(tA.pla[i][j]==2 && j<(RM-1))
            {
                if(tA.pla[i][j+1]==0)
                {
                    tA.pla[i][j]=0;
                    tA.pla[i][j+1]=2;
                    ruchPiona=true;
                    if(!czyMat(tA)) return false;
                }
                tA=A;
                if(i>0 && tA.pla[i-1][j+1]==1)
                {
                    tA.pla[i-1][j+1]=2;
                    tA.pla[i][j]=0;
                    ruchPiona=true;
                    if(!czyMat(tA)) return false;
                }
                tA=A;
                if(i<(RM-1) && tA.pla[i+1][j+1]==1)
                {
                    tA.pla[i+1][j+1]=2;
                    tA.pla[i][j]=0;
                    ruchPiona=true;
                    if(!czyMat(tA)) return false;
                }
            }
        }
    for(int j=0; j<RM; j++)
        for(int i=0; i<RM; i++)
            if(A.pla[i][j]==4)
            {
                tA=A;
                if(!ruchPiona)
                {
//debug//                   if(A.pla[1][1]==1) printf("BOOYAKURWA\n");

                    if(!czyMat(tA))  return false;
                }

                tA=A;
                if(i>0 && j>0 && tA.pla[i-1][j-1]!=2)
                {
                    tA.pla[i-1][j-1]=4;
                    tA.xc=i-1; tA.yc=j-1;
                    tA.pla[i][j]=0;
                    if(!czyMat(tA)) return false;
                }
                tA=A;
                if(i>0 && tA.pla[i-1][j]!=2)
                {
                    tA.pla[i-1][j]=4;
                    tA.xc=i-1;
                    tA.pla[i][j]=0;
                    if(!czyMat(tA)) return false;

                }
                tA=A;
                if(i>0 && j<(RM-1) && tA.pla[i-1][j+1]!=2)
                {
                    tA.pla[i-1][j+1]=4;
                    tA.xc=i-1; tA.yc=j+1;
                    tA.pla[i][j]=0;
                    if(!czyMat(tA)) return false;
                }
                tA=A;
                if(j>0 && tA.pla[i][j-1])
                {
                    tA.pla[i][j-1]=4;
                    tA.yc=j-1;
                    tA.pla[i][j]=0;
                    if(!czyMat(tA)) return false;
                }
                tA=A;
                if(j<(RM-1) && tA.pla[i][j+1])
                {
                    tA.pla[i][j+1]=4;
                    tA.yc=j+1;
                    tA.pla[i][j]=0;
                    if(!czyMat(tA)) return false;
                }
                tA=A;
                if(i<(RM-1) && j>0 && tA.pla[i+1][j-1])
                {
                    tA.pla[i+1][j-1]=4;
                    tA.xc=i+1; tA.yc=j-1;
                    tA.pla[i][j]=0;
                    if(!czyMat(tA)) return false;
                }
                tA=A;
                if(i<(RM-1) && tA.pla[i+1][j]!=2)
                {
                    tA.pla[i+1][j]=4;
                    tA.xc=i+1;
                    tA.pla[i][j]=0;
                    if(!czyMat(tA)) return false;

                }
                tA=A;
                if(i<(RM-1) && j<(RM-1) && tA.pla[i+1][j+1]!=2)
                {
                    tA.pla[i+1][j+1]=4;
                    tA.xc=i+1; tA.yc=j+1;
                    tA.pla[i][j]=0;
                    if(!czyMat(tA)) return false;
                }
            }



//    printf("WSZEDZIE byl mat\n");
//    A.Wypisz();

    return true;

}

bool czyZad(sza A)
{
    for(int j=0; j<RM; j++)
        for(int i=0; i<RM; i++)
            if(A.pla[i][j]==1 && j>0)
            {
                sza tA=A;
                if(tA.pla[i][j-1]==0)
                {
                    tA.pla[i][j-1]=1;
                    tA.pla[i][j]=0;

//debug/                    if(i==1 && j==2) tA.Wypisz();
                    if(czyPlansza(tA)) return true;
                }
                tA=A;
                if(i>0 && tA.pla[i-1][j-1]==2)
                {
                    tA.pla[i-1][j-1]=1;
                    tA.pla[i][j]=0;
///debug/                   if(i==2 && j==2) tA.Wypisz();
                    if(czyPlansza(tA)) return true;
                }
                tA=A;
                if(i<(RM-1) && tA.pla[i+1][j-1]==2)
                {
                    tA.pla[i+1][j-1]=1;
                    tA.pla[i][j]=0;
                    if(czyPlansza(tA)) return true;
                }
            }
    return false;
}


int main()
{
    int zw;
    scanf("%d", &zw);
    for(int kl=0; kl<zw; kl++)
    {
        sza A;
        A.Wczytaj();
//debug/        A.Wypisz();
        if(czyZad(A)) printf("TAK\n");
        else printf("NIE\n");

    }
    return 0;
}
