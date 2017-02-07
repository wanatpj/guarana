#include <cstdio>
using namespace std;

class wyrazenia
{
private:
	char znak[15];
	int liczba[15];
	int suma;
	int max;
	void Read()
	{
		for(int i=0;i<15;i++)
		{
			scanf("%d%c",&liczba[i],&znak[i]);
			if(znak[i]=='\n')
			{
				max=i;
				break;
			}
		}
	}
	void Restart()
	{
		suma=0;
		for(int g=0;g<15;g++)
		{
			liczba[g]=0;
			znak[g]=0;
		}
	}
	void Sum()
	{
		if(max!=1)
		for(int i=0;i<=max;i++)
		{
			if(i==max)
			{
				suma+=liczba[i]+liczba[i+1];
			}
			else if(znak[i]=='+'&&znak[i+1]!='*')
			{
				suma+=liczba[i]+liczba[i+1];
				i++;
			}
			else if(znak[i]=='+'&&znak[i+1]=='*')
			{
				suma+=liczba[i];
				int temp=1;
				for(int u=i+1;u<max+1;u++)
				{
					if(znak[u]!='*')
					{
						temp=temp*liczba[u];
						i=u;
						break;
					}
					temp=temp*liczba[u];
				}
				suma+=temp;
			}
			else if(znak[i]=='*')
			{
				int temp=1;
				int u;
				for(u=i;u<max+1;u++)
				{
					if(znak[u]!='*')
					{
						temp=temp*liczba[u];
						i=u;
						break;
					}
					temp=temp*liczba[u];
				}
				i=u;
				suma+=temp;
			}
		}
		else
			if(znak[0]=='+')
				suma=liczba[0]+liczba[1];
			else suma = liczba[0]*liczba[1];
		printf("%d\n",suma);
	}
public:
	void Do()
	{
		Restart();
		Read();
		Sum();
	}


};
wyrazenia wyr;
int n;
int main()
{
	scanf("%d",&n);getchar();
	for(int i=0;i<n;i++)
	{
		wyr.Do();
	}




	return 0;
}
