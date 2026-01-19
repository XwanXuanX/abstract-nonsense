// Problem: F. Tree, TREE!!!
// Contest: Codeforces - Codeforces Round 1062 (Div. 4)
// URL: https://codeforces.com/contest/2167/problem/F
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
template <typename T> using V    = vector<T>;
template <typename T> using MnPQ = priority_queue<T, V<T>, greater<T>>;
template <typename T> using MxPQ = priority_queue<T, V<T>, less<T>>;
}  // namespace Util

#ifndef ONLINE_JUDGE
  #define debug(...) do { __VA_ARGS__ } while (0)
#else
  #define debug(...) do {} while (0)
#endif

// for a random root, you can only add nodes whose subtree size >= k
// now the problem is, for all nodes as the root, calculate the number of subtrees
// whose size >= k quickly

struct FenwickTree {
  vector<int> bit;  // binary indexed tree
  int n;

  FenwickTree(int n) {
    this->n = n;
    bit.assign(n, 0);
  }

  FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
    for (size_t i = 0; i < a.size(); i++) add(i, a[i]);
  }

  int sum(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
    return ret;
  }

  int sum(int l, int r) {
    return sum(r) - sum(l - 1);
  }

  void add(int idx, int delta) {
    for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;
  }
};

void solve() {
  int n, k; read(n, k);
  V<V<int>> tr(n+1);
  rep(n-1) {
    int u, v; read(u, v);
    tr[u].push_back(v), tr[v].push_back(u);
  }
  V<int> sub(n+1, 0);
  function<int(const int, const int)> dfs;
  dfs = [&](const int nod, const int par) -> int {
    if (tr[nod].size() == 1 && tr[nod][0] == par) {
      return sub[nod] = 1;
    }
    int tot = 0;
    for (const auto adj : tr[nod]) {
      if (adj == par) continue;
      tot += dfs(adj, nod);
    }
    return sub[nod] = tot + 1;
  };
  dfs(1, 0);
  V<int> cnt(n+1, 0);
  for (int i = 1; i <= n; ++i) {
    assert(sub[i] <= n);
    cnt[sub[i]]++;
  }
  FenwickTree BIT(cnt);
  int ans = 0;
  function<void(const int, const int)> dfs2;
  dfs2 = [&](const int nod, const int par) -> void {
    // assume BIT has been adjusted for the new root
    ans += BIT.sum(k, n);
    if (tr[nod].size() == 1 && tr[nod][0] == par) return;
    for (const auto adj : tr[nod]) {
      if (adj == par) continue;
      const int save_nod = sub[nod], save_adj = sub[adj];
      // adjust BIT
      BIT.add(sub[nod], -1), BIT.add(sub[adj], -1);
      sub[nod] = save_nod - save_adj, sub[adj] = save_nod;
      BIT.add(sub[nod], +1), BIT.add(sub[adj], +1);
      dfs2(adj, nod);
      // restore BIT
      BIT.add(sub[nod], -1), BIT.add(sub[adj], -1);
      sub[nod] = save_nod, sub[adj] = save_adj;
      BIT.add(sub[nod], +1), BIT.add(sub[adj], +1);
    }
  };
  dfs2(1, 0);
  print(ans);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; read(tt);
  rep(tt) solve();
}