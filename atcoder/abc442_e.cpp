// Problem: E - Laser Takahashi
// Contest: AtCoder - JPRS Programming Contest 2026#1 (AtCoder Beginner Contest 442)
// URL: https://atcoder.jp/contests/abc442/tasks/abc442_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroint-loops")
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
struct Dir {
  int x, y;
  bool up;
};

bool operator<(const Dir& a, const Dir& b) {
  if (a.up != b.up) return a.up > b.up;
  return a.x * b.y - a.y * b.x < 0;
}

void solve() {
  int n, q; read(n, q);
  vector<Dir> d(n);
  for (int i = 0; i < n; i++) {
    int x, y; read(x, y);
    int g = gcd(llabs(x), llabs(y));
    x /= g; y /= g;
    bool up = (y > 0) || (y == 0 && x > 0);
    d[i] = {x, y, up};
  }
  vector<Dir> all = d;
  sort(all.begin(), all.end());
  vector<Dir> uniq;
  vector<int> cnt;
  for (auto &v : all) {
    if (uniq.empty() ||
        uniq.back().x != v.x ||
        uniq.back().y != v.y ||
        uniq.back().up != v.up) {
      uniq.push_back(v);
      cnt.push_back(1);
    } else {
      cnt.back()++;
    }
  }
  int m = uniq.size();
  vector<int> pref(m + 1, 0);
  for (int i = 0; i < m; i++) pref[i + 1] = pref[i] + cnt[i];
  vector<int> id(n);
  for (int i = 0; i < n; i++) {
    id[i] = lower_bound(uniq.begin(), uniq.end(), d[i]) - uniq.begin();
  }
  rep(q) {
    int a, b; read(a, b); a--, b--;
    int s = id[a], t = id[b];
    int ans;
    if (s == t) ans = cnt[s];
    else if (s < t) ans = pref[t + 1] - pref[s];
    else ans = (pref[m] - pref[s]) + pref[t + 1];
    print(ans);
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; // read(tt);
  rep(tt) solve();
}
