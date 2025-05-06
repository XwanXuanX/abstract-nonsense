// recursion version 1
namespace {
    #include <bits/stdc++.h>
    using namespace std;

    constexpr int mod = 1e9 + 7;

    // to get the distinct number of ways, that means we need to maintain
    // non-decreasing order in the indices

    int bktk(int i, int sum, vector<int>& a, vector<vector<int>>& dp) {
        if (sum < 0) {
            return 0;
        }
        if (sum == 0) {
            return 1;
        }
        if (dp[i][sum] != -1) {
            return dp[i][sum];
        }
        int ans = 0;
        for (int j = i; j < a.size(); ++j) {
            // note the difference: sum - a[j] and sum - a[i];
            // the dp state should be defined as:
            // dp[i][j] contains the distinct ways to construct j with the last used index i
            ans = (ans + bktk(j, sum - a[j], a, dp)) % mod;
        }
        return dp[i][sum] = ans;
    }

    signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> dp(n+1, vector<int>(x+1, -1));
        int ans = bktk(0, x, a, dp);
        cout << ans << '\n';
    }
}

// recursion version 2
namespace {
    #include <bits/stdc++.h>
    using namespace std;

    constexpr int mod = 1e9 + 7;

    // to get the distinct number of ways, that means we need to maintain
    // non-decreasing order in the indices

    // number of ways to make sum, with first 1 coins
    int bktk(int i, int sum, vector<int>& a, vector<vector<int>>& dp) {
        if (sum < 0 || i < 0) {
            return 0;
        }
        if (sum == 0) {
            return 1;
        }
        if (dp[i][sum] != -1) {
            return dp[i][sum];
        }
        // we can either pick the coin, or not pick the coin
        return dp[i][sum] = (bktk(i - 1, sum, a, dp) + bktk(i, sum - a[i], a, dp)) % mod;
    }

    signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> dp(n+1, vector<int>(x+1, -1));
        int ans = bktk(n - 1, x, a, dp);
        cout << ans << '\n';
    }
}