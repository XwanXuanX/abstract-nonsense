#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,s;
    cin>>n>>s;
    vector<int> a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];

    auto check=[&](int k)->int{
        // compute the new prices, base on k
        vector<int> pri(n);
        for(int i=0;i<a.size();++i)
            pri[i] = a[i] + k * (i+1);
        sort(pri.begin(), pri.end());
        // we pick the 0-kth items
        int tot=0;
        for(int i=0;i<k;++i)
            tot += pri[i];
        return tot;
    };

    int left=0, right=n; // n is the upper bound
    while(left<=right){
        int mid=(left + right) / 2;
        int tot = check(mid);
        if(tot > s)
            right=mid-1;
        else
            left=mid+1;
    }

    cout<<right<<' '<<check(right)<<endl;
    return 0;
}