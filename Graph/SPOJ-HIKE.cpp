#include <bits/stdc++.h>
using namespace std;
#define piiii pair<int, pair<int, pair<int, int> > >
#define A first
#define B second.first
#define C second.second.first
#define cost second.second.second
#define mp(a,b,c,d) make_pair(a,make_pair(b,make_pair(c,d)))
int n,p1,p2,p3;
char color[51][51];
bool visited[51][51][51];
int bfs()
{
	queue<piiii> temp;
	temp.push(mp(p1,p2,p3,0));
	for(int i=0;i<51;i++)
		for(int j=0;j<51;j++)
			for(int k=0;k<51;k++)
				visited[i][j][k] = false;

	while(!temp.empty())
	{
		piiii q = temp.front();
		temp.pop();
		//cout<<q.A<<" "<<q.B<<" "<<q.C<<endl;
		if(q.A == q.B && q.B == q.C)
			return q.cost;
		if(visited[q.A][q.B][q.C])
			continue;
		visited[q.A][q.B][q.C] = true;
		for(int i=0;i<n;i++)
		{
			if(q.A!=i && color[q.A][i]==color[q.B][q.C])
				temp.push(mp(i,q.B,q.C,q.cost+1));
			if(q.B!=i && color[q.B][i]==color[q.A][q.C])
				temp.push(mp(q.A,i,q.C,q.cost+1));
			if(q.C!=i && color[q.C][i]==color[q.A][q.B])
				temp.push(mp(q.A,q.B,i,q.cost+1));
		}
	}
	return -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(false);
	cin>>n;
	while(n)
	{
		cin>>p1>>p2>>p3;
		p1--;p2--;p3--;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>color[i][j];

		int ans = bfs();
		if(ans==-1) cout<<"impossible\n";
		else cout<<ans<<endl;
		cin>>n;
	}
	return 0;
}
