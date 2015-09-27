#include <bits/stdc++.h>
using namespace std;
const int vertices = 6;
bool bfs(vector<pair<int, int> > rG[], int s, int t, int parent[])
{
    bool visited[vertices];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0;i<rG[u].size();i++)
        {
            if(visited[rG[u][i].first]==false && rG[u][i].second > 0)
            {
                q.push(rG[u][i].first);
                parent[rG[u][i].first] = u;
                visited[rG[u][i].first] = true;
            }
        }
    }

    return (visited[t] == true);
}
int fordFulkerson(vector<pair<int, int> > G[], int s, int t)
{
    int u,v;
    vector<pair<int, int> > rG[vertices];
    for(u=0;u<vertices;u++)
    {
        rG[u] = G[u];
    }
    
    int parent[vertices];
    int max_flow;
    while(bfs(rG, s, t, parent))
    {
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rG[u][v].second);
        }
        cout<<path_flow
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rG[u][v].second -= path_flow;
            rG[v][u].second += path_flow;
        }
 
        max_flow += path_flow;
    }
    return max_flow;
}
int main()
{
    /* code */
    vector< pair<int,int> > G[vertices];
    G[0].push_back(make_pair(1,16));
    G[0].push_back(make_pair(2,13));
    G[1].push_back(make_pair(2,10));
    G[1].push_back(make_pair(3,12));
    G[2].push_back(make_pair(1,4));
    G[2].push_back(make_pair(1,4));
    G[2].push_back(make_pair(4,14));
    G[3].push_back(make_pair(2,9));
    G[3].push_back(make_pair(5,20));    
    G[4].push_back(make_pair(3,7)); 
    G[4].push_back(make_pair(5,4)); 
    cout<<fordFulkerson(G,0,5)<<endl;
    return 0;
}