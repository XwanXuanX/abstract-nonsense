#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    cin>>s;

    // build prefix sum to query in constant time
    vector<int> pfs(a.begin(), a.end());
    for(int i=1;i<pfs.size();++i)
        pfs[i] += pfs[i-1];

    int sum=0;
    for(int i=0;i<a.size();++i)
        if(s[i] == '1')
            sum += a[i];
    
    int ans=sum;
    if(s[0] == '1')
        sum -= a[0];
    
    for(int i=1;i<n;++i)
        if(s[i] == '1'){
            sum -= a[i];
            ans=max(ans, sum + pfs[i-1]);
        }

    cout<<ans<<endl;
    return 0;
}

/**
 * note that if you turn a one to zero, you are free to add up all the numbers in front of it
 */