//Algorytm Manachera
#include <iostream>
#define MAX 1000005
using namespace std;

char t[MAX];
int res[MAX];
int dl, last, lastp;

int main()
{
        scanf("%s",&t);
        dl=strlen(t);
        last=0;
        for(int i=0;i<dl;i++)
        {
                //printf("last:%d i:%d t[i]:%c\n",last,i,t[i]);
                if(last>i)
                {
                        res[i]=res[lastp-(i-lastp)];
                        if(res[i]+i>=last)
                        {
                                res[i]=last-i;
                                for(int j=last+1;j<dl;j++)
                                {
                                        if(t[j]==t[i-res[i]-1]) res[i]++;
                                        else
                                        {
                                                last=j-1;
                                                lastp=i;
                                                break;
                                        }
                                }
                        }
                }
                else
                {
                        for(int j=i+1;j<dl;j++)
                        {
                                if(t[j]==t[i-res[i]-1]) res[i]++;
                                else
                                {
                                        last=j-1;
                                        lastp=i;
                                        break;
                                }
                        }
                }
        }
        for(int i=0;i<dl;i++) printf("%d ",res[i]);
        return 0;
}
