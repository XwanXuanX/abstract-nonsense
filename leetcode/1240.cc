#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    vector<vector<int>> dp;

    int dfs(const vector<int>& piles, const int i, const int m) {
        const int n = piles.size();
        if (i >= n) {
            return 0;
        }
        if (dp[i][m] != INT_MIN) {
            return dp[i][m];
        }
        int mx = INT_MIN;
        for (int x = 1; x <= 2 * m; ++x) {
            int mine = 0;
            for (int k = i; k < min(i + x, n); ++k) {
                mine += piles[k];
            }
            const int opps = dfs(piles, i + x, min(n, max(m, x)));
            mx = max(mx, mine - opps);
        }
        return dp[i][m] = mx;
    }

    int stoneGameII(vector<int>& piles) {
        const int n = piles.size();
        dp.assign(n, vector<int>(2 * n, INT_MIN));
        const int tot = accumulate(piles.begin(), piles.end(), 0);
        const int ans = dfs(piles, 0, 1);
        return (tot + ans) / 2;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)