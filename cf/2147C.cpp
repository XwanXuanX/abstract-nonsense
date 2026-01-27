// Problem: C. Rabbits
// Contest: Codeforces - Codeforces Global Round 29 (Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/2147/C
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
#define int                        long long
#define rep(x)                     for (int _ = (0); _ < (x); ++_)
constexpr int INF                = (1ll << 60);
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
note that 11....11 is an individual segment, everything in there MUST resolve itself
isolate all such segments and find all the subsegment that is made up by contiguous 0s
only two cases that it's valid:
1) at least one subsegment's length is 2
2) if not 1, then the pattern is like 1010101...010101. to be feasible, the number of 0s in the segment must be even.
note that the left and right boarder needs special treatment
*/
void solve() {
  int n; read(n);
  string s; read(s);
  V<pair<int, int>> seg;
  {
    int start = 0;
    for (int i = 1; i < n; ++i) if (s[i] != s[i-1]) {
      seg.push_back({start, i-1});
      start = i;
    }
    seg.push_back({start, n-1});
  }
  auto val = [&](pair<int, int>& sg) -> char { return s[sg.first]; };
  auto len = [&](pair<int, int>& sg) -> int { return sg.second - sg.first + 1; };
  auto divider = [&](pair<int, int>& sg) -> bool { return val(sg) == '1' && len(sg) >= 2; };
  
  int starto = 0, end = seg.size() - 1;
  if (val(seg[0]) == '1') {
    starto = 1;
  } else { // find the index immediately to the right of the first '11'
    while (starto < seg.size() && !divider(seg[starto])) starto++;
  }
  if (val(seg[end]) == '1') {
    end = end - 1;
  } else {
    while (end >= 0 && !divider(seg[end])) end--;
  }
  
  // debug(print(starto, end););
  if (starto > end) { // nothing to check
    print("YES"); return;
  }
  
  int start2 = starto;
  V<pair<int, int>> seg2;
  for (int i = starto + 1; i <= end; ++i) if (divider(seg[i])) {
    seg2.push_back({start2, i-1});
    start2 = i;
  }
  seg2.push_back({start2, end});
  for (auto [l, r] : seg2) {
    int len2 = 0, n0 = 0;
    for (int i = l; i <= r; ++i) {
      if (val(seg[i]) == '0') {
        if (len(seg[i]) >= 2) len2 |= 1;
        n0++;
      }
    }
    if (!len2 && n0 % 2) {
      print("NO"); return;
    }
  }
  print("YES");
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; read(tt);
  rep(tt) solve();
}