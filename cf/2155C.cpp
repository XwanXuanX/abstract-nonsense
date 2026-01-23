// Problem: C. The Ancient Wizards' Capes
// Contest: Codeforces - Codeforces Round 1056 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2155/C
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

// 1 3 2
// |1  |2  3|
void solve() {
  int n; read(n);
  V<int> a(n); read(a);
  if (n == 1) {
    print(2); return;
  }
  auto check =[&](const V<bool>& c) -> bool {
    V<int> L(n, 0), R(n, 0);
    L[0] = c[0] == 0 ? 1 : 0, R[n-1] = c[n-1] == 1 ? 1 : 0;
    for (int i = 1; i < n; ++i) {
      L[i] += L[i-1] + (c[i] == 0 ? 1 : 0);
    }
    for (int i = n - 2; i >= 0; --i) {
      R[i] += R[i+1] + (c[i] == 1 ? 1 : 0);
    }
    for (int i = 0; i < n; ++i) {
      int l = i > 0 ? L[i-1] : 0;
      int r = i < n-1 ? R[i+1] : 0;
      if (a[i] != l + r + 1) return false;
    }
    return true;
  };
  if (abs(a[1]-a[0]) == 0) { // 2 versions
    V<bool> c1(n), c2(n);
    c1[0] = 0, c1[1] = 1;
    c2[0] = 1, c2[1] = 0;
    for (int i = 1; i < n; ++i) {
      if (a[i] - a[i-1] == 0) c1[i] = !c1[i-1], c2[i] = !c2[i-1];
      else c1[i] = c1[i-1], c2[i] = c2[i-1];
    }
    int ans = check(c1) + check(c2);
    print(ans);
  } else { // 1 version
    V<bool> c(n);
    if (a[1] - a[0] == 1) c[0] = 0, c[1] = 0;
    else c[0] = 1, c[1] = 1;
    for (int i = 1; i < n; ++i) {
      if (a[i] - a[i-1] == 0) c[i] = !c[i-1];
      else c[i] = c[i-1];
    }
    print(check(c));
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; read(tt);
  rep(tt) solve();
}