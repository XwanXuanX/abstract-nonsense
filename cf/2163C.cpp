// Problem: C. Monopati
// Contest: Codeforces - Codeforces Round 1063 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2163/C
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

struct safe_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
template <class K, class V> using safe_map = unordered_map<K, V, safe_hash>;
template <class T> using safe_set = unordered_set<T, safe_hash>;

/*
1 2 3
3 2 1
[1,1] [1,2] [1,3]
[1,3] [1,2] [1,2] -> (1,2) (1,3) (1,4) (1,5) (1,6)
now do you know why they need to make it 2 rows only?
*/
#define int long long
const int inf = 1ll << 60;
void solve() {
  int n; read(n);
  V<V<int>> g(2, V<int>(n)); read(g);
  V<pair<int, int>> top(n), bot(n);
  top[0] = {g[0][0], g[0][0]};
  for (int i = 1; i < n; ++i) {
    top[i] = {min(g[0][i], top[i-1].first), max(g[0][i], top[i-1].second)};
  }
  bot[n-1] = {g[1][n-1], g[1][n-1]};
  for (int i = n - 2; i >= 0; --i) {
    bot[i] = {min(g[1][i], bot[i+1].first), max(g[1][i], bot[i+1].second)};
  }
  V<pair<int, int>> merged(n);
  for (int i = 0; i < n; ++i) {
    auto [tl, tr] = top[i]; auto [bl, br] = bot[i];
    merged[i] = {min(tl, bl), max(tr, br)};
  }
  V<int> grp(2*n + 1, inf); // grp[i] = left as i
  for (int i = 0; i < n; ++i) {
    auto [l, r] = merged[i];
    grp[l] = min(grp[l], r);
  }
  for (int i = 2*n - 1; i >= 1; --i) {
    grp[i] = min(grp[i], grp[i+1]);
  }
  // fix l, and find the smallest r that satisfies
  int ans = 0;
  for (int i = 1; i <= 2*n; ++i) {
    ans += max(0ll, 2*n - grp[i] + 1);
  }
  print(ans);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; read(tt);
  rep(tt) solve();
}