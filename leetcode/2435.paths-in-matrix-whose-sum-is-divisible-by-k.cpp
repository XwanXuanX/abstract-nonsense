#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2435 lang=cpp
 *
 * [2435] Paths in Matrix Whose Sum Is Divisible by K
 */

// @lc code=start
class Solution {
public:
  using ll = long long;
  static constexpr ll mod = 1e9 + 7;
  template <class T> using V = vector<T>;
  int numberOfPaths(vector<vector<int>> &grid, ll k) {
    ll n = grid.size(), m = grid[0].size();
    V<V<V<ll>>> dp(n, V<V<ll>>(m, V<ll>(k, 0)));
    dp[0][0][grid[0][0] % k] = 1;
    for (ll i = 1; i < n; ++i) {
      for (ll o = 0; o < k; ++o) {
        dp[i][0][(o + grid[i][0]) % k] += dp[i - 1][0][o];
        dp[i][0][(o + grid[i][0]) % k] %= mod;
      }
    }
    for (ll j = 1; j < m; ++j) {
      for (ll o = 0; o < k; ++o) {
        dp[0][j][(o + grid[0][j]) % k] += dp[0][j - 1][o];
        dp[0][j][(o + grid[0][j]) % k] %= mod;
      }
    }
    for (ll i = 1; i < n; ++i) {
      for (ll j = 1; j < m; ++j) {
        for (ll o = 0; o < k; ++o) {
          dp[i][j][(o + grid[i][j]) % k] += dp[i - 1][j][o];
          dp[i][j][(o + grid[i][j]) % k] %= mod;
        }
        for (ll o = 0; o < k; ++o) {
          dp[i][j][(o + grid[i][j]) % k] += dp[i][j - 1][o];
          dp[i][j][(o + grid[i][j]) % k] %= mod;
        }
      }
    }
    return static_cast<int>(dp[n - 1][m - 1][0]);
  }
};
// @lc code=end
