#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2131 lang=cpp
 *
 * [2131] Longest Palindrome by Concatenating Two Letter Words
 */

// @lc code=start
class Solution {
public:
  int longestPalindrome(vector<string>& words) {
    unordered_map<string,int> cnt;
    unordered_set<string> unq(words.begin(), words.end());
    for (auto& s : words) {
      cnt[s]++;
    }
    int odd = 0;
    int ans = 0;
    for (auto& s : unq) {
      if (!cnt.count(s)) {
        continue;
      }
      string counterpart(s.rbegin(), s.rend());
      if (!cnt.count(counterpart)) { // If the counter part is never seen
        // Then the current one is useless
        cnt.erase(s);
        continue;
      }
      // If the counter part is present
      int fwd = cnt[s], bkwd = cnt[counterpart];
      // Now check if the two charaters are the same
      if (s[0] == s[1]) {
        assert(s == counterpart);
        if (fwd % 2) {
          odd |= 1;
        }
        ans += ((fwd / 2) * 2) * 2;
        cnt.erase(s);
      } else {
        ans += (min(fwd, bkwd) * 2) * 2;
        cnt.erase(s), cnt.erase(counterpart);
      }
    }
    return ans + (odd * 2);
  }
};
// @lc code=end

