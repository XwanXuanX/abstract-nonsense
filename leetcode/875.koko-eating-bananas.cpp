#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
public:
  bool check(vector<int>& piles, int perh, int h) {
    unsigned long long timeNeed = 0;
    for (int i = 0; i < piles.size(); ++i) {
      timeNeed += (unsigned long long)ceil((double)piles[i] / perh);
    }
    return timeNeed <= h;
  }

  int minEatingSpeed(vector<int>& piles, int h) {
    int ans = INT_MAX;
    int l = 1, r = 1e9;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (check(piles, mid, h)) {
        ans = min(ans, mid);
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return ans;
  }
};
// @lc code=end

