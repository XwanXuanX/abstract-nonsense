#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1090 lang=cpp
 *
 * [1090] Largest Values From Labels
 */

// @lc code=start
class Solution {
public:
  int largestValsFromLabels(vector<int> &values, vector<int> &labels,
                            int numWanted, int useLimit) {
    int n = values.size();
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
      a[i].first = values[i], a[i].second = labels[i];
    }
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    unordered_map<int, int> cnt;
    int idx = 0, ans = 0;
    while (idx < n && numWanted) {
      if (cnt[a[idx].second] < useLimit) {
        ans += a[idx].first;
        cnt[a[idx].second]++;
        numWanted--;
      }
      idx++;
    }
    return ans;
  }
};
// @lc code=end
