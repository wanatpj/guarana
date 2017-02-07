#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#define MN 100001

using namespace std;

int n;
vector<int> Graf[MN];

int IsOnCycle[MN];
stack<int> CycleStack;
int From[MN];
vector<int> Cycle;

bool Visited[MN];
int Parent[MN];

int WithNode[MN];
int WithHalfNode[MN];
int WithOutNode[MN];

bool IsHalfPos[MN];

bool FindCycle(int C)
{
	CycleStack.push( C );
	for (int i=0;i<Graf[C].size();i++)
		if (From[ Graf[C][i] ] == 0)
		{
			From[ Graf[C][i] ] = C;
			if (FindCycle( Graf[C][i] ))
				return true;
		}
		else
		if (From[ C ] != Graf[C][i])
		{
			while ( CycleStack.top() != Graf[C][i] )
			{
				IsOnCycle[ CycleStack.top() ] = true;
				Cycle.push_back( CycleStack.top() );
				CycleStack.pop();
			}
			IsOnCycle[ CycleStack.top() ] = true;
			Cycle.push_back( CycleStack.top() );
			return true;
		}
	CycleStack.pop();
	return false;
}

void CountTree(int C)
{
	Visited[C] = true;
	for (int i=0;i<Graf[C].size();i++)
		if (!Visited[ Graf[C][i] ] && !IsOnCycle[ Graf[C][i] ])
		{
			Parent[ Graf[C][i] ] = C;
			CountTree( Graf[C][i] );
		}

	for (int i=0;i<Graf[C].size();i++)
		if (Parent[ Graf[C][i] ] == C)
			WithOutNode[C] += max( WithOutNode[ Graf[C][i] ], WithNode[ Graf[C][i] ] );

	if (IsHalfPos[ C ])
		for (int i=0;i<Graf[C].size();i++)
			if (Parent[ Graf[C][i] ] == C)
			{
				int TempVal = WithOutNode[ C ];
				TempVal -= max( WithOutNode[ Graf[C][i] ], WithNode[ Graf[C][i] ] );
				TempVal += WithOutNode[ Graf[C][i] ];
				WithHalfNode[C] = max( WithHalfNode[ C ], TempVal );
			}

	for (int i=0;i<Graf[C].size();i++)
		if (Parent[ Graf[C][i] ] == C && IsHalfPos[ Graf[C][i] ])
		{
			int TempVal = WithOutNode[ C ];
			TempVal -= max( WithOutNode[ Graf[C][i] ], WithNode[ Graf[C][i] ] );
			TempVal += WithHalfNode[ Graf[C][i] ];
			TempVal++;
			WithNode[C] = max( WithNode[ C ], TempVal );
		}

	int BestNr[2] = {-1,-1};
	int BestVal[2] = {-MN*2,-MN*2};
	for (int i=0;i<Graf[C].size();i++)
		if (Parent[ Graf[C][i] ] == C)
		{
			int TempVal = -max( WithOutNode[ Graf[C][i] ], WithNode[ Graf[C][i] ] );
			TempVal += WithOutNode[ Graf[C][i] ];
			if (TempVal>=BestVal[0])
			{
				BestVal[1] = BestVal[0]; BestNr[1] = BestNr[0];
				BestVal[0] = TempVal; BestNr[0] = i;
			}
			else
			if (TempVal>=BestVal[1])
			{
				BestVal[1] = TempVal; BestNr[1] = i;
			}
		}
	if (BestNr[1] != -1)
	{
		WithNode[C] = max(WithOutNode[C] 
			- max( WithOutNode[ Graf[C][ BestNr[0] ] ], WithNode[ Graf[C][ BestNr[0] ] ] ) 
			- max( WithOutNode[ Graf[C][ BestNr[1] ] ], WithNode[ Graf[C][ BestNr[1] ] ] )
			+ WithOutNode[ Graf[C][ BestNr[0] ] ]
			+ WithOutNode[ Graf[C][ BestNr[1] ] ] 
			+ 1, WithNode[C] );
	}
}

int BestResult[MN];

int CycleCount(int IterL, int IterR)
{
	if (IterL>IterR) return 0;
	BestResult[ IterL-1 ] = 0;
	BestResult[ IterL ] = max(WithNode[ Cycle[IterL] ], WithOutNode[ Cycle[ IterL ] ] );
	for (int i=IterL+1;i<=IterR;i++)
	{
		BestResult[i] = max(WithNode[ Cycle[i] ], WithOutNode[ Cycle[ i ] ] ) + BestResult[ i- 1 ];
		if (IsHalfPos[ Cycle[i] ])
			BestResult[i] = max(BestResult[i], WithHalfNode[ Cycle[i] ] + 1 + BestResult[ i-2 ] + WithOutNode[ Cycle[i-1] ]);
		if (IsHalfPos[ Cycle[i-1] ])
			BestResult[i] = max(BestResult[i], WithHalfNode[ Cycle[i-1] ] + 1 + BestResult[ i-2 ] + WithOutNode[ Cycle[i] ]);
		if (i>=IterL+2)
			BestResult[i] = max(BestResult[i], WithOutNode[ Cycle[i] ] + WithOutNode[ Cycle[i-1] ] + WithOutNode[ Cycle[i-2] ] + 1 + BestResult[i-3]);
	}
	return BestResult[IterR];
}

int main()
{
	scanf("%d",&n);

	for (int i=0;i<n;i++)
	{
		int A,B;
		scanf("%d%d",&A,&B);
		Graf[A].push_back(B);
		Graf[B].push_back(A);
	}

	for (int i=1;i<=n;i++)
		IsOnCycle[i] = false;

	From[1] = -1;
	FindCycle(1);

	//for (int i=1;i<=n;i++)
	//	printf("IsOnCycle %d.: %d\n",i,IsOnCycle[i]);

	for (int i=1;i<=n;i++)
	{
		Visited[i] = false;
		WithNode[i] = 0;
		WithHalfNode[i] = 0;
		WithOutNode[i] = 0;
		if (IsOnCycle[i])
			IsHalfPos[i] = (Graf[i].size()>2)?(true):(false);
		else
			IsHalfPos[i] = (Graf[i].size()>=2)?(true):(false);
	}

	for (int i=1;i<=n;i++)
		if (IsOnCycle[i])
		{
			Parent[i] = -1;
			CountTree( i );
		}

	//for (int i=1;i<=n;i++)
	//	printf("TreeSize: %d %d %d %d\n",IsHalfPos[i],WithOutNode[i],WithHalfNode[i],WithNode[i]);

	int P[6] = {0,0,0,0,0,0};
	P[0] = CycleCount(1, Cycle.size()-1) + max( WithNode[ Cycle[0] ], WithOutNode[ Cycle[0] ] );

	if (IsHalfPos[ Cycle[0] ] || IsHalfPos[ Cycle[1] ])
	{
		int TempCycleOut = CycleCount(2, Cycle.size()-1);
		if (IsHalfPos[ Cycle[0] ])
			P[1] = max(P[1],TempCycleOut + 1 + WithHalfNode[ Cycle[0] ] + WithOutNode[ Cycle[1] ]);
		if (IsHalfPos[ Cycle[1] ])
			P[1] = max(P[1],TempCycleOut + 1 + WithHalfNode[ Cycle[1] ] + WithOutNode[ Cycle[0] ]);
	}
	if (IsHalfPos[ Cycle[0] ] || IsHalfPos[ Cycle[ Cycle.size()-1 ] ])
	{
		int TempCycleOut = CycleCount(1, Cycle.size()-2);
		if (IsHalfPos[ Cycle[0] ])
			P[2] = max(P[2],TempCycleOut + 1 + WithHalfNode[ Cycle[0] ] + WithOutNode[ Cycle[ Cycle.size()-1 ] ]);
		if (IsHalfPos[ Cycle[ Cycle.size()-1 ] ])
			P[2] = max(P[2],TempCycleOut + 1 + WithHalfNode[ Cycle[ Cycle.size()-1 ] ] + WithOutNode[ Cycle[0] ]);
	}
	P[3] = CycleCount(3, Cycle.size()-1) + 1 + WithOutNode[ Cycle[0] ] + WithOutNode[ Cycle[1] ] + WithOutNode[ Cycle[2] ];
	P[4] = CycleCount(2, Cycle.size()-2) + 1 + WithOutNode[ Cycle[0] ] + WithOutNode[ Cycle[1] ] + WithOutNode[ Cycle[ Cycle.size()-1 ] ];
	P[5] = CycleCount(1, Cycle.size()-3) + 1 + WithOutNode[ Cycle[0] ] + WithOutNode[ Cycle[ Cycle.size()-1 ] ] + WithOutNode[ Cycle[ Cycle.size()-2] ];

	printf("%d\n",max(max(max(max(max(P[0],P[1]),P[2]),P[3]),P[4]),P[5]));

	return 0;
}


