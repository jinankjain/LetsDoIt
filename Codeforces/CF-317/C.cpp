#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long a[3],l;
	cin>>a[0]>>a[1]>>a[2]>>l;
	long long tot = (l+3)*(l+2)*(l+1)/6;
	sort(a,a+3);
	for(int i=0;i<=l;i++)
	{
		if(a[2]+i>=a[1]+a[0])
		{
			//cout<<"gfdg";
			long long cur = min(l-i, (a[2]+i - (a[1]+a[0])));
			tot -= (((cur+1)*(cur+2))/2);
		}
		if(a[1]+i>=a[2]+a[0])
		{
			//cout<<"fdgdf";
			long long cur = min(l-i, (a[1]+i - (a[2]+a[0])));
			tot -= (((cur+1)*(cur+2))/2);
		}
		if(a[0]+i>=a[1]+a[2])
		{
			//cout<<"dfdsf";
			long long cur = min(l-i, (a[0]+i - (a[1]+a[2])));
			tot -= (((cur+1)*(cur+2))/2);
		}
	}
	cout<<tot<<endl;
	return 0;
}