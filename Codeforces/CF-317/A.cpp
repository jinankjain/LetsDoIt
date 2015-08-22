#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	int k,n;
	cin>>k>>n;
	long long v[a], g[b];
	for(int i=0;i<a;i++)
	{
		cin>>v[i];
	}
	for(int i=0;i<b;i++) cin>>g[i];
	if(v[k-1]<g[b-n]) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}