#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=269 lang=cpp
 *
 * [269] Alien Dictionary
 */

// @lc code=start
class Solution {
public:
  string alienOrder(vector<string> &words) {
    if (words.size() == 1) {
      unordered_set<char> unq(words[0].begin(), words[0].end());
      return string(unq.begin(), unq.end());
    }

    unordered_map<char, vector<char>> G;
    int n = words.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        // a is lex-smaller than b
        auto &a = words[i], &b = words[j];
        for (auto ch : a)
          (void)G[ch];
        for (auto ch : b)
          (void)G[ch];
        int mnsz = min(a.size(), b.size());
        int diff = 0;
        for (int k = 0; k < mnsz; ++k) {
          if (a[k] != b[k]) {
            // Then a[k] is smaller than b[k]
            G[a[k]].push_back(b[k]);
            diff |= 1;
            break;
          }
        }
        // No difference, one is a prefix of another
        // a.size() == b.size() is fine
        if (!diff && a.size() > b.size()) {
          return {};
        }
      }
    }

    // Top sort
    int nnodes = G.size();
    unordered_map<char, int> indeg;
    for (auto &p : G) {
      (void)indeg[p.first];
      for (auto ch : p.second) {
        indeg[ch]++;
      }
    }
    queue<char> q;
    for (auto &p : indeg) {
      if (p.second == 0) {
        q.push(p.first);
      }
    }
    string ans;
    while (q.size()) {
      char node = q.front();
      q.pop();
      ans.push_back(node);
      for (char adj : G[node]) {
        indeg[adj]--;
        if (indeg[adj] == 0) {
          q.push(adj);
        }
      }
    }
    if (ans.size() != nnodes) {
      return {};
    }
    return ans;
  }
};
// @lc code=end
