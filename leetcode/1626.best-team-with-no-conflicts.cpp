#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1626 lang=cpp
 *
 * [1626] Best Team With No Conflicts
 */

// @lc code=start
class Solution {
public:
  int bestTeamScore(vector<int> &scores, vector<int> &ages) {
    int n = ages.size();
    vector<pair<int, int>> play;
    for (int i = 0; i < n; ++i) {
      play.push_back({ages[i], scores[i]});
    }
    sort(play.begin(), play.end());
    vector<int> dp(n, 0);
    dp[0] = play[0].second;
    for (int i = 1; i < n; ++i) {
      auto [cur_age, cur_score] = play[i];
      dp[i] = max(dp[i], cur_score);
      for (int j = 0; j < i; ++j) {
        auto [prev_age, prev_score] = play[j];
        if (prev_age < cur_age && prev_score > cur_score) {
          continue;
        }
        dp[i] = max(dp[i], dp[j] + cur_score);
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
// @lc code=end
