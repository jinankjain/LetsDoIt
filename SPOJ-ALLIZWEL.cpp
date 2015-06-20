#include <bits/stdc++.h>
using namespace std;
int T,r,c;
char a[11] = {'A','L','L','I','Z','Z','W','E','L','L','\0'};
bool visited[101][101] = {false};
char G[101][101];
bool ans;
bool dfs(int x, int y, int pos)
{
	if(pos==10) {return ans = true;}
	visited[x][y] = 1;
	if(x-1>=0 && G[x-1][y]==a[pos] && !visited[x-1][y]) {dfs(x-1, y, pos+1);}
	if(y-1>=0 && G[x][y-1]==a[pos] && !visited[x][y-1]){ dfs(x, y-1, pos+1);}
	if(y+1<c && G[x][y+1]==a[pos] && !visited[x][y+1]) { dfs(x, y+1, pos+1);}
	if(x+1<r && G[x+1][y]==a[pos] && !visited[x+1][y]) { dfs(x+1, y, pos+1);}
	if(x-1>=0 && y+1<c && G[x-1][y+1]==a[pos] && !visited[x-1][y+1]) { dfs(x-1, y+1, pos+1);}
	if(x+1<r && y+1<c && G[x+1][y+1]==a[pos] && !visited[x+1][y+1]) { dfs(x+1, y+1, pos+1);}
	if(x+1<r && y-1>=0 && G[x+1][y-1]==a[pos] && !visited[x+1][y-1]) { dfs(x+1, y-1, pos+1);}
	if(x-1>=0 && y-1>=0 && G[x-1][y-1]==a[pos] && !visited[x-1][y-1]) { dfs(x-1, y-1, pos+1);}
	visited[x][y] = 0;
	return false;
}
int main()
{
	cin>>T;
	while(T--)
	{

		cin>>r>>c;
		vector< pair<int, int> > v;
		for(int i=0;i<r;i++)
		{	
			for(int j=0;j<c;j++)
			{
				cin>>G[i][j];
				if(G[i][j]=='A')
				{
					v.push_back(make_pair(i,j));
				}
				visited[i][j] = false;
			}		
		}
		bool fuckYou = false;
		for(int i=0;i<v.size();i++)
		{	
			ans = false;		
			dfs(v[i].first, v[i].second, 1);
			if(ans)
			{
				fuckYou = true;
				break;
			}
		}
		if(fuckYou) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}