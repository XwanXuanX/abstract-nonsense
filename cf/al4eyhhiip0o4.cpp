#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b,k;
    cin>>a>>b>>k;

    // generate all the primes
    vector<int> prime(b+1, 1);
    prime[0] = prime[1] = 0;
    for(int p=2;p*p<=b;++p){
        if(prime[p]){
            for(int i=p*p;i<=b;i+=p)
                prime[i]=0;
        }
    }

    for(int i=2;i<prime.size();++i)
        prime[i] += prime[i-1];
    
    auto check=[&](int l)->bool{
        for(int x=a; x<=b-l+1; ++x)
            if(prime[x+l-1] - prime[x-1] < k)
                return false;
        return true;
    };

    int left=1, right=b-a+1;
    while(left <= right){
        int mid=(left+right)/2;
        if(check(mid)) // go smaller
            right = mid-1;
        else
            left = mid+1;
    }

    if(left > b-a+1) cout<<-1<<endl;
    else cout<<left<<endl;
    return 0;
}