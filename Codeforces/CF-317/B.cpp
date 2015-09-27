#include <bits/stdc++.h>
using namespace std;
int main()
{
	//int b[100017], s[100017];
	map<long long, long long> b,s;
	long long n,p;
	char a;
	long long q,w;
	cin>>n>>p;
	for(long long i=0;i<n;i++) 
	{
		cin>>a>>q>>w;
		if(a=='B') b[q]+=w;
		else s[q]+=w;
	}
	map<long long, long long> ::iterator i = s.end();
	long long j = 0;
	long long t1 = s.size();
	if(t1>0) i--;
	if(t1>p)
	{
		while(t1>p)
		{
			i--;
			t1--;
		}
		for(j=0;j<t1;j++)
		{
			cout <<"S "<<i->first<<" "<< i->second<< "\n";
			i--;
		}
	}
	else
	{
		for(j=0;j<t1;j++)
		{
			cout <<"S "<<i->first<<" "<< i->second<< "\n";
			i--;
		}
	}
	
	i = b.end();
	t1 = b.size();
	if(t1>0) i--;
	if(t1>p)
	{
		for(long long j=0;j<p;j++)
		{
			cout <<"B "<<i->first<<" "<< i->second<< "\n";
			i--;
		}
	}
	else
	{
		for(long long j=0;j<t1;j++)
		{
			cout <<"B "<<i->first<<" "<< i->second<< "\n";
			i--;
		}
	}
	return 0;
}