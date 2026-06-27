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

void solve() {
    vector<vector<int>> dp(105, vector<int>(105, INF));
    string t;
    cin >> t;
    int tl=t.size();
    int n;
    cin >> n;
    dp[0][0]=0;
    for(int i=1; i<=n; ++i) {
        for(int j=0; j<105; ++j) {
            dp[i][j]=dp[i-1][j];
        }
        int a;
        cin >> a;
        while(a--) {
            string s;
            cin >> s;
            int sl=s.size();
            for(int j=0; j+sl<=tl; ++j) {
                bool ok=true;
                for(int k=0; k<sl; ++k) {
                    if(t[j+k]!=s[k]) {
                        ok=false;
                        break;
                    }
                }
                if(ok) {
                    dp[i][j+sl]=min(dp[i][j+sl],dp[i-1][j]+1);
                }
            }
        }
    }
    cout << (dp[n][tl]==INF ? -1 : dp[n][tl]) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1; //cin>>T;
    while(T--) solve();
}
