#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef pair<int, int> PII;

char P[5][5];
char M[5][5];
char Z[5][5];

bool inbounds(int x, int y){
    if ( x < 0 || y < 0 ) return 0;
    if ( x > 3 || y > 3 ) return 0;
return 1;
}

int movex[] = {0, 1, 1, 1,  0, 0,  -1, -1, -1};
int movey[] = {0, -1, 0, 1, -1, 1, -1, 0,   1};

bool krol_szachowany(){
    for ( int x=0; x<4; ++x )
        for ( int y=0; y<4; ++y ){
            if ( Z[x][y] == 'C' ){
                if ( inbounds(x+1, y+1) && ( Z[x+1][y+1] == 'b' ) ) return true;
                if ( inbounds(x+1, y-1) && ( Z[x+1][y-1] == 'b' ) ) return true;

                for (int i=0; i<9; ++i) if ( inbounds( x+movex[i], y+movey[i] ) )
                    if ( Z[ x+movex[i] ][ y+movey[i] ] == 'B'  ) return true;

                return false;
            }
        }
}

bool mat(){

    for (int x=0; x<4; ++x) for (int y=0; y<4; ++y) {

        if (  M[x][y] == 'C'  ){

//              cout << "czarny krol " << x << ' ' << y << endl;

                for (int i=0; i<9; ++i) if ( inbounds( x+movex[i], y+movey[i] ) )
                    if ( M[ x+movex[i] ][ y+movey[i] ] != 'c'  ){
                        for (int xx=0; xx<4; ++xx) for (int yy=0; yy<4; ++yy) Z[xx][yy] = M[xx][yy];

                        Z[x][y] = '.';
                        Z[ x+movex[i] ][ y+movey[i] ] = 'C'; // kolejnosc tych linijek jest istotna, jak nie ruszamy krola

                        if ( ! krol_szachowany() ) return false;
                    }
        }
        else if ( M[x][y] == 'c' ) {

//      cout << "czarny pion " << x << ' ' << y << endl;

        // bicie w lewo ( x+1, y-1 )
            if ( inbounds( x+1, y-1 ) && ( M[x+1][y-1] == 'b' ) ){

//              cout << "bije w lewo" << endl;

                for (int xx=0; xx<4; ++xx) for (int yy=0; yy<4; ++yy) Z[xx][yy] = M[xx][yy];
                Z[x][y] = '.'; Z[x+1][y-1] = 'c';
                if ( ! krol_szachowany() ) return false;
            }



            // bicie w prawo ( x+1, y+1 )
            if ( inbounds( x+1, y+1 ) && ( M[x+1][y+1] == 'b' ) ){

//              cout << "bicie w prawo" << endl;

                for (int xx=0; xx<4; ++xx) for (int yy=0; yy<4; ++yy) Z[xx][yy] = M[xx][yy];
                Z[x][y] = '.'; Z[x+1][y+1] = 'c';
                if ( ! krol_szachowany() ) return false;
            }



            // ruch (x+1, y)
            if ( inbounds( x+1, y ) && M[x+1][y] == '.' ){

//              cout << "ruch" << endl;

                for (int xx=0; xx<4; ++xx) for (int yy=0; yy<4; ++yy) Z[xx][yy] = M[xx][yy];
                Z[x][y] = '.'; Z[x+1][y] = 'c';
                if ( ! krol_szachowany() ) return false;
            }
        }
    }

return true;
}

bool ruch_b(int x, int y){
    // bicie w lewo ( x-1, y-1 )
    if ( inbounds( x-1, y-1 ) && ( P[x-1][y-1] == 'c' ) ){
        for (int xx=0; xx<4; ++xx) for (int yy=0; yy<4; ++yy) M[xx][yy] = P[xx][yy];

//      cout << "bije w lewo" << endl;

        M[x][y] = '.'; M[x-1][y-1] = 'b';
        if ( mat() ) return true;
    }


    // bicie w prawo ( x-1, y+1 )
    if ( inbounds( x-1, y+1 ) && ( P[x-1][y+1] == 'c' ) ){
        for (int xx=0; xx<4; ++xx) for (int yy=0; yy<4; ++yy) M[xx][yy] = P[xx][yy];

//      cout << "bicie w prawo" << endl;

        M[x][y] = '.'; M[x-1][y+1] = 'b';
        if ( mat() ) return true;
    }


    // ruch (x-1, y)
    if ( inbounds( x-1, y ) && P[x-1][y] == '.' ){
        for (int xx=0; xx<4; ++xx) for (int yy=0; yy<4; ++yy) M[xx][yy] = P[xx][yy];

//      cout << "ruch" << endl;

        M[x][y] = '.'; M[x-1][y] = 'b';
        if ( mat() ) return true;
    }

//cout << "nic nie daje" << endl;

return false;
}

bool solve(){
    for ( int i=0; i<4; ++i ) for ( int j=0; j<4; ++j ){
        if ( P[i][j] == 'b' ) {
//          cout << "ruch bialego z " << i << ' ' << j << endl;
            if ( ruch_b( i, j ) ) return true;
        }
    }
return false;
}

int main(){
int d; scanf("%d", &d);
while(d--){
    for (int i=0; i<4; ++i){
        scanf("%s", P[i]);
    }
//    cout << "wczytalem" << endl;

    if ( solve() )
        printf("TAK\n");
    else
        printf("NIE\n");
}
return 0;
}
