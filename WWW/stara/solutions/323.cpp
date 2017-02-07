#include<cstdio>
#include<queue>
using namespace std;
queue<int> Q;
char t[1002][1002];
bool color[1002][1002];
int pre[1002][1002];
int dw[4]={0,-1,0,1};
int dk[4]={-1,0,1,0};
int md[4]={'p','d','l','g'};
void prep(int N){
    for(int i=1;i<=N;++i)
    for(int j=1;j<=N;++j)
        color[i][j]=1;
    for(int i=0;i<=N+1;++i)
        color[i][0]=color[0][i]=color[i][N+1]=color[N+1][i]=0;
}
int main()
{
    int C,N,x,y;
    scanf("%d", &C);
    while(C--){
        scanf("%d", &N);
        prep(N);
        for(int i=1;i<=N;i++)
            scanf("%s", t[i]);
        for(int i=1;i<=N;++i)
        for(int j=N;j>=1;--j)
            t[i][j]=t[i][j-1];
        for(int i=1;i<=N;++i)
        for(int j=1;j<=N;++j)
            if(t[i][j]=='k'){
                Q.push(i*(N+2)+j);
                pre[i][j]=i*(N+2)+j;
            }
        x=Q.front();
        color[x/(N+2)][x%(N+2)]=0;
        while(!Q.empty()){
            y=Q.front();
            Q.pop();
            x=y/(N+2);
            y=y-x*(N+2);
            for(int i=0;i<4;i++)
                if(color[x+dw[i]][y+dk[i]]&&(t[x+dw[i]][y+dk[i]]==md[i]||t[x+dw[i]][y+dk[i]]=='.')){
                    Q.push((x+dw[i])*(N+2)+y+dk[i]);
                    pre[x+dw[i]][y+dk[i]]=(N+2)*x+y;
                    color[x+dw[i]][y+dk[i]]=0;
                }
        }
        y=1;
        x=(N+1)*(N+1);
        while(pre[x/(N+2)][x%(N+2)]!=x){
            x=pre[x/(N+2)][x%(N+2)];
            ++y;
        }
        printf("%d\n", y);
        x=(N+1)*(N+1);
        while(pre[x/(N+2)][x%(N+2)]!=x){
            printf("%d %d\n", x%(N+2), N+1-x/(N+2));
            x=pre[x/(N+2)][x%(N+2)];
        }
        printf("%d %d\n", x%(N+2), N+1-x/(N+2));
    }
    return 0;
}
