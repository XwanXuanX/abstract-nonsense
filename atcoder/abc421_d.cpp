// Problem: D - RLE Moving
// Contest: AtCoder - AtCoder Beginner Contest 421
// URL: https://atcoder.jp/contests/abc421/tasks/abc421_d
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
#define int long long

struct Seg {
  int len;
  char dirT, dirA;
};

void solve() {
  int Rt, Ct, Ra, Ca; read(Rt, Ct, Ra, Ca);
  int N, M, L; read(N, M, L);
  V<char> S, T;
  V<int> A, B;
  rep(M) {
    char x; int y; read(x, y);
    S.push_back(x), A.push_back(y);
  }
  rep(L) {
    char x; int y; read(x, y);
    T.push_back(x), B.push_back(y);
  }
  const V<Seg> seg = [&]() -> V<Seg> {
    int i = 0, j = 0;
    int remA = A[0], remB = B[0];
    V<Seg> segments;
    while (i < (int)S.size() && j < (int)T.size()) {
      int len = min(remA, remB);
      segments.push_back({len, S[i], T[j]});
      remA -= len, remB -= len;
      if (remA == 0) {
        i++;
        if (i < (int)S.size()) remA = A[i];
      }
      if (remB == 0) {
        j++;
        if (j < (int)T.size()) remB = B[j];
      }
    }
    return segments;
  }();
  int ans = 0;
  auto handle = [&](int r, int c, int l, char dir) -> pair<int, int> {
    if (dir == 'U') return {r-l, c};
    if (dir == 'D') return {r+l, c};
    if (dir == 'L') return {r, c-l};
    assert(dir == 'R'); return {r, c+l};
  };
  auto dir_vec = [&](char d) -> pair<long long,long long> {
    if (d == 'U') return {-1, 0};
    if (d == 'D') return { 1, 0};
    if (d == 'L') return { 0,-1};
    return {0, 1}; // 'R'
  };
  for (const auto [len, dirT, dirA] : seg) {
    const auto [nRt, nCt] = handle(Rt, Ct, len, dirT);
    const auto [nRa, nCa] = handle(Ra, Ca, len, dirA);
    long long dx = Rt - Ra;
    long long dy = Ct - Ca;
    auto [vTx, vTy] = dir_vec(dirT);
    auto [vAx, vAy] = dir_vec(dirA);
    long long vx = vTx - vAx;
    long long vy = vTy - vAy;
    if (vx == 0 && vy == 0) {
      ans += (dx == 0 && dy == 0) ? len : 0;
    } else {
      bool ok = true;
      long long kx = LLONG_MIN, ky = LLONG_MIN;
      if (vx == 0) {
        if (dx != 0) ok = false;
      } else {
        if (-dx % vx != 0) ok = false;
        else kx = (-dx) / vx;
      }
      if (vy == 0) {
        if (dy != 0) ok = false;
      } else {
        if (-dy % vy != 0) ok = false;
        else ky = (-dy) / vy;
      }
      if (ok) {
        long long k;
        if (kx == LLONG_MIN) k = ky;
        else if (ky == LLONG_MIN) k = kx;
        else if (kx == ky) k = kx;
        else ok = false;
        ans += (ok && 1 <= k && k <= len);
      }
    }
    Rt = nRt, Ct = nCt, Ra = nRa, Ca = nCa;
  }
  print(ans);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; // read(tt);
  rep(tt) solve();
}