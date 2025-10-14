#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=758 lang=cpp
 *
 * [758] Bold Words in String
 */

// @lc code=start
class Solution {
public:
  void markAll(vector<bool>& rng, string& s, string& pat) {
    for (int i = 0; i < s.size() - pat.size() + 1; ++i) {
      bool ok = true;
      for (int j = 0; j < pat.size(); ++j) {
        if (s[i+j] != pat[j]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        for (int j = 0; j < pat.size(); ++j) {
          rng[i+j] = true;
        }
      }
    }
  }

  // Basically you need to find the range to add tags
  string boldWords(vector<string>& words, string s) {
    int n = s.size();
    vector<bool> rng(n, false);
    for (auto& pat : words) {
      markAll(rng, s, pat);
    }
    bool tags = false;
    string ans;
    for (int i = 0; i < n; ++i) {
      if (rng[i] && !tags) {
        ans += "<b>";
        tags = true;
      }
      if (!rng[i] && tags) {
        ans += "</b>";
        tags = false;
      }
      ans.push_back(s[i]);
    }
    if (tags) {
      ans += "</b>";
    }
    return ans;
  }
};
// @lc code=end

