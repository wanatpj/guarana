#include <iostream>
#include <vector>
#define MAXD 20 //2^4
#define MAXS 4100 //2^12
#define MAXT 5000 //2^12
#define LL long long
using namespace std;

struct vertex { int x,y; } tmp, rig;
struct skarb { int x,y,w,t; };
struct dyn { int z; bool k; };

vector <vertex> D[MAXD];
skarb ska[MAXS];
dyn tt[MAXD][MAXT], wynikowy[MAXT], tempowy[MAXT];
int przy[MAXS];
int iloscs[MAXD], dochod[MAXD], czas[MAXD], sized[MAXD];
int z,d,s,T,res,zlicz,procent,akt,last;
bool end;

int det(vertex a, vertex b, vertex c)
{
    LL det=(LL)a.x*b.y+(LL)b.x*c.y+(LL)c.x*a.y-a.y*(LL)b.x-(LL)b.y*c.x-(LL)c.y*a.x;
    if(det>0) return 1;
    if(det<0) return -1;
    return 0;
}

bool przeciecie(vertex a1, vertex a2, int b1, int b2, int from)
{
    int ile=0;
    int det1=det(a1,a2,D[from][b1]);
    int det2=det(a1,a2,D[from][b2]);
    if(det1==0) ile++;
    if(ile==1&&det2==0) ile++;
    if(ile>0)
    {
        if(ile==1)
        {
            if(!((a1.x>D[from][b1].x&&a2.x<D[from][b1].x)||(a1.x<D[from][b1].x&&a2.x>D[from][b1].x))) return 0;
            det1=det(a1,a2,D[from][b1-1]);
            det2=det(a1,a2,D[from][b2]);
            if(det1+det2==0) return 1;
        }
        else if(ile==2)
        {
            if(!((a1.x>D[from][b1].x&&a2.x<D[from][b1].x)||(a1.x<D[from][b1].x&&a2.x>D[from][b1].x))) return 0;
            if(!((a1.x>D[from][b2].x&&a2.x<D[from][b2].x)||(a1.x<D[from][b2].x&&a2.x>D[from][b2].x))) return 0;
            det1=det(a1,a2,D[from][b1-1]);
            det2=det(a1,a2,D[from][b2+1]);
            if(det1+det2==0) return 1;
        }
    }
    else if(det1+det2==0)
    {
        det1=det(D[from][b1],D[from][b2],a1);
        det2=det(D[from][b1],D[from][b2],a2);
        if(det1+det2==0) return 1;
    }
    return 0;
}

bool wsp(vertex a, vertex b, vertex c)
{
    if(det(a,b,c)!=0) return 0;
    if(a.x<b.x&&b.x<c.x) return 1;
    if(a.x>b.x&&b.x>c.x) return 1;
    return 0;
}

