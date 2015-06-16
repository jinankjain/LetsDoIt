#include <bits/stdc++.h>
using namespace std;
const int vertices = 6;
vector<pair<int,int> > G[vertices];
void topoSort(int v, bool* visited, stack<int> &s)
{
	visited[v] = true;
	for(int i=0;i<G[v].size();i++)
	{
		if(!visited[G[v][i].first])
		{
			topoSort(G[v][i].first, visited, s);
		}
	}
	s.push(v);
}
int main()
{
	G[0].push_back(make_pair(1,5));
	G[0].push_back(make_pair(2,3));
	G[1].push_back(make_pair(3,6));
	G[1].push_back(make_pair(2,2));
	G[2].push_back(make_pair(4,4));
	G[2].push_back(make_pair(5,2));
	G[2].push_back(make_pair(3,7));
	G[3].push_back(make_pair(5,1));
	G[3].push_back(make_pair(4,-1));
	G[4].push_back(make_pair(5,-2));
	bool visited[vertices];
	stack<int> s;
	memset(visited, false, sizeof(bool)*vertices);
	for(int i=0;i<vertices;i++)
	{
		if(!visited[i]) topoSort(i, visited, s);
	}
	int dist[vertices];
	for(int i=0;i<vertices;i++)
	{
		dist[i] = INT_MIN;
	}
	dist[1] = 0;
	while(!s.empty())
	{
		for(int i=0;i<G[s.top()].size();i++)
		{
			if(dist[G[s.top()][i].first]<dist[s.top()]+G[s.top()][i].second)
			{
				dist[G[s.top()][i].first]=dist[s.top()]+G[s.top()][i].second;
			}
		}
		s.pop();
	}
	for(int i=0;i<vertices;i++) cout<<dist[i]<<" ";
	return 0;
}