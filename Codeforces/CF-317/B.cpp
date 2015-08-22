#include <bits/stdc++.h>
using namespace std;
int main()
{
	
	ios_base::sync_with_stdio(false);
    cin.tie(false);
	vector<pair<int, int> > b,s;
	int n,p;
	char a;
	int q,w;
	cin>>n>>p;
	for(int i=0;i<n;i++) 
	{
		cin>>a>>q>>w;
		if(a=='B') b.push_back(make_pair(q,w));
		else s.push_back(make_pair(q,w));
	}
	sort(s.begin(), s.end());
	sort(b.begin(), b.end());
	int th = p;
	int i = 0,j;
	vector<pair<int, int > > ans;
	while(p>0 && i<s.size())
	{
		int s1 = s[i].second;
		j = i+1;
		while(j>=0)
		{
			if(s[j].first == s[i].first)
			{
				s1+=s[j].second;
				j++;
			}
			else
			{
				break;
			}
		}
		p--;
		ans.push_back(make_pair(s[i].first, s1));
		i = j;
	}
	int gg = ans.size()-1;
	for(int i=gg;i>=0;i--)
	{
		cout<<"S "<<ans[i].first<<" "<<ans[i].second<<"\n";
	}
	i = b.size()-1;
	while(th>0 && i>=0)
	{
		int s1 = b[i].second;
		j = i-1;
		while(j>=0)
		{
			if(b[j].first == b[i].first)
			{
				s1+=b[j].second;
				j--;
			}
			else
			{
				break;
			}
		}
		th--;
		cout<<"B "<<b[i].first<<" "<<s1<<"\n";
		i = j;
	}
	return 0;
}
