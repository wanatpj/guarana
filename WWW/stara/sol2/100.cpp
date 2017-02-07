#include <iostream>
#include <set>
#define MAX 100010
using namespace std;

int dl, pot, l, to, r, from, to2, p, tot;
int numer[MAX], numer2[MAX], tmp[MAX], li[26];
char t[MAX];
bool byl[26];
struct por { 
	bool operator()(const int &a, const int &b) {  
		if(numer[a]==numer[b]) 
			return numer[a+r]<numer[b+r];
		return numer[a]<numer[b];
	} 
};

set <int, por> S;

bool cmp(const int &a, const int &b)
{
	if(numer[a]==numer[b])
	{
		if(numer[a+(pot>>1)]==numer[b+(pot>>1)]) return a<b;
		return numer[a+(pot>>1)]<numer[b+(pot>>1)];
	}
	return numer[a]<numer[b];
}

main()
{
	scanf("%s",&t);
	dl=strlen(t);
	pot=1;
	for(int i=0;i<26;i++) byl[i]=0;
	for(int i=0;i<dl;i++)
	{
		t[i]-='a';
		byl[t[i]]=1;
	}
	l=0;
	for(int i=0;i<26;i++)
	{
		if(byl[i]==1)
		{
			li[i]=l;
			l++;
		}
	}
	for(int i=0;i<dl;i++) numer[i]=li[t[i]];
	to=dl-1;
	tot=to;
	for(int i=1;;i++)
	{
		pot*=2;
		tot=to;
		if(dl<=pot) break;
		to=dl-pot+1;
		for(int j=0;j<to;j++) tmp[j]=j;
		sort(tmp,tmp+to,cmp);
		l=0;
		to--;
		for(int j=0;j<to;j++)
		{
			numer2[tmp[j]]=l;
			if(numer[tmp[j]]!=numer[tmp[j+1]]||numer[tmp[j]+(pot>>1)]!=numer[tmp[j+1]+(pot>>1)]) l++;	
		}
		if(l==to) break;
		numer[tmp[to]]=l;
		for(int j=0;j<to;j++) numer[tmp[j]]=numer2[tmp[j]];
	}
	pot/=2;
	from=0;
	to=tot;
	to2=pot;
	p=-1;
	while(from+1<to2)
	{
		S.clear();
		r=(from+to2)/2;
		p=-1;
		tot=to-r;
		for(int i=0;i<=tot;i++)
		{
			S.insert(i);
			if(S.size()!=i+1)
			{
				p=i;
				break;
			}
		}
		if(p==-1) to2=r;
		else from=r;
	}
	printf("%d\n",pot+from);
	/*if(p!=-1)
	{
		for(int i=p-1;i>=0;i--)
		{
			if(numer[i]==numer[p]&&numer[i+r]==numer[p+r])
			{
				printf("%d %d\n",i+1,p+1);
			}
		}
	}
	else
	{
		for(int i=0;i<dl;i++) tmp[i]=-1;
		for(int i=0;i<=to;i++)
		{
			if(tmp[numer[i]]==-1) tmp[numer[i]]=i;
			else
			{
				printf("%d %d\n",tmp[numer[i]]+1,i+1);
				break;
			}
		}
	}*/
	return 0;
}

