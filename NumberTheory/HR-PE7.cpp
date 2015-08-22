#include <bits/stdc++.h>
using namespace std;
long long arr[200000] = {0};
int main()
{
	long long t;
	long long n;
	vector<long long> prime;
	for (long long i = 2; i*i < 200000; i++)
    {
       	if(arr[i]==0)
       	{
       		for (long long j = i * i; j < 200000; j+=i)
       		{
        	   	arr[j - 1] = 1;
       		}
       	}
	}
    for (long long i = 1; i < 200000; i++)
    {
       	if (arr[i - 1] == 0 && i!=1)
           	prime.push_back(i);
    }
    //prime.pop_front();
    for(int i=0;i<prime.size();i++) cout<<prime[i]<<endl;
	cin>>t;
	while(t--)
	{
		cin>>n;
		
    	
    	cout<<prime[n]<<endl;
	}
	return 0;
}