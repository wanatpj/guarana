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
                int SizeS[MN];
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

                SigT.Sigma[ v ] = Iter;
                SigT.SigmaD1[ Iter ] = v;
                SigT.SizeN[ v ] = T.begin()->Size;

                T.begin()->Erase( T.begin()->Nodes.begin() );
                int StartNr   = T.begin()->Nr;

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
                                        T.erase( Where[*x].Gr );

                                Where[*x].Gr = DestinationGroup;
                                Where[*x].Poz = Where[*x].Gr->Add( *x );
                        }
                if (Type == NORMAL)
                        SigT.SizeS[v] = HowManyToFirst;
                else
                        SigT.SizeS[v] = SigT.SizeN[v] - HowManyToFirst - 1;
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

bool IsV1Empty(int v, int type)
{
        if (type == NORMAL)
                return (Sig1.SizeN[ v ] == 1) || ( (Sig1.SizeN[ v ]  ==  1+Sig1.SizeN[ NextV(v, Sig1) ]) && (Sig1.SizeS[ v ] != 0) );
        else
                return (Sig2.SizeN[ v ] == 1) || ( (Sig2.SizeN[ v ]  ==  1+Sig2.SizeN[ NextV(v, Sig2) ]) && (Sig2.SizeS[ v ] != 0) );
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
    if (Outs[v].size() >=1)
        printf("WTF\n");
        if ( IsV1Empty(v,NORMAL) && IsV1Empty(v,COMPLEMENT) )
    {
        Outs[v].push_back(v);
                return 1;
    }
        if ( IsV1Empty(v,NORMAL) )
    {
        Outs[v].push_back(v);
                return Each( 1, Clicque( NextV(v, Sig2) ), NextV(v,Sig2),v ) ;
    }
        if ( IsV1Empty(v,COMPLEMENT) )
    {
        Outs[v].push_back(v);
                return Parallel( 1, Clicque( NextV(v,Sig1) ), NextV(v,Sig1), v);
    }
        int F = Sig1.SigmaD1[ Sig1.SizeN[ NextV(v,Sig1) ] + Sig1.Sigma[ v ] + 1 ];
        int S = Sig2.SigmaD1[ Sig2.SizeN[ NextV(v,Sig2) ] + Sig2.Sigma[ v ] + 1 ];
        int Out = 1;
    Outs[v].push_back(v);

        if ( Neighbours( F, S ) )
        {
                int T = Sig1.Sigma[ v ] + Sig1.SizeN[ NextV(v,Sig1) ] + 1;
                int T1 = Sig2.Sigma[ v ] + Sig2.SizeN[ NextV(v,Sig2) ] + 1;
                while (T <= Sig1.Sigma[ v ] + Sig1.SizeN[ v ] - 1)
                {
                        F = Sig1.SigmaD1[ T ];
                        Out = Parallel( Out, Clicque( F ), F, v );
                        if (T1 <= Sig2.Sigma[ v ] + Sig2.SizeN[ v ] - 1)
                        {
                                S = Sig2.SigmaD1[ T1 ];
                                Out = Each( Out, Clicque( S ), S, v );
                                T1 += Sig2.SizeN[ S ];
                        }
            else break;
                        T += Sig1.SizeN[ F ];
                }
        }
        else
        {
                int T = Sig2.Sigma[ v ] + Sig2.SizeN[ NextV(v,Sig2) ] + 1;
                int T1 = Sig1.Sigma[ v ] + Sig1.SizeN[ NextV(v,Sig1) ] + 1;

                while (T <= Sig2.Sigma[ v ] + Sig2.SizeN[ v ] - 1)
                {
                        S = Sig2.SigmaD1[ T ];
                        F = Sig1.SigmaD1[ T1 ];
                        Out = Each( Out, Clicque( S ), S, v );
                        if (T1 <= Sig1.Sigma[ v ] + Sig1.SizeN[ v ] - 1)
                        {
                                Out = Parallel( Out, Clicque( F ), F, v );
                                T1 += Sig1.SizeN[ F ];
                        }
            else break;
                        T += Sig2.SizeN[ S ];
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
/*
                for (int i=0;i<n;i++)
                        printf("%d ",Sig1.SigmaD1[i]+1);
                printf("\n");
                for (int i=0;i<n;i++)
                        printf("%d ",Sig2.SigmaD1[i]+1);
                printf("\n");
*/
                printf("%d\n",Clicque( Sig1.SigmaD1[0] ) );

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

