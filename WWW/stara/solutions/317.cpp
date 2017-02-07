#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 10010

int p[MAXN];

int oskarzony[2*MAXN];
bool oskarzenie[2*MAXN];

char buf[5];

int main(){
int d; scanf("%d", &d);
while(d--){
        int n, z; scanf("%d%d", &n, &z);
        vector<int> oskarza[MAXN];
        vector<int> uniewinnia[MAXN];
//      cout << "run" << endl;
        for (int i=0; i<=n; ++i) p[i] = 0;

        for (int i=1; i<=z; ++i){
                int a, b; scanf("%d %s %d", &a, buf, &b);
        //      if (a > z || a <=0 || b <=0 || b > z) cout << "GG" << endl;
                if ( buf[0] == 'W' || buf[0] == 'w'){

                        oskarzenie[i] = true;
                        oskarzony[i] = b;
                        oskarza[a].push_back(b);
                } else if ( buf[0] == 'P' || buf[0] == 'p' ) {
        //      if ( b >= i ) cout << "NNNN" << endl;

                        if ( oskarzenie[b] ){
                                oskarzenie[i] = true;
                                oskarzony[i] = oskarzony[b];
                                oskarza[a].push_back( oskarzony[i] );
                        } else {
                                oskarzenie[i] = false;
                                oskarzony[i] = oskarzony[b];
                                uniewinnia[a].push_back( oskarzony[i] );
                        }
                } else if ( buf[0] == 'F' || buf[0] == 'f') {
        //      if ( b >= i ) cout << "NNN" << endl;
                        if ( oskarzenie[b] ){
                                oskarzenie[i] = false;
                                oskarzony[i] = oskarzony[b];
                                uniewinnia[a].push_back( oskarzony[i] );
                        } else {
                                oskarzenie[i] = true;
                                oskarzony[i] = oskarzony[b];
                                oskarza[a].push_back( oskarzony[i] );
                        }
                }
        }

//      cout << "wczytano" << endl;

        for ( int i=1; i<=n; ++i ){
                //cout << i << " oskarza :"; for ( vector<int>::iterator j=oskarza[i].begin(); j!=oskarza[i].end(); ++j ) cout << *j << ' '; cout << endl;
                //cout << i << " uniewinnia :"; for ( vector<int>::iterator j=uniewinnia[i].begin(); j!=uniewinnia[i].end(); ++j ) cout << *j << ' '; cout << endl;

                sort( oskarza[i].begin(), oskarza[i].end() );
                sort( uniewinnia[i].begin(), uniewinnia[i].end() );

                if ( oskarza[i].empty() && uniewinnia[i].empty() ) continue;

                oskarza[i].resize( unique(oskarza[i].begin(), oskarza[i].end()) - oskarza[i].begin() );
                uniewinnia[i].resize( unique(uniewinnia[i].begin(), uniewinnia[i].end()) - uniewinnia[i].begin() );

                if ( oskarza[i].size() > 1 ){
                        oskarza[i].clear();
                        uniewinnia[i].clear();
                        continue;
                }

                if (oskarza[i].empty()) continue;

                for ( vector<int>::iterator j=uniewinnia[i].begin(); j!=uniewinnia[i].end(); ++j ) if (*j == oskarza[i][0]) {
                        oskarza[i].clear();
                        uniewinnia[i].clear();
                        break;
                };

        uniewinnia[i].clear();

        }
        /*
        cout << "------------------------\n po upie:" << endl;

        for ( int i=1; i<=n; ++i ){
                cout << i << " oskarza :"; for ( vector<int>::iterator j=oskarza[i].begin(); j!=oskarza[i].end(); ++j ) cout << *j << ' '; cout << endl;
                cout << i << " uniewinnia :"; for ( vector<int>::iterator j=uniewinnia[i].begin(); j!=uniewinnia[i].end(); ++j ) cout << *j << ' '; cout << endl;
                }
        */
        // tylko uniewinnia == oskarza 0
        // uniewinnia i oskarza x == oskarza x
        // oskarza kilku == wywalamy
        // oskarza jednego == oskarza jednego

        vector<int>ans; int best= -1;

        for ( int i=1; i<=n; ++i ){

                if ( ! oskarza[i].empty() ){
                        p[ oskarza[i][0] ]++;
                }

                for ( vector<int>::iterator j=uniewinnia[i].begin(); j!=uniewinnia[i].end(); ++j ) p[*j]--;

        }

        for ( int i=1; i<=n; ++i ){

                if ( p[i] > best ) {
                        best = p[i];
                        ans.clear();
                }
                if ( p[i] == best ) ans.push_back( i );

        }

        //printf("%d\n", ans.size());
        for ( vector<int>::iterator i=ans.begin(); i!=ans.end(); ++i ) printf("%d ", *i);
        printf("\n");
}

return 0;
}

