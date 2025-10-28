#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1010 lang=cpp
 *
 * [1010] Pairs of Songs With Total Durations Divisible by 60
 */

// @lc code=start
class Solution {
public:
  int numPairsDivisibleBy60(vector<int> &time) {
    int n = time.size();
    int num0 = 0;
    for (int i = 0; i < n; ++i) {
      time[i] %= 60;
      if (time[i] == 0) {
        num0++;
      }
    }
    int ans = 0;
    for (int i = 1; i < num0; ++i) {
      ans += i;
    }
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      int other = 60 - time[i];
      ans += cnt[other];
      cnt[time[i]]++;
    }
    return ans;
  }
};
// @lc code=end
