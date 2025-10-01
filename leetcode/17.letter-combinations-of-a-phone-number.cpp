#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
  string path;
  vector<string> ans;
  map<int, vector<char>> mp;

  void backtrack(const string& digits, int pos) {
    if (pos == digits.size()) {
      ans.push_back(path);
      return;
    }
    int d = digits[pos] - '0';
    for (int i = 0; i < mp[d].size(); ++i) {
      path.push_back(mp[d][i]);
      backtrack(digits, pos + 1);
      path.pop_back();
    }
  }

  vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) {
      return {};
    }
    mp[2] = {0, 1, 2};
    mp[3] = {3, 4, 5};
    mp[4] = {6, 7, 8};
    mp[5] = {9, 10, 11};
    mp[6] = {12, 13, 14};
    mp[7] = {15, 16, 17, 18};
    mp[8] = {19, 20, 21};
    mp[9] = {22, 23, 24, 25};
    for (auto& p : mp) {
      for (char& c : p.second) {
        c += 'a';
      }
    }
    backtrack(digits, 0);
    return ans;
  }
};
// @lc code=end

