#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1042 lang=cpp
 *
 * [1042] Flower Planting With No Adjacent
 */

// @lc code=start
class Solution {
public:
  vector<int> gardenNoAdj(int n, vector<vector<int>> &paths) {
    unordered_map<int, vector<int>> G;
    for (auto &e : paths) {
      int u = e[0], v = e[1];
      G[u].push_back(v), G[v].push_back(u);
    }
    unordered_set<int> V;
    unordered_map<int, set<int>> ava;
    for (int i = 2; i <= n; ++i) {
      ava[i] = set<int>{1, 2, 3, 4};
    }
    for (int i = 1; i <= n; ++i) {
      if (V.contains(i)) {
        continue;
      }
      queue<int> Q;
      Q.push(i);
      ava[i] = {1};
      while (Q.size()) {
        int node = Q.front();
        Q.pop();
        V.insert(node);
        int choose = *ava[node].begin();
        ava[node] = {choose};
        for (auto &adj : G[node]) {
          if (V.contains(adj)) {
            continue;
          }
          ava[adj].erase(choose);
          Q.push(adj);
        }
      }
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
      assert(ava[i].size() >= 1);
      ans.push_back(*ava[i].begin());
    }
    return ans;
  }
};
// @lc code=end
