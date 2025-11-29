#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2246 lang=cpp
 *
 * [2246] Longest Path With Different Adjacent Characters
 */

// @lc code=start
class Solution {
public:
  template <class T> using V = vector<T>;
  V<V<int>> G;
  string str;
  int ans = 1;

  int dfs(int node) {
    if (G[node].empty()) {
      return 1;
    }
    // At a root, from all the subtrees,
    // We need to find two paths with different characters
    auto &adjs = G[node];
    V<int> res(adjs.size());
    for (int i = 0; i < adjs.size(); ++i) {
      res[i] = dfs(adjs[i]);
    }
    int first = -1, second = -1;
    for (int i = 0; i < adjs.size(); ++i) {
      if (str[adjs[i]] != str[node]) {
        if (res[i] > first) {
          second = first;
          first = res[i];
        } else if (res[i] > second) {
          second = res[i];
        }
      }
    }
    if (first == -1 && second == -1) {
      return 1;
    } else if (first == -1 && second != -1 || first != -1 && second == -1) {
      int mx = max(first, second);
      ans = max(ans, mx + 1);
      return mx + 1;
    } else {
      ans = max(ans, first + 1 + second);
      return max(first, second) + 1;
    }
  }

  int longestPath(vector<int> &parent, string s) {
    str = s;
    int n = parent.size();
    G.assign(n, V<int>());
    for (int i = 1; i < n; ++i) {
      G[parent[i]].emplace_back(i);
    }
    dfs(0);
    return ans;
  }
};
// @lc code=end
