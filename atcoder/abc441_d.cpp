// Problem: D - Paid Walk
// Contest: AtCoder - AtCoder Beginner Contest 441 (Promotion of Engineer Guild Fes)
// URL: https://atcoder.jp/contests/abc441/tasks/abc441_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma")
#include <bits/stdc++.h>
using namespace std;

inline namespace FastIO {
template <typename T, typename = void> struct DefaultI : std::false_type {}; template <typename T> struct DefaultI<T, std::void_t<decltype(std::cin  >> std::declval<T&>())>> : std::true_type {};
template <typename T, typename = void> struct DefaultO : std::false_type {}; template <typename T> struct DefaultO<T, std::void_t<decltype(std::cout << std::declval<T&>())>> : std::true_type {};
template <typename T, typename = void> struct IsTuples : std::false_type {}; template <typename T> struct IsTuples<T, std::void_t<typename std::tuple_size<T>::type>>         : std::true_type {};
template <typename T, typename = void> struct Iterable : std::false_type {}; template <typename T> struct Iterable<T, std::void_t<decltype(std::begin(std::declval<T>()))>>   : std::true_type {};
template <typename T> char sp(T& t) { return (Iterable<T>::value || IsTuples<T>::value) ? '\n' : ' '; }
template <typename T> void re(T& t) {
  if constexpr      (DefaultI<T>::value) { cin >> t; }
  else if constexpr (Iterable<T>::value) { for (auto& x : t) re(x); }
  else if constexpr (IsTuples<T>::value) { std::apply([&](auto& ...args) { (re(args), ...); }, t); }
}
template <typename T> void pt(T& t) {
  if constexpr      (DefaultO<T>::value) { cout << t; }
  else if constexpr (Iterable<T>::value) { int i = 0; for (auto&& x : t) ((i++) ? (cout << sp(x), pt(x)) : pt(x)); }
  else if constexpr (IsTuples<T>::value) { std::apply([&](auto const& ...args) { int i = 0; (((i++) ? (cout << " ", pt(args)) : pt(args)), ...); }, t); }
}
template <typename T, typename... Ts> void ps(const string& s, T& t, Ts& ...ts) { pt(t), ((cout << s, pt(ts)), ...), cout << '\n'; }
/* It passed locally but TLEsagain */ void ps(const string&) { cout << '\n'; }
template <typename... Ts> void print(const Ts& ...ts) { FastIO::ps(" ", ts...); }
template <typename... Ts> void read (Ts& ...ts) { ((FastIO::re(ts)), ...); }
}  // namespace FastIO

inline namespace Util {
#define rep(x)                     for (int _ = (0); _ < (x); ++_)
template <typename T> using V    = vector<T>;
template <typename T> using MnPQ = priority_queue<T, V<T>, greater<T>>;
template <typename T> using MxPQ = priority_queue<T, V<T>, less<T>>;
}  // namespace Util

#ifndef ONLINE_JUDGE
#  define debug(...) do { __VA_ARGS__ } while (0)
#else
#  define debug(...) do {} while (0)
#endif

int N, M, L, S, T;
unordered_map<int, V<pair<int, int>>> G;

void solve() {
  read(N, M, L, S, T);
  rep(M) {
    int u, v, c; read(u, v, c);
    G[u].push_back({v, c});
  }
  V<V<V<int>>> dp(L+1, V<V<int>>(N+1));
  dp[0][1].push_back(0);
  for (int k = 0; k < L; ++k) {
    for (int u = 1; u <= N; ++u) {
      for (int c : dp[k][u]) {
        for (const auto [v, w] : G[u]) {
          const int nc = c + w;
          if (nc <= T) dp[k+1][v].push_back(nc);
        }
      }
    }
    for (int n = 1; n <= N; ++n) {
      auto& v = dp[k+1][n];
      sort(v.begin(), v.end());
      v.erase(unique(v.begin(), v.end()), v.end());
    }
  }
  V<int> ans;
  for (int n = 1; n <= N; ++n) {
    for (const int c : dp[L][n]) {
      if (S <= c && c <= T) {
        ans.push_back(n);
        break;
      }
    }
  }
  print(ans);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; // read(tt);
  rep(tt) solve();
}