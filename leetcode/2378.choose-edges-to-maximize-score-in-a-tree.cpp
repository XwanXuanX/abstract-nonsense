#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2378 lang=cpp
 *
 * [2378] Choose Edges to Maximize Score in a Tree
 */

// @lc code=start
class Solution {
public:
  using ll = long long;
  template <class T> using V = vector<T>;
  V<V<pair<ll, ll>>> G;
  ll ans = 0;

  // {pick one edge, pick no edge} in the subtree
  pair<ll, ll> dfs(ll node) {
    if (G[node].empty()) {
      return {0, 0};
    }
    auto &adjs = G[node];
    V<pair<ll, ll>> res(adjs.size());
    for (ll i = 0; i < adjs.size(); ++i) {
      res[i] = dfs(adjs[i].first);
    }
    // Choice 1: Pick nothing
    // That means we can pick anything freely in all the subtrees
    ll pickNothing = 0;
    for (auto &p : res) {
      pickNothing += max(p.first, p.second);
    }
    // Choice 2: Pick one edge
    // If we pick one edge, then we can only pick no edge for that subtree
    // and pick anything freely in all other subtrees
    ll pickOne = 0;
    for (ll i = 0; i < adjs.size(); ++i) {
      ll rest = 0;
      for (ll j = 0; j < adjs.size(); ++j) {
        if (j != i) {
          rest += max(res[j].first, res[j].second);
        }
      }
      pickOne = max(pickOne, rest + res[i].second + adjs[i].second);
    }
    ans = max({ans, pickNothing, pickOne});
    return {max(pickOne, 0ll), max(pickNothing, 0ll)};
  }

  long long maxScore(vector<vector<int>> &edges) {
    ll n = edges.size();
    G.assign(n, V<pair<ll, ll>>());
    for (ll i = 1; i < n; ++i) {
      ll par = edges[i][0], wei = edges[i][1];
      G[par].emplace_back(i, wei);
    }
    dfs(0);
    return ans;
  }
};
// @lc code=end
