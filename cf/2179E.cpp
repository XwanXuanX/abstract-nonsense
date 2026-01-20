// Problem: E. Blackslex and Girls
// Contest: Codeforces - Codeforces Round 1071 (Div. 3)
// URL: https://codeforces.com/contest/2179/problem/E
// Memory Limit: 256 MB
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
// up[i] = p[i], lo[i] = ceil(p[i] / 2), rng[i] = [lo[i], up[i]]

#define int long long
void solve() {
  int n, x, y; read(n, x, y);
  string s; read(s);
  V<int> p(n); read(p);
  const int acc = accumulate(p.begin(), p.end(), 0ll);
  if (x+y < acc) { print("NO"); return; }
  // since each district MUST have p[i] voters, then there MUST be at least (p/2) + 1
  // designated winner, this is a HARD requirement
  for (int i = 0; i < n; ++i) {
    const int des = (p[i]/2) + 1;
    if (s[i] == '0') x -= des;
    else y -= des;
    if (x < 0 || y < 0) { print("NO"); return; }
  }
  int dist = 0;
  for (int i = 0; i < n; ++i) {
    const int c = s[i] - '0';
    assert(c == 0 || c == 1);
    dist |= (1<<c);
  }
  if (dist&(1<<0) && dist&(1<<1)) { // both winners appears
    // designated winner is secured for each i. since x+y >= sum(p), the rest is at least
    // large enough to fill the blanks. now p[i] is fulfilled for all i. but there can be leftovers.
    // for whoever is leftover, put all of them into the district where they are the designated winner.
    // done.
    print("YES"); return;
  }
  // only one winner appears, call it x
  // at least x can win all district, use y to fill the blanks.
  // there might be leftovers for x and y, call it x' and y'; if x' >= y' -> fine
  // in case of y' > x', let z = # of even p[i] for all i, there are two cases:
  // 1. y' <= z: -> fine
  // 2. let y'' = y' - z, there are two cases:
  //    1) y'' <= x' -> fine.
  //    2) y'' > x' -> not fine. no p[i] can handle one more y. but there is not enough x to compensate for y.. oops!
  int z = 0;
  for (int i = 0; i < n; ++i) if (p[i] % 2 == 0) z++;
  auto judge = [&](const int x, const int y) -> bool {
    const int xp = x;
    int yp = y;
    for (int i = 0; i < n; ++i) {
      yp -= (p[i] - ((p[i]/2) + 1));
    }
    if (xp >= yp || yp <= z) return true;;
    const int ypp = yp - z;
    return ypp <= xp;
  };
  if (dist&(1<<0)) print(judge(x, y) ? "YES" : "NO");
  else print(judge(y, x) ? "YES" : "NO");
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; read(tt);
  rep(tt) solve();
}