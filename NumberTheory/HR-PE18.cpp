#include <bits/stdc++.h>
using namespace std;
int maxi = -1;
int sum = 0;
void DFS(int s, vector<int> G[], int color[],map<int , int> hashX, map<int , int> hashY, int has[])
{
	color[s] = 1;
	sum+=hashX[has[s]];
	
	//cout<<G[s].size()<<endl;
	for(int i=0;i<G[s].size();i++)
	{
		if(color[G[s][i]]==0)
		{
			DFS(G[s][i], G, color, hashX,hashY, has);
		}
	}
	if(G[s].size()==0) {maxi = max(maxi,sum);}
	color[s] = 2;
	if(s==1) cout<<maxi<<endl;
	sum-=hashX[has[s]];
}

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n][n];
		for(int i=0;i<n;i++)
		{
			int j=0;
			while(j<i+1)
			{
				cin>>a[i][j];
				j++;
			}
		}
		for(int i=n-2;i>=0;i--)
		{
			for(int j=0;j<i+1;j++)
			{
				a[i][j] = a[i][j] + max(a[i+1][j], a[i+1][j+1]);
			}
		}
		cout<<a[0][0]<<endl;
	}
	return 0;
}