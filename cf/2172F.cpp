// Problem: F. Cluster Computing System
// Contest: Codeforces - 2025 ICPC Asia Taichung Regional Contest (Unrated, Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/problemset/problem/2172/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

// why this solution works:
// to form a tree, we need to add exactly n-1 edges. among all the ways that we can add edges
// what could yield minimum sum of gcds?
// note that gcd on a range is non-increasing and if we connect a[1] with a[n], it will have
// no more cost than connecting a[2] with a[n].
// for l and r, cost(a[l], a[r]) <= cost(a[l+1], a[r]) and cost(a[l], a[r]) <= cost(a[l], a[r-1])
// then we greedily connect the first and the last, since it must have the lowest cost.
// what about internal nodes? say a[x]. where should you connect it to?
// two cases:
// 1. connect with some a[y] where x < y, then by the principle above, just connect with a[n]
// 2. connect with some a[u] wgere u < x, then we are adding a cost(a[u], a[x]). by the principle above, connect a[u] with a[x] is not as good as connect a[u] with a[n], so this is not optimal.
#define int long long
void solve() {
  int n; read(n);
  V<int> a(n); read(a);
  V<int> GCD(n);
  GCD[n-1] = a[n-1];
  for (int i = n - 2; i >= 0; --i) {
    GCD[i] = gcd(GCD[i+1], a[i]);
  }
  for (int i = 1; i < n; ++i) {
    GCD[i] += GCD[i-1];
  }
  V<int> GCDD(n);
  GCDD[0] = a[0];
  for (int i = 1; i < n; ++i) {
    GCDD[i] = gcd(GCDD[i-1], a[i]);
  }
  for (int i = 1; i < n; ++i) {
    GCDD[i] += GCDD[i-1];
  }
  
  // debug(print(GCD); print(GCDD););
  int ans = LLONG_MAX;
  for (int i = n - 2; i >= 0; --i) {
    const int first = GCDD[n-1] - GCDD[i];
    const int rest = GCD[i] - GCD[0];
    ans = min(ans, first + rest);
  }
  print(ans);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; // read(tt);
  rep(tt) solve();
}