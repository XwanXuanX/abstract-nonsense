// Problem: E - Come Back Quickly
// Contest: AtCoder - AtCoder Beginner Contest 191
// URL: https://atcoder.jp/contests/abc191/tasks/abc191_e
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

inline namespace FastIO {
#define SFINAE(x, ...) template <class, class = void> struct x : std::false_type {}; template <class T> struct x<T, std::void_t<__VA_ARGS__>> : std::true_type {}
SFINAE(DefaultI, decltype(std::cin >> std::declval<T &>())); SFINAE(DefaultO, decltype(std::cout << std::declval<T &>())); SFINAE(IsTuples, typename std::tuple_size<T>::type); SFINAE(Iterable, decltype(std::begin(std::declval<T>())));
template <typename T> char sp(T& t) { return (Iterable<T>::value || IsTuples<T>::value) ? '\n' : ' '; }
template <typename T> void re(T& t) { if constexpr (DefaultI<T>::value) { cin >> t; } else if constexpr (Iterable<T>::value) { for (auto& x : t) re(x); } else if constexpr (IsTuples<T>::value) { std::apply([&](auto& ...args) { (re(args), ...); }, t); } }
template <typename T> void pt(T& t) { if constexpr (DefaultO<T>::value) { cout << t; } else if constexpr (Iterable<T>::value) { int i = 0; for (auto&& x : t) ((i++) ? (cout << sp(x), pt(x)) : pt(x)); } else if constexpr (IsTuples<T>::value) { std::apply([&](auto const& ...args) { int i = 0; (((i++) ? (cout << " ", pt(args)) : pt(args)), ...); }, t); } }
template <typename T, typename... Ts> void ps(const string& s, T& t, Ts& ...ts) { pt(t), ((cout << s, pt(ts)), ...), cout << '\n'; } void ps(const string&) { cout << '\n'; }
template <typename... Ts> void print(const Ts& ...ts) { FastIO::ps(" ", ts...); }
template <typename... Ts> void read(Ts& ...ts) { ((FastIO::re(ts)), ...); }
#undef SFINAE
}  // namespace FastIO

inline namespace Util {
#define rep(x)                     for (int _ = (0); _ < (x); ++_)
template <typename T> using V    = vector<T>;
template <typename T> using MnPQ = priority_queue<T, V<T>, greater<T>>;
template <typename T> using MxPQ = priority_queue<T, V<T>, less<T>>;
}  // namespace Util

#ifndef ONLINE_JUDGE
  #define debug(...) do { __VA_ARGS__ } while (0)
#else
  #define debug(...) do {} while (0)
#endif

#define int long long
const int INF = 4e18;
struct Edge {
  int to, w;
};

void solve() {
  int n, m; read(n, m);
  V<V<Edge>> G(n);
  V<int> self(n, INF);
  rep(m) {
    int a, b, c; read(a, b, c); a--, b--;
    if (a == b) {
      self[a] = min(self[a], c);
    } else {
      G[a].push_back({b, c});
    }
  }
  V<V<int>> dist(n, V<int>(n, INF));
  auto dijkstra = [&](int src) -> void {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[src][src] = 0;
    pq.push({0, src});
    while (pq.size()) {
      auto [d, u] = pq.top();
      pq.pop();
      if (d > dist[src][u]) continue;
      for (const auto [v, w] : G[u]) {
        if (dist[src][v] > dist[src][u] + w) {
          dist[src][v] = dist[src][u] + w;
          pq.push({dist[src][v], v});
        }
      }
    }
  };
  for (int i = 0; i < n; ++i) {
    dijkstra(i); // populate dist table
  }
  for (int i = 0; i < n; ++i) {
    int ans = INF;
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      ans = min(ans, dist[i][j] + dist[j][i]);
    }
    ans = min(ans, self[i]);
    print(ans == INF ? -1 : ans);
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; // read(tt);
  rep(tt) solve();
}