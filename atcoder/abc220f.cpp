#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma")
#include <bits/stdc++.h>
using namespace std;

#define all(x)                          x.begin(), x.end()
#define rep(x)                          for (int _ = (0); _ < (x); ++_)
template <typename T> using V           = vector<T>;
template <typename T> using pr          = pair<T, T>;
template <typename T> using minPq       = priority_queue<T, V<T>, greater<T>>;
template <typename T> using maxPq       = priority_queue<T, V<T>, less<T>>;

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
int N, u, v;
V<V<int>> tree;
V<unordered_map<int, int>> subsz;
int tot;
V<int> ans;

int dfs_sub(const int node, const int par) {
  // This dfs finds the subtree size BELOW the node
  if (tree[node].size() == 1 && tree[node][0] == par) return 1;
  for (const auto adj : tree[node]) {
    if (adj == par) continue;
    assert(!subsz[node].count(adj));
    subsz[node][adj] = dfs_sub(adj, node);
  }
  int below = 0;
  for (const auto& p : subsz[node]) {
    below += p.second;
  }
  return below + 1;
}

void dfs_reroot(const int node, const int par) {
  // This dfs finds the subtree size ABOVE the node, after rerooting
  if (tree[node].size() == 1 && tree[node][0] == par) return;
  for (const auto adj : tree[node]) {
    if (adj == par) continue;
    assert(!subsz[adj].count(node));
    subsz[adj][node] = tot - subsz[node][adj] + 1;
    dfs_reroot(adj, node);
  }
}

void dfs_query(const int node, const int par) {
  // This dfs answers the per-node query
  ans[node] = ans[par] - subsz[par][node] + (1) + (tot - subsz[par][node]);
  if (tree[node].size() == 1 && tree[node][0] == par) return;
  for (const auto adj : tree[node]) {
    if (adj == par) continue;
    dfs_query(adj, node);
  }
}

void solve() {
  read(N);
  ans.assign(N + 1, 0);
  tree.resize(N + 1);
  subsz.resize(N + 1);
  rep(N - 1) {
    read(u, v);
    tree[u].push_back(v), tree[v].push_back(u);
  }
  dfs_sub(1, 0);
  tot = 0;
  for (const auto& p : subsz[1]) {
    tot += p.second;
  }
  dfs_reroot(1, 0);
  DEBUG(print(tot););
  DEBUG(for (int i = 1; i <= N; ++i) print("Node " + to_string(i)), print(subsz[i]););
  queue<pair<int, int>> que;
  unordered_set<int> vis;
  que.push({1, 0}), vis.insert(1);
  while (que.size()) {
    const auto [node, s] = que.front(); que.pop();
    assert(vis.count(node));
    for (const auto adj : tree[node]) {
      if (vis.count(adj)) continue;
      ans[1] += s + 1;
      que.push({adj, s + 1}), vis.insert(adj);
    }
  }
  DEBUG(print(ans[1]););
  for (const auto adj : tree[1]) {
    dfs_query(adj, 1);
  }
  for (int i = 1; i <= N; ++i) {
    print(ans[i]);
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; // read(tt);
  rep(tt) solve();
}