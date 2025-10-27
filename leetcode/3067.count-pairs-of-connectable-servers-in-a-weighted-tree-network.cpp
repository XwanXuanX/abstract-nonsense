#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=3067 lang=cpp
 *
 * [3067] Count Pairs of Connectable Servers in a Weighted Tree Network
 */

// @lc code=start
class Solution {
public:
  unordered_map<int, vector<pair<int,int>>> G;
  int sigSpeed = 0;

  int dfs(int node, int par, int len) {
    int res = 0;
    for (auto& adj : G[node]) {
      if (adj.first != par) {
        res += dfs(adj.first, node, len + adj.second);
      }
    }
    return res + (len % sigSpeed == 0);
  }

  int solve(int root) {
    int cur = 0, res = 0;
    for (auto& adj : G[root]) {
      int cnt = dfs(adj.first, root, adj.second);
      res += cnt * cur;
      cur += cnt;
    }
    return res;
  }

  vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
    sigSpeed = signalSpeed;
    for (auto& e : edges) {
      int u = e[0], v = e[1], w = e[2];
      G[u].push_back({v, w}), G[v].push_back({u, w});
    }
    int n = G.size();
    vector<int> ans(n, 0);
    for (int i = 0; i < n; ++i) {
      ans[i] = solve(i);
    }
    return ans;
  }
};
// @lc code=end

