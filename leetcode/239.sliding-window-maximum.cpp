#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int n = nums.size();
    map<int, int> s;
    vector<int> ans;
    for (int i = 0; i < k; ++i) {
      s[nums[i]]++;
    }
    ans.push_back(s.rbegin()->first);
    for (int l = 1, r = k; r < n; ++r, ++l) {
      s[nums[l - 1]]--;
      if (s[nums[l - 1]] == 0) {
        s.erase(nums[l - 1]);
      }
      s[nums[r]]++;
      ans.push_back(s.rbegin()->first);
    }
    return ans;
  }
};
// @lc code=end
