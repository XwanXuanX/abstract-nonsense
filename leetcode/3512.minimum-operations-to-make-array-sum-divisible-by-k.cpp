#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=3512 lang=cpp
 *
 * [3512] Minimum Operations to Make Array Sum Divisible by K
 */

// @lc code=start
class Solution {
public:
  int minOperations(vector<int> &nums, int k) {
    return accumulate(nums.begin(), nums.end(), 0) % k;
  }
};
// @lc code=end
