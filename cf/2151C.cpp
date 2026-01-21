// Problem: C. Incremental Stay
// Contest: Codeforces - Codeforces Round 1053 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2151/C
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

#define int long long
void solve() {
  int n; read(n);
  V<int> a(2*n);
  read(a);
  sort(a.begin(), a.end());
  a.insert(a.begin(), 0);
  V<int> pref(2*n+1, 0), odd(2*n+1, 0), even(2*n+1, 0);
  for (int i = 1; i <= 2*n; ++i) {
    pref[i] = pref[i-1] + a[i];
    odd[i] = odd[i-1] + ((i & 1) ? a[i] : 0);
    even[i] = even[i-1] + ((i & 1) ? 0 : a[i]);
  }
  auto sum = [&](const V<int>& p, int l, int r) {
    if (l > r) return 0LL;
    return p[r] - p[l-1];
  };
  V<int> ans;
  for (int k = 1; k <= n; ++k) {
    const int t = k - 1;
    const int long_part = (pref[2*n] - pref[2*n - t]) - pref[t];
    const int L = t + 1, R = 2*n - t;
    const int evenSum = sum(even, L, R);
    const int oddSum = sum(odd, L, R);
    const int mid_part = (L & 1) ? (evenSum - oddSum) : (oddSum - evenSum);
    ans.push_back(long_part + mid_part);
  }
  print(ans);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; read(tt);
  rep(tt) solve();
}