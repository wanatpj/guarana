#include <iostream>
#include <cstdio>
using namespace std;

int main(){
int d; scanf("%d", &d);
while(d--){
    int n; scanf("%d", &n);
    int os = 0; for (int i=0; i<n; ++i){
        int x; scanf("%d", &x);
        os += x;
    }
    int c; scanf("%d", &c);
    printf("%d\n", ((os) ? (c%os) : (c)));
}
return 0;
}
