#include <iostream>
#include <algorithm>
using namespace std;

int tab[10001],TAB[10001];
int main()
{ios_base::sync_with_stdio(0);

    int z; cin>>z;
for(int i=1;i<=z;i++)
        {     int e=0; 
        int n; cin>>n;
        for(int j=1; j<=n;j++)
        cin>>tab[j];
        
        sort(tab,tab+n);
        

   if  (n==0) cout<<0<<endl;
   else if(n==1) cout<<tab[1]<<endl;
   else if(n==2) cout<<max(tab[1],tab[2])<<endl;
   else if(n==3) cout<<tab[1]+tab[2]+tab[3]<<endl;
   

     
  //   if(n==1) TAB[]=tab[0]; //return 0;
   // else if(n==2) e=max(tab[1],tab[2]); //return 0;
   // else if (n==3) e=tab[0]+tab[1]+tab[2]; //return 0;
       else  {
TAB[1]=tab[1];
	   TAB[2]=(tab[2]);
     TAB[3]= tab[3]+tab[1]+tab[2];
             e=min(tab[n-2]+tab[1]+2*tab[2]+tab[n],tab[n-1]+tab[1]+tab[n]);
           
   for(int i=4;i<=n;i++)
   {   
    TAB[i]=min(TAB[i-2]+tab[1]+2*tab[2]+tab[i],TAB[i-1]+tab[1]+tab[i]);
     if (TAB[i]>e) e=TAB[i];
    }
     
    cout<<e<<endl;    }
//  for(int i=1;i<=n;i++)
//{  e=e+TAB[i];     }
//cout<<e;
//e=0;
//system("pause");
}
return 0;
}
