#include <iostream>
#include <fstream>
#include <string>
#define MAX 10000 //Maksymalna liczba zgloszen
using namespace std;

string path;
int zad[MAX], id, dl;

int main(int argc, char * argv[])
{
  if(argc!=3) 
  {
	printf("Bledna liczba argumentow\n");
	return 0;
  }  
  id=0;
  dl=strlen(argv[2]);
  for(int i=dl-1, pot=1;i>=0;i--,pot*=10) id+=pot*(argv[2][i]-'0');
  path="./kat/";
  for(int i=0;i<strlen(argv[1]);i++)
  path+=argv[1][i];
  path+="/zgl";
  fstream file;  
  file.open(&path[0], ios::in);
  if(!file.is_open())
  {
	  file.open(&path[0], ios::out);
  	  file.close();
	  file.open(&path[0], ios::in);
  }
  int il=0;
  while(file.eof()!=true) file >> zad[il++]; 
  zad[il-1]=id;
  sort(zad,zad+il);
  il=unique(zad,zad+il)-zad;
  file.close();
  file.open(&path[0], ios::out | ios::trunc);
  for(int i=0;i<il;i++) file << zad[i] << " ";
  file << endl;
  file.close();
  return 0;
}

