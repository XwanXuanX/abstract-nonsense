#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1101 lang=cpp
 *
 * [1101] The Earliest Moment When Everyone Become Friends
 */

// @lc code=start
struct UnionFind {
  vector<int> par;
  vector<int> sz;

  UnionFind(int n) {
    par = vector<int>(n);
    iota(par.begin(), par.end(), 0);
    sz = vector<int>(n, 1);
  }

  int find(int u) {
    // this optimisation was good.
    if (par[u] != par[par[u]])
      par[u] = find(par[par[u]]);
    return par[u];
  }

  bool join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;
    if (sz[u] <= sz[v]) {
      sz[v] += sz[u];
      par[u] = v;
    } else {
      sz[u] += sz[v];
      par[v] = u;
    }
    return true;
  }
};

class Solution {
public:
  int earliestAcq(vector<vector<int>> &logs, int n) {
    sort(logs.begin(), logs.end(),
         [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
    UnionFind dsu(n);
    for (auto &l : logs) {
      int time = l[0], u = l[1], v = l[2];
      dsu.join(u, v);
      if (dsu.sz[dsu.find(u)] == n) {
        return time;
      }
    }
    return -1;
  }
};
// @lc code=end
