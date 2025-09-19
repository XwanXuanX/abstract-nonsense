#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1024 lang=cpp
 *
 * [1024] Video Stitching
 */

// @lc code=start
class Solution {
public:
  int videoStitching(vector<vector<int>>& clips, int time) {
    int INF = 10000;
    vector<int> dp(time + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= time; ++i) {
      for (int o = 0; o < clips.size(); ++o) {
        int st = clips[o][0], ed = clips[o][1];
        if (st <= i && i <= ed) {
          // This means time i can be covered
          // And we need to calculate min number of clips needed
          // To cover 0...i prefix
          dp[i] = min(dp[i], dp[st] + 1);
        }
      }
    }
    if (dp[time] == INF) return -1;
    return dp[time];
  }
};
// @lc code=end

