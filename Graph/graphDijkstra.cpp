#include <bits/stdc++.h>
using namespace std;

// Graph details
const int v = 9;
vector< pair<int, int> > G[v];
set< pair<int,int> > pq;
int d[v];

void dijkstra(int s)
{
	for(int i=0;i<v;i++) d[i]=100000;
	int u;
	d[s] = 0;
	pq.insert(make_pair(d[s], s));
	
	while(!pq.empty())
	{
		set< pair<int, int> >::iterator top = pq.begin();
		u = (*top).second;
		pq.erase(top);
		for(int i=0;i<G[u].size();i++)
		{
			int next = G[u][i].first;
			int wt = G[u][i].second;
			if(d[next]>d[u]+wt)
			{
				if(d[next]!=100000)
            	{
                	pq.erase(pq.find(pair<int,int>(d[next],next)));
            	}
            	d[next]=d[u]+wt;
            	//cout<<d[next]<<endl;
            	pq.insert(pair<int,int>(d[next],next));
			}
		}
	}
}

int main()
{
	G[0].push_back(make_pair(1, 4));
    G[0].push_back(make_pair(7, 8));
    G[1].push_back(make_pair(2, 8));
    G[1].push_back(make_pair(7, 11));
    G[2].push_back(make_pair(3, 7));
    G[2].push_back(make_pair(8, 2));
    G[2].push_back(make_pair(5, 4));
    G[3].push_back(make_pair(4, 9));
    G[3].push_back(make_pair(5, 14));
    G[4].push_back(make_pair(5, 10));
    G[5].push_back(make_pair(6, 2));
    G[6].push_back(make_pair(7, 1));
    G[6].push_back(make_pair(8, 6));
    G[7].push_back(make_pair(8, 7));

    G[1].push_back(make_pair(0,4));
    G[7].push_back(make_pair(0,8));
    G[2].push_back(make_pair(1,8));
    G[7].push_back(make_pair(1,11));
    G[3].push_back(make_pair(2,7));
    G[8].push_back(make_pair(2,2));
    G[5].push_back(make_pair(2,4));
    G[4].push_back(make_pair(3,9));
    G[5].push_back(make_pair(3,14));
    G[5].push_back(make_pair(4,10));
    G[6].push_back(make_pair(5,2));
    G[7].push_back(make_pair(6,1));
    G[8].push_back(make_pair(6,6));
    G[8].push_back(make_pair(7,7));
    
    dijkstra(0);

    for(int i=0;i<v;i++) cout<< d[i] <<" ";

	return 0;
}