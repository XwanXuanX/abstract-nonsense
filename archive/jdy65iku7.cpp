#include <bits/stdc++.h>
using namespace std;
#define int long long 

constexpr int lim = 1e6;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    
    int mx=0;
    vector<int> dp(lim + 6, 0);
    for(int i=0;i<a.size();++i){
        dp[a[i]]++;
        for(int j=2*a[i]; j<=lim; j+=a[i])
            dp[j] = max(dp[j], dp[a[i]]);
        mx=max(mx, dp[a[i]]);
    }
    
    cout<<mx<<endl;
    return 0;
}

/**
 * obviously this is a dp problem... but how to dp
 * 3 4 6 8 10 18 21 24
 * the inputs are guarenteed in ascending order
 */