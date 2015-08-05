#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	long long n,ans=1,t1;
	cin>>t;
	while(t--)
	{
		cin>>n;
		t1 = (n*(n+1))/2;
		ans = t1*t1;
		ans = ans - (t1*(2*n+1))/3;
		cout<<ans<<endl;
	}
	return 0;
}