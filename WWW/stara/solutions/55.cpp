#include<cstdio>
#include<cstring>
using namespace std;
char c[40];
int main()
{
    int t,len;
    long long res,tr;
    scanf("%d", &t);
    while(t--){
        scanf("%s", c);
        len = strlen(c);
        res=0;
        tr=1;
        for(int i=0;i<len;i+=2){
            tr*=c[i]-'0';
            if(i+1==len||c[i+1]=='+'){
                res+=tr;
                tr=1;
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}
