#include <bits/stdc++.h>
using namespace std;
int vertices = 4;
const int edges = 5;

// (Weight , (Vertex, Vertex))

struct subset
{
	int parent;
	int rank;
};

vector<subset> V;

int findParent(int x)
{
	if(V[x].parent!=x)
	{
		V[x].parent = findParent(V[x].parent);
	}
	return V[x].parent;
}

void unionSet(int x, int y)
{
	int xroot = findParent(x);
	int yroot = findParent(y);
	if(V[xroot].rank<V[yroot].rank)
	{
		V[xroot].parent = yroot;
	}
	else if(V[xroot].rank>V[yroot].rank)
	{
		V[yroot].parent = xroot;
	}
	else
	{
		V[xroot].parent = yroot;
		V[yroot].rank++;
	}
}

void createSet()
{
	for(int i=0;i<vertices;i++)
	{
		subset t = {i,0};
		V.push_back(t);
	}
}

long long kruskal(set< pair<int, pair<int, int> > > Graph)
{
	int e = 0;
	createSet();
	long long w = 0;
	while(e<(vertices-1))
	{
		set< pair<int, pair<int, int> > >::iterator it = Graph.begin();
		pair<int, pair<int, int> > temp = *it;
		Graph.erase(it);
		int x = findParent(temp.second.first);
		int y = findParent(temp.second.second);
		if(x!=y)
		{
			unionSet(x,y);
			w+=temp.first;
			e++;
		}
	}
	return w;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		set< pair<int, pair<int, int> > > Graph; 
		string s;
		cin>>vertices;
		V.clear();
		int u,e,wt;
		for(int i=0;i<vertices;i++)
		{
			cin>>s>>e;
			for(int j=0;j<e;j++)
			{
				cin>>u>>wt;
				Graph.insert(make_pair(wt, make_pair(i,u-1)));
			}
		}
		cout<<kruskal(Graph)<<"\n";
	}
	
	return 0;
}