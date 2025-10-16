#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=554 lang=cpp
 *
 * [554] Brick Wall
 */

// @lc code=start
class Solution {
public:
  int leastBricks(vector<vector<int>>& wall) {
    int n = wall.size();
    vector<vector<unsigned long long>> dp(n);
    for (unsigned long long i = 0; i < n; ++i) {
      auto& row = wall[i];
      dp[i].resize(row.size());
      dp[i][0] = row[0];
      for (unsigned long long j = 1; j < row.size(); ++j) {
        dp[i][j] += dp[i][j-1] + row[j];
      }
    }
    // dp[i] contains all the slits for each row
    unordered_map<unsigned long long,int> mp;
    for (unsigned long long i = 0; i < n; ++i) {
      for (unsigned long long j = 0; j < dp[i].size() - 1; ++j) {
        mp[dp[i][j]]++;
      }
    }
    int ans = INT_MAX;
    for (auto& p : mp) {
      ans = min(ans, n - p.second);
    }
    if (ans == INT_MAX) {
      return n;
    }
    return ans;
  }
};
// @lc code=end

