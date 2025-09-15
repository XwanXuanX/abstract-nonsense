#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    if (nums.size() < 3)
      return 0;
    vector<int> adj;
    for (int i = 1; i < nums.size(); ++i)
      adj.push_back(nums[i] - nums[i-1]);
    // Now partition the array
    vector<pair<int,int>> seg;
    int start = 0;
    for (int i = 1; i < adj.size(); ++i)
      if (adj[i] != adj[i-1]) {
        seg.push_back(make_pair(start, i-1));
        start = i;
      }
    seg.push_back(make_pair(start, adj.size() - 1));
    // Now count the answer
    int ans = 0;
    for (auto [l, r] : seg) {
      int len = r - l + 2;
      ans += ((len - 1) * (len - 2)) / 2;
    }
    return ans;
  }
};
// @lc code=end
