#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int z, V, E, T[100001];
    set <int> S[100001], D[100001];
    cin >> z;
    for (int i=0; i<z; i++)
    {
        cin >> V;
        for (int i=2; i<=V; i++)
        {
            cin >> E;
            for (int j=0; j<E; j++)
            {
                int v;
                cin >> v;
                S[v].insert(i);
                S[i].insert(v);
            }
        }
        for (int i=1; i<=V; i++)
            D[i].insert(i);
        int i=1, j, Z=V;
        while (Z>1)
        {
           // for (int l=1; l<=V; l++)
           //     if (!D[l].empty())
           //     {
           //         cout << "| ";
           //         for (set <int>::iterator k=D[l].begin(); k!=D[l].end(); k++)
           //             cout << *k << " ";
           //         cout << "| ";
           //     }
           // cout << endl;
            j=i+1;
            while (D[j].empty()) j=j%V+1;
            //cout << i << " " << j << endl;
            bool f=1;
            for (set <int>::iterator k=D[j].begin(); k!=D[j].end(); k++)
                if (S[i].find(*k)==S[i].end())
                    f=0;
            if (f)
            {
                //cout << "CZYSZCZE " << j << endl;
                for (set <int>::iterator k=S[j].begin(); k!=S[j].end(); k++)
                    if (S[i].find(*k)==S[i].end())
                        S[i].erase(*k);
                for (set <int>::iterator k=S[i].begin(); k!=S[i].end(); k++)
                    if (S[j].find(*k)==S[j].end())
                        S[i].erase(*k);
                for (set <int>::iterator k=D[j].begin(); k!=D[j].end(); k++)
                    D[i].insert(*k);
                D[j].clear();
            }
            else
            {
                //cout << "I TAK CZYSZCZE " << j << endl;
                if (D[i].size()>=D[j].size())
                    D[j].clear();
                else
                {
                    D[i].clear();
                    for (set <int>::iterator k=D[j].begin(); k!=D[j].end(); k++)
                        D[i].insert(*k);
                    D[j].clear();
                }
            }
            Z--; i++;
            while (D[i].empty()) i=i%V+1;
        }
        //cout << endl << "/////////////////////////////" << endl;
        cout << D[1].size() << endl;
        for (set <int>::iterator k=D[i].begin(); k!=D[i].end(); k++)
            cout << *k << " ";
        cout << endl;
        D[1].clear();
        //cout << endl << "/////////////////////////////" << endl;
    }
}
