#include <bits/stdc++.h>
using namespace std;
vector<int> prime;
void sieve(int upperBound)
{
	int upperBoundSquareRoot = (int)sqrt((double)upperBound);
    bool *isComposite = new bool[upperBound + 1];
    memset(isComposite, 0, sizeof(bool) * (upperBound + 1));
    for (int m = 2; m <= upperBoundSquareRoot; m++) {
          if (!isComposite[m]) {
                cout << m << " ";
                for (int k = m * m; k <= upperBound; k += m)
                      isComposite[k] = true;
          }
    }
    for (int m = upperBoundSquareRoot; m <= upperBound; m++)
          if (!isComposite[m])
                prime.push_back(m);
    delete [] isComposite;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin>>t;
	int a,b;
	sieve(10000);
	while(t--)
	{
		cin>>a>>b;
		vector<int> G[10000];

	}
	return 0;
}