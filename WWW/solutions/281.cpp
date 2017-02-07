#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, z, c;
    cin >> z;
    for (int i=0; i<z; i++)
    {
        int suma=0;
        cin >> n;
        for (int i=0; i<n; i++)
        {
            int a;
            cin >> a;
            suma+=a;
        }
        cin >> c;
        if (suma) cout << c%suma << endl;
        else cout << c << endl;
    }
}
