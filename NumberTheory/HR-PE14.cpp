#include <bits/stdc++.h>
using namespace std;
long long a[5000017];
int lookup[5000017] = { 0 };

unsigned long long NextNumber(unsigned long long value) {
  if ((value % 2) == 0) value >>= 1;
  else value = (value * 3) + 1;
  return value;
}

int main()
{
	long long i = 0;
  	long long chainlength = 0;
  	long long longest = 0;
  	long long longestchain = 0;
  	unsigned long long value = 0;
  	for (i = 1; i < 5000017; ++i) {
  	  chainlength = 0;
  	  value = i;
  	  while (value != 1) {
  	    ++chainlength;
  	    value = NextNumber(value);
  	    if (value >= 5000017) continue;
  	    if (lookup[value] != 0) {
  	      chainlength += lookup[value];
  	      break;
  	    }
  	  }
  	  lookup[i] = chainlength;
  	  a[i] = longest;
  	  if (longestchain <= chainlength) {
  	    longest = i;
  	    longestchain = chainlength;
  	    a[i] = longest;
  	  }
  	}
	int t;
	cin>>t;
	unsigned long long n;
	while(t--)
	{
		cin>>n;
		cout<<a[n]<<endl;
	}
	return 0;
}