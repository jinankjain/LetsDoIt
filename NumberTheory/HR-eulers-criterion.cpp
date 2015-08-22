#include <bits/stdc++.h>
using namespace std;
long long modulo(long long a,long long b,long long c){
    long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c; // squaring the base
        b /= 2;
    }
    return x%c;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t;
	long long a,p;
	cin>>t;
	while(t--)
	{
		cin>>a>>p;
		if (a==0) cout<<"YES\n";
		else{
		if(p==2)
		{
			if(a==1 || a==0 || a==-1)
			{
				cout<<"YES\n";
			}
			else
			{
				cout<<"NO\n";
			}
		}
		else
		{
			long long ans = modulo(a, (p-1)/2, p);
			if(ans == 1) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	}
	return 0;
}