#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod=1e9+7;

int binpow(int a,int b){
    if(b==0)
        return 1;
    int res=binpow(a,b/2);
    if(b%2)
        return (a%mod * res%mod * res%mod) % mod;
    return (res%mod * res%mod) % mod;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    // prefix sum array
    vector<int> pfs = a;
    for(int i=1;i<n;++i)
        pfs[i] += pfs[i-1];
    
    int sum=0;
    for(int i=0;i<n-1;++i){
        int x = a[i] % mod;
        int y = (pfs.back() - pfs[i]) % mod;
        sum = (sum + ((x%mod * y%mod) % mod)) % mod;
    }

    int cnt=(n*(n-1)) / 2;
    int bp=binpow(cnt, mod-2);
    cout<<((sum%mod) * (bp%mod)%mod)<<endl;
    return;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}