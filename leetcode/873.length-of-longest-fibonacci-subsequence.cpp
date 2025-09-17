#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=873 lang=cpp
 *
 * [873] Length of Longest Fibonacci Subsequence
 */

// @lc code=start
class Solution {
public:
  int lenLongestFibSubseq(vector<int>& arr) {
    int n = arr.size();
    int ans = 0;
    // Record the set of previous numbers that can form fib
    vector<unordered_map<int,int>> prev(n);
    prev[0][0] = 1;
    prev[1][arr[0]] = 2;
    for (int i = 2; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        prev[i][arr[j]] = 2;
        int r = arr[i] - arr[j];
        if (!prev[j].contains(r))
          continue;
        // This means arr[j] can be a prev of arr[i]
        // The length is derived
        prev[i][arr[j]] = prev[j][r] + 1;
        ans = max(ans, prev[i][arr[j]]);
      }
    }
    if (ans < 3) ans = 0;
    return ans;
  }
};
// @lc code=end

