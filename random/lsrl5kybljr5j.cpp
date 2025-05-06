#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> a(3);
    for(int i=0;i<3;++i)
        cin>>a[i];

    // WRONG ATTEMPT!    
    // sort(a.begin(), a.end());
    // cout<<(a[0] + (a[1]-a[0])/3 + (a[2]-a[0])/3)<<endl;

    auto calc=[&](int mix)->int{
        int res=0;
        vector<int> tmp(a.begin(), a.end());
        for(int i=0;i<3;++i){
            if(tmp[i] < mix)
                return LLONG_MIN;
            tmp[i] -= mix;
            res += (tmp[i] / 3);
        }
        return res + mix;
    };

    int ans=LLONG_MIN;
    for(int i=0;i<3;++i)
        ans=max(ans, calc(i));
    
    cout<<ans<<endl;
    return 0;
}