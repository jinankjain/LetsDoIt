#include <bits/stdc++.h>
using namespace std;
const int vertices = 4;
const int edges = 5;

// (Weight , (Vertex, Vertex))
set< pair<int, pair<int, int> > > Graph; 

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

void kruskal()
{
	int e = 0;
	createSet();
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
			cout<<temp.second.first<<" "<<temp.second.second<<" "<< temp.first<<endl;
			e++;
		}
	}
}

int main()
{
	Graph.insert(make_pair(10, make_pair(0,1)));
	Graph.insert(make_pair(6, make_pair(0,2)));
	Graph.insert(make_pair(5, make_pair(0,3)));
	Graph.insert(make_pair(15, make_pair(1,3)));
	Graph.insert(make_pair(4, make_pair(2,3)));
	kruskal();
	return 0;
}