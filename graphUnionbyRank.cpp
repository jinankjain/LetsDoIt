#include <bits/stdc++.h>
using namespace std;
const int vertices = 3;
vector< pair<int, int> > Graph;

struct subset
{
	int parent;
	int rank;
};

vector<struct subset> S;

int findParent(int x)
{
	if(S[x].parent!=x) S[x].parent = findParent(S[x].parent);
	return S[x].parent;
}

void unionSet(int x, int y)
{
	int xset = findParent(x);
	int yset = findParent(y);
	if(S[xset].rank>S[yset].rank)
		S[yset].parent = xset;
	else if(S[xset].rank<S[yset].rank)
		S[xset].parent = yset;
	else
	{
		S[xset].parent = yset;
		S[yset].rank++;
	}
}

bool isCycle()
{
	for(int i=0;i<vertices;i++)
	{
		struct subset t = {i,0};
		S.push_back(t);
	}
	for(int i=0;i<Graph.size();i++)
	{
		int x = findParent(Graph[i].first);
		int y = findParent(Graph[i].second);
		if(x==y) return 1;
		unionSet(x,y);
	}
	return 0;
}

int main()
{
	Graph.push_back(make_pair(0,1));
	Graph.push_back(make_pair(1,2));
	Graph.push_back(make_pair(0,2));
	cout<<isCycle()<<endl;
	return 0;
}