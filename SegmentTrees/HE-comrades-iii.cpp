#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define repi(i,n) for(int (i)=(int)(n);(i)<=0;--(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define each(it,o) for(auto it= (o).begin(); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back((x))
#define mset(m,v) memset(m,v,sizeof(m))
#define inrep int t;cin>>t; while(t--)
#define ff first
#define ss second
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(0);
#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
 
#define sc1(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define sll(x) scanf(" %I64d",&x)
#define s2ll(x,y) scanf(" %I64d%I64d",&x,&y)

#define MOD 1000000007

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii > vpii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll > vpll;
typedef vector<string> vs;
typedef map<int, int> mii;
typedef map<char, int> mci;
typedef long double ld;
typedef unsigned long long ull;

#define N 100005

int inNumber[N]={0};
int outNumber[N]={0};
int dfsNumber;
vector<int> G[N];

void dfs(int node, int parent)
{
	inNumber[node] = ++dfsNumber;
	rep(i,G[node].size())
	{
		if(G[node][i]!=parent)
		{
			dfs(G[node][i], node);
		}
	}
	outNumber[node] = dfsNumber;
}

int segTree[4*N];
int lazy[4*N]={0};

void build(int node, int s, int e)
{
	if(s==e)
	{
		segTree[node] = 1;
		lazy[node] = 0;
		return;
	}
	int mid = (s+e)/2;
	build(2*node, s, mid);
	build(2*node+1, mid+1, e);
	segTree[node] = segTree[2*node]+segTree[2*node+1];	
}

void updateRange(int node, int s, int e, int l, int r, int val)
{
	if(s>e) return;
	int mid = (s+e)/2;
	if(lazy[node])
	{
		if(lazy[node]==1)
			segTree[node] = 0;
		else
			segTree[node] = e-s+1;
		if(s!=e)
		{
			lazy[2*node] = lazy[2*node+1] = lazy[node];
		}
		lazy[node] = 0;
	}
	if(s>r || e<l) return;
	if(l <= s && e <= r)
	{
		if(val==1)
			segTree[node] = 0;
		else
			segTree[node] = e-s+1;
		if(s!=e)
			lazy[2*node] = lazy[2*node+1] = val;
		return;
	}
	updateRange(2*node, s, mid, l, r, val);
	updateRange(2*node+1, mid+1, e, l, r, val);
	segTree[node] = segTree[2*node] + segTree[2*node+1];
}

int queryRange(int node, int s, int e, int l, int r)
{
	if(s > e || s > r || e < l)
        return 0;

    if(lazy[node])
	{
		if(lazy[node]==1)
			segTree[node] = 0;
		else
			segTree[node] = e-s+1;
		if(s!=e)
		{
			lazy[2*node] = lazy[2*node+1] = lazy[node];
		}
		lazy[node] = 0;
	}

	if(l <= s && e <= r)
	{
		return segTree[node];
	}
	int mid = (s+e)/2;
	return queryRange(2*node, s, mid, l, r) + queryRange(2*node+1, mid+1, e, l, r);
}

int main()
{
	fast
	int n;
	cin>>n;
	int root = -1;
	for(int i=1;i<=n;i++)
    {
        int j;
        cin>>j;
        if(j == 0)
            root = i;
        else
            G[j].push_back(i);
    }
    dfs(root,0);
    build(1,1,n);
    int q;
    cin>>q;
    while(q--)
    {
        int op,u;
        cin>>op>>u;
        if(op <= 2)
        {
            updateRange(1,1,n,inNumber[u]+1,outNumber[u],3-op);
        }
        else
        {
            int ans = queryRange(1,1,n,inNumber[u]+1,outNumber[u]);
            cout<<ans<<endl;
        }
    }
	return 0;
}