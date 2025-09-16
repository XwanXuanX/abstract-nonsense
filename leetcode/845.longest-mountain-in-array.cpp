#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=845 lang=cpp
 *
 * [845] Longest Mountain in Array
 */

// @lc code=start
class Solution {
public:
  int longestMountain(vector<int>& arr) {
    int n = arr.size();
    vector<int> a(n, 0), b(n, 0);
    for (int i = 1; i < n; ++i) {
      if (arr[i] > arr[i-1])
        a[i] = a[i-1] + 1;
    }
    for (int i = n - 2; i >= 0; --i) {
      if (arr[i] > arr[i+1])
        b[i] = b[i+1] + 1;
    }
    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
      if (a[i] > 0 && b[i] > 0)
        ans = max(ans, a[i] + b[i] + 1);
    }
    return ans;
  }
};
// @lc code=end

