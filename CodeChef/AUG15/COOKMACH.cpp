#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	long long a,b;
	while(t--)
	{
		cin>>a>>b;
		if(a==b)
		{
			cout<<"0\n";
		}
		else
		{
			int cnt = 0;
			while(b%a!=0 && a!=1)
			{
				cnt++;
				a = a/2;
			}
			while(b!=a)
			{
				a = a*2;
				cnt++;
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}