#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> ac(3, vector<int>(n+1));
    for (int i=0; i<3; ++i) {
        for (int j=1; j<n+1; ++j) {
            cin >> ac[i][j];
        }
    }
    // we use a, b, c to indicate if we have done activities a, b, c
    // the state would be, the max you can get on day d, with the status
    // of those activities
    vector<vector<vector<vector<int>>>> dp(n+1,
        vector<vector<vector<int>>>(2,
            vector<vector<int>>(2, vector<int>(2, 0))));
    for (int i=0; i<n; ++i) {
        for (int a : {0, 1}) {
            for (int b : {0, 1}) {
                for (int c : {0, 1}) {
                    // on day i, we have many choices
                    // if we haven't do a, then do a; same for b and c
                    if (a == 0) {
                        dp[i+1][1][b][c] = max(dp[i+1][1][b][c], dp[i][0][b][c] + ac[0][i+1]);
                    }
                    if (b == 0) {
                        dp[i+1][a][1][c] = max(dp[i+1][a][1][c], dp[i][a][0][c] + ac[1][i+1]);
                    } 
                    if (c == 0) {
                        dp[i+1][a][b][1] = max(dp[i+1][a][b][1], dp[i][a][b][0] + ac[2][i+1]);
                    }
                    // if we've run out of anything to do, simply propogate
                    dp[i+1][a][b][c] = max(dp[i+1][a][b][c], dp[i][a][b][c]);
                }
            }
        }
    }

    cout << dp[n][1][1][1] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}