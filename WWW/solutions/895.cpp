#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>
#define MN 100009
#define FORvit(v,T) for (vector<int>::iterator v=T.begin();v!=T.end();++v)

using namespace std;

const bool NORMAL = true;
const bool COMPLEMENT = false;

class Sig
{
public:
	int Sigma[MN];
	int SigmaD1[MN];
	int SizeN[MN];
	bool IsA[MN];
};

class Group
{
public:
	Group(){Size = 0;}
	Group(int nr, int it, int fr)
	{
		Nr = nr;
		Iteration = it;
		From = fr;
		Size = 0;
	}
	list<int> Nodes;
	int Size, Iteration, From, Nr;

	void Erase(list<int>::iterator it)
	{
		Size--;
		Nodes.erase(it);
	}

	list<int>::iterator Add(int v)
	{
		Size++;
		return Nodes.insert(Nodes.end(), v);
	}
};

class Position
{
public:
	list<Group>::iterator Gr;
	list<int>::iterator   Poz;
};

int n;
vector<int> G[MN];
Sig Sig1,Sig2;
int OrderW[MN];
Position Where[MN];

template<class It>
It PrevIt(It x)
{
	return --x;
}

template<class It>
It NextIt(It x)
{
	return ++x;
}

void LexBFS( int *Order, Sig &SigT, bool Type )
{
	int NrT = 0;
	list<Group> T;
	T.push_back( Group(NrT++,-1,-1) );
	for (int i=0;i<n;i++)
	{
		Where[ Order[i] ].Gr = T.begin();
		Where[ Order[i] ].Poz = T.begin()->Add( Order[i] );
		SigT.Sigma[ i ] = -1;
	}

	int Iter = 0;
	while (!T.empty())
	{
		int v = T.begin()->Nodes.front();

		if (Type == COMPLEMENT)
			SigT.IsA[ v ] = true;

		SigT.Sigma[ v ] = Iter;
		SigT.SigmaD1[ Iter ] = v;
		SigT.SizeN[ v ] = T.begin()->Size;

		T.begin()->Erase( T.begin()->Nodes.begin() );
		int StartNr   = T.begin()->Nr;

		if (Type == COMPLEMENT && T.begin()->Size == 0)
			SigT.IsA[ v ] = false;

		if (T.begin()->Size == 0)
			T.erase( T.begin() );

		int HowManyToFirst = 0;

		FORvit(x,G[v])
			if (SigT.Sigma[ *x ] == -1)
			{
				if ( Where[*x].Gr->Nr == StartNr )
					HowManyToFirst++;

				list<Group>::iterator DestinationGroup;
				if (Type == NORMAL)
				{
					if (Where[*x].Gr == T.begin() || PrevIt(Where[*x].Gr)->Iteration != Iter || PrevIt(Where[*x].Gr)->From != Where[*x].Gr->Nr)
						T.insert( Where[*x].Gr, Group(NrT++,Iter, Where[*x].Gr->Nr) );
					DestinationGroup = PrevIt(Where[*x].Gr);
				}
				else
				{
					if (NextIt(Where[*x].Gr) == T.end() || NextIt(Where[*x].Gr)->Iteration != Iter || NextIt(Where[*x].Gr)->From != Where[*x].Gr->Nr)
						T.insert( NextIt(Where[*x].Gr), Group(NrT++,Iter,Where[*x].Gr->Nr) );
					DestinationGroup = NextIt(Where[*x].Gr);
				}

				Where[*x].Gr->Erase( Where[*x].Poz );

				if (Where[*x].Gr->Size == 0)
				{
					if (Type == COMPLEMENT && Where[*x].Gr == T.begin())
						SigT.IsA[ v ] = false;
					T.erase( Where[*x].Gr );
				}

				Where[*x].Gr = DestinationGroup;
				Where[*x].Poz = Where[*x].Gr->Add( *x );
			}
			if (Type == NORMAL)
			{
				if (SigT.SizeN[ v ] == 1)
					SigT.IsA[ v ] = false;
				else
					SigT.IsA[ v ] = (T.begin()->Iteration == Iter);
			}
			Iter++;
	}
}

struct Cmp
{
	int *Order;
	Cmp(int *order):Order(order){}
	bool operator()(const int A,const int B) const
	{
		return Order[A] < Order[B];
	}
};

