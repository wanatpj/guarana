#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
const int size=1009;
char kier[ size ][ size ];
bool kol [ size ][ size ];
char niew[ size ][ size ];
char k[7] = {0,'g','d','p','l',0,0};
int c,n,il;
    struct point
    {	int x,y;
    };
stack<point> stos;
point pkt, wyn[size*size];
void zeruj()
{
    il=0;
    for(int i=1;i<=n;++i)
	for(int j=0;j<=n;++j)
	{	
	    kier[ i ][ j ] = '.';
	    kol[ i ][ j ] = false;
	    niew[ i ][ j ] = 0;
	}
    while( stos.size() )
	stos.pop();
}
void wrzuc(point &p,char kr)
{	
    if( kr == 'p')
		++pkt.x;
    else if( kr == 'l')
		--pkt.x;
    else if( kr == 'g')
		++pkt.y;
    else if( kr == 'd')
		--pkt.y;	
}
void cofnij()
{
    stos.pop();
    pkt = stos.top();
    while( kier[ pkt.x ][ pkt.y ] != '.' )
    {	stos.pop();
	pkt = stos.top();
    }
}
void szukaj()
{   pkt.x=1;
    pkt.y=1;
    stos.push(pkt);
    while(1)
    {	if( kier[ pkt.x ][ pkt.y ] == 'k')
	    break;
	//printf("jestem w %d %d ide do %c\n",pkt.x,pkt.y,kier[pkt.x][pkt.y]);
	if( kol[ pkt.x ][ pkt.y ] || pkt.x == 0 || pkt.x > n || pkt.y == 0 || pkt.y > n)
	{   //printf("wszedlem\n"); 
	    cofnij();
	}
	//printf("ok\n");    
	kol[ pkt.x ][ pkt.y ] = true;
	if( kier[ pkt.x ][ pkt.y ] == '.')
	    wrzuc(pkt, k[ ++niew[ pkt.x ][ pkt.y ] ]); 	
	else
	    wrzuc(pkt, kier[ pkt.x ][ pkt.y ]);
	//printf("ok\n"); 
	stos.push(pkt);	
    }
    //printf("po whilyu\n");
    il = stos.size();
    while( stos.size() )
    {	wyn[ stos.size() ] = stos.top();
	stos.pop();
    }
}
void obroc()
{
    for(int i=1;i<n;++i)
	for(int j=i+1;j<=n;++j)
	    swap(kier[i][j],kier[j][i]);
}
void wypisz()
{
    for(int i=1;i<=n;++i)
    {	for(int j=1;j<=n;++j)
	    printf("%c",kier[i][j]);	    
	printf("\n");
    }
}
int main()
{	scanf("%d",&c);
    while(c--)
    {	zeruj();
	scanf("%d",&n);
	for(int i=n;i>=1;--i)
	    scanf("%s",kier[i]+1);
	obroc();
	//wypisz();
	//printf("wczytalem\n");        
	szukaj();
	printf("%d\n",il);
	for(int i=1;i<=il;++i)
	    printf("%d %d\n",wyn[ i ].x,wyn[ i ].y);
    }	
return 0;
}