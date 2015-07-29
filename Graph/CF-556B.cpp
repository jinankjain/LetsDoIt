#include <bits/stdc++.h>
using namespace std;
vector<int> V;
bool check(int n)
{
	for(int i=0;i<n;i++)
	{
		if(V[i]!=i) return false;
	}
	return true;
}
int main()
{
	int n,t;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		V.push_back(a[i]);
	}
	bool ans = false, cond=true, tt=false;
	while(cond)
	{
		for(int i=0;i<n;i++)
		{
			if(i%2==0)
			{
				V[i] = (V[i]+1)%n;
			}
			else
			{
				if(V[i]!=0) V[i] = V[i]-1;
				else V[i] = n-1;
			}
		}
		if(check(n)) 
		{
			ans = true;
			break;
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				if(a[i]==V[i])
				{
					tt = true;
				}
				else
				{
					tt = false;
					break;
				}
			}
			//cout<<tt<<endl;
			if(tt) cond = false;
		}
	}
	if(ans) cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}