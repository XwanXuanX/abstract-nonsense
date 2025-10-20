#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=3043 lang=cpp
 *
 * [3043] Find the Length of the Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
  int len(int n) {
    int ans = 0;
    while (n) {
      ans++;
      n /= 10;
    }
    return ans;
  }

  int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int> prefix;
    for (int x : arr1) {
      while (x) {
        prefix.insert(x);
        x /= 10;
      }
    }
    int ans = 0;
    for (int y : arr2) {
      while (y) {
        if (prefix.count(y)) {
          ans = max(ans, len(y));
          break;
        }
        y /= 10;
      }
    }
    return ans;
  }
};
// @lc code=end

