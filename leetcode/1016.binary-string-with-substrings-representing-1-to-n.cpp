#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1016 lang=cpp
 *
 * [1016] Binary String With Substrings Representing 1 To N
 */

// @lc code=start
class Solution {
public:
  bool queryString(string s, int n) {
    unordered_set<unsigned int> st;
    for (int i = 0; i < s.size(); ++i) {
      unsigned int num = 0;
      for (int j = i; j < min(i + 32, (int)s.size()); ++j) {
        if (s[j] == '1') {
          num |= 1;
        }
        st.insert(num);
        num <<= 1;
      }
    }
    if (n > st.size()) {
      return false;
    }
    for (int i = 1; i <= n; ++i) {
      if (!st.count(i)) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end

