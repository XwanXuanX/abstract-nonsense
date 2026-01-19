// Problem: E. khba Loves to Sleep!
// Contest: Codeforces - Codeforces Round 1062 (Div. 4)
// URL: https://codeforces.com/contest/2167/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

int n, k, x;
V<int> a;
struct Rng {
  int l, r;
  int type;
  int dist() const { // the min dist after the cut
    if (type == 0 || type == 2) return r - l;
    assert(type == 1);
    return (r - l) / 2;
  }
};
struct Cmp {
  bool operator()(const Rng& a, const Rng& b) const {
    const int a_d = a.dist(), b_d = b.dist();
    if (a_d != b_d) return a_d < b_d;
    return a.l > b.l;
  }
};

void solve() {
  read(n, k, x);
  a.resize(n), read(a);
  sort(a.begin(), a.end());
  priority_queue<Rng, V<Rng>, Cmp> pq;
  if (a[0] > 0) pq.push({0, a[0], 0});
  for (int i = 1; i < n; ++i) {
    pq.push({a[i-1], a[i], 1});
  }
  pq.push({a[n-1], x, 2});
  unordered_set<int> ans;
  while (ans.size() < k) {
    const auto [l, r, t] = pq.top(); pq.pop();
    // debug(print(l, r, t););
    if (t == 0) {
      const int PUT = l;
      if (ans.count(PUT)) continue;
      ans.insert(PUT);
      if (PUT + 1 <= r) pq.push({PUT+1, r, 0});
    } else if (t == 2) {
      const int PUT = r;
      if (ans.count(PUT)) continue;
      ans.insert(PUT);
      if (l <= PUT - 1) pq.push({l, PUT - 1, 2});
    } else {
      assert(t == 1);
      const int PUT = l + ((r-l)/2);
      if (ans.count(PUT)) continue;
      ans.insert(PUT);
      if (l <= PUT - 1) pq.push({l, PUT-1, 2});
      if (PUT + 1 <= r) pq.push({PUT+1, r, 0});
    }
  }
  V<int> ANS(ans.begin(), ans.end());
  sort(ANS.begin(), ANS.end());
  print(ANS);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; read(tt);
  rep(tt) solve();
}