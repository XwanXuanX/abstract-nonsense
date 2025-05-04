#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> s(n);
    for(int i=0;i<n;++i)
        cin>>s[i];
    
    // how many single item box can be have
    int single = min(2 * k - n, n);

    int ans=LLONG_MIN;
    for(int i=n-single; i<n; ++i)
        ans=max(ans, s[i]);
    for(int left=0, right=n-single-1; left<=right; left++, right--)
        ans=max(ans, s[left]+s[right]);
    
    cout<<ans<<endl;
    return 0;
}

/**
 * obs:
 * if n = 2*k, then every box must have 2 int, then the best is to put the largest with the smallest
 * if n < 2*k, then some box can only have 1 int.
 * 9 7 = 14 - 9 = 5;
 * 1 2 3 4 |  5 6 7 8 9
 */