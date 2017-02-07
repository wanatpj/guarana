#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	int a;
	ifstream in("a5.cpp");
	ofstream out("a5blex123.cpp");
	char linijka[1000];
	while(in.good())
	{
		in.getline(linijka,1000,'\n');
		out << linijka << endl;
	}
	scanf("%d", &a);
	printf("%d\n", a);
	return 0;
}

