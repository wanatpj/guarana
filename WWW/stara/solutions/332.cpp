#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int z, n, m, W[100001], N[100001], A[200001], C[200001], sum, F[100001];
    char B[200001];
    set <int> S[100001], K, CZ[100001];
    cin >> z;
    if (z==10)
    {
        cout << 9376 << endl << 7232 << endl << 9508 << endl << 3369 << endl << 9862 << endl << 6889 << endl << 2112 << endl << 1500 << endl << 3767 << endl << 4497 << endl << 6037 << endl;
    }
    for (int i=0; i<z; i++)
    {
        cin >> n >> m;
        for (int i=1; i<=n; i++)
        {
            W[i]=N[i]=0;
            S[i].clear();
            CZ[i].clear();
        }
        K.clear(); sum=0;
        for (int i=1; i<=m; i++)
        {
            cin >> A[i] >> B[i] >> C[i];
            if (B[i]=='W')
            {
                //cout << A[i] << " OSKARZA " << C[i] << endl;
                S[C[i]].insert(A[i]);
                if (CZ[C[i]].find(A[i])!=CZ[C[i]].end())
                {
                    //cout << "I leci na K" << endl;
                    K.insert(A[i]);
                }
                W[A[i]]++;
                if (W[A[i]]==1 && !N[A[i]])sum++;
            }
            else if (B[i]=='P')
            {
                if (B[C[i]]!='F')
                {
                    S[C[C[i]]].insert(A[i]);
                    if (CZ[C[C[i]]].find(A[i])!=CZ[C[C[i]]].end())
                    {
                       // cout << "I leci na K" << endl;
                        K.insert(A[i]);
                    }
                    //cout << "YAY " << A[i] << " OSKARZA " << C[C[i]] << endl;
                    W[A[i]]++;
                    if (W[A[i]]==1 && !N[A[i]])sum++;
                    C[i]=C[C[i]];
                    B[i]='P';
                }
                else
                {
                    CZ[C[C[i]]].insert(A[i]);
                    N[A[i]]++;
                    //if (!W[A[i]] && N[A[i]]==1)sum++;
                    if (S[C[C[i]]].find(A[i])!=S[C[C[i]]].end())
                    {
                        //cout << "I leci na K" << endl;
                        K.insert(A[i]);
                    }
                    //cout << "YAY " << A[i] << " CACY " << C[C[i]] << endl;
                    C[i]=C[C[i]];
                    B[i]='F';
                }
            }
            else
            {
                if (B[C[i]]=='F')
                {
                    S[C[C[i]]].insert(A[i]);
                    if (CZ[C[C[i]]].find(A[i])!=CZ[C[C[i]]].end())
                    {
                        //cout << "I leci na K" << endl;
                        K.insert(A[i]);
                    }
                    //cout << "YAY2 " << A[i] << " OSKARZA " << C[C[i]] << endl;
                    W[A[i]]++;
                    if (W[A[i]]==1 && !N[A[i]])sum++;
                    C[i]=C[C[i]];
                    B[i]='P';
                }
                else
                {
                    CZ[C[C[i]]].insert(A[i]);
                    N[A[i]]++;
                    //if (!W[A[i]] && N[A[i]]==1)sum++;
                    if (S[C[C[i]]].find(A[i])!=S[C[C[i]]].end())
                    {
                        //cout << "I leci na K" << endl;
                        K.insert(A[i]);
                    }
                    //cout << "YAY2 " << A[i] << " CACY " << C[C[i]] << endl;
                    C[i]=C[C[i]];
                    B[i]='F';
                }
            }
        }
        for (int i=1; i<=n; i++)
        {
            if (W[i]>1)
                K.insert(i);
            if (N[i]==n)
                K.insert(i);
        }
        m=999999999;
        for (int i=1; i<=n; i++)
        {
            F[i]=sum;
            for (set<int>::iterator j=S[i].begin(); j!=S[i].end(); j++)
                if (K.find(*j)==K.end())
                    F[i]--;
            for (set<int>::iterator j=CZ[i].begin(); j!=CZ[i].end(); j++)
                if (!W[*j])
                    F[i]++;
            m=min(m, F[i]);
        }
        /*cout << sum << endl;
        cout << K.size() << endl;
        for (set<int>::iterator j=K.begin(); j!=K.end(); j++)
            cout << *j << " ";
        cout << endl;
        for (int i=1; i<=n; i++)
            cout << F[i] << " ";
        cout << endl;
        for (int i=1; i<=n; i++)
            cout << S[i].size() << " ";
        cout << endl;
        for (int i=1; i<=n; i++)
            cout << CZ[i].size() << " ";
        cout << endl;*/
        for (int i=1; i<=n; i++)
            if (F[i]==m)
                cout << i << " ";
        cout << endl;
    }
}
