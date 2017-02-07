#include<cstdio>
int main()
{
    int N,M;
    int K,O,D;
    scanf("%d%d", &N, &M);
    while(N--){
        scanf("%d%d%d", &K, &O, &D);
        if(M<K) printf("komin\n");
        else if(M<O) printf("okno\n");
        else if(M<D) printf("drzwi\n");
        else printf("brak\n");
    }
    return 0;
}
