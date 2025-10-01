#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=261 lang=cpp
 *
 * [261] Graph Valid Tree
 */

// @lc code=start
class Solution {
public:
  set<int> stack;
  bool dfs(map<int, vector<int>>& G, int node, int parent) {
    if (stack.count(node)) {
      return false;
    }
    stack.insert(node);
    for (auto adj : G[node]) {
      if (adj == parent) continue;
      if (!dfs(G, adj, node)) {
        return false;
      }
    }
    stack.erase(node);
    return true;
  }

  bool validTree(int n, vector<vector<int>>& edges) {
    map<int, vector<int>> G;
    for (auto& e : edges) {
      int u = e[0], v = e[1];
      G[u].push_back(v), G[v].push_back(u);
    }
    if (n != edges.size() + 1) return false;
    for (int i = 0; i < n; ++i) {
      if (!dfs(G, i, -1)) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end

