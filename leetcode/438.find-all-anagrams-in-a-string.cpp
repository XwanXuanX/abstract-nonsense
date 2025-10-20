#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
  bool possible(unordered_map<char,int>& cnt, unordered_map<char,int>& slide) {
    for (auto& p : slide) {
      if (!cnt.count(p.first)) {
        return false;
      }
      if (p.second > cnt[p.first]) {
        return false;
      }
    }
    return true;
  }

  vector<int> findAnagrams(string s, string p) {
    unordered_map<char,int> cnt;
    for (char ch : p) {
      cnt[ch]++;
    }
    vector<int> ans;
    unordered_map<char,int> slide;
    for (int l = 0, r = 0; r < s.size(); ++r) {
      slide[s[r]]++;
      // Need to move the end if impossible
      while (!possible(cnt, slide) && l < r) {
        slide[s[l]]--;
        if (slide[s[l]] == 0) {
          slide.erase(s[l]);
        }
        l++;
      }
      if (slide == cnt) {
        ans.push_back(l);
      }
    }
    return ans;
  }
};
// @lc code=end

