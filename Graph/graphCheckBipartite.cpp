#include <bits/stdc++.h>
using namespace std;
const int vertices = 100;
vector<int> G[vertices];
bool isBipartite()
{
	int color[vertices];
	memset(color, -1, sizeof(int)*vertices);
	queue<int> q;
	q.push(0);
	color[0] = 1;
	while(!q.empty())
	{
		int temp = q.front();
		q.pop();
		for(int i=0;i<G[temp].size();i++)
		{
			if(color[G[temp][i]]==-1)
			{
				color[G[temp][i]] = 1 - color[temp];
				q.push(G[temp][i]);
			}
			else if(color[G[temp][i]]==color[temp])
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	G[0].push_back(3);
	G[3].push_back(0);
	G[1].push_back(3);
	G[3].push_back(1);
	G[0].push_back(4);
	G[4].push_back(0);
	G[0].push_back(1);
	G[1].push_back(0);
	cout<<isBipartite();
	return 0;
}