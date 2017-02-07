#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int z, n, T[100001], sum;
	cin >> z;
	for(int i=0; i<z; i++)
	{
        sum=0;
        cin >> n;
        for(int i=1; i<=n; i++)
            cin >> T[i];
        sort(T+1, T+n+1);
        if(n==1) cout << T[1] << endl;
        else if(n==2) cout << T[2] << endl;
        else if(n==3) cout << T[1]+T[2]+T[3] << endl;
        else
        {
            int i;
            if(n%2) 
            {
                i=5;
                sum=T[1]+T[2]+T[3];
            }
            else 
            {
                i=4;
                sum=T[2];
            }
            while (i<=n)
            {
                sum+=min(2*T[1]+T[i-1]+T[i], 2*T[2]+T[1]+T[i]);
                i+=2;
            }
            cout << sum << endl;
        }  
    }
}
