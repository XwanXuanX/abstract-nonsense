#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1ll<<60)

#ifndef ONLINE_JUDGE
    #include "debug.hpp"
    #define debug(...) do { __VA_ARGS__ } while (0)
#else
    #define debug(...) do {} while (0)
#endif

//claim: a string S is beautiful iff the numebr of zeros in it is even
//proof:
//  prove by strong induction. base case is trivial.
//  suppose this claim holds for all strings shorter than length n. Let S be a string
//  of length n. Then S = AB, where A and B satisfies the claim. Eventually,
//  A and B will reduce to one bit. By the induction hypothesis, there are 4 cases:
//      - z(A), z(B) even => z(S) even, and 11 is beautiful
//      - z(A) even, z(B) odd (or vice versa) => z(S) odd, and 01 (10) not beautiful
//      - z(A), z(B) odd => z(S) even, and 00 is beautiful
//  Q.E.D.
void solve() {
    int n; string T; cin>>n>>T;
    vector<int> pfs(n+1,0);
    for(int i=0; i<n; ++i) {
        if(T[i]=='0')
            pfs[i+1]=1;
    }
    for(int i=1; i<=n; ++i) {
        pfs[i]+=pfs[i-1];
    }
    vector<int> even(n+1,0), odd(n+1,0);
    for(int i=0; i<=n; ++i) {
        if(pfs[i]%2) {
            odd[i]=1;
        } else {
            even[i]=1;
        }
    }
    for(int i=1; i<=n; ++i) {
        even[i]+=even[i-1];
        odd[i]+=odd[i-1];
    }
    int ans=0;
    for(int i=1; i<=n; ++i) {
        if(pfs[i]%2) { // when odd, look at number of odds
            ans += odd[i-1];
        } else {       // when even, look at number of even
            ans += even[i-1];
        }
    }
    cout<<ans<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1; //cin>>T;
    while(T--) solve();
}
