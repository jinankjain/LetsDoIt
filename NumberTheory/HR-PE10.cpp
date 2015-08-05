#include <bits/stdc++.h>
using namespace std;
long long arr[1000001] = {0};
int main()
{
	long long t;
	long long n;
	vector<long long> prime;
	for (long long i = 2; i < 1000001; i++)
    {
       	for (long long j = i * i; j < 1000001; j+=i)
       	{
           	arr[j - 1] = 1;
       	}
	}
    for (long long i = 1; i < 1000001; i++)
    {
       	if (arr[i - 1] == 0)
           	prime.push_back(i);
    }
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long sum = 0;
		int i=0;
		while(prime[i]<n)
		{
			sum+=prime[i];
			i++;
		}
    	
    	cout<<sum<<endl;
	}
	return 0;
}