// Problem: B - +1 and -1
// Contest: AtCoder - AtCoder Regular Contest 185
// URL: https://atcoder.jp/contests/arc185/tasks/arc185_b
// Memory Limit: 1024 MB
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

/*
WRONG APPROACH:
you cant decrease a[0], and increase it would make things worse.
if a[i+1] <= a[i], then need to bring a[i+1] == a[i] is the best move; otherwise,
if a[i+1] is too large, it might block the rest, not good. try to distribute as many 1s to the prefix, and continue.
this is how you construct the optimal array
WHY WRONG?
[x, x, x, x, x+1, x+1, x+1] and ..., x+1 + 9 arrives
[x+1, x+1, x+1, x+1, x+2, x+2, x+2, x+3] raise the entire prefix, not good,
Better solution
[x, x, x, x, x+1, x+1, x+1] and ..., x+1 + 9 arrives
[x+1, x+1, x+1, x+2, x+2, x+2, x+2, x+2] first fill the gap then raise, good.
*/
#define int long long
void solve() {
  int n; read(n);
  V<int> a(n); read(a);
  const int sum = accumulate(a.begin(), a.end(), 0ll);
  const int depth = sum / n, remain = sum % n;
  V<int> b(n, depth);
  int pop = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (pop == remain) break;
    b[i] += 1, pop++;
  }
  for (int i = 1; i < n; ++i) {
    b[i] += b[i-1], a[i] += a[i-1];
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] > b[i]) {
      print("No"); return;
    }
  }
  print("Yes");
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; read(tt);
  rep(tt) solve();
}