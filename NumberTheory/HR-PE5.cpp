#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(false);
    long long t,n;
    long long ans = 1,temp;
    cin>>t;
    int prime[12] = {2,3,5,7,11,13,17,19,23,29,31,37};
    while(t--)
    {
    	ans = 1;
    	cin>>n;
    	for(int i=0;i<12;i++)
    	{
    		temp = 1;
    		//cout<<temp<<endl;
    		while(temp<n)
    		{
    			temp = temp*prime[i];
    		}
    		if(temp>n) temp = temp/prime[i];
    		cout<<temp<<endl;
    		ans = ans*temp;
    	}
    	cout<<ans<<endl;
    }
	return 0;
}