#include <bits/stdc++.h>
using namespace std;

typedef struct segTree{
	int cntEven;
	int cntOdd;
}segTree;

segTree st[400000];

int a[100017];

void build(int node, int s, int e)
{
	//leaf node
	if(s==e)
	{
		if(a[s]%2) { st[node].cntOdd = 1; st[node].cntEven = 0;}
		else	   { st[node].cntOdd = 0; st[node].cntEven = 1;}
	}
	else
	{
		int mid = (s+e)/2;
		build(2*node, s, mid);
		build(2*node+1, mid+1, e);
		st[node].cntEven = st[2*node].cntEven + st[2*node+1].cntEven;
		st[node].cntOdd = st[2*node].cntOdd + st[2*node+1].cntOdd;
		//cout<<st[2*node].cntEven<<" "<<node<<endl;
	}	
}

void update(int node, int s, int e, int idx, int val)
{
	if(s==e)
	{
		a[idx] = val;
		if(val%2){ st[node].cntOdd = 1; st[node].cntEven = 0; }
		else	 { st[node].cntOdd = 0; st[node].cntEven = 1; }
	}
	else
	{
		int mid = (s + e) / 2;
    	if(s <= idx and idx <= mid)
    	{
    	    update(2*node, s, mid, idx, val);
    	}
    	else
    	{
    	    update(2*node+1, mid+1, e, idx, val);
    	}
    	st[node].cntEven = st[2*node].cntEven + st[2*node+1].cntEven;
		st[node].cntOdd = st[2*node].cntOdd + st[2*node+1].cntOdd;
	}
}

pair<int, int> query(int node, int s, int e, int l, int r)
{
	if(s>e || s>r || e<l)
	{
		pair<int, int> p;
		p = make_pair(0,0);
		return p;
	}

	if(s>=l && e<=r)
	{
		pair<int, int> p;
		p = make_pair(st[node].cntEven,st[node].cntOdd);
		return p;
	}

	int mid = (s+e)/2;
	pair<int,int> p1 = query(2*node, s, mid, l, r);
	pair<int,int> p2 = query(2*node+1, mid+1, e, l, r);
	pair<int, int> p3;
	p3 = make_pair(p1.first+p2.first, p1.second+p2.second);
	return p3;
}

int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>a[i];
	int Q;
	cin>>Q;
	int q,l,r;
	build(1,0,N-1);
	//pair<int, int> t = query(0,0,N-1,1,1);
	//cout<<st[6].cntOdd<<endl;
	for(int i=0;i<Q;i++)
	{
		cin>>q>>l>>r;
		if(q==0) update(1,0,N-1, l-1, r);
		else if(q==1) 
		{
			pair<int, int> t = query(1,0,N-1,l-1,r-1);
			cout<<t.first<<endl;
		}
		else
		{
			pair<int, int> t = query(1,0,N-1,l-1,r-1);
			cout<<t.second<<endl;	
		}

	}
	return 0;
}