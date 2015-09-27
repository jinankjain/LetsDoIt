#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==1)
		{
			cout<<"2\n";
		}
		else
		{
			if(((n+1)&n)==0)
				cout<<n/2<<endl;
			else
				cout<<"-1\n";
		}
	}
	return 0;
}