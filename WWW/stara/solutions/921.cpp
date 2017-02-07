#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int z, n, x, sum, sum2;
    multiset <int> L, P;
    cin >> z;
    for (int i=0; i<z; i++)
    {
        sum=sum2=0;
        cin >> n;
        for (int i=0; i<n; i++)
        {
            cin >> x;
            P.insert(x);
        }
        L.insert(*P.begin());
        if (P.size()>2) sum2+=(P.size()-3)*(*P.begin());
        else sum2=999999999;
        for (multiset <int>::iterator j=P.begin(); j!=P.end(); j++)
            sum2+=*j;
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
        cout << min(sum, sum2) << endl;
        L.clear(); P.clear();
    }
}
