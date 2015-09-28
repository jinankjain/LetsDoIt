#include <bits/stdc++.h>
using namespace std;

int stringToint(string s)
{
   int n;
   stringstream(s)>>n;
   return n;
}

string intTostring(int n)
{
   stringstream ss;
   ss <<n;
   return ss.str();

}

bool check(int a)
{
	bool ans =false;
	string s = intTostring(a);
	int t = s.size();
	for(int i=0;i<=t/2;i++)
	{
		if(s[i]!=s[t-1-i])
		{
			ans = false;
			break;
		}
		else
		{
			ans = true;
		}
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,l,r;
	cin>>t;
	bool tt[100017] = {0};
	for(int i=1;i<100017;i++)
	{
		if(check(i)) tt[i] = 1;
	}
	while(t--)
	{
		long long ans = 0;
		cin>>l>>r;
		for(int i=l;i<=r;i++)
		{
			if(tt[i]) ans+=i;
		}
		cout<<ans<<"\n";
	}
	return 0;
}