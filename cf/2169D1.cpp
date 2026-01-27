// Problem: D1. Removal of a Sequence (Easy Version)
// Contest: Codeforces - Educational Codeforces Round 184 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/2169/D1
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
#define int                        long long
#define rep(x)                     for (int _ = (0); _ < (x); ++_)
constexpr int INF                = (1ll << 60);
template <typename T> using V    = vector<T>;
template <typename T> using MnPQ = priority_queue<T, V<T>, greater<T>>;
template <typename T> using MxPQ = priority_queue<T, V<T>, less<T>>;
}  // namespace Util

#ifndef ONLINE_JUDGE
  #define debug(...) do { __VA_ARGS__ } while (0)
#else
  #define debug(...) do {} while (0)
#endif

/*
define F(p) = # of survivors after x removal on prefix [1, 2, 3, ..., p]
define S = (s1, s2, s3, ... Sk) be the resulting sequence
note that for any p st. F(p) < k is automatically impossible
we will prove: min{p | F(p) >= k} = Sk.
Hypo: p = minimum integer such that F(p) >= k
Premise: p = Sk
Proof:
| p < Sk: obviously impossible
| p > Sk: but since F(Sk) = k, and Sk < p, then we can find a smaller integer p' st. F(p') >= k, which is Sk.
          this contradicts to the hypo that p is the minimum integer that does this.
since both p < Sk and p > Sk impossible, then p = Sk.
this justifies the binary search solution.
*/
void solve() {
  int x, y, k; read(x, y, k);
  auto check = [&](int p) -> int {
    for (int i = 0; i < x; ++i) p -= p/y;
    return p;
  };
  int l = 1, r = 1e12, ans = INF;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid) >= k) {
      ans = min(ans, mid);
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  print(ans == INF ? -1 : ans);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; read(tt);
  rep(tt) solve();
}