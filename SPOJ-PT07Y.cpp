#include <bits/stdc++.h>
using namespace std;
const int vertices = 10017;
int state[vertices];
vector<int> G[vertices];
bool detectCycleUndirected()
{
	bool hasCycle = false;
	int predecessor[vertices];
	memset(predecessor, -1, sizeof(int)*vertices);
	memset(state, 0, sizeof(int)*vertices);
	list<int> stack;
	stack.push_back(1);
	state[1] = 1;
	while(!stack.empty())
	{
		int temp = stack.back();
		stack.pop_back();
		for(int i=0;i<G[temp].size();i++)
		{
			if(state[G[temp][i]]==1 && predecessor[temp]!=G[temp][i])
				hasCycle = true;
			if(state[G[temp][i]]==0)
			{
				stack.push_back(G[temp][i]);
				predecessor[G[temp][i]] = temp;
				state[G[temp][i]] = 1;
			}
		}
	}
	return hasCycle;
}
int main()
{
	int n,m;
	cin>>n>>m;
	int t,p;
	if(n==(m+1))
	{
		
		for(int i=0;i<m;i++)
		{
			cin>>t>>p;
			G[t].push_back(p);
			G[p].push_back(t);
		}
		bool gg = detectCycleUndirected();
		bool gt = true;
		//cout<<gg<<endl;
		for(int i=1;i<=n;i++)
		{
			if(state[i]==0)
			{
				gt = false;
				break;
			}
		}
		if(!gg && gt)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
	else
	{
		cout<<"NO\n";
	}
	return 0;
}