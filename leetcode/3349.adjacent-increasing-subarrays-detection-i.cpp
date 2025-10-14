#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=3349 lang=cpp
 *
 * [3349] Adjacent Increasing Subarrays Detection I
 */

// @lc code=start
class Solution {
public:
  int len(pair<int,int> p) {
    return p.second - p.first + 1;
  }

  bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    vector<pair<int,int>> seg;
    int start = 0;
    for (int i = 1; i < n; ++i) {
      if (nums[i] <= nums[i-1]) {
        seg.push_back({start, i-1});
        start = i;
      }
    }
    seg.push_back({start, n-1});
    for (int i = 0; i < seg.size(); ++i) {
      if (seg[i].second - seg[i].first + 1 >= 2 * k) {
        return true;
      }
    }
    for (int i = 1; i < seg.size(); ++i) {
      auto a = seg[i-1], b = seg[i];
      if (a.second + 1 == b.first && len(a) >= k && len(b) >= k) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end

