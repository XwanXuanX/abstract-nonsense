#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */

// @lc code=start
class Solution {
public:
/**
 * Each weight corresponds to a range on the number line
 * Larger weight means larger range
 * Basically you need to generate a random number, and determine which range
 * it falls into.
 */

  vector<int> pfs;
  random_device rd;

  Solution(vector<int>& w) {
    pfs.assign(w.size() + 1, 0);
    pfs[1] = w[0];
    for (int i = 2; i <= w.size(); ++i) {
      pfs[i] += pfs[i-1] + w[i-1];
    }
  }
  
  int pickIndex() {
    uniform_int_distribution<int> ud(1, pfs.back());
    int randi = ud(rd);
    auto it = lower_bound(pfs.begin() + 1, pfs.end(), randi);
    return it - pfs.begin() - 1;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

