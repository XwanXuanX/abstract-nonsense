#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution {
public:
  map<char,int> cnt;

  int getOthers() const {
    int mx = 0, tot = 0;
    for (auto& p : cnt) {
      tot += p.second;
      mx = max(mx, p.second);
    }
    return tot - mx;
  }

  int characterReplacement(string s, int k) {
    int n = s.size();
    int ans = 0;
    for (int l = 0, r = 0; r < n; ++r) {
      cnt[s[r]]++;
      while (l < r && getOthers() > k) {
        cnt[s[l]]--;
        if (cnt[s[l]] == 0) {
          cnt.erase(s[l]);
        }
        l++;
      }
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};
// @lc code=end

