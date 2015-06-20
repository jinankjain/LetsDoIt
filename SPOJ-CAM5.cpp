#include <bits/stdc++.h>
using namespace std;
const int vertices = 100010;
bool visited[vertices];
void DFS(int s, vector<int> G[])
{
	list<int> queue;
	queue.push_back(s);
	visited[s] = true;
	while(!queue.empty())
	{
		int temp = queue.back();
		queue.pop_back();
		//cout<<temp<<" ";
		for(int i=0;i<G[temp].size();i++)
		{
			if(!visited[G[temp][i]])
			{
				visited[G[temp][i]] = true;
				queue.push_back(G[temp][i]);
			}
		}
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,e,r,s;
		scanf("%d%d", &n, &e);
		for(int i=0;i<n;i++) visited[i] = false;
		vector<int> G[n];
		for(int i=0;i<e;i++)
		{
			scanf("%d%d", &r, &s);
			G[r].push_back(s);
			G[s].push_back(r);
		}
		int ans = 0;
		for(int i=0;i<n;i++)
		{
			if(!visited[i])
			{
				ans++;
				DFS(i, G);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}