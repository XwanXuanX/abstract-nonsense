// Problem: E. The Robotic Rush
// Contest: Codeforces - Codeforces Round 1074 (Div. 4)
// URL: https://codeforces.com/contest/2185/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma")
#include <bits/stdc++.h>
using namespace std;

inline namespace FastIO {
#define SFINAE(x, ...) template <class, class = void> struct x : std::false_type {}; \
                       template <class T> struct x<T, std::void_t<__VA_ARGS__>> : std::true_type {}
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

int n, m, k;
V<int> a, b;
string spi;

void solve() {
  read(n, m, k);
  a.resize(n), read(a);
  b.resize(m), read(b);
  read(spi);
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  V<int> mn(k + 1), mx(k + 1);
  int cur = 0;
  mn[0] = mx[0] = 0;
  for (int i = 1; i <= k; ++i) {
    if (spi[i - 1] == 'L') cur--;
    else cur++;
    mn[i] = min(mn[i - 1], cur);
    mx[i] = max(mx[i - 1], cur);
  }
  V<int> die(n, k + 1);
  for (int i = 0; i < n; ++i) {
    int pos = a[i];
    auto it = lower_bound(b.begin(), b.end(), pos);
    for (int t = 0; t < 2; ++t) {
      if (t == 0 && it == b.end()) continue;
      if (t == 1 && it == b.begin()) continue;
      const int spike = (t == 0 ? *it : *prev(it));
      const int need = spike - pos;
      int l = 1, r = k, best = k + 1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (mn[mid] <= need && mx[mid] >= need) {
          best = mid;
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      die[i] = min(die[i], best);
    }
  }
  V<int> cnt(k + 2);
  for (int i = 0; i < n; ++i) {
    if (die[i] <= k) cnt[die[i]]++;
  }
  V<int> ans(k);
  int alive = n;
  for (int i = 1; i <= k; ++i) {
    alive -= cnt[i];
    ans[i-1] = alive;
  }
  print(ans);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; read(tt);
  rep(tt) solve();
}