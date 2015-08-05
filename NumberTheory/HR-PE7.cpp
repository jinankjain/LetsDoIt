#include <bits/stdc++.h>
using namespace std;
long long arr[200000] = {0};
int main()
{
	long long t;
	long long n;
	vector<long long> prime;
	for (long long i = 2; i < 200000; i++)
    {
       	for (long long j = i * i; j < 200000; j+=i)
       	{
           	arr[j - 1] = 1;
       	}
	}
    for (long long i = 1; i < 200000; i++)
    {
       	if (arr[i - 1] == 0)
           	prime.push_back(i);
    }
	cin>>t;
	while(t--)
	{
		cin>>n;
		
    	
    	cout<<prime[n]<<endl;
	}
	return 0;
}