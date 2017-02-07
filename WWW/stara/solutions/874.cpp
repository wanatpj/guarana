//Algorytm O(n^3) na podstawie niebieskiej ksiazeczki z XI OI - zadanie Kaglony
#include <iostream>
#include <vector>
#include <queue>
#define MAX 2000
using namespace std;

int z,n,k,a;
vector <short int> V[MAX];
vector <short int> VD[MAX];
vector <short int> wynikowy;
queue <short int> Q;
bool m[MAX];

vector <short int> fun(vector <bool> graf)
{
    int wie=0;
    for(int i=0;i<n;i++) if(graf[i]) wie++;
    if(wie==1)
    {
        vector <short int> res;
        for(int i=0;i<n;i++) if(graf[i]) res.push_back(i);
        return res;
    }
    //licze spojne skladowe
    vector <short int> tmp, res;
    vector <bool> graph(n);
    int color[MAX];
    for(int i=0;i<n;i++) color[i]=0;
    int now=1;
    for(int i=0;i<n;i++)
    {
        if(graf[i]==1&&color[i]==0)
        {
            color[i]=now;
            Q.push(i);
            while(!Q.empty())
            {
                a=Q.front();
                Q.pop();
                for(vector<short int>::iterator it=V[a].begin();it!=V[a].end();it++)
                {
                    if(color[*it]==0&&graf[*it]==1)
                    {
                        color[*it]=now;
                        Q.push(*it);
                    }
                }
            }
            now++;
        }
    }
    if(now>2)
    {
        int maxi=0;
        for(int i=1;i<now;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(color[j]==i) graph[j]=1;
                else graph[j]=0;
            }
            tmp=fun(graph);
            if(tmp.size()>maxi)
            {
                maxi=tmp.size();
                res=tmp;
            }
        }
        return res;
    }
    else
    {
        //licze silnie spojne na dopelnieniu grafu
        for(int i=0;i<n;i++) color[i]=0;
        now=1;
        for(int i=0;i<n;i++)
        {
            if(graf[i]==1&&color[i]==0)
            {
                color[i]=now;
                Q.push(i);
                while(!Q.empty())
                {
                    a=Q.front();
                    Q.pop();
                    for(vector<short int>::iterator it=VD[a].begin();it!=VD[a].end();it++)
                    {
                        if(color[*it]==0&&graf[*it]==1)
                        {
                            color[*it]=now;
                            Q.push(*it);
                        }
                    }
                }
                now++;
            }
        }
        for(int i=1;i<now;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(color[j]==i) graph[j]=1;
                else graph[j]=0;
            }
            tmp=fun(graph);
            int ss=tmp.size();
            for(int i=0;i<ss;i++) res.push_back(tmp[i]);
        }
        return res;
    }
}

int main()
{
    scanf("%d",&z);
    while(z--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++) { V[i].clear(); VD[i].clear(); }
        for(int i=1;i<n;i++)
        {
            scanf("%d",&k);
            for(int j=0;j<k;j++)
            {
                scanf("%d",&a);
                a--;
                V[a].push_back(i);
                V[i].push_back(a);
            }
        }
        //tworze dopelnienie grafu
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++) m[j]=0;
            for(vector<short int>::iterator it=V[i].begin();it!=V[i].end();it++) m[*it]=1;
            for(int j=i+1;j<n;j++)
            {
                if(m[j]==0)
                {
                    VD[i].push_back(j);
                    VD[j].push_back(i);
                }
            }
        }
        vector <bool> graf(n,1);
        wynikowy.clear();
        wynikowy=fun(graf);
        sort(wynikowy.begin(),wynikowy.end());
        printf("%d\n",wynikowy.size());
        for(vector<short int>::iterator it=wynikowy.begin();it!=wynikowy.end();it++)
        {
            printf("%hd ",*it+1);
        }
        printf("\n");
    }
    return 0;
}
