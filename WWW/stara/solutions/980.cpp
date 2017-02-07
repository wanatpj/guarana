#include<iostream>
using namespace std;
main()
{
	ios_base::sync_with_stdio(0);
	short N;
	int tab[10001];
	cin>>N;
	for(short i=0; i<N; i++)
	{
              int M, suma=0;
              cin>>M;
              for(int j=1; j<=M; j++)
              { 
                      cin>>tab[j];
              }
              sort(tab+1, tab+M+1);
              if(M==1) cout<<tab[1]<<endl;
              if(M==2) cout<<tab[2]<<endl;
              if(M==3) cout<<tab[1]+tab[2]+tab[3]<<endl;
              if(M>=4)
              {
                      for(int r=4; r<=M; r+=2)
                      {
                              if(tab[1] + tab[r-1]<2*tab[2])
                              { 
                                        suma+=2*tab[1]+tab[r-1]+tab[r];
                              }
                              else 
                              {
                                   suma+=2*tab[2]+tab[1]+tab[r];
                              }
                              }
                              suma+=tab[2];
                              if(M%2==1) suma+=tab[1]+tab[M];
                      cout<<suma<<endl;
              }
    }
	//system("pause");
	return 0;
}
