#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=3006 lang=cpp
 *
 * [3006] Find Beautiful Indices in the Given Array I
 */

// @lc code=start
class Solution {
public:
  bool doesStringAppear(string& s, string& a, int start) {
    assert(start + a.size() <= s.size());
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] != s[start + i]) {
        return false;
      }
    }
    return true;
  }

  bool hasJ(vector<int>& bi, int i, int k) {
    int lb = -1;
    int l = 0, r = bi.size() - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (bi[mid] > i) {
        r = mid - 1;
      } else {
        lb = max(lb, mid);
        l = mid + 1;
      }
    }
    if (lb == -1) {
      return abs(bi[0] - i) <= k;
    }
    int closer = bi[lb];
    if (lb + 1 < bi.size() && abs(bi[lb+1] - i) < abs(closer - i)) {
      closer = bi[lb+1];
    }
    return abs(closer - i) <= k;
  }

  vector<int> beautifulIndices(string s, string a, string b, int k) {
    int sn = s.size(), an = a.size(), bn = b.size();
    // First you find the index in s where a and b is present
    vector<int> ai, bi;
    for (int i = 0; i < sn - an + 1; ++i) {
      if (doesStringAppear(s, a, i)) {
        ai.push_back(i);
      }
    }
    for (int i = 0; i < sn - bn + 1; ++i) {
      if (doesStringAppear(s, b, i)) {
        bi.push_back(i);
      }
    }
    if (ai.empty() || bi.empty()) {
      return {};
    }

    vector<int> ans;
    // Now for each i in ai, we need to check if there exists a j in bi
    // there i and j differ by no more than k
    // We can do binary search on bi
    for (int i : ai) {
      if (hasJ(bi, i, k)) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
// @lc code=end

