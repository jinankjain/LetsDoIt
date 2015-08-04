#include <bits/stdc++.h>
using namespace std;
vector<int> G[1002001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    int n,m;
    cin>>m>>n;
    int ver = m*n;
    bool visited[ver];

    string a[m];
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]=='S' && (i+1)<m) {G[i*n+j].push_back((i+1)*n+j);G[(i+1)*n+j].push_back(i*n+j);}
            else if(a[i][j]=='N' && (i-1)>=0) {G[i*n+j].push_back((i-1)*n+j);G[(i-1)*n+j].push_back(i*n+j);}
            else if(a[i][j]=='W' && (j-1)>=0) {G[i*n+j].push_back(i*n+(j-1));G[i*n+(j-1)].push_back(i*n+j);}
            else if(a[i][j]=='E' && (j+1)<n)  {G[i*n+j].push_back(i*n+(j+1));G[i*n+(j+1)].push_back(i*n+j);}
            visited[i*n+j] = false;
        }
    }
    int ans = 0;

    for(int i=0;i<ver;i++)
    {
        if(!visited[i])
        {
            ans++;
            list<int> queue;
            queue.push_back(i);
            visited[i] = true;
            while(!queue.empty())
            {
                int temp = queue.front();
                //cout<<temp<<" ";
                for(int i=0;i<G[temp].size();i++)
                {
                    //cout<<G[temp][i]<<" ";
                    if(!visited[G[temp][i]])
                    {
                        visited[G[temp][i]] = true;
                        queue.push_back(G[temp][i]);
                    }
                }
                queue.pop_front();
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
