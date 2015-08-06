#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[20][20];
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			cin>>a[i][j];
		}
	}
	int maxi = 0;
	int i=0,j=0,k=0,l=0;
	for(i=0;i<20;i++)
	{
		j = 0;
		while(j<17)
		{
			maxi =  max(maxi, a[i][j]*a[i][j+1]*a[i][j+2]*a[i][j+3]);
			j++;
		}
	}
	for(i=0;i<20;i++)
	{
		j = 0;
		while(j<17)
		{
			maxi =  max(maxi, a[j][i]*a[j+1][i]*a[j+2][i]*a[j+3][i]);
			j++;
		}
	}
	for(i=0;i<17;i++)
	{
		for(j=0;j<17;j++)
		{
			k=i;
			l=j;
			while(k<17 && l<17)
			{
				maxi = max(maxi,a[k][l]*a[k+1][l+1]*a[k+2][l+2]*a[k+3][l+3]);
				k++;l++;
			}
		}
	}
	for(i=0;i<17;i++)
	{
		for(j=19;j>2;j--)
		{
			k=i;
			l=j;
			while(k<17 && l>2)
			{
				//cout<<a[k][l]<<" "<<a[k+1][l-1]<<" "<<a[k+2][l-2]<<" "<<a[k+3][l-3]<<endl;
				maxi = max(maxi,a[k][l]*a[k+1][l-1]*a[k+2][l-2]*a[k+3][l-3]);
				k++;l--;
			}
		}
	}
	cout<<maxi<<endl;
	return 0;
}