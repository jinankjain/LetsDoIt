#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long n,t,prev,curr,total,b;
    cin>>t;
    while(t--)
    {
        curr = 1;
        prev = 0;
        total=0;
        cin>>n;
        while(true)
       {
            b = curr;
            curr = prev+curr;
            prev = b;
            //cout<<curr<<endl;
            if(curr>n)
                break;
            if(curr%2==0)
                total+=curr;
        }
        cout<<total<<endl;
    }
    return 0;
}
