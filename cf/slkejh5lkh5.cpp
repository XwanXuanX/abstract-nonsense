#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> w(n);
    int mx=0;
    for(int i=0;i<n;++i)
        cin>>w[i], mx=max(mx, w[i]);
    
    vector<int> cnt(mx+1, 0);
    for(int i=0;i<n;++i)
        cnt[w[i]]++;

    for(int i=1;i<=mx;++i)
        if(cnt[i-1] >= 2){
            cnt[i] += (cnt[i-1] / 2);
            cnt[i-1] = cnt[i-1] % 2;
        }
    
    int ans=0;
    for(int i=0;i<cnt.size();++i)
        ans += __builtin_popcount((unsigned long long)cnt[i]);

    cout<<ans<<endl;
    return 0;
}

/**
 * 1 1 2 3 3
 * 1 : 0
 * 2 : 0
 * 3 : 3 = 2 + 1
 * if 5 -> 4 + 1
 * 
 * 0 : 0
 * 1 : 1
 * 19 : 1
 * 688 : 1 (5)
 * 689 : 0
 * 670 : 1 (1) in power of 2
 * 
 * for all the cnt, count the number of power of 2
 */