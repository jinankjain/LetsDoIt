// Assuming that graph is connected :P

#include <bits/stdc++.h>
using namespace std;
const int vertices = 100;
vector<int> G[vertices];
void BFS(int s)
{
	list<int> queue;
	queue.push_back(s);
	bool visited[vertices];
	for(int i=0;i<vertices;i++)
	{
		visited[i] = false;
	}
	visited[s] = true;
	while(!queue.empty())
	{
		int temp = queue.front();
		cout<<temp<<" ";
		for(int i=0;i<G[temp].size();i++)
		{
			if(!visited[G[temp][i]])
			{
				visited[G[temp][i]] = true;
				queue.push_back(G[temp][i]);
			}
		}
		queue.pop_front();
	}
}
int main()
{
	G[0].push_back(1);
	G[0].push_back(2);
	G[1].push_back(2);
	G[2].push_back(0);
	G[2].push_back(3);
	G[3].push_back(3);
	cout<<"BFS traversal for the graph is ";
	BFS(2);
	cout<<"\n\n";
	return 0;
}