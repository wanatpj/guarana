#include <iostream>
using namespace std;
const int bpion=1;
const int bkrol=2;
const int cpion=3;
const int ckrol=4;
const int puste=0;

int t;
char tab[6];
int P[5][5];
bool OK;

int znak(char x)
{
    if(x=='b') return 1;
    else if(x=='B') return 2;
    else if(x=='c') return 3;
    else if(x=='C') return 4;
    else return 0;
}
bool CzyDobrePole(int x, int y)
{
    bool zab=0;
    bool niebity=1;
    if(y>0)
    {
	if(x>0) //lewy gorny
	{
	    if(P[y-1][x-1]==bkrol) zab=1;
	    if(P[y-1][x-1]==cpion) niebity=0;
	}
	if(P[y-1][x]==bkrol) zab=1;//gora, nic z tad nas nie zbije
	if(x<3)
	{
	    if(P[y-1][x+1]==bkrol) zab=1;
	    if(P[y-1][x+1]==cpion) niebity=0;
	}
    }
    if(x>0) if(P[y][x-1]==bkrol) zab=1; //nic z tad nas nie zbije
    if(x<3) if(P[y][x+1]==bkrol) zab=1;
    if(y<3)
    {
	if(x>0) if(P[y+1][x-1]==bkrol || P[y+1][x-1]==bpion) zab=1; //czarne piony nie zbijan as do tylu
	if(P[y+1][x]==bkrol) zab=1;
	if(x<3) if(P[y+1][x+1]==bkrol || P[y+1][x+1]==bpion) zab=1;
    }
    return zab && niebity;
}
bool CzyAtakowany(int x, int y) //czy czarny bedzie na danym polu atakowany
{
    if(y>0)
    {
	if(x>0) if(P[y-1][x-1]==bkrol) return true;
	if(P[y-1][x]==bkrol) return true;
	if(x<3) if(P[y-1][x+1]==bkrol) return true;
    }
    if(x>0) if(P[y][x-1]==bkrol) return true;
    if(x<3) if(P[y][x+1]==bkrol) return true;
    if(y<3)
    {
	if(x>0) if(P[y+1][x-1]==bkrol || P[y+1][x-1]==bpion) return true;
	if(P[y+1][x]==bkrol) return true;
	if(x<3) if(P[y+1][x+1]==bkrol || P[y+1][x+1]==bpion) return true;
    }
    return false;
}
bool NieUcieknie(int x, int y)
{
    if(y>0)
    {
	if(x>0) if((!P[y-1][x-1] || P[y-1][x-1]==bpion) && !CzyAtakowany(x-1,y-1)) return false;
	if((!P[y-1][x] || P[y-1][x]==bpion) && !CzyAtakowany(x, y-1)) return false;
	if(x<3) if((!P[y-1][x+1] || P[y-1][x+1]==bpion) && !CzyAtakowany(x+1,y-1)) return false;
    }
    if(x>0) if((!P[y][x-1] || P[y][x-1]==bpion) && !CzyAtakowany(x-1,y)) return false;
    if(x<3) if((!P[y][x+1] || P[y][x+1]==bpion) && !CzyAtakowany(x+1, y)) return false;
    if(y<3)
    {
	if(x>0) if((!P[y+1][x-1] || P[y+1][x-1]==bpion) && !CzyAtakowany(x-1, y+1)) return false;
	if((!P[y+1][x] || P[y+1][x]==bpion) && !CzyAtakowany(x, y+1)) return false;
	if(x<3) if((!P[y+1][x+1] || P[y+1][x+1]==bpion) && !CzyAtakowany(x+1, y+1)) return false;
    }
    return true;
}

void Badaj(int xs, int ys, int x, int y)
{
    int backup=P[y][x];
    int typ=P[ys][xs];
    P[ys][xs]=0;
    P[y][x]=typ;
    if(y>0)
    {
	if(x>0 && P[y-1][x-1]==ckrol)
	{
	    //SPRAWDZAMY CZY TO DOBRY RUCH
	    if(CzyDobrePole(x,y) && NieUcieknie(x-1,y-1))
	    {
		//cout << "X: "<< x << " Y: " << y << endl;
		OK=1;
		return;
	    }
	}
	if(x<3 && P[y-1][x+1]==ckrol)
	{
	    //SPRAWDZAMY CZY TO DOBRY RUCH
	    if(CzyDobrePole(x,y) && NieUcieknie(x+1,y-1))
	    {
		//cout << "X: "<< x << " Y: " << y << endl;
		OK=1;
		return;
	    }
	}
    }
    P[y][x]=backup;
    P[ys][xs]=typ;
}
bool Sprawdz(int x, int y)
{
    if(y>0 && P[y-1][x]==0) Badaj(x,y,x,y-1);
	if(OK) return true;
    if(y>0 && x>0) Badaj(x,y,x-1,y-1);
	if(OK) return true;
    if(y>0 && x<3) Badaj(x,y,x+1,y-1);
	if(OK) return true;
    return false;
}
void SzukajRuchow()
{
    for(int i=3; i>0; i--)
    {
	for(int j=0; j<4; j++)
	{
	    if(P[i][j]==1)
		if(Sprawdz(j,i)) return;
	}	
    }
}
int main()
{
    scanf("%d", &t);
    while(t--)
    {
	OK=0;
	for(int i=0; i<4; i++)
	{
	    scanf("%s", &tab);
	    for(int j=0; j<4; j++)
		P[i][j]=znak(tab[j]);
	}
	SzukajRuchow();
	if(OK) printf("TAK\n");
	else printf("NIE\n");
    }
return 0;
}