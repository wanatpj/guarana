#include <iostream>
#include <algorithm>
using namespace std;

int tab[10001],TAB[10001];
int main()
{ios_base::sync_with_stdio(0);
    int e;
    int z; cin>>z;
for(int i=0;i<z;i++)
        {
        int n; cin>>n;
        for(int j=0; j<n;j++)
        cin>>tab[j];
        
                for (int i=0; i<n; i++)
	    sort(tab,tab+n);
        
   	    TAB[0]=tab[0];
	   TAB[1]=max(tab[0],tab[1]);
     TAB[2]= tab[0]+tab[1]+tab[2];
   
   if(n==1) cout<<tab[0]<<endl;
   else if(n==2) cout<<max(tab[1],tab[0])<<endl;
   else if(n==3) cout<<tab[1]+tab[2]+tab[0]<<endl;
   

     
  //   if(n==1) TAB[]=tab[0]; //return 0;
   // else if(n==2) e=max(tab[1],tab[2]); //return 0;
   // else if (n==3) e=tab[0]+tab[1]+tab[2]; //return 0;
       else  {
             
             e=min(TAB[n-3]+tab[0]+2*tab[1]+tab[n-1],TAB[n-2]+tab[0]+tab[n-1]);
   for(int i=5;i<n;i++)
   {   
    TAB[i]=min(TAB[i-3]+tab[0]+(2*tab[1])+tab[i-1],TAB[i-2]+tab[0]+tab[i-1]);
     if (TAB[i]>e) e=TAB[i];
    }
    cout<<e<<endl;    }
//  for(int i=1;i<=n;i++)
//{  e=e+TAB[i];     }
//cout<<e;
//e=0;
//system("pause");
}
return 0;}
