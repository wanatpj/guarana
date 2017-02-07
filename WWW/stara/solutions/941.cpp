#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int z, n, x, sum, sum2, state;
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
        sum=*P.begin();
        P.erase(P.begin());
        if (!P.empty())
        {
            L.insert(*P.begin());
            sum=*P.begin();
            P.erase(P.begin());
        }
        state=0;
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
            if (P.size()==2)
            {
                multiset <int>::iterator it=P.end();
                it--;
                sum+=*it;
                break;
            }
            else if (P.size()==3)
            {
                multiset <int>::iterator dos=P.begin(), tres=P.begin();
                dos++; tres++; tres++;
                if (*dos+min(*L.begin(), *P.begin())+*tres<=*tres+min(*L.begin(), *dos)+max(*P.begin(), min(*L.begin(), *dos)))
                    sum+=*dos+min(*L.begin(), *P.begin())+*tres;
                else sum+=*tres+min(*L.begin(), *dos)+max(*P.begin(), min(*L.begin(), *dos));
                break;
            }
            /*cout << "LEWY" << endl;
            for (multiset <int>::iterator j=L.begin(); j!=L.end(); j++)
                cout << *j << " ";
            cout << endl;
            cout << "PRAWY" << endl;
            for (multiset <int>::iterator j=P.begin(); j!=P.end(); j++)
                cout << *j << " ";
            cout << endl;*/
            multiset <int>::iterator dos=P.begin();
            dos++;
            if (!state)
            {
                dos=P.end();
                dos--;
                sum+=*dos;
                L.insert(*dos);
                P.erase(dos);
                dos=P.end();
                dos--;
                L.insert(*dos);
                P.erase(dos);
                state=1;
            }
            else
            {
                dos=P.begin();
                dos++;
                sum+=*dos;
                L.insert(*dos);
                P.erase(dos);
                dos=P.begin();
                L.insert(*dos);
                P.erase(dos);
                state=0;
            }
        }
        cout << sum << endl;
        L.clear(); P.clear();
    }
}
