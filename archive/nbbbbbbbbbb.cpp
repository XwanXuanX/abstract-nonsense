#include <bits/stdc++.h>
using namespace std;
#define int long long

int count(int x, int y, int z){
    int xm = x % z;
    if(xm != 0) x += (z - xm);
    y -= (y % z);
    if(x > y) return 0;
    return (y - x) / z + 1;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b,p,q; cin>>n>>a>>b>>p>>q;
    int common = count(1, n, lcm(a, b));
    int ca = count(1, n, a), cb = count(1, n, b);
    int ans = (ca - common) * p + (cb - common) * q + common * max(p,q);
    cout<<ans<<endl;
}

/**
 * suppose we can find the numbers that are multiple of a or b, we don't want to miss any oppotunity
 * thus we greedily add up all the p/qs. for numbers that are a multiple of both a and b we need max(p,q)
 */