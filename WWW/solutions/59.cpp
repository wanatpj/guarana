#include<iostream>
//#include<cstdio>
using namespace std;

long long licznik;
int ilosc,top;
long long A[30], STOS[15];

void wpis()
{
     char POM[30];
     scanf("%s", &POM);
     ilosc = strlen(POM);
     //cout<<"ilosc: "<<ilosc<<endl;
     for(int j=0;j<ilosc;j++){
             if(POM[j]=='*')
              A[j]=1;
             else{
              if(POM[j]=='+')
               A[j]=0;
              else
                A[j]=POM[j]-48;
             }
          //cout<<"tab A od "<<j<<"="<<A[j]<<endl;;
     }
     A[ilosc]=0;
}
void por()
{
     for(int l=1;l<=ilosc;l+=2){
      if(A[l]==1)
       A[l+1]=A[l-1]*A[l+1];
      else
       STOS[top++]=A[l-1];
     }
     //for(int i=0;i<top;i++)
     //cout<<"STOS od "<<i<<"="<<STOS[i]<<endl;
     //cout<<endl;
}
void dod()
{
     for(int i=0;i<top;i++)
      licznik+=STOS[i];
      cout<<licznik<<endl;
}
int main()
{ 
    ios_base::sync_with_stdio(0);
    int z;
    scanf("%d\n",&z);
    while(z--){
     top=0;
     licznik=0;
     wpis();
     por();
     dod();     
    }
    //system("pause");
    return 0;
}
