#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char c[1000001];
int t[1000000];
int main()
{
    scanf("%s", &c);
    int lenc = strlen(c);
    t[0]=0;
    int mi=0,x=0,s;
    for(int i=1;i<lenc;i++){
        if(i==x+1) {++x; ++mi;}
        if(min(x-i,t[2*mi-i])==x-i){
            mi=i;
            while(x+1<lenc&&2*i-x-1>=0&&c[x+1]==c[2*i-x-1])
                ++x;
            t[i]=x-i;
        }
        else t[i]=t[2*mi-i];
    }
    for(int i=0;i<lenc;i++)
        printf("%d ", t[i]);
    return 0;
}
