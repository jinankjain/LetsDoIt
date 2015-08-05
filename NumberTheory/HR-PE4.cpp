#include <bits/stdc++.h>
using namespace std;
string intTostring(long n)
{
   stringstream ss;
   ss <<n;
   return ss.str();
}
long long stringToint(string s)
{
   long long n;
   stringstream(s)>>n;
   return n;
}
bool checkPalin(string s)
{
	int t = s.size();
	//cout<<t<<endl;
	int j=t-1,i=0;
	while(i<j)
	{
		if(s[i]!=s[j])
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(false);
	int t;
	cin>>t;
	set<long long> v;
	set<long long>::iterator itlow;
	string s;
	long long g;
	long long n;
	
	for(int i=100;i<1000;i++)
	{
		for(int j=100;j<1000;j++)
		{
			g = i*j;
			s = intTostring(g);
			//cout<<s<<endl;
			if(checkPalin(s)==1)
			{
				v.insert(stringToint(s));
			}
		}
	}
	
	while(t--)
	{
		cin>>n;
		itlow=v.lower_bound (n);
		itlow--;
		cout<<(*itlow)<<"\n";      
	}
	return 0;
}