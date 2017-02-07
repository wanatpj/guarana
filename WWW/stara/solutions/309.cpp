
#include <cstdio>
#include <vector>

using namespace std;

#define MP make_pair

const int RM = 1009;
char tab[RM][RM];
bool flag[RM][RM];
pair<int, int> skad[RM][RM];
vector< pair<int, int> > Wynik;
int N;
bool found;

void DFS(int x, int y)
{

//	printf("teraz jestem w msc %d %d \n", x, y);
//	if(tab[x][y]=='.') printf("KROPA\n");

	while(!Wynik.empty() && Wynik.back()!=skad[x][y])
		Wynik.pop_back();
	Wynik.push_back(MP(x,y));
	flag[x][y]=true;
	if(!found && tab[x][y] == 'k') // znalezlismy sciezke, hurra :)
	{
		found = true;
		return;
	}
	if(!found && (tab[x][y] == '.' || tab[x][y] == 'p') && x+1 < N && flag[x+1][y]==false)
	{	
		skad[x+1][y] = MP(x,y);
		DFS(x+1, y); 
	}
	if(!found && (tab[x][y] == '.' || tab[x][y] == 'l') && x-1 >= 0 && flag[x-1][y]==false)
	{	
		skad[x-1][y] = MP(x,y);
		DFS(x-1, y); 
	}
	if(!found && (tab[x][y] == '.' || tab[x][y] == 'g') && y-1 >= 0 && flag[x][y-1]==false)
	{	
		skad[x][y-1] = MP(x,y);
		DFS(x, y-1); 
	}
	if(!found && (tab[x][y] == '.' || tab[x][y] == 'd') && y+1 < N && flag[x][y+1]==false)
	{	
		skad[x][y+1] = MP(x,y);
		DFS(x, y+1); 
	}
	return;
}

int main()
{
	int zw;
	scanf("%d", &zw);
	while(zw--)
	{
		scanf("%d", &N);
		char C;
		for(int j=0; j<N; j++)
			for(int i=0; i<N; i++)
			{	
				C = getchar();
				while(C!='p' && C!='g' && C!='l' && C!='d' && C!='.' && C!='k')
					C = getchar();
				tab[i][j] = C;	
				flag[i][j] = false;
			}
			Wynik.clear();
			found = false;
			skad[0][N-1] = MP(0, N-1);		
			DFS(0, N-1);
			int s = Wynik.size();
			printf("%d\n", s);
			for(int i=0; i<s; i++)
				printf("%d %d\n", Wynik[i].first+1, N - Wynik[i].second);
	}
	return 0;
}