#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
class Solution {
public:
  vector<string> summaryRanges(vector<int>& nums) {
    if (nums.size() == 0) {
      return {};
    }
    vector<pair<int,int>> seg;
    int start = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i-1] + 1) {
        seg.push_back({start, i-1});
        start = i;
      }
    }
    seg.push_back({start, nums.size() - 1});
    vector<string> ans;
    for (auto& p : seg) {
      if (p.first == p.second) {
        ans.push_back(to_string(nums[p.first]));
      } else {
        string s = to_string(nums[p.first]) + "->" + to_string(nums[p.second]);
        ans.push_back(s);
      }
    }
    return ans;
  }
};
// @lc code=end