int main()
{
    scanf("%d",&z);
    while(z--)
    {
        rig.x=0;
        scanf("%d %d",&d,&s);
        for(int i=0;i<s;i++) przy[i]=-1;
        for(int i=0;i<d;i++)
        {
            scanf("%d",&sized[i]);
            D[i].push_back(tmp);
            for(int j=1;j<=sized[i];j++)
            {
                scanf("%d %d",&tmp.x,&tmp.y);
                if(tmp.x>rig.x) rig.x=tmp.x;
                D[i].push_back(tmp);
            }
            D[i][0]=D[i][sized[i]];
            D[i].push_back(D[i][1]);
            D[i].push_back(D[i][2]);
        }
        for(int i=0;i<s;i++)
        {
            scanf("%d %d %d %d",&ska[i].x,&ska[i].y,&ska[i].t,&ska[i].w);
        }
        scanf("%d",&T);
        res=0;
        for(int i=0;i<s;i++) //przyporzadkuje sobie skarby do dzialek
        {
            rig.y=ska[i].y;
            rig.x++;
            end=0;
            for(int j=0;j<d;j++)
            {
                zlicz=0;
                if(end) break;
                for(int u=1;u<=sized[j];u++)
                {
                    if(ska[i].x==D[j][u].x&&ska[i].y==D[j][u].y) { przy[i]=j; end=1; break; } //sprawdzam na wierz
                    tmp.x=ska[i].x;
                    tmp.y=ska[i].y;
                    zlicz+=przeciecie(tmp,rig,u,u+1,j);
                }
                if(zlicz%2==1) { przy[i]=j; break; }
            }
        }
        /*for(int i=0;i<s;i++)
        {
            printf("Skarb numer: %d nalezy do: %d\n",i,przy[i]);
        }*/
        for(int i=0;i<d;i++) { iloscs[i]=0; czas[i]=0; dochod[i]=0; }
        for(int i=0;i<s;i++)
        {
                if(przy[i]==-1) continue;
                iloscs[przy[i]]++;
                dochod[przy[i]]+=ska[i].w;
                czas[przy[i]]+=ska[i].t;
        }
        for(int i=0;i<d;i++)
        {
            procent=iloscs[i]*dochod[i];
            if(procent%100==0)
            {
                dochod[i]+=procent/100;
            }
            else
            {
                dochod[i]+=(procent/100)+1;
            }
        }
        for(int i=0;i<d;i++)
            for(int j=0;j<=T;j++) tt[i][j].k=tt[i][j].z=0;
        for(int i=0;i<d;i++) tt[i][0].k=1;
        last=0;
        for(int i=0;i<s;i++) //licze zysk dla kazdej dzialki
        {
            if(przy[i]==-1) continue;
            akt=przy[i];
            for(int j=last;j>=0;j--)
            {
                if(tt[akt][j].k==1)
                {
                    if(j+ska[i].t>T) continue;
                    if(tt[akt][j+ska[i].t].k==0)
                    {
                        tt[akt][j+ska[i].t].k=1;
                        tt[akt][j+ska[i].t].z=ska[i].w+tt[akt][j].z;
                        if(j+ska[i].t>last) last=j+ska[i].t;
                    }
                    else
                    {
                        if(ska[i].w+tt[akt][j].z>tt[akt][j+ska[i].t].z)
                        {
                            tt[akt][j+ska[i].t].z=ska[i].w+tt[akt][j].z;
                            if(j+ska[i].t>last) last=j+ska[i].t;
                        }
                    }
                }
            }
        }
        for(int i=0;i<d;i++)
        {
            if(czas[i]<=T)
            {
                if(dochod[i]>tt[i][czas[i]].z)
                {
                    tt[i][czas[i]].z=dochod[i];
                    tt[i][czas[i]].k=1;
                }
            }
        }
        last=0;
        for(int i=0;i<=T;i++) wynikowy[i].z=wynikowy[i].k=0;
        wynikowy[0].k=1;
        for(int i=0;i<d;i++)
        {
            for(int j=0;j<=last;j++) tempowy[j]=wynikowy[j];
            for(int j=0;j<=T;j++)
            {
                if(tt[i][j].k==0) continue;
                for(int u=last;u>=0;u--)
                {
                    if(tempowy[u].k==1)
                    {
                        if(u+j>T) continue;
                        if(wynikowy[u+j].k==0)
                        {
                            wynikowy[u+j].k=1;
                            wynikowy[u+j].z=tempowy[u].z+tt[i][j].z;
                            if(last<u+j) last=u+j;
                        }
                        else
                        {
                            if(tempowy[u].z+tt[i][j].z>wynikowy[u+j].z)
                            {
                                wynikowy[u+j].z=tempowy[u].z+tt[i][j].z;
                                if(u+j>last) last=u+j;
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<s;i++)
        {
            if(przy[i]!=-1) continue;
            for(int j=last;j>=0;j--)
            {
                if(wynikowy[j].k==1)
                {
                    if(j+ska[i].t>T) continue;
                    if(wynikowy[j+ska[i].t].k==0)
                    {
                        wynikowy[j+ska[i].t].k=1;
                        wynikowy[j+ska[i].t].z=wynikowy[j].z+ska[i].w;
                        if(j+ska[i].t>last) last=j+ska[i].t;
                    }
                    else if(wynikowy[j].z+ska[i].w>wynikowy[j+ska[i].t].z)
                    {
                        wynikowy[j+ska[i].t].z=wynikowy[j].z+ska[i].w;
                        if(j+ska[i].t>last) last=j+ska[i].t;
                    }
                }
            }
        }
        /*for(int i=0;i<d;i++)
        {
            printf("%d. dochod:%d czas:%d ilosc:%d\n",i,dochod[i],czas[i],iloscs[i]);
        }*/
        for(int i=0;i<=T;i++) if(wynikowy[i].k==1&&res<wynikowy[i].z) res=wynikowy[i].z;
        printf("%d\n",res);
        for(int i=0;i<d;i++) D[i].clear();
    }
    return 0;
}
