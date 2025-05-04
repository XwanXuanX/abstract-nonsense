#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int v1,v2,t,d;
    cin>>v1>>v2>>t>>d;

    vector<int> l2r(t,v1), r2l(t,v2), res(t,LLONG_MAX);
    for(int i=0;i<t;++i)
        l2r[i] += (d * i);
    for(int i=t-1;i>=0;--i)
        r2l[i] += (d * (t-i-1));

    for(int i=0;i<t;++i)
        res[i] = min(l2r[i], r2l[i]);
    
    int sum=0;
    for(int i=0;i<t;++i)
        sum += res[i];
    
    cout<<sum<<endl;
    return 0;
}

/**
 * it's clearly more optimal if you increase your speed at the beginning and decrease at the end
 * simulate.
 */