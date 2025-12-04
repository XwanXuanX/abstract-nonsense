#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    /*
     * Aka: Find the longest common substring in initial and target
     */
    int minOperations(string initial, string target) {
        const int n = initial.size(), m = target.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int lcs = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (initial[i - 1] == target[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    lcs = max(lcs, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return n + m - 2 * lcs;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)