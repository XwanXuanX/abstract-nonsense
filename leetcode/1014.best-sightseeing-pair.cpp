#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 */

// @lc code=start
class Solution {
public:
  int maxScoreSightseeingPair(vector<int>& values) {
    int n = values.size();
    int mx = values[0], ans = 0;
    for (int i = 1; i < n; ++i) {
      ans = max(ans, mx + values[i] - i);
      mx = max(mx, values[i] + i);
    }
    return ans;
  }
};
// @lc code=end

