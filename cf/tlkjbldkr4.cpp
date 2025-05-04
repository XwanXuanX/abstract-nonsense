#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int mod = 1e9 + 7;

int count(int x, int y, int z){
    int xm = x % z;
    if(xm != 0) x += (z - xm);
    y -= (y % z);
    if(x > y) return 0;
    return (y - x) / z + 1;
}

int cons(int b, bool upper, int k){
    int n = 0;
    if(upper){
        if(b + 1 == 10) return -1; // cannot use the upper section at all
        n += (b+1);
        for(int i=0;i<k-1;++i) n *= 10;
    }else{
        if(b - 1 < 0) return -1; // cannot use the lower seciton at all
        n += (b-1);
        for(int i=0;i<k-1;++i) n *= 10, n += 9;
    }
    return n;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;
    vector<int> a(n/k), b(n/k);
    for(int i=0;i<n/k;++i) cin>>a[i];
    for(int i=0;i<n/k;++i) cin>>b[i];

    // the upper bound for each block
    int upb = 0;
    for(int i=0;i<k;++i) upb *= 10, upb += 9;

    int ans = 1;
    for(int i=0;i<n/k;++i){
        int tot = 0;
        int up = cons(b[i], true, k);
        if(up != -1) tot += count(up, upb, a[i]);
        int bo = cons(b[i], false, k);
        if(bo != -1) tot += count(0, bo, a[i]);
        ans = ((ans % mod) * (tot % mod)) % mod;
    }
    
    cout<<ans<<endl;
    return 0;
}