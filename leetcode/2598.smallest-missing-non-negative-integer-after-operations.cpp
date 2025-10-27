#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2598 lang=cpp
 *
 * [2598] Smallest Missing Non-negative Integer After Operations
 */

// @lc code=start
class Solution {
public:
  int findSmallestInteger(vector<int>& nums, int value) {
    int n = nums.size();
    unordered_map<int,int> cnt;
    for (int i = 0; i < n; ++i) {
      if (nums[i] > 0) {
        nums[i] %= value;
      } else if (nums[i] < 0) {
        int x = abs(nums[i]) % value;
        nums[i] = (x != 0) ? -x + value : 0;
      }
      assert(nums[i] >= 0);
      cnt[nums[i]]++;
    }
    vector<int> restore;
    for (auto& p : cnt) {
      int cur = p.first;
      for (int i = 0; i < p.second; ++i) {
        restore.push_back(cur);
        cur += value;
      }
    }
    sort(restore.begin(), restore.end());
    for (int i = 0; i < n; ++i) {
      if (i != restore[i]) {
        return i;
      }
    }
    return n;
  }
};
// @lc code=end

