// Problem: C. Symmetrical Polygons
// Contest: Codeforces - Codeforces Round 1057 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2153/C
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
// at least 1 pair of even cnt edges - put on the side
// now check degenerate -> longest bottom < sum of all other sides + top
// note that even count edges does not matter. So greedy.
void solve() {
  int n; read(n);
  V<int> a(n); read(a);
  map<int, int> CNT;
  for (const int x : a) {
    CNT[x]++;
  }
  int even = 0;
  for (const auto& p : CNT) {
    even += p.second / 2;
  }
  if (!even) {
    print(0); return;
  }
  V<int> pq;
  int ans = 0;
  for (const auto& p : CNT) {
    if (p.second & 1) {
      pq.push_back(p.first);
      ans += (p.second - 1) * p.first;
    } else {
      ans += p.second * p.first;
    }
  }
  sort(pq.begin(), pq.end());
  // select 0
  const int sel0 = even > 1 ? ans : 0;
  // select 1
  int sel1 = 0;
  for (int i = 0; i < pq.size(); ++i) {
    if (pq[i] < ans) sel1 = max(sel1, ans + pq[i]);
  }
  if (pq.size() == 0) {
    print(sel0);
  } else if (pq.size() == 1) {    
    print(max(sel0, sel1));
  } else {
    // select 2
    int sel2 = 0;
    for (int i = 0; i < pq.size() - 1; ++i) {
      const int tot = ans + pq[i];
      const auto it = lower_bound(pq.begin() + i + 1, pq.end(), tot);
      const int ind = it - pq.begin() - 1;
      if (i < ind) sel2 = max(sel2, tot + pq[ind]);
    }
    print(max({sel0, sel1, sel2}));
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; read(tt);
  rep(tt) solve();
}