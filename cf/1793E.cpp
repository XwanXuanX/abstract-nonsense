// Problem: E. Velepin and Marketing
// Contest: Codeforces - Codeforces Round 852 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1793/E
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
claim1: the set of satisfied people form a prefix of the sorted array (a1 <= a2 <= ... <= an)
proof1: assume there exists an optimal solution where a[j] is satisfied, and a[i] is not, while i < j.
        let the group where a[j] is in be S and |S| >= a[j]. since a[j] >= a[i], then |S| >= a[i].
        thus we can swap a[j] with a[i] and not making the answer worse.
        as long as the satisfied people is not the prefix, there must exists a[i] unsat and a[j] sat with i < j.
        by continuously applying the above exchange, we can make the optimal solution to be the prefix.

claim2: the satisfied people in a group form a contiguous segment of the prefix
proof2: assume there exists an optimal arrangement for a group G such that it is not contiguous.
        specifically G = {[L, R], [L', R'], ...}, where R+1 < L'. the gap between segment [L, R] and [L', R'], which is [R+1, L'-1], must belong to another group G'.
        we'll try to arrange the optimal solution to the form that we want, while keeping optimality and feasibility.
        we can slide [L, R] to the right and make contact with [L', R'] so that they form a contigous segment.
        at the meantime, the segment [R+1, L'-1] will be squeezed to the left. why this change is valid?
        1) since a[L'] is sat, this means |G| >= a[L'] >= a[L'-1] >= ... a[1]. note that by sliding [L, R] segment, |G| is unchanged.
           thus G can sat the new slided segment.
        2) the segment [R+1, L'-1] is squeezed to the left, which doesn't change the size of |G'|.
           if |G'| >= a[L'-1], then |G'| >= a[L'-1] >= a[L'-2] >= ... >= a[1]. thus it's valid to move that segment left.
        by applying the above exchange continuously, we can eventually make all satisfied group into a contiguous segment.
*/
void solve() {
  int n; read(n);
  V<int> a(n+1);
  for (int i = 1; i <= n; ++i) read(a[i]);
  sort(a.begin()+1, a.end());
  V<int> dp(n+1), pmx(n+1, -INF);
  dp[0] = pmx[0] = 0;; // no people -> no groups
  for (int i = 1; i <= n; ++i) {
    // try to satisfy a[i]
    if (a[i] > i) { // a[i] is unsatisfiable with the prefix
      dp[i] = -INF;
    } else {
      dp[i] = pmx[i-a[i]] + 1;
    }
    chmax(pmx[i], max(dp[i], pmx[i-1]));
  }
  // # of satisfied groups using prefix [1..i] while making everyone satisfied
  // debug(print(dp););
  // for a prefix [1..i], if everyone can be sat, then the group is dp[i].
  // since we won't need to sat the rest of (n-i) people, just put them in the rest of the pot individually to maximize k.
  V<int> canHandle(n+1);
  for (int i = 1; i <= n; ++i) {
    if (dp[i] != -INF) { // can make prefix [1..i] sat using only i people
      canHandle[i] = dp[i] + (n-i);
    } else { // cannot make prefix [1..i] sat using only i people
      // to make prefix [1..i] sat, need to bring more people.
      // put a[1] to a[i] into the same pot, and bring extra (a[i] - i) people in
      canHandle[i] = 1 + (n - a[i]);
    }
  }
  // debug(print(canHandle););
  // for each k, you need to know the max i such that canHandle[i] >= k
  // because if you can handle k groups, then you can handle k-1, k-2, ..., 1 groups by merging.
  V<int> best(n+1, 0);
  for (int i = 1; i <= n; ++i) {
    chmax(best[canHandle[i]], i);
  }
  for (int i = n-1; i > 0; --i) {
    chmax(best[i], best[i+1]);
  }
  int q; read(q);
  rep(q) {
    int k; read(k);
    print(best[k]);
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; // read(tt);
  rep(tt) solve();
}