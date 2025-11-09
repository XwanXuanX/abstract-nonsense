#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1059 lang=cpp
 *
 * [1059] All Paths from Source Lead to Destination
 */

// @lc code=start
class Solution {
public:
  int n;
  int src, dst;
  unordered_map<int, unordered_set<int>> G;

  void checkConnect(int node, unordered_set<int> &vis) {
    vis.insert(node);
    for (auto &adj : G[node]) {
      if (!vis.contains(adj)) {
        checkConnect(adj, vis);
      }
    }
  }

  bool checkCycle(unordered_set<int> &vis) {
    vector<int> ind(n, 0);
    queue<int> q;
    unordered_set<int> visited;
    for (auto &node : vis) {
      for (auto &u : G[node]) {
        ind[u]++;
      }
    }
    if (ind[src] > 0) {
      return false;
    }
    for (auto &node : vis) {
      if (ind[node] == 0) {
        q.push(node);
      }
    }
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      visited.insert(u);
      for (auto adj : G[u]) {
        ind[adj]--;
        if (ind[adj] == 0) {
          q.push(adj);
        }
      }
    }
    return visited.size() == vis.size();
  }

  bool leadsToDestination(int n, vector<vector<int>> &edges, int source,
                          int destination) {
    this->n = n, src = source, dst = destination;
    for (auto &e : edges) {
      G[e[0]].insert(e[1]);
    }
    unordered_set<int> vis;
    checkConnect(src, vis);
    if (!vis.contains(dst)) {
      return false;
    }
    if (!checkCycle(vis)) {
      return false;
    }
    // Now the connected component has no cycle
    // There should be only one node with out degree of 0
    for (auto &node : vis) {
      if (node != dst && G[node].size() == 0) {
        return false;
      }
    }
    return G[dst].size() == 0;
  }
};
// @lc code=end
