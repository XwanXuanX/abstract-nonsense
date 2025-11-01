#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1229 lang=cpp
 *
 * [1229] Meeting Scheduler
 */

// @lc code=start
class Solution {
public:
  template <class T> using V = vector<T>;

  int lowerBound(V<V<int>> &a, int target) {
    int l = 0, r = a.size() - 1;
    int ans = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (a[mid][0] <= target) {
        ans = max(ans, mid);
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return ans;
  }

  int solve(V<V<int>> &a, V<V<int>> &b, int dur) {
    for (int i = 0; i < a.size(); ++i) {
      int lb = lowerBound(b, a[i][0]);
      if (!(a[i][1] - a[i][0] < dur || lb == -1 || b[lb][1] - a[i][0] < dur)) {
        return a[i][0];
      }
    }
    return INT_MAX;
  }

  vector<int> minAvailableDuration(vector<vector<int>> &slots1,
                                   vector<vector<int>> &slots2, int duration) {
    sort(slots1.begin(), slots1.end());
    sort(slots2.begin(), slots2.end());
    int ans1 = solve(slots1, slots2, duration),
        ans2 = solve(slots2, slots1, duration);
    int ans = min(ans1, ans2);
    if (ans == INT_MAX) {
      return {};
    }
    return {ans, ans + duration};
  }
};
// @lc code=end
