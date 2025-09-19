#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=638 lang=cpp
 *
 * [638] Shopping Offers
 */
/**
 * This is a backtracking problem, each state would be the
 * needs array
 */

// @lc code=start
class Solution {
public:
  vector<int> price;
  vector<vector<int>> special;
  map<vector<int>, int> dp; // This records the mapping between each
  // Need state and the minimum price needed to go to that state

  bool canUseSpecial(const vector<int>& spe, const vector<int>& needs) {
    for (int i = 0; i < spe.size() - 1; ++i) {
      if (needs[i] < spe[i]) {
        return false;
      }
    }
    return true;
  }

  int backtrack(vector<int> needs) {
    if (dp.contains(needs)) {
      return dp[needs];
    }
    int pr = INT_MAX >> 1;
    for (auto& spe : special) {
      if (canUseSpecial(spe, needs)) {
        for (int i = 0; i < spe.size() - 1; ++i) needs[i] -= spe[i];
        pr = min(pr, spe[spe.size() - 1] + backtrack(needs));
        for (int i = 0; i < spe.size() - 1; ++i) needs[i] += spe[i];
      }
    }
    for (int i = 0; i < needs.size(); ++i) {
      if (needs[i] > 0) {
        needs[i]--;
        pr = min(pr, price[i] + backtrack(needs));
        needs[i]++;
      }
    }
    if (pr == INT_MAX >> 1) return dp[needs] = 0;
    return dp[needs] = pr;
  }

  int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    this->price = price;
    this->special = special;
    int pr = backtrack(needs);
    return pr;
  }
};
// @lc code=end

