//Algorytm Manachera dla palindromow nieparzystych
//obliczanie promieni slow symetrycznych (palindromow)
//zalozenie: znaki '#' i '$' nie wystepuja w tekscie
#include <iostream>
#define MAX 1000010

char txt[MAX], r[MAX];
int dl, last, j, a, b;

main()
{
    scanf("%s",&txt[1]);
    dl=strlen(txt+1);
    txt[0]='#';
    txt[dl+1]='$';
    r[0]=0;
    last=0;
    for(int i=1;i<=dl;i++)
    {
        if(r[last]+last>=i)
        {
            a=last-r[last];
            b=2*last-i-r[2*last-i];
            if(a<b) r[i]=r[2*last-i];
            else if(a>b) r[i]=r[last]-i+last;
            else
            {
                r[i]=r[2*last-i];
                while(txt[i-r[i]-1]==txt[i+r[i]+1]) r[i]++;
                last=i;
            }
        }
        else
        {
            j=0;
            while(txt[i-j-1]==txt[i+1+j]) j++;
            r[i]=j;
            last=i;
        }
    }
    for(int i=1;i<=dl;i++) printf("%d ",r[i]);
    return 0;
}