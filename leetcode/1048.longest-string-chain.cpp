#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */

// @lc code=start
class Solution {
public:
  bool canInsertToMake(string &a, string &b) {
    int i = 0;
    int j = 0;
    bool skipped = false;

    while (i < (int)a.size() && j < (int)b.size()) {
      if (a[i] == b[j]) {
        i++;
        j++;
      } else {
        if (skipped)
          return false;
        skipped = true;
        i++;
      }
    }

    if (j == (int)b.size() && skipped)
      return true;
    if (!skipped && j == (int)b.size() && i + 1 == (int)a.size())
      return true;
    return false;
  }

  int longestStrChain(vector<string> &words) {
    int n = words.size();
    sort(words.begin(), words.end(),
         [](string &a, string &b) { return a.size() < b.size(); });
    unordered_map<int, vector<int>> buk;
    for (int i = 0; i < n; ++i) {
      buk[words[i].size()].push_back(i);
    }
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
      string &w = words[i];
      dp[i] = 1;
      if (buk.count(w.size() - 1)) {
        for (int j : buk[w.size() - 1]) {
          if (canInsertToMake(w, words[j]))
            dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
    int ans = 1;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
// @lc code=end
