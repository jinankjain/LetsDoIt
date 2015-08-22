#include <bits/stdc++.h>
using namespace std;
int largeFac(int n)
{
	int a[20000];
	a[0] = 1;
	int temp = 0; // Temp variable to store carry
	int m = 1; // Current size of the array
	int x;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			x = a[j]*i+temp;
			a[j] = x%10;
			temp = x/10;
		}
		while(temp>0)
		{
			a[m] = temp%10;
			temp = temp/10;
			m++;
		}
	}
	int ans = 0;
	for(int i=0;i<m;i++) ans+=a[i];
    return ans;
}
int largeFacSum(int n)
{
	int p = largeFac(n);
	return p;
}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int ans = largeFacSum(n);
		cout<<ans<<endl;
	}
	return 0;
}