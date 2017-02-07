#include <cstdio>
#include <algorithm>
#define MM  20000
#define MP  32000
#define MLP 32000
#define LLD long long int

using namespace std;

int In[MM];
int Pier[MLP];
bool CzyP[MP];
int Kwa[MP];
LLD CoP[MP];
int Back[MP];
int LP;

int main()
{
        int m; LLD M;
        scanf("%d%lld",&m,&M);

        int Max = 0;
        for (int i=0;i<m;i++)
        {
                scanf("%d",&In[i]);
                Max = max(In[i],Max);
        }

        int Prog = 1;

        for (int i=0;i*i<=Max;i++)
        {
                CzyP[i] = true;
                CoP[i] = 0;
                Prog = i;
        }

        CzyP[0] = CzyP[1] = false;
        LP = 0;

        for (int i=2;i<=Prog;i++)
        {
                if (CzyP[i])
                {
                        for (int j=i*i;j<=Prog;j+=i)
                                if (CoP[j] == 0)
                                {
                                        CzyP[j] = false;
                                        CoP[j] = 1;
                                        int t = j;
                                        while (t%i == 0)
                                        {
                                                t/=i;
                                                CoP[j]=CoP[j]*i+1;
                                        }
                                        Back[j] = t;
                                }
                        CoP[i] = i+1;
                        Back[i] = 1;
            Kwa[LP] = i*i;
                        Pier[LP++] = i;
                }
        }
        CoP[1] = 1;

        for (int i=2;i<=Prog;i++)
                CoP[i] = CoP[i] * CoP[ Back[i] ];

        for (int i=0;i<m;i++)
        {
                int n = In[i];
                int Temp,Tym;
                LLD Sum = 1;
        if (n<=Prog)
        {
            Sum*=CoP[n];
            n=1;
        }
        else
                for (int j=0;j<LP;++j)
                {
                        Temp = 1;
                        while ( n%Pier[j] == 0)
                        {
                                n/=Pier[j];
                                Temp = Pier[j]*Temp + 1;
                        }
            if (Temp>1)
             {
                            Sum *= Temp;
                            if (n<=Prog)
                            {
                                                Sum *= CoP[n];
                                                n = 1;
                                break;
                                        }
             }
                                if (Kwa[j]>n)
                                    break;
                }
                if (n!=1)
                        Sum *= (n+1);
                Sum%=M;
                printf("%lld\n",Sum);
        }

        return 0;
}

