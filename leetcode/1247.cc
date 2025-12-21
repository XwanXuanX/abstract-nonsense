#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        const int n = nums.size();
        int ans = 1e9;
        {
            vector<vector<int>> dp(n, vector<int>(1001, 1e9));
            for (int j = 0; j <= nums[0]; ++j) {
                dp[0][j] = nums[0] - j;
            }
            // Type 1
            for (int i = 1; i < n; ++i) {
                vector<int> mnl(1001, 1e9), mnr(1001, 1e9);
                mnl[0] = min(mnl[0], dp[i - 1][0]);
                mnr[1000] = min(mnr[1000], dp[i - 1][1000]);
                for (int j = 1; j <= 1000; ++j) {
                    mnl[j] = min({mnl[j], mnl[j - 1], dp[i - 1][j]});
                }
                for (int j = 999; j >= 0; --j) {
                    mnr[j] = min({mnr[j], mnr[j + 1], dp[i - 1][j]});
                }
                for (int j = 0; j <= nums[i]; ++j) {
                    int mn = 1e9;
                    if (i % 2) {
                        mn = min(mn, j > 0 ? mnl[j - 1] : static_cast<int>(1e9));
                    } else {
                        mn = min(mn, j < 1000 ? mnr[j + 1] : static_cast<int>(1e9));
                    }
                    dp[i][j] = mn + nums[i] - j;
                }
            }
            for (int j = 0; j <= 1000; ++j) {
                ans = min(ans, dp[n - 1][j]);
            }
        }
        {
            vector<vector<int>> dp(n, vector<int>(1001, 1e9));
            for (int j = 0; j <= nums[0]; ++j) {
                dp[0][j] = nums[0] - j;
            }
            // Type 1
            for (int i = 1; i < n; ++i) {
                vector<int> mnl(1001, 1e9), mnr(1001, 1e9);
                mnl[0] = min(mnl[0], dp[i - 1][0]);
                mnr[1000] = min(mnr[1000], dp[i - 1][1000]);
                for (int j = 1; j <= 1000; ++j) {
                    mnl[j] = min({mnl[j], mnl[j - 1], dp[i - 1][j]});
                }
                for (int j = 999; j >= 0; --j) {
                    mnr[j] = min({mnr[j], mnr[j + 1], dp[i - 1][j]});
                }
                for (int j = 0; j <= nums[i]; ++j) {
                    int mn = 1e9;
                    if (i % 2) {
                        mn = min(mn, j < 1000 ? mnr[j + 1] : static_cast<int>(1e9));
                    } else {
                        mn = min(mn, j > 0 ? mnl[j - 1] : static_cast<int>(1e9));
                    }
                    dp[i][j] = mn + nums[i] - j;
                }
            }
            for (int j = 0; j <= 1000; ++j) {
                ans = min(ans, dp[n - 1][j]);
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)