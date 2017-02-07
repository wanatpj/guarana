#include <iostream>

int z,mik,a,b,c;

int main()
{
    scanf("%d %d",&z,&mik);
    while(z--)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a>mik) printf("komin");
        else if(b>mik) printf("okno");
        else if(c>mik) printf("drzwi");
        else printf("brak");
        printf("\n");
    }
    return 0;
}

