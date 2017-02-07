#include <iostream>
#include <fstream>
#define MAX 10000
using namespace std;

int i;
bool ok;
char line[MAX];
fstream plik;

main()
{
	ok=1;
	plik.open("kom",ios::in);
	while(true)
	{
		plik.getline(line,MAX);
		if(plik.eof()) break;
		if(line[0]=='.')
		{
			i=0;		
			while(line[i]!=' '&&i<MAX-1) i++;
			i++;
			if(!(line[i]=='/'&&line[i+1]=='u'&&line[i+2]=='s'&&line[i+3]=='r'&&line[i+4]=='/')) ok=0;
		}
		else
		{			
			ok=0;
			break;
		}
	}
	plik.close();
	if(ok==0) system("rm pro");
	//system("rm kom");
	return 0;
}

