// Problem: E. Sponsor of Your Problems
// Contest: Codeforces - Codeforces Round 1032 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2121/E
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
you can't avoid common prefix, so count the common prefix
if nothing left -> done
else -> the immediate next digit must satisfy R[i] > L[i] otherwise r cannot be greater than l
if R[i] - L[i] >= 2 -> we can select L[i]+1, and L[i] < L[i]+1 < R[i], and we can avoid the rest -> done
else -> for the remaining sequence, the only case you cannot avoid having one collision is when L[i] = 9 and R[i] = 0
        you can play around with all the cases to see that's the case.
        as soon as we see a non 0-9 pattern, that means we can freely choose the rest digits for x
        thus we break
     -> done
*/
void solve() {
  int l, r; read(l, r);
  V<int> L, R;
  while (l) L.pb(l%10), l/=10;
  while (r) R.pb(r%10), r/=10;
  reverse(all(L)), reverse(all(R));
  int ans = 0, i = 0;
  // have to take the common prefix
  for (i = 0; i < sz(L); ++i) {
    if (L[i] == R[i]) ans += 2;
    else break;
  }
  if (i == sz(L) || R[i] - L[i] >= 2) {
    print(ans); return;
  }
  debug(assert(i < sz(L)););
  debug(assert(R[i] - L[i] == 1););
  int ans2 = 1;
  // the only case you cannot take a number is 0-9
  for (++i; i < sz(L); ++i) {
    if (R[i] == 0 && L[i] == 9) {
      ans2++;
    } else {
      break;
    }
  }
  print(ans + ans2);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; read(tt);
  rep(tt) solve();
}