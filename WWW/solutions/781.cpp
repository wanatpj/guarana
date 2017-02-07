#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int z, V, E, v;
    bool f;
    set <int> T;
    vector <int> K[100001];
    cin >> z;
    for (int i=0; i<z; i++)
    {
        int m=0, index;
        cin >> V;
        K[1].clear();
        for (int i=2; i<=V; i++)
        {
            K[i].clear();
            f=1;
            cin >> E;
            for (int j=0; j<E; j++)
            {
                cin >> v;
                T.insert(v);
            }
            for (set<int>::iterator j=T.begin(); j!=T.end(); j++)
            {
                if (K[*j].size()==0)
                    K[*j].push_back(i);
                else
                {
                    for (int k=0; k<K[*j].size(); k++)
                        if (T.find(K[*j][k])==T.end())
                            f=0;
                    if (f)
                        K[*j].push_back(i);
                }
                if (K[*j].size()>m)
                {
                    m=K[*j].size();
                    index=*j;
                }
                else if (K[*j].size()==m)
                    index=min(*j, index);
            }
            T.clear();
        }
        /*for (int i=1; i<=V; i++)
        {
            cout << K[i].size() << endl;
            for (int j=0; j<K[i].size(); j++)
                cout << K[i][j] << " ";
            cout << endl << endl;
        }*/
        cout << m+1 << endl << index << " ";
        for (int i=0; i<m; i++)
            cout << K[index][i] << " ";
        cout << endl;
    }
}
