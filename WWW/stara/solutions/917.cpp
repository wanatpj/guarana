#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int z, n, x, sum;
    multiset <int> L, P;
    cin >> z;
    for (int i=0; i<z; i++)
    {
        sum=0;
        cin >> n;
        for (int i=0; i<n; i++)
        {
            cin >> x;
            P.insert(x);
        }
        L.insert(*P.begin());
        sum+=*P.begin();
        P.erase(P.begin());
        if (!P.empty())
        {
            L.insert(*P.begin());
            sum=*P.begin();
            P.erase(P.begin());
        }
        while (!P.empty())
        {
            /*cout << "LEWY" << endl;
            for (multiset <int>::iterator j=L.begin(); j!=L.end(); j++)
                cout << *j << " ";
            cout << endl;
            cout << "PRAWY" << endl;
            for (multiset <int>::iterator j=P.begin(); j!=P.end(); j++)
                cout << *j << " ";
            cout << endl;*/
            P.insert(*L.begin());
            sum+=*L.begin();
            L.erase(L.begin());
            /*cout << "LEWY" << endl;
            for (multiset <int>::iterator j=L.begin(); j!=L.end(); j++)
                cout << *j << " ";
            cout << endl;
            cout << "PRAWY" << endl;
            for (multiset <int>::iterator j=P.begin(); j!=P.end(); j++)
                cout << *j << " ";
            cout << endl;*/
            multiset <int>::iterator lol=P.begin(), lal=P.end();
            lol++; lal--;
            if (*lol<*L.begin())
            {
                L.insert(*P.begin());
                int T=*P.begin();
                P.erase(P.begin());
                L.insert(*P.begin());
                sum+=max(*P.begin(), T);
                P.erase(P.begin());
            }
            else
            {
                L.insert(*lal);
                int T=*lal;
                P.erase(lal);
                lal=P.end();
                lal--;
                L.insert(*lal);
                sum+=max(T,*lal);
                P.erase(lal);
            }
        }
        cout << sum << endl;
        L.clear(); P.clear();
    }
}
