#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // bitmask dp
    // each entry represents the result of a SUBSET
    // to add another element to the subset and calculate the new result for the new subset,
    // we can exclude an element x, and transition from state of a subset that does not contain x
    // namely, dp[X - x], where X = the new subset, and X - x = the subset without x
    vector<pair<int,int>> dp(1 << n, {INF, INF});
    dp[0] = make_pair(1, 0);

    // Notice the iteration order!
    // we MUST iterate from smaller subset to larger subset
    // thus when we do a "pull-dp", all the required states have been calculated previously
    for (int msk = 1; msk < (1 << n); ++msk) {
        for (int bit = 0; bit < n; ++bit) {
            if ((1 << bit) & msk) {
                int space_taken = dp[msk ^ (1 << bit)].second;
                if (space_taken + a[bit] <= x) {
                    // we did not exceed one ride limit
                    // append on the space taken
                    dp[msk] = min(
                        dp[msk],
                        make_pair(dp[msk ^ (1 << bit)].first, space_taken + a[bit])
                    );
                } else {
                    // we did exceed one ride limit
                    // append on rides taken
                    dp[msk] = min(
                        dp[msk],
                        make_pair(dp[msk ^ (1 << bit)].first + 1, a[bit])
                    );
                }
            }
        }
    }

    // the answer lies in the full subset
    cout << dp[(1 << n) - 1].first << '\n';
}