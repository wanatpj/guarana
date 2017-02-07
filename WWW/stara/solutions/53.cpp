#include <iostream>
#include <string>
using namespace std;

int main()
{
  int z;
  scanf("%d",&z);
  for (int q=0;q<z;q++)
  {
    long long tab[31];
    string bielizna;
    cin >> bielizna;
    long long suma=0;
    for (int i=0;i<bielizna.size();i=i+2)
      tab[i/2]=bielizna[i]-'0';
    for (int i=1;i<bielizna.size()-1;i=i+2)
      if(bielizna[i]=='*') 
      {
        tab[(i+1)/2]*=tab[(i-1)/2];
	tab[(i-1)/2]=0;
      }
    for (int i=0;i<bielizna.size();i=i+2)
      suma+=tab[i/2];
    cout << suma << endl;
    for (int i=0;i<bielizna.size();i=i+2)
      tab[i]=0;
  }
  return 0;
}
