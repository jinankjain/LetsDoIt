#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	string s,s1;
	while(t--)
	{
		cin>>s>>s1;
		bool ans = true;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]!=s1[i] && s[i]!='?' && s1[i]!='?')
			{
				ans = false;
				break;
			}
		}
		if(ans) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}