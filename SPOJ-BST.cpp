#include <bits/stdc++.h>
using namespace std;
map<int, long long> m;
int main()
{
	int n,z,root;
	long long ans=0, val=0;
	scanf("%d", &n);
	while(n--)
	{
		int left=0,right=0;
		scanf("%d", &z);
		m[z] = 0;
		if(m.size()==1)
		{
			root = z;
			printf("%d\n", 0);
			continue;
		}
		map<int, long long>::iterator it = m.find(z);
		map<int, long long>::iterator itCopy = it;
		if(z>root)
		{
			if(++it != m.end())
				right = it->second;
			left = (--itCopy)->second;
		}
		else
		{
			right = (++it)->second;
			if(itCopy!=m.begin())
				left = (--itCopy)->second;
		}
		val = max(right, left);
		val++;
		ans+=val;
		m[z] = val;
		printf("%lld\n",ans);
	}
	return 0;
}