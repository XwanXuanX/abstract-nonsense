#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - a[j] < 0) {
                break;
            }
            dp[i] = min(dp[i], dp[i - a[j]] + 1);
        }
    }
    if (dp[x] == INT_MAX) {
        cout << -1 << '\n';
    } else {
        cout << dp[x] << '\n';
    }
}