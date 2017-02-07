#include<cstdio>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int,int> Punkt;
#define x first 
#define y second
#define MP make_pair
const int NIL=-1;
const int END=4;
const int P=0;
const int G=1;
const int L=2;
const int D=3;
const int MAXN=1010;
const bool dbg=0;

int pla[MAXN][MAXN];
bool ok[MAXN][MAXN];
int n;
Punkt k;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int par[]={2,3,0,1};

void init()
{
//    for(int i=0;i<=n+1;i++)
//	for(int j=0;j<=n+1;j++)
//	    ok[i][j]=0;
    for(int i=0;i<=n+1;i++)
    {
	ok[0][i]=1;
	ok[n+1][i]=1;
	ok[i][n+1]=1;
	ok[i][0]=1;
    }
}

void read()
{
    char s[MAXN];
    char c;
    scanf("%d",&n);
    for(int y=n;y>=1;y--)
    {
	scanf("%s",s);
	for(int x=1;x<=n;x++)
	{
	    c=s[x-1];
	    if(c=='k')
	    {
		pla[x][y]=END;
		k=MP(x,y);
	    }
	    else if(c=='p')
		pla[x][y]=P;
	    else if(c=='g')
		pla[x][y]=G;
	    else if(c=='l')
		pla[x][y]=L;
	    else if(c=='d')
		pla[x][y]=D;
	    else pla[x][y]=NIL;
	    ok[x][y]=0;
	}
    }
    init();
    if(dbg)printf("READ:OK\nk:(%d %d)\n",k.x,k.y);
    if(dbg)
    {
	printf("pla:\n");
	for(int y=n+1;y>=0;y--)
	{
	    for(int x=0;x<=n+1;x++)
		printf("%2d(%d)",pla[x][y],(int)ok[x][y]);
	    printf("\n");
	}
    }
}

void print(Punkt p)
{
    int d;
    queue<Punkt> que;
    que.push(p);
    while(pla[p.x][p.y]!=END)
    {
	d=pla[p.x][p.y];
	p=MP(p.x+dx[d],p.y+dy[d]);
	que.push(p);
    }
    printf("%d\n",(int)que.size());
    while(!que.empty())
    {
	printf("%d %d\n",que.front().x,que.front().y);
	que.pop();
    }
}


void compute()
{
    queue<Punkt> que;
    ok[k.x][k.y]=1;
    que.push(k);
    Punkt p,t;
    Punkt poc=MP(1,1);
    while(!que.empty())
    {
	p=que.front();
	if(dbg)printf("p:(%d %d)\n",p.x,p.y);
	que.pop();
	if(p==poc)
	{
	    if(dbg)printf("print()\n");
	    print(p);
	    return;
	}
	for(int i=0;i<4;i++)
	{
	    if(dbg)printf("i:%d\n",i);
	    t=MP(p.x+dx[i],p.y+dy[i]);
	    if(dbg)printf("t:(%d,%d)\n",t.x,t.y);
	    if(ok[t.x][t.y])continue;
	    if(pla[t.x][t.y]==NIL || pla[t.x][t.y]==par[i])
	    {
		pla[t.x][t.y]=par[i];
		ok[t.x][t.y]=1;
		que.push(t);
	    }
	}
    }
}

int main()
{
    int d;
    scanf("%d",&d);
    while(d--)
    {
	read();
	compute();
    }
    return 0;
}

