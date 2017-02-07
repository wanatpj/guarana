#include <cstdio>
#include <stack>
#include <queue>
using namespace std;
int z,n,m,e,ff,a,b;
struct zwei{short a,b;};
zwei nju;
queue<zwei> S;
stack<zwei> S2;
char s[1001][1001];
char u[1001][1001];
zwei f[1001][1001];
bool wyp;


void DFS()//short a, short b)
{
nju.a=0; nju.b=0; S.push(nju); u[0][0]=1;
while(!S.empty()) {
    a=S.front().a; b=S.front().b; S.pop();
//    printf("wlaze do %d %d (%c)\n", a,b,s[a][b]);
    if (wyp==true) continue;
    u[a][b]=1;
    if (s[a][b]=='k') {e=a; ff=b; wyp=true;}
    if ((s[a][b]=='p' || s[a][b]=='.') && b+1<n && u[a][b+1]==0 && !wyp) {nju.a=a; nju.b=b+1; f[a][b+1].a=a; f[a][b+1].b=b; u[a][b+1]=1; S.push(nju);}
    if ((s[a][b]=='l' || s[a][b]=='.') && b-1>=0 && u[a][b-1]==0 && !wyp) {nju.a=a; nju.b=b-1; f[a][b-1].a=a; f[a][b-1].b=b; u[a][b-1]=1; S.push(nju);}
    if ((s[a][b]=='g' || s[a][b]=='.') && a+1<n && u[a+1][b]==0 && !wyp) {nju.a=a+1; nju.b=b; f[a+1][b].a=a; f[a+1][b].b=b; u[a+1][b]=1; S.push(nju);}
    if ((s[a][b]=='d' || s[a][b]=='.') && a-1>=0 && u[a-1][b]==0 && !wyp) {nju.a=a-1; nju.b=b; f[a-1][b].a=a; f[a-1][b].b=b; u[a-1][b]=1; S.push(nju);}
}
}

void doit()
{
m=0;
scanf("%d", &n); wyp=false;
for(int i=n-1; i>=0; i--) {
    scanf("%s", s[i]);
    for(int j=0; j<n; j++) {
	u[i][j]=0;
    }    
}
DFS();
int c,d;
c=e; d=ff;
while(c!=0 || d!=0) {
    m++;
    nju.a=d+1; nju.b=c+1;
    S2.push(nju);
    e=f[c][d].a; ff=f[c][d].b;
    c=e; d=ff;
}

printf("%d\n", m+1);
printf("1 1\n");
while(!S2.empty()) {printf("%d %d%c\n", S2.top().a, S2.top().b,13); S2.pop();}

}








int main()
{
scanf("%d", &z);
while(z--) doit();
return 0;
}
