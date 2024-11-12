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
    // auto calc=[&](double bmx)->double{
    //     return bmx * n + min((double)bmx / 2, (double)a.front()) * n;
    // };
    auto check=[&](double x)->bool{
        for(int i=0;i<n;++i)
            if(x>a[i] || 2*x>a[i+n])
                return false;
        if(3 * n * x > w)
            return false;
        return true;
    };

    // using binary search to find the maximum bmx
    /// the problem is some of the cases are invalid
    /// the right bound should be a[0] * 2
    double left=0, right=w;
    for(int i=0;i<100;++i){
        double mid=(left + right) / 2;
        if(!check(mid))
            right = mid;
        else
            left = mid;
    }

    cout<<3 * n * left<<endl;
    return 0;
}

/**
 * it's obviously better to give the larger cups to boys and smaller cups to girls.
 * in that case that water poured to boys will not be limited, which is the upper bound for girls
 * oh, i forgot the w...
 */