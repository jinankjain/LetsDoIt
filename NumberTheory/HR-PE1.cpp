#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t; 
    while(t--){
        long long int n,sum=0;
        cin>>n;
        long long a=n/3,b=n/5,c=n/15;
        if(n%3==0) a--;
        if(n%5==0) b--;
        if(n%15==0) c--;
        sum = (a*(6+(a-1)*3))/2;
        sum+= (b*(10+(b-1)*5))/2;
        sum-=(c*(30+(c-1)*15))/2;
        cout<<sum<<endl;
    }
    return 0;
}
