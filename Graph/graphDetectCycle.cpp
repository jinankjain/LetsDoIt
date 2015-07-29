// Detect Cycle in Directed Graph

#include <bits/stdc++.h>
using namespace std;
const int vertices = 100;
vector<int> G[vertices];
bool detectCycle()
{
	bool hasCycle = false;
	list<int> stack;
	stack.push_back(0);
	bool visited[vertices];
	memset(visited, false, sizeof(visited));
	while(!stack.empty())
	{
		int temp = stack.back();
		stack.pop_back();
		for(int i=0;i<G[temp].size();i++)
		{
			if(visited[G[temp][i]])
			{
				hasCycle = true;
			}
			else
			{
				stack.push_back(G[temp][i]);
				visited[G[temp][i]] = true;
			}
		}
	}
	return hasCycle;
}

// Detect Cycle in Directed Graph
bool detectCycleUndirected()
{
	bool hasCycle = false;
	int predecessor[vertices];
	memset(predecessor, -1, sizeof(int)*vertices);
	int state[vertices];
	memset(state, 0, sizeof(int)*vertices);
	list<int> stack;
	stack.push_back(0);
	state[0] = 1;
	while(!stack.empty())
	{
		int temp = stack.back();
		stack.pop_back();
		for(int i=0;i<G[temp].size();i++)
		{
			if(state[G[temp][i]]==1 && predecessor[temp]!=G[temp][i])
				hasCycle = true;
			if(state[G[temp][i]]==0)
			{
				stack.push_back(G[temp][i]);
				predecessor[G[temp][i]] = temp;
				state[G[temp][i]] = 1;
			}
		}
	}
	return hasCycle;
}

int main()
{
	G[0].push_back(1);
	G[1].push_back(0);
	G[1].push_back(2);
	G[2].push_back(1);
	G[2].push_back(0);
	G[0].push_back(2);
	
	cout<<detectCycleUndirected()<<endl;
	return 0;
}