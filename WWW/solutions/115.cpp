#include <iostream>
using namespace std;

int main(){
int n, m; scanf("%d%d", &n, &m);
int d1[1100], d2[1100]; for (int i=0; i<1050; ++i) d1[i] = d2[i] = 0;

while(m--){
    int a, b, c, f1, f2;
    scanf("%d%d%d%d%d", &a, &b, &c, &f1, &f2);
    if ( f1 == 1 && f2 == 0 ) d1[c] ++;
    if ( f2 == 1 && f1 == 0 ) d2[c] ++;
}

bool tak = true;
int moves = 0;
for ( int i=0; i<1050; ++i ){
    if ( d1[i] != d2[i] ) {tak = false; break;}
    moves += d1[i];
}

if (tak){
    printf("%d\n", moves);
} else {
    printf("NIE\n"); // to nie powinno zajsc. jic
}

return 0;
}
