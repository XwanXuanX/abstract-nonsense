#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1061 lang=cpp
 *
 * [1061] Lexicographically Smallest Equivalent String
 */

// @lc code=start
class Solution {
public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    unordered_map<char, unordered_set<char>> G;
    for (int i = 0; i < s1.size(); ++i) {
      char u = s1[i], v = s2[i];
      G[u].insert(v), G[v].insert(u);
    }

    unordered_set<char> vis;
    function<void(char, char &)> dfs;
    dfs = [&](char node, char &smallest) {
      smallest = min(smallest, node);
      vis.insert(node);
      for (auto &adj : G[node]) {
        if (!vis.count(adj)) {
          dfs(adj, smallest);
        }
      }
    };

    string ans;
    for (auto &c : baseStr) {
      vis.clear();
      char smallest = CHAR_MAX;
      dfs(c, smallest);
      ans.push_back(smallest);
    }

    return ans;
  }
};
// @lc code=end
