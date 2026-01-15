// Problem: E - Erasing Vertices 2
// Contest: AtCoder - NEC Programming Contest 2022 (AtCoder Beginner Contest 267)
// URL: https://atcoder.jp/contests/abc267/tasks/abc267_e
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
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

int N, M;
V<int> A;
unordered_map<int, V<int>> G;
unordered_set<int> used;

void solve() {
  read(N, M);
  A.resize(N), read(A);
  rep(M) {
    int u, v; read(u, v); u--, v--;
    G[u].push_back(v), G[v].push_back(u);
  }
  MinPQ<pair<int, int>> pq;
  unordered_map<int, int> cur;
  for (int i = 0; i < N; ++i) {
    int cost = 0;
    for (const auto adj : G[i]) {
      cost += A[adj];
    }
    cur[i] = cost;
    pq.push({cost, i});
  }
  int ans = LLONG_MIN;
  while (!pq.empty()) {
    const auto [cost, node] = pq.top(); pq.pop();
    if (!used.count(node) && cost == cur[node]) { // valid
      used.insert(node);
      ans = max(ans, cost);
      for (const auto adj : G[node]) {
        cur[adj] = cur[adj] - A[node];
        pq.push({cur[adj], adj});
      }
    }
  }
  print(ans);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; // read(tt);
  rep(tt) solve();
}