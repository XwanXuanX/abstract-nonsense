#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1947 lang=cpp
 *
 * [1947] Maximum Compatibility Score Sum
 */

// @lc code=start
class Solution {
public:
  template <class T> using V = vector<T>;
  unordered_map<int, map<set<int>, int>> dp;

  int distance(V<int> &a, V<int> &b) {
    int ans = 0;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] == b[i]) {
        ans++;
      }
    }
    return ans;
  }

  int dfs(int node, set<int> ava, V<V<int>> &workers, V<V<int>> &bikes) {
    if (dp.contains(node) && dp[node].contains(ava)) {
      return dp[node][ava];
    }
    // At the leaf, pick the bike with the closest distance
    if (node == workers.size() - 1) {
      assert(ava.size() > 0);
      int mndist = INT_MIN;
      for (auto &bi : ava) {
        mndist = max(mndist, distance(workers[node], bikes[bi]));
      }
      return dp[node][ava] = mndist;
    }
    // Not at the leaf, assign the current node a bike from ava
    int mndist = INT_MIN;
    for (auto &bi : ava) {
      int dist = distance(workers[node], bikes[bi]);
      auto nextAva = ava;
      nextAva.erase(bi);
      dist += dfs(node + 1, nextAva, workers, bikes);
      mndist = max(mndist, dist);
    }
    return dp[node][ava] = mndist;
  }

  int maxCompatibilitySum(vector<vector<int>> &students,
                          vector<vector<int>> &mentors) {
    int m = mentors.size();
    set<int> ava;
    for (int i = 0; i < m; ++i) {
      ava.insert(i);
    }
    return dfs(0, ava, students, mentors);
  }
};
// @lc code=end
