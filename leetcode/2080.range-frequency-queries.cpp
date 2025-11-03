#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2080 lang=cpp
 *
 * [2080] Range Frequency Queries
 */

// @lc code=start
class RangeFreqQuery {
public:
  int n;
  unordered_map<int, vector<int>> index;

  RangeFreqQuery(vector<int> &arr) {
    n = arr.size();
    for (int i = 0; i < n; ++i) {
      index[arr[i]].push_back(i);
    }
  }

  int searchLeft(vector<int> &v, int target) {
    int l = 0, r = v.size() - 1;
    int ans = INT_MAX;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (v[mid] >= target) {
        ans = min(ans, mid);
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return ans;
  }

  int searchRight(vector<int> &v, int target, int start) {
    int l = start, r = v.size() - 1;
    int ans = INT_MIN;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (v[mid] <= target) {
        ans = max(ans, mid);
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return ans;
  }

  int query(int left, int right, int value) {
    auto &v = index[value];
    int l = searchLeft(v, left);
    if (l == INT_MAX) {
      return 0;
    }
    int r = searchRight(v, right, l);
    if (r == INT_MIN) {
      return 0;
    }
    return r - l + 1;
  }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
// @lc code=end
