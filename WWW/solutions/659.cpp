#include <iostream>

using namespace std;

int W[200][200], N[200][200], S[200][200], T[200], z, n, s;

void fatality()
{
    for (int l=1; l<n; l++)
    {
        for (int i=0; i+l<n; i++)
        {
            int j=i+l;
            int w=999999999;
            for (int k=i; k<j-1; k++)
            {
                if (w>W[i][k]+S[i][k]+W[k+1][j]+S[k+1][j])
                {
                    w=W[i][k]+S[i][k]+W[k+1][j]+S[k+1][j];
                    s=N[i][k]+N[k+1][j];
                }
                else if (w==W[i][k]+S[i][k]+W[k+1][j]+S[k+1][j])
                {
                    s=min(s, N[i][k]+N[k+1][j]);
                }
            }
            if (w>W[i][j-1]+S[i][j-1]+S[j][j])
            {
                W[i][j]=W[i][j-1]+S[i][j-1]+S[j][j];
                N[i][j]=N[i][j-1];
            }
            else if (w==W[i][j-1]+S[i][j-1]+S[j][j])
            {
                W[i][j]=w;
                N[i][j]=min(s+1, N[i][j-1]);
            }
            else
            {
                W[i][j]=w;
                N[i][j]=s+1;
            }
        }
    }
}

void pucupucu()
{
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            W[i][j]=N[i][j]=0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    scanf("%d", &z);//cin >> z;
    for (int i=0; i<z; i++)
    {
        scanf("%d", &n);//cin >> n;
        pucupucu();
        for (int i=0; i<n; i++)
            scanf("%d", &T[i]);//cin >> T[i];
        for (int i=0; i<n; i++)
        {
            S[i][i]=T[i];
            for (int j=i+1; j<n; j++)
                S[i][j]=S[i][j-1]+T[j];
        }
        fatality();
        /*for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
                cout << S[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
                cout << N[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
                cout << W[i][j] << " ";
            cout << endl;
        }
        cout << endl;*/
        printf("%d %d\n", W[0][n-1], N[0][n-1]);//cout << W[0][n-1] << " " << N[0][n-1] << endl;
    }
}
