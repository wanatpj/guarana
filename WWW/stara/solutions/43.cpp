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
	bool Block[8];								//076
	bool attacked;
	void Read()
	{
		int tempX=0,tempY=0;
		int bi,wi;
		bool getEnter=false;
		
		for(int i=0;i<19;i++)
		{
			if(getEnter)
			{
				getchar();
				getEnter=!getEnter;
				continue;
			}
			else
			scanf("%c",&map[tempX][tempY]);
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
		if(BlackKing.x-1==-1)
		{
			/*Block[0]=vector2(BlackKing.x-1,BlackKing.y+1);
			Block[1]=vector2(BlackKing.x-1,BlackKing.y);
			Block[2]=vector2(BlackKing.x-1,BlackKing.y-1);*/
			Block[0]=true;
			Block[1]=true;
			Block[2]=true;
		}
		if(BlackKing.y-1==-1)
		{
			/*Block[2]=vector2(BlackKing.x-1,BlackKing.y-1);
			Block[3]=vector2(BlackKing.x,BlackKing.y-1);
			Block[4]=vector2(BlackKing.x+1,BlackKing.y-1);*/
			Block[2]=true;
			Block[3]=true;
			Block[4]=true;
		}
		if(BlackKing.x+1==4)
		{
			/*Block[4]=vector2(BlackKing.x+1,BlackKing.y-1);
			Block[5]=vector2(BlackKing.x+1,BlackKing.y);
			Block[6]=vector2(BlackKing.x+1,BlackKing.y+1);*/
			Block[4]=true;
			Block[5]=true;
			Block[6]=true;
		}
		if(BlackKing.y+1==4)
		{
			/*Block[6]=vector2(BlackKing.x+1,BlackKing.y+1);
			Block[7]=vector2(BlackKing.x,BlackKing.y+1);
			Block[8]=vector2(BlackKing.x-1,BlackKing.y+1);*/
			Block[0]=true;
			Block[6]=true;
			Block[7]=true;
		}
		for(int warriors=0;warriors<3;warriors++)
		{
			bool worked;
			if(ProtectedWarrior(WhiteWarrior[warriors],warriors,false))
				if(WhiteWarrior[warriors].y-1==BlackKing.y)
				{
					if(WhiteWarrior[warriors].x+1==BlackKing.x)
					{
						for(int sWarriors=0;sWarriors<3;sWarriors++)
						{
							if(BlackWarrior[sWarriors].y+1==WhiteWarrior[warriors].y)
							{
								if(BlackWarrior[sWarriors].x-1==WhiteWarrior[warriors].x){worked=true;break;}
								else if(BlackWarrior[sWarriors].x+1==WhiteWarrior[warriors].x){worked=true;break;}
								else {attacked=true; worked=true; break;}
							}
							else worked=false;
						}
						if(!worked)
							attacked=true;
					}
					else if(WhiteWarrior[warriors].x-1==BlackKing.x)
					{
						for(int sWarriors=0;sWarriors<3;sWarriors++)
						{
							if(BlackWarrior[sWarriors].y+1==WhiteWarrior[warriors].y)
							{
								if(BlackWarrior[sWarriors].x-1==WhiteWarrior[warriors].x){worked=true;break;}
								else if(BlackWarrior[sWarriors].x+1==WhiteWarrior[warriors].x){worked=true;break;}
								else attacked=true;
							}
								else {attacked=true; worked=true; break;}
						}
						if(!worked)
							attacked=true;
					}
				}
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
				if(WhiteKing.y-1==war.y)
				{
					if(war.x+1==WhiteKing.x||
						war.x+1==WhiteKing.x-1||
						war.x+1==WhiteKing.x+1||
						war.x-1==WhiteKing.x||
						war.x-1==WhiteKing.x-1||
						war.x-1==WhiteKing.x+1)
						return true;
				}
				else
				if(WhiteWarrior[ble].y-1==war.y)
					if(WhiteWarrior[ble].x-1==war.x)
						return true;
					else if(WhiteWarrior[ble].x+1==war.x)
						return true;
					else return false;
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
	void Test()
	{
		for(int i=0;i<3;i++)
		{
			if(WhiteWarrior[i].y-1==BlackKing.y)
			{
				if(WhiteWarrior[i].x+1==BlackKing.x)
				{
					if(Block[3]==true)
						printf("TAK");

				}
			}
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

	}
public:
	mini(){}
	void Do()
	{
		Reset();
		Read();
		setBasicBlock();

	}

};

mini mat;
int main()
{
	mat.Do();
	return 0;
}

					/*if(BlackKing.y-1==BlackWarrior[warriors].y)
					{
						for(int sWarriors=0;sWarriors<3;sWarriors++)
						{
							if(BlackWarrior[warriors].y+1==WhiteWarrior[sWarriors].y)
							{
								if(BlackWarrior[warriors].x+1==WhiteWarrior[sWarriors].x)
									Block[3]=false;
								else if(BlackWarrior[warriors].x-1==WhiteWarrior[sWarriors].x)
									Block[3]=false;
								else Block[3]=true;
							}
							else Block[3]=true;
						}
					}
					if(BlackKing.y+1==BlackWarrior[warriors].y)
					{
						if(BlackWarrior[warriors].y+1==4)
							if(BlackWarrior[warriors].x==BlackKing.x)
								Block[7]=true;
						if(BlackWarrior[warriors].y+1==WhiteKing.y)
							if(BlackWarrior[warriors].x==WhiteKing.x)
								Block[7]=true;
						for(int smallWarriors;smallWarriors<3;smallWarriors++)
						{
							if(BlackWarrior[warriors].y+1==WhiteWarrior[smallWarriors].y)
								if(BlackWarrior[warriors].x==WhiteWarrior[smallWarriors].x)
									Block[7]=true;
						}
					}*/

