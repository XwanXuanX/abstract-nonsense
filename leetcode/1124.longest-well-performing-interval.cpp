#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1124 lang=cpp
 *
 * [1124] Longest Well-Performing Interval
 */

// @lc code=start
class Solution {
public:
  template <class T> using V = vector<T>;
  int lowerBound(V<pair<int, int>> &a, int target) {
    int l = 0, r = a.size() - 1;
    int ans = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (a[mid].first <= target) {
        ans = max(ans, mid);
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return ans;
  }

  int longestWPI(vector<int> &hours) {
    int n = hours.size();
    for (int i = 0; i < n; ++i) {
      hours[i] = hours[i] > 8 ? +1 : -1;
    }
    int sum = 0;
    V<pair<int, int>> pref;
    for (int i = 0; i < n; ++i) {
      sum += hours[i];
      pref.push_back({sum, i});
    }
    ranges::sort(pref);
    V<int> minIdx(n);
    minIdx[0] = pref[0].second;
    for (int i = 1; i < n; ++i) {
      minIdx[i] = min(minIdx[i - 1], pref[i].second);
    }
    int ans = 0;
    sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += hours[i];
      if (sum > 0) {
        ans = max(ans, i + 1);
      } else {
        int toFind = sum - 1;
        int fi = lowerBound(pref, toFind);
        if (fi != -1 && minIdx[fi] < i) {
          ans = max(ans, i - minIdx[fi]);
        }
      }
    }
    return ans;
  }
};
// @lc code=end
