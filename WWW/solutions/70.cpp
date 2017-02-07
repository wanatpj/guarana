#include <cstdio>
using namespace std;

class vector2
{
public:
	int x,y;
	vector2(){}
	vector2(int xx, int yy)
	{
		x=xx; 
		y=yy;
	}

};

class mini
{
private:
	char map[4][4];
	vector2 BlackKing;
	vector2 BlackWarrior[3];					
	vector2 WhiteKing;							//234
	vector2 WhiteWarrior[3];					//1K5
	bool attacked;
	void Read()
	{
		int tempX=0,tempY=0;
		int bi=0,wi=0;
		bool getEnter=false;
		
		for(int i=0;i<16;i++)
		{
			do{
			scanf("%c",&map[tempX][tempY]);
			}while (!( (map[tempX][tempY]>='a' && map[tempX][tempY]<='z') ||
				      (map[tempX][tempY]>='A' && map[tempX][tempY]<='Z') ||
					  (map[tempX][tempY]=='.')
					) ); 
			if(map[tempX][tempY]=='C')
				BlackKing = vector2(tempY,tempX);
			else if(map[tempX][tempY]=='c'){
				BlackWarrior[bi] = vector2(tempY,tempX); bi++;}
			else if(map[tempX][tempY]=='B')
				WhiteKing = vector2(tempY,tempX);
			else if(map[tempX][tempY]=='b'){
				WhiteWarrior[wi] = vector2(tempY,tempX); wi++;}
		
			if(tempY==3)
			{
				getEnter=true;
				tempY=-1;
				tempX++;
			}
			tempY++;
		}
	}
	void setBasicBlock()
	{
		for(int warriors=0;warriors<3;warriors++)
		{
			if (WhiteWarrior[warriors].x>100) continue;
				if( (WhiteWarrior[warriors].y-2==BlackKing.y) )
				{
					if ((WhiteWarrior[warriors].x-1==BlackKing.x) || (WhiteWarrior[warriors].x+1==BlackKing.x) )
					{
						if( map[ WhiteWarrior[warriors].y-1 ][ WhiteWarrior[warriors].x ] == '.' )
								Test(vector2(WhiteWarrior[warriors].x,WhiteWarrior[warriors].y-1),warriors);
					}

					if( (WhiteWarrior[warriors].x-2==BlackKing.x) &&
						( map[ WhiteWarrior[warriors].y-1 ][ WhiteWarrior[warriors].x-1 ] == 'c') 
					  )
						Test(vector2(WhiteWarrior[warriors].x-1,WhiteWarrior[warriors].y-1),warriors);
					if( (WhiteWarrior[warriors].x+2==BlackKing.x) &&
						( map[ WhiteWarrior[warriors].y-1 ][ WhiteWarrior[warriors].x+1 ] == 'c') 
					  )
						Test(vector2(WhiteWarrior[warriors].x+1,WhiteWarrior[warriors].y-1),warriors);
				}
				//----
		}
	}
	bool ProtectedWarrior(vector2 war,int num,bool black)
	{
		for(int ble=0;ble<3;ble++)
		{
			if(ble==num)
			{
				continue;
			}
			if(!black)
			{
				if( (WhiteKing.y-1==war.y) || 
					(WhiteKing.y==war.y) ||
					(WhiteKing.y+1==war.y))
				{
					if( (war.x+1==WhiteKing.x)||
						(war.x==WhiteKing.x)||
						(war.x-1==WhiteKing.x)
						)
						return true;
				}
				else
				if(WhiteWarrior[ble].y-1==war.y)
					if(WhiteWarrior[ble].x-1==war.x)
						return true;
					else if(WhiteWarrior[ble].x+1==war.x)
						return true;
			}
			if(black)
			{
				if(BlackKing.y+1==war.y)
				{
					if(war.x+1==BlackKing.x||
						war.x+1==BlackKing.x-1||
						war.x+1==BlackKing.x+1||
						war.x-1==BlackKing.x||
						war.x-1==BlackKing.x-1||
						war.x-1==BlackKing.x+1)
						return true;
				}
				else
				if(BlackWarrior[ble].y+1==BlackWarrior[num].y)
					if(BlackWarrior[ble].x-1==war.x)
						return true;
					else if(BlackWarrior[ble].x+1==war.x)
						return true;
					else return false;
			}
		}
		return false;
	}
	bool WarriorKillsWarrior(vector2 war)
	{
		for(int again=0;again<3;again++)
		{
			if(war.y-1==BlackWarrior[again].y)
			{
				if(war.x-1==BlackWarrior[again].x)
					return true;
				else if(war.x+1==BlackWarrior[again].x)
					return true;
			}
		}
		return false;
	}

	bool KingEscape(vector2 warrior, int warriors, int Nx,int Ny)
	{
		char old = map[ warrior.y ][ warrior.x ];
		map[ warrior.y ][ warrior.x ] = 'b';
		map[ WhiteWarrior[warriors].y ][ WhiteWarrior[warriors].x ] = '.';
		bool Out = true;

		for (int x=-1;x<=1;x++)
			for (int y=-1;y<=1;y++)
			{
				if (x==0 && y==0) continue;
				if (!(Nx+x>=0 &&
					Nx+x<4 &&
					Ny+y>=0 &&
					Ny+y<4))
						continue;
				if (map[Ny+y][Nx+x] == 'B')
					Out = false;
			}

		for (int ech=0;ech<3;ech++)
			if (WhiteWarrior[ech].y == Ny+1)
			{
				if (WhiteWarrior[ech].x == Nx+1)
					Out = false;
				if (WhiteWarrior[ech].x == Nx-1)
					Out = false;
			}

		map[ warrior.y ][ warrior.x ] = old;
		map[ WhiteWarrior[warriors].y ][ WhiteWarrior[warriors].x ] = 'b';
		return Out;
	}

	void Test(vector2 warrior, int warriors)
	{
		bool worked;
		if(ProtectedWarrior(warrior,warriors,false))
			if(!WarriorKillsWarrior(warrior))
			{
				bool PosEsc = false;
				for (int x=-1;x<=1;x++)
					for (int y=-1;y<=1;y++)
					{
						if (x==0 && y==0) continue;
						if (!(BlackKing.x+x>=0 &&
							BlackKing.x+x<4 &&
							BlackKing.y+y>=0 &&
							BlackKing.y+y<4))
							continue;
						int Nx = BlackKing.x+x;
						int Ny = BlackKing.y+y;

						if ( map[Ny][Nx] != 'c') 
						{
							if (KingEscape(warrior, warriors, Nx, Ny))
								PosEsc = true;
						}
					}
				if (!PosEsc)
					attacked = true;
			}
	}
	void Reset()
	{
			for(int bum=0;bum<3;bum++)
			{
				WhiteWarrior[bum]=vector2(6123980,517893);
				BlackWarrior[bum]=vector2(135785,51329563);
				WhiteKing=vector2(3561297,631289);
				BlackKing=vector2(15386123,613097);
			}
		attacked=false;
	}
public:
	mini(){}
	void Do()
	{
		Reset();
		Read();
		setBasicBlock();
		if(attacked==true)
			printf("TAK\n");
		else printf("NIE\n");
	}

};

mini mat;
int n;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	mat.Do();
	}
	return 0;
}
