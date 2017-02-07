#include<cstdio>
int NWD(int a, int b){
    int c;
    while(b!=0){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
    int n,p,q,d,a,b;
    scanf("%d", &n);
    while(n--){
        scanf("%d%d", &p, &q);
        d=NWD(p,q);
        p/=d;
        q/=d;
        if(p>q){
            a=2*p-q+1;
            b=q-1;
        }
        else{
            a=1+p;
            b=2*q-1-p;
        }
        d=NWD(a,b);
        a/=d;
        b/=d;
        printf("%d %d\n", a, b);
    }
    return 0;
}
