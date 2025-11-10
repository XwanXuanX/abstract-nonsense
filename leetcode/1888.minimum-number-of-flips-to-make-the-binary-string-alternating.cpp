#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1888 lang=cpp
 *
 * [1888] Minimum Number of Flips to Make the Binary String Alternating
 */

// @lc code=start
class Solution {
public:
  int minFlips(string s) {
    int n = s.size();
    string ref;
    for (int i = 0; i < n; ++i) {
      ref.push_back((i % 2) ? '0' : '1');
    }
    int ini = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] != ref[i]) {
        ini++;
      }
    }
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
      ref.push_back((ref.back() == '0') ? '1' : '0');
      s.push_back(s[i]);
      if (s[i] != ref[i]) {
        ini--;
      }
      if (s[i + n] != ref[i + n]) {
        ini++;
      }

      ans = min(ans, min(ini, n - ini));
    }
    return ans;
  }
};
// @lc code=end
