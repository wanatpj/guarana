#include <iostream>
using namespace std;




string s;
long long stos[51];
int point;
long long wynik;


main()
{
   int z;
   cin>>z;
   for(int j=0; j<z; ++j)
   {
      cin>>s;
         point=1;
         wynik=0;
         stos[0]=s[0]-'0';
         for(int i=2; i<s.size(); i++)
         {
             if(s[i-1]=='*')
             {
                 long long k=stos[point-1]*(s[i]-'0');
                 stos[point-1]=k; 
             }
             else if(s[i-1]=='+')
             {
                 stos[point]=(s[i]-'0');
                 point++;
             }
         }
         for(int i=0; i<point; i++)
         wynik+=stos[i];
         cout<<wynik<<endl;
   }
}
