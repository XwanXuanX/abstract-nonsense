#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1774 lang=cpp
 *
 * [1774] Closest Dessert Cost
 */

// @lc code=start
class Solution {
public:
  template <class T> using V = vector<T>;
  V<int> allTop;

  void allComb(V<int> &topCosts, int i, int sum) {
    if (i == topCosts.size()) {
      allTop.push_back(sum);
      return;
    }
    allComb(topCosts, i + 1, sum);
    allComb(topCosts, i + 1, sum + topCosts[i]);
    allComb(topCosts, i + 1, sum + topCosts[i] * 2);
  }

  int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts,
                  int target) {
    int n = baseCosts.size(), m = toppingCosts.size();
    // There are at most 3^10 types of ways to choose the toppings
    // Just enumerate them all
    allComb(toppingCosts, 0, 0);
    int diff = INT_MAX, ans = 0;
    for (auto base : baseCosts) {
      for (auto top : allTop) {
        int tot = base + top;
        if (abs(tot - target) < diff ||
            (abs(tot - target) == diff && tot < ans)) {
          diff = abs(tot - target);
          ans = tot;
        }
      }
    }
    return ans;
  }
};
// @lc code=end
