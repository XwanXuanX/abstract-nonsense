#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];

    // check if you can sort the array using only x number of operations
    // we can make the first x and the last n-x+1 sorted for sure!
    auto check=[&](int x)->bool{
        vector<int> ca;
        // head
        for(int i=1;i<=x;++i)
            ca.push_back(i);
        // middle
        for(int i=0;i<n;++i)
            if(a[i]>x && a[i]<n-x+1)
                ca.push_back(a[i]);
        // bottom
        for(int i=n-x+1;i<=n;++i)
            ca.push_back(i);

        if(is_sorted(ca.begin(), ca.end()))
            return true;
        return false;
    };

    // the maximum operation needed is n/2
    int left=0, right=n/2;
    while(left<=right){
        int mid=(left + right) / 2;
        if(check(mid))
            right=mid-1;
        else
            left=mid+1;
    }

    cout<<left<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}