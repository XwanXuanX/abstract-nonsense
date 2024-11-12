#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,w;
    cin>>n>>w;
    vector<int> a(2*n);
    for(int i=0;i<2*n;++i)
        cin>>a[i];

    sort(a.begin(), a.end());
    
    double bmx = (double)a[n];
    auto calc=[&](double bmx)->double{
        return bmx * n + min((double)bmx / 2, (double)a.front()) * n;
    };

    // using binary search to find the maximum bmx
    /// the problem is some of the cases are invalid
    /// the right bound should be a[0] * 2
    double left=0, right=min(bmx, (double)a[0] * 2);
    double ans=0;
    while(left <= right){
        double mid=(left + right) / 2;
        double tot=calc(mid);
        if(tot > w)
            right = mid - 0.000000001;
        else
            left = mid + 0.000000001, ans=max(ans, tot);
    }

    cout<<ans<<endl;
    return 0;
}

/**
 * it's obviously better to give the larger cups to boys and smaller cups to girls.
 * in that case that water poured to boys will not be limited, which is the upper bound for girls
 * oh, i forgot the w...
 */