#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 */

// @lc code=start
class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string> &products,
                                           string searchWord) {
    int n = products.size();
    sort(products.begin(), products.end());
    string pref;
    vector<vector<string>> ans;
    for (auto c : searchWord) {
      pref.push_back(c);
      int i = lower_bound(products.begin(), products.end(), pref) -
              products.begin();
      ans.push_back({});
      for (int j = i; j < min(i + 3, n); ++j) {
        // Make sure they have the same prefix
        if (products[j].compare(0, pref.size(), pref)) {
          break;
        }
        ans.back().push_back(products[j]);
      }
    }
    return ans;
  }
};
// @lc code=end
