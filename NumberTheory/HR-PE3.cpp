#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	long long n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<long long> v;
		long long temp = 2;
		while(n>1)
		{
            
			while(n%temp==0)
			{
                //cout<<temp<<endl;
				v.push_back(temp);
				n = n/temp;
			}
			temp++;
			if(temp*temp>n)
			{
				if (n > 1)
				{	
					v.push_back(n);
            		break;
            	}
			}
		}
        //sort(v.begin(), v.end());
		cout<<v[v.size()-1]<<endl;
	}
	return 0;
}