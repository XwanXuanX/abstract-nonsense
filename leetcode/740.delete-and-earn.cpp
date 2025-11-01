#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution {
public:
  int deleteAndEarn(vector<int> &nums) {
    unordered_map<int, int> cnt;
    for (int x : nums) {
      cnt[x]++;
    }
    vector<int> unq;
    for (auto &p : cnt) {
      unq.push_back(p.first);
    }
    sort(unq.begin(), unq.end());
    int n = unq.size();
    unordered_map<int, int> pos;
    for (int i = 0; i < n; ++i) {
      pos[unq[i]] = i;
    }
    vector<int> dp(n, 0);
    dp[0] = unq[0] * cnt[unq[0]];
    for (int i = 1; i < n; ++i) {
      if (!pos.count(unq[i] - 1)) {
        dp[i] = max(dp[i], dp[i - 1] + unq[i] * cnt[unq[i]]);
      } else {
        assert(pos[unq[i] - 1] == i - 1);
        dp[i] = max(dp[i], max(dp[i - 1], (i - 2 >= 0)
                                              ? unq[i] * cnt[unq[i]] + dp[i - 2]
                                              : unq[i] * cnt[unq[i]]));
      }
    }
    return dp[n - 1];
  }
};
// @lc code=end
