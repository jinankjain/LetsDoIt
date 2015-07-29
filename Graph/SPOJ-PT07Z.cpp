#include <bits/stdc++.h>
using namespace std;
const int vertices = 10100;
vector<int> G[vertices];
int level[vertices] = {0};
void zero()
{
	for(int i=0;i<vertices;i++)
	{
		level[i] = 0;
	}
}
void BFS(int s)
{
	list<int> queue;
	zero();
	queue.push_back(s);
	bool visited[vertices];
	for(int i=0;i<vertices;i++)
	{
		visited[i] = false;
	}
	visited[s] = true;
	
	level[s] = 0;
	while(!queue.empty())
	{
		int temp = queue.front();
		for(int i=0;i<G[temp].size();i++)
		{
			if(!visited[G[temp][i]])
			{
				level[G[temp][i]] = level[temp]+1;
				visited[G[temp][i]] = true;
				queue.push_back(G[temp][i]);
			}
		}
		queue.pop_front();
	}
}
int main()
{
	int n,t,p;
	cin>>n;
	if(n==1)
	{
		cout<<1;
	}
	else
	{
		for(int i=0;i<n-1;i++)
		{
			cin>>t>>p;
			G[t-1].push_back(p-1);
			G[p-1].push_back(t-1);
		}
		BFS(0);
		int maxi = 0;
		for(int i=0;i<n;i++)
		{
			if(level[maxi]<level[i])
			{
				maxi = i;
			}
		}
		BFS(maxi);
		int maxii = 0;
		for(int i=0;i<n;i++)
		{
			if(level[maxii]<level[i])
				maxii = i;
		}
		cout<<level[maxii];
	}
	return 0;
}