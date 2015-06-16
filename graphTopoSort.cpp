#include <bits/stdc++.h>
using namespace std;
const int vertices = 6;
vector<int> G[vertices];
void topoSort(int v, bool* visited, stack<int> &s)
{
	visited[v] = true;
	for(int i=0;i<G[v].size();i++)
	{
		if(!visited[G[v][i]])
		{
			topoSort(G[v][i], visited, s);
		}
	}
	s.push(v);
}
int main()
{
	G[5].push_back(2);
	G[5].push_back(0);
	G[4].push_back(0);
	G[4].push_back(1);
	G[2].push_back(3);
	G[3].push_back(1);
	bool visited[vertices];
	stack<int> s;
	memset(visited, false, sizeof(bool)*vertices);
	for(int i=0;i<vertices;i++)
	{
		if(!visited[i]) topoSort(i, visited, s);
	}
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}