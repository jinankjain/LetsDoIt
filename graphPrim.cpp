// The fucking decrease key :(

#include <bits/stdc++.h>
#define MAX 1e8
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long w = 0;
	int V;
	cin>>V;
 	vvii G(V);
 	vector<bool>disc(V,false);
 	vi d(V,MAX);
 	vi par(V,-1);
 	vii edge;
 	int E;
	cin>>E;
 	for(int i=0;i<E;i++)
 	{
 		int u,v,wt;
  		cin>>u;
  		cin>>v;
  		cin>>wt;
  		G[u-1].push_back(make_pair(v-1,wt));
  		G[v-1].push_back(make_pair(u-1,wt));
  	}
  	int s=0;
  	set<ii> Q;
  	for(int i=0;i<V;i++)
  		Q.insert(make_pair(d[i],i));
  	Q.erase(Q.find(make_pair(d[s],s)));
  	d[s]=0;
  	Q.insert(make_pair(d[s],s));
  	while(!Q.empty())
  	{
  		ii top=*Q.begin();
   		Q.erase(Q.begin());
   		int v=top.second;
   		w+=top.first;
   		disc[v]=true;
   		if(v!=s)
   			edge.push_back(make_pair(par[v],v));
   		for(int i=0;i<G[v].size();i++)
   		{
   			if(disc[G[v][i].first]==false)
    		{
    			int v2=G[v][i].first;
				int cost=G[v][i].second;
				if(d[v2]>cost)
				{
					Q.erase(Q.find(make_pair(d[v2],v2)));
  					d[v2]=cost;
  					Q.insert(make_pair(d[v2],v2));
  					par[v2]=v;
  				}
			}

   		}
   }
   cout<<w<<"\n";
	return 0;
}
