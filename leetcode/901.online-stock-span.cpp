#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
class StockSpanner {
public:
  vector<int> vals;
  deque<int> stk;
  map<int,int> dp;

  StockSpanner() {}

  int next(int price) {
    vals.push_back(price);
    if (stk.empty()) {
      int i = vals.size() - 1;
      stk.push_back(i);
      return dp[i] = 1;
    }
    // Then we need to pop until you find a bigger element
    int mni = INT_MAX;
    while (stk.size() && vals[stk.back()] <= price) {
      mni = min(mni, stk.back());
      stk.pop_back();
    }

    int i = vals.size() - 1;
    stk.push_back(i);
    if (mni < INT_MAX) {
      int ans = i - mni + dp[mni];
      return dp[i] = ans;
    } else {
      return dp[i] = 1;
    }
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

