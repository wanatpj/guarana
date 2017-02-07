#include <iostream>
#include <stack>

using namespace std;

stack <int> S;
char T[1001][1001], G[1001][1001];;
bool V[1001][1001], yay;
int n,z;

void DFS(int a, int b)
{
    //cout << a << " " << b << endl;
    if (G[a][b]=='k')
    {
        yay=1;
        S.push(b);
        S.push(a);
    }
    if (V[a][b] || yay) return;
    V[a][b]=1;
    if (G[a][b]=='g' && b<n) DFS(a, b+1);
    else if (G[a][b]=='d' && b>1) DFS(a, b-1);
    else if (G[a][b]=='l' && a>1) DFS(a-1, b);
    else if (G[a][b]=='p' && a<n) DFS(a+1, b);
    else
    {
        if (b<n) DFS(a, b+1);
        if (b>1) DFS(a, b-1);
        if (a>1) DFS(a-1, b);
        if (a<n) DFS(a+1, b);
    }
    if (yay)
    {
        S.push(b); S.push(a);
    }
}

void pucupucu(int n)
{
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            V[i][j]=0;
    yay=0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> z;
    for (int i=0; i<z; i++)
    {
        cin >> n;
        pucupucu(n);
        for (int j=1; j<=n; j++)
            cin >> T[j];
        for (int i=n; i; i--)
            for (int j=1; j<=n; j++)
                G[j][i]=T[n-i+1][j-1];
        DFS(1,1);
        cout << S.size()/2 << endl;
        while(!S.empty())
        {
            cout << S.top() << " ";
            S.pop();
            cout << S.top() << endl;
            S.pop();
        }
    }
}
