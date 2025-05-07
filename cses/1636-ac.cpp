#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    scanf("%d %d", &n, &x);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }

    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = a[i]; j <= x; ++j) {
            dp[j] = (dp[j] + dp[j - a[i]]) % mod;
        }
    }

    printf("%d\n", dp[x]);
}