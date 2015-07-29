#include <bits/stdc++.h>
using namespace std;
const int vertices=3;
vector< pair<int, int> > Graph;
int parent[vertices];
int findParent(int x)
{
	if(parent[x]==-1)
		return x;
	return findParent(parent[x]);
}
void unionSet(int x, int y)
{
	int xset = findParent(x);
	int yset = findParent(y);
	parent[xset] = yset;
}
bool isCycle()
{
	for(int i=0;i<Graph.size();i++)
	{
		int x = findParent(Graph[i].first);
		int y = findParent(Graph[i].second);
		if(x==y) return 1;
		unionSet(x,y);
	}
	return 0;
}
int main()
{
	Graph.push_back(make_pair(0,1));
	Graph.push_back(make_pair(1,2));
	Graph.push_back(make_pair(0,2));
	memset(parent, -1, sizeof(int)*vertices);
	cout<<isCycle()<<endl;
	return 0;
}