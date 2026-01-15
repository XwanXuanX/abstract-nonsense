// Problem: F - Manhattan Christmas Tree 2
// Contest: AtCoder - UNIQUE VISION Programming Contest 2025 Christmas (AtCoder Beginner Contest 437)
// URL: https://atcoder.jp/contests/abc437/tasks/abc437_f
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma")
#include <bits/stdc++.h>
using namespace std;

#define rep(x)                          for (int _ = (0); _ < (x); ++_)
template <typename T> using V           = vector<T>;
template <typename T> using MinPQ       = priority_queue<T, V<T>, greater<T>>;
template <typename T> using MaxPQ       = priority_queue<T, V<T>, less<T>>;

template <typename T, typename = void> struct DefaultI : std::false_type {}; template <typename T> struct DefaultI<T, std::void_t<decltype(std::cin  >> std::declval<T&>())>> : std::true_type {};
template <typename T, typename = void> struct DefaultO : std::false_type {}; template <typename T> struct DefaultO<T, std::void_t<decltype(std::cout << std::declval<T&>())>> : std::true_type {};
template <typename T, typename = void> struct IsTuples : std::false_type {}; template <typename T> struct IsTuples<T, std::void_t<typename std::tuple_size<T>::type>>         : std::true_type {};
template <typename T, typename = void> struct Iterable : std::false_type {}; template <typename T> struct Iterable<T, std::void_t<decltype(std::begin(std::declval<T>()))>>   : std::true_type {};
template <typename T> char sp(T& t) {return(Iterable<T>::value||IsTuples<T>::value)?'\n':' ';};
template <typename T> void re(T& t) {if constexpr(DefaultI<T>::value){cin>>t;}else if constexpr(Iterable<T>::value){for(auto&x:t)re(x);}else if constexpr(IsTuples<T>::value){std::apply([&](auto&...args){(re(args),...);},t);}};
template <typename T> void pt(T& t) {if constexpr(DefaultO<T>::value){cout<<t;}else if constexpr(Iterable<T>::value){int i=0;for(auto&&x:t)((i++)?(cout<<sp(x),pt(x)):pt(x));}else if constexpr(IsTuples<T>::value){std::apply([&](auto const&...args){int i=0;(((i++)?(cout<<" ",pt(args)):pt(args)),...);},t);}};
template <typename T, typename... Ts> void ps(const string& s, T& t, Ts& ...ts) {pt(t),((cout<<s,pt(ts)),...),cout<<'\n';}; void ps(const string&) {cout<<'\n';};
template <typename... Ts> void print(const Ts& ...ts) {ps(" ", ts...);};
template <typename... Ts> void read(Ts& ...ts) {((re(ts)), ...);};

#ifndef ONLINE_JUDGE
#define DEBUG(...) do { __VA_ARGS__ } while (0)
#else
#define DEBUG(...) do {} while (0)
#endif
#define int long long

struct SegTree {
  int n;
  vector<int> mn, mx;

  SegTree(int _n) {
    n = 1;
    while (n < _n) n <<= 1;
    mn.assign(2 * n, LLONG_MAX), mx.assign(2 * n, LLONG_MIN);
  }

  void build(const vector<int>& a) {
    for (int i = 0; i < (int)a.size(); ++i) mn[n + i] = mx[n + i] = a[i];
    for (int i = n - 1; i > 0; --i) {
      mn[i] = min(mn[i << 1], mn[i << 1 | 1]);
      mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
    }
  }

  void update(int pos, int val) {
    pos += n;
    mn[pos] = mx[pos] = val;
    for (pos >>= 1; pos > 0; pos >>= 1) {
      mn[pos] = min(mn[pos << 1], mn[pos << 1 | 1]);
      mx[pos] = max(mx[pos << 1], mx[pos << 1 | 1]);
    }
  }

  int query_min(int l, int r) {
    int res = LLONG_MAX;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = min(res, mn[l++]);
      if (r & 1) res = min(res, mn[--r]);
    }
    return res;
  }

  int query_max(int l, int r) {
    int res = LLONG_MIN;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = max(res, mx[l++]);
      if (r & 1) res = max(res, mx[--r]);
    }
    return res;
  }
};

// |m|+|n| = max(|m+n|, |m-n|)
// d((x1,y1), (x2,y2)) = |x1-x2| + |y1-y2| = max(|(x1+y1)-(x2+y2)|, |(y1-x1)-(y2-x2)|)
// QP (x, y). C = x+y, D = y-x. max(|C-c|, |D-d|)

int N, Q;
V<pair<int, int>> A;

void solve() {
  read(N, Q);
  A.resize(N), read(A);
  SegTree s(N), t(N);
  V<int> ss(N), tt(N);
  for (int i = 0; i < N; ++i) {
    const auto [x,y] = A[i];
    const int c = x + y, d = y - x;
    ss[i] = c, tt[i] = d;
  }
  s.build(ss), t.build(tt);
  rep(Q) {
    int T; read(T);
    if (T == 1) {
      int i, x, y; read(i, x, y);
      s.update(i-1, x + y), t.update(i-1, y - x);
    } else {
      int L, R, x, y; read(L, R, x, y);
      const int C = x + y, D = y - x;
      const int ansC = max(abs(C - s.query_min(L-1, R)), abs(C - s.query_max(L-1, R)));
      const int ansD = max(abs(D - t.query_min(L-1, R)), abs(D - t.query_max(L-1, R)));
      print(max(ansC, ansD));
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; // read(tt);
  rep(tt) solve();
}