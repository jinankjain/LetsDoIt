#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,k;
	cin>>t;
	string s;
	long long  maxi = -1,t1=1;
	while(t--)
	{
		cin>>n>>k;
		cin>>s;
		for(int i=0;i<(n-k);i++)
		{
			t1 = 1;
			for(int j=i;j<i+k;j++)
			{
				t1 = t1*(s[j]-'0');
			}
			maxi = max(t1, maxi);
		}
		cout<<maxi<<endl;
	}
	return 0;
}