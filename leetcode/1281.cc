#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        s.insert(s.begin(), 0);
        const int n = s.size();
        for (int i = 1; i < n; ++i) {
            s[i] = s[i] - 'a';
        }
        vector<vector<int>> dp(26, vector<int>(n, 0));
        for (int i = 1; i < n; ++i) {
            dp[s[i]][i] += 1;
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] += dp[i][j - 1];
            }
        }
        vector<bool> ans;
        for (const auto& q : queries) {
            const int l = q[0], r = q[1] + 1, k = q[2];
            int odd = 0;
            for (int i = 0; i < 26; ++i) {
                const int cnt = dp[i][r] - dp[i][l];
                if (cnt % 2) {
                    odd += 1;
                }
            }
            ans.push_back(odd / 2 <= k);
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)