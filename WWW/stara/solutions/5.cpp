#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct Point{
    int x,y,id;
    Point(){}
    Point(int x, int y, int id){
        this->x=x;
        this->y=y;
        this->id=id;
    }
};
bool operator==(Point A, Point B){
    return A.x==B.x&&A.y==B.y;
}
bool Cmp(Point A, Point B){
    if(A.x==B.x) return A.y<B.y;
    return A.x<B.x;
}
int power[18];
struct KMR{
    char c[200001];
    int tree[18][200001];
    int cnt;
    Point st[200000];
    int tlog;
    int len;
    void buildTree(){
        cnt=0;
        len = strlen(c);
        tlog=(int)floor(log2(len-1));
        for(int i=0;i<len;i++)
            tree[0][i]=c[i]-'a';
        cnt=26;
        for(int i=1;i<=tlog;i++){
            for(int j=0;j+power[i-1]<len;j++)
                st[j]=Point(tree[i-1][j],tree[i-1][j+power[i-1]],j);
            sort(st,st+len-power[i-1],Cmp);
            tree[i][st[0].id]=cnt;
            for(int j=1;j<len-power[i-1];j++)
                if(st[j]==st[j-1])
                    tree[i][st[j].id]=cnt;
                else tree[i][st[j].id]=++cnt;
            cnt++;
        }
    }
    bool check(int k){
        tlog=(int)floor(log2(k));
        for(int i=0;i+k<=len;i++)
            st[i]=Point(tree[tlog][i],tree[tlog][i+k-power[tlog]],0);
        sort(st,st+len+1-k,Cmp);
        for(int i=1;i+k<=len;i++)
            if(st[i]==st[i-1]) return true;
        return false;
    }
    int findMaxLength(){
        if(!check(1))
            return 0;
        int start=1,end=len-1,tmp;
        while(start+1<end){
            tmp=(start+end)/2;
            if(check(tmp))
                start=tmp;
            else end=tmp-1;
        }
        if(check(end)) return end;
        return start;
    }
};
int main()
{
    power[0]=1;
    for(int i=1;i<18;i++)
        power[i]=power[i-1]*2;
    KMR my;
    scanf("%s", my.c);
    my.buildTree();
    int x = my.findMaxLength();
    printf("%d", x);
    return 0;
}
