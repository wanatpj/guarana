#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
    {
        int k, o, d;
        cin >> k >> o >> d;
        if (m<k)
            cout << "komin" << endl;
        else if (m<o)
            cout << "okno" << endl;
        else if (m<d) 
            cout << "drzwi" << endl;
        else cout << "brak" << endl;
    }
}
