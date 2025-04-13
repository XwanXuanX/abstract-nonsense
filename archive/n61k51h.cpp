#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1000000007;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin>>n>>k;

    vector<vector<int>> dp(k+1, vector<int>(n+1, 0));
    // at the last position, whatever the number is, only one option
    for (int i=1; i<=n; ++i) {
        dp[k][i] = 1;
    }

    // now for the previous pos, accumulate the answer
    for (int j=k-1; j>=1; --j) {
        for (int i=1; i<=n; ++i) {
            int acc = 0;
            for (int b=i; b<=n; b+=i) {
                acc = (acc + dp[j+1][b]) % mod;
            }
            dp[j][i] = acc;
        }
    }

    int ans = 0;
    for (int i=1; i<=n; ++i) {
        ans = (ans + dp[1][i]) % mod;
    }

    cout<<ans<<'\n';
    return 0;
}

/**
 * we need to find the number of numbers that are a multiple of another:
 * 1: 1, 2, 3, 4
 * 2: 2, 4
 * 3: 3
 * 4: 4
 * if the current is 4, only 1 option (4, 4, 4, ...
 * if the current is 3, only 1 option (3, 3, 3, ...
 * if the current is 2, can be (2, 2, 2, 2) or (2, 2, 2, 4) or (2, 2, 4, 4) or (2, 4, 4, 4), or (4, 4, 4, 4)
 * if the current is 1, we have far more options
 * thus this is clearly a dp problem
 */