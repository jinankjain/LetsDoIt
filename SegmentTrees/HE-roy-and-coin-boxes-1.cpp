#include <bits/stdc++.h>

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define each(it,o) for(auto it= (o).begin(); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define inrep int t;cin>>t; while(t--)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii > vpii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll > vpll;
typedef vector<string> vs;
typedef long double ld;

int segTree[4*1000017] = {0};

void update(int node, int s, int e, int l, int r, int val)
{
	if(l<=s && e<=r)
	{
		segTree[node]+=val;
		return;
	}
	int mid = (s+e)/2;
	if(l<=mid) update(2*node, s, mid, l, r, val);
	if(r>mid) update(2*node+1, mid+1, e, l, r ,val);
}

int query(int node, int s, int e, int pos)
{
	int val = segTree[node];
	if(e==s) return val;
	int mid = (s+e)/2;
	if(pos<=mid) val+=query(2*node, s, mid, pos);
	else if(pos>mid) val+=query(2*node+1, mid+1, e, pos);
	return val;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int m,l,r;
	cin>>m;
	rep(i,m)
	{
		cin>>l>>r;
		update(1, 0, n-1, l-1, r-1, 1);
	}
	vll curr(m+1);
	rep(i,n)
	{
		int val = query(1,0,n-1,i);
		curr[val]++;
	}
	ll last = 0 ;
	for(int i=m;i>=0;i--)
	{
		//cout<<curr[i]<<endl;
		last = curr[i] = curr[i]+last;
	}
	int q,pos;
	cin>>q;
	vll res;
	while(q--)
	{
		cin>>pos;
		res.push_back(curr[min(pos,m)]);
	}
	rep ( i,m ) cout<<res[i]<<"\n";
	return 0;
}