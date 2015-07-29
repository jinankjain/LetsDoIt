#include <bits/stdc++.h>
using namespace std;
const int vertices = 100100;
vector<int> G[vertices];
int level[vertices] = {0};
int visited[vertices];
void BFS(int s, int lev)
{
	level[s] = lev;
	visited[s] = 1;
	for(int i=0;i<G[s].size();i++)
		if(!visited[G[s][i]]) BFS(G[s][i], lev+1);
}
int main()
{
	int n,t,p;
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
           G[i].clear(),visited[i]=0;
		for(int i=0;i<n-1;i++)
		{
			cin>>t>>p;
			G[t].push_back(p);
			G[p].push_back(t);
		}
		level[0] = 0;
		BFS(0, 0);
		int maxi = 0;
		for(int i=0;i<n;i++)
		{
			if(level[maxi]<level[i])
			{
				maxi = i;
			}
		}
		memset(visited,0,sizeof(visited));
		BFS(maxi, 0);
		int maxii = 0;
		for(int i=0;i<n;i++)
		{
			if(level[maxii]<level[i])
				maxii = i;
		}
		if( level[maxii] & 1 ) cout<< ( level[maxii]>>1 ) + 1 <<endl;
        else cout<< ( level[maxii]>>1 ) <<endl;
	}
	return 0;
}