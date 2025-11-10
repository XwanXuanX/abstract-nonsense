#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1986 lang=cpp
 *
 * [1986] Minimum Number of Work Sessions to Finish the Tasks
 */

// @lc code=start
class Solution {
public:
  // bitmask dp
  // each entry represents the result of a SUBSET
  // to add another element to the subset and calculate the new result for the
  // new subset, we can exclude an element x, and transition from state of a
  // subset that does not contain x namely, dp[X - x], where X = the new subset,
  // and X - x = the subset without x

  template <class T> using V = vector<T>;
  int minSessions(vector<int> &tasks, int sessionTime) {
    constexpr int INF = 1e9;
    int n = tasks.size();
    V<pair<int, int>> dp(1 << n, {INF, INF}); // 2^n subsets/states
    dp[0] = {1, 0}; // dp[i].first = # of rides, dp[i].second = space taken
    for (int msk = 1; msk < (1 << n); ++msk) {
      for (int bit = 0; bit < n; ++bit) {
        if ((1 << bit) & msk) {
          auto [rides, space_taken] = dp[msk ^ (1 << bit)];
          if (space_taken + tasks[bit] <= sessionTime) {
            // We can still fit it in one work session
            dp[msk] = min(dp[msk], {rides, space_taken + tasks[bit]});
          } else {
            // Exceeds, then we need to start a new ride
            dp[msk] = min(dp[msk], {rides + 1, tasks[bit]});
          }
        }
      }
    }
    return dp[(1 << n) - 1].first;
  }
};
// @lc code=end
