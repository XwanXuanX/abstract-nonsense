#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    deque<int> dq(nums.begin(), nums.end());
    while (k--) {
      int back = dq.back();
      dq.pop_back();
      dq.push_front(back);
    }
    nums = vector<int>(dq.begin(), dq.end());
  }
};
// @lc code=end

