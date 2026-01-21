// Problem: C. Kanade's Perfect Multiples
// Contest: Codeforces - Codeforces Round 1068 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2173/C
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

/*
For a chosen mn, the inner loop visits all multiples mn * j ≤ k.
A value x in the array can be visited once for each chosen mn that divides x.
Thus, total inner-loop work ≤ sum_{x ∈ a} d(x), where d(x) is the number of divisors of x.
For k ≤ 1e9, max d(x) ≤ 1344, so total inner iterations ≤ 1344 * n.
Overall complexity:
- Sorting: O(n log n)
- Inner loops: O(1344 * n)
Final: O(n log n)
*/
void solve() {
  int n, k; read(n, k);
  V<int> a(n); read(a);
  sort(a.begin(), a.end());
  unordered_map<int, int> mark;
  for (const int x : a) mark[x] = 0;
  set<int> ans;
  for (int i = 0; i < n; ++i) {
    assert(mark.count(a[i]));
    if (mark[a[i]] > 0) continue;
    const int mn = a[i];
    ans.insert(mn);
    for (int j = 1; mn*j <= k; ++j) {
      if (!mark.count(mn*j)) {
        print(-1); return;        
      } else {
        mark[mn*j]++;
      }
    }
  }
  print(ans.size());
  print(ans);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; read(tt);
  rep(tt) solve();
}