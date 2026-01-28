// Problem: C. Ultimate Value
// Contest: Codeforces - Codeforces Round 1049 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2140/C
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
#define int     long long
#define double  long double
#define pb      push_back
#define sz(x)   (int)((x).size())
#define rep(x)  for (int _ = (0); _ < (x); ++_)
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

constexpr int INF    = 1ll << 60;
constexpr int MOD    = 1'000'000'007; // 998'244'353;
constexpr double EPS = 1e-12L;
constexpr double PI  = 3.141592653589793238462643383279502884L;
constexpr array<int, 4> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

template <typename T> using V    = vector<T>;
template <typename T> using MnPQ = priority_queue<T, V<T>, greater<T>>;
template <typename T> using MxPQ = priority_queue<T, V<T>, less<T>>;
template <typename T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } return false; }
template <typename T> bool chmax(T& a, const T& b) { if (b > a) { a = b; return true; } return false; }
}  // namespace Util

#ifndef ONLINE_JUDGE
  #define debug(...) do { __VA_ARGS__ } while (0)
#else
  #define debug(...) do {} while (0)
#endif

/*
swap will only happen ONCE, by alice. this is why:
assume that alice swapped. then bob has two choices:
1) swap for good: then alice can end the game on the next turn -> bad for bob -> no
2) swap for bad: then alice can redo bob's swap, which adds twice the cost.
   then bob has two choices:
   1) end the game: the arrangment is still what alice wants + additional cost -> bad for bob -> better to end early
   2) continue doing: but the game can goes upto 10^100, even each swap costs 1, the final score can still be O(10^100) >> O(10^5 - 10^14).
      this means if bob continue to do this, alice can make the score better and better. so eventually bob has to end the game.
      so bob might as well just end the game immediately.
*/
void solve() {
  int n; read(n);
  V<int> a(n); read(a);
  int no = 0;
  for (int i = 0; i < n; ++i) {
    if (i & 1) no -= a[i];
    else no += a[i];
  }
  // if the current arrangement is good
  // then we can just swap the farest with the same parity
  const int org = no;
  if (n & 1) no += n - 1;
  else no += n - 2;
  // otherwise, we need to perform different parity swap
  int yes = -INF;
  int minOE = INF, minEO = INF;
  for (int i = 0; i < n; ++i) {
    if (i%2 == 0) {
      chmin(minOE, 2*a[i] + i);
    } else {
      chmax(yes, org + (2*a[i] + i) - minOE);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i%2 == 1) {
      chmin(minEO, i - 2*a[i]);
    } else {
      chmax(yes, org + (i - 2*a[i]) - minEO);
    }
  }
  print(max(yes, no));
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; read(tt);
  rep(tt) solve();
}