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

constexpr int inf = 1e9;
struct Entry { int dist, src; };
int N, M, u, v;
V<V<int>> G;
string S;

void solve() {
  read(N, M);
  G.resize(N + 1);
  rep(M) {
    read(u, v);
    G[u].push_back(v), G[v].push_back(u);
  }
  read(S);
  S = " " + S;
  V<array<Entry, 2>> best(N + 1, {{{inf, -1}, {inf, -1}}});
  queue<pair<int, int>> que;
  for (int i = 1; i <= N; ++i) if (S[i] == 'S') {
    best[i][0] = {0, i};
    que.push({i, i});
  }
  while (que.size()) {
    auto [u, src] = que.front(); que.pop();
    int cur_dist = -1;
    if (best[u][0].src == src) cur_dist = best[u][0].dist;
    else if (best[u][1].src == src) cur_dist = best[u][1].dist;
    else continue;
    for (const int v : G[u]) {
      const int nd = cur_dist + 1;
      if (best[v][0].src == src || best[v][1].src == src) continue;
      if (nd < best[v][0].dist) {
        best[v][1] = best[v][0];
        best[v][0] = {nd, src};
        que.push({v, src});
      } else if (nd < best[v][1].dist) {
        best[v][1] = {nd, src};
        que.push({v, src});
      }
    }
  }
  for (int i = 1; i <= N; ++i) {
    if (S[i] == 'D') print(best[i][0].dist + best[i][1].dist);
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; // read(tt);
  rep(tt) solve();
}