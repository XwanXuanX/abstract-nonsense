#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2898 lang=cpp
 *
 * [2898] Maximum Linear Stock Score
 */

// @lc code=start
class Solution {
public:
  long long maxScore(vector<int> &prices) {
    long long n = prices.size();
    vector<long long> arr(n);
    for (long long i = 0; i < n; ++i) {
      arr[i] = prices[i] - (i + 1);
    }
    unordered_map<long long, long long> cnt;
    for (long long i = 0; i < n; ++i) {
      cnt[arr[i]] += prices[i];
    }
    long long ans = 0;
    for (auto &p : cnt) {
      ans = max(ans, p.second);
    }
    return ans;
  }
};
// @lc code=end
