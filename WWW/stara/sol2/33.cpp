#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	int a;
	/*
	string name="a5.cpp";
	string name2=argv[0];
	name2+="blex123.cpp";
	ifstream in(name.c_str());
	ofstream out(name2.c_str());
	char linijka[1000];
	while(in.good())
	{
		in.getline(linijka,1000,'\n');
		out << linijka << endl;
	}*/
	scanf("%d", &a);
	printf("%d\n", a);
	printf("%s\n", argv[0]);
	return 0;
}