void ReArrange( Sig &SigT )
{
	for (int i=0;i<n;i++)
		sort(G[i].begin(),G[i].end(),Cmp( SigT.Sigma ) );
}

bool Neighbours( int F, int S )
{
	FORvit(i,G[F])
		if (S == *i)
			return true;
	return false;
}

int NextV( int v, Sig &SigT)
{
	return SigT.SigmaD1[ SigT.Sigma[ v ] + 1 ];
}

vector<int> Outs[MN];

int Parallel(int Out, int NewOut, int F, int v)
{
	if (Out < NewOut)
	{
		Outs[v] = Outs[F];
		return NewOut;
	}
	if (Out == NewOut && !lexicographical_compare(Outs[v].begin(),Outs[v].end(),Outs[F].begin(),Outs[F].end()))
	{
		Outs[v] = Outs[F];
		return NewOut;
	}
	return Out;
}

int Each(int Out, int NewOut, int F, int v)
{
	for (int i=0;i<Outs[F].size();i++)
		Outs[v].push_back( Outs[F][i] );
	sort(Outs[v].begin(),Outs[v].end());
	return Out + NewOut;
}

int Clicque( int v )
{
	int HowFar1   = Sig1.Sigma[ v ] + Sig1.SizeN[ v ];
	int HowFar2   = Sig2.Sigma[ v ] + Sig2.SizeN[ v ];

	int Position1 = Sig1.Sigma[ v ] + 1;
	int Position2 = Sig2.Sigma[ v ] + 1;
	int F,S;

	if (Sig1.IsA[ v ])
		Position1 += Sig1.SizeN[ NextV(v, Sig1) ];
	if (Sig2.IsA[ v ])
		Position2 += Sig2.SizeN[ NextV(v, Sig2) ];

	if ( HowFar1 <= Position1 && HowFar2 <= Position2 )
	{
		Outs[v].push_back(v);
		return 1;
	}
	if ( HowFar1 <= Position1 )
	{
		Outs[v].push_back(v);
		S = Sig2.SigmaD1[ Position2 ];
		return Each( 1, Clicque( S ), S,v ) ;
	}
	if ( HowFar2 <= Position2 )
	{
		Outs[v].push_back(v);
		F = Sig1.SigmaD1[Position1];
		return Parallel( 1, Clicque( F ), F, v);
	}
	F = Sig1.SigmaD1[ Position1 ];
	S = Sig2.SigmaD1[ Position2 ];
	int Out = 1;
	Outs[v].push_back(v);

	if ( Neighbours( F, S ) )
	{
		while (Position1 < HowFar1)
		{
			F = Sig1.SigmaD1[ Position1 ];
			S = Sig2.SigmaD1[ Position2 ];
			Out = Parallel( Out, Clicque( F ), F, v );
			if (Position2 < HowFar2)
			{
				Out = Each( Out, Clicque( S ), S, v );
			}
			else break;
			Position1 += Sig1.SizeN[ F ];
			Position2 += Sig2.SizeN[ S ];
		}
	}
	else
	{
		while (Position2 < HowFar2)
		{
			S = Sig2.SigmaD1[ Position2 ];
			F = Sig1.SigmaD1[ Position1 ];
			Out = Each( Out, Clicque( S ), S, v );
			if (Position1 < HowFar1)
			{
				Out = Parallel( Out, Clicque( F ), F, v );
			}
			else break;
			Position1 += Sig1.SizeN[ F ];
			Position2 += Sig2.SizeN[ S ];
		}
	}
	return Out;
}

int main()
{
	int lw;
	scanf("%d",&lw);

	while (lw--)
	{
		scanf("%d",&n);

		for (int i=1;i<n;i++)
		{
			int L,A;
			scanf("%d",&L);
			while (L--)
			{
				scanf("%d",&A); A--;
				G[i].push_back(A);
				G[A].push_back(i);
			}
		}

		for (int i=0;i<n;i++)
			OrderW[i] = i;

		LexBFS( OrderW, Sig1, NORMAL );
		ReArrange( Sig1 );
		LexBFS( Sig1.SigmaD1, Sig2, COMPLEMENT );

		printf("%d\n", Clicque( 0 ) );
		FORvit(i,Outs[ Sig1.SigmaD1[0] ])
			printf("%d ",*i+1);
		printf("\n");

		for (int i=0;i<n;i++)
		{
			G[i].clear();
			Outs[i].clear();
		}
	}

	return 0;
}

