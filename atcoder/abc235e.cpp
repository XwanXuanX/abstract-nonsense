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

int N, M, Q, u, v, w;

struct edge {
  int a, b, c;
  bool operator<(const edge& other) const {
    return c < other.c;
  }
  friend ostream& operator<<(ostream& os, const edge& e);
};
ostream& operator<<(ostream& os, const edge& e) {
  os << e.a << ' ' << e.b << ' ' << e.c << '\n';
  return os;
}
V<edge> edges;

struct DSU {
  vector<int> parent, rank;

  DSU(const int n) {
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    rank.assign(n, 1);
  }
  
  void make_set(int v) {
    parent[v] = v, rank[v] = 0;
  }

  int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
  }

  void union_sets(int a, int b) {
    a = find_set(a), b = find_set(b);
    if (a != b) {
      if (rank[a] < rank[b]) swap(a, b);
      parent[b] = a;
      if (rank[a] == rank[b]) rank[a]++;
    }
  }
};

V<edge> mst;

struct MSTPathMax {
  int N, LOG;
  vector<vector<pair<int,int>>> adj;
  vector<vector<int>> parent, mx;
  vector<int> depth;

  MSTPathMax(int n) : N(n) {
    LOG = 0;
    while ((1 << LOG) <= N) LOG++;
    adj.assign(N + 1, {});
    parent.assign(LOG, vector<int>(N + 1, 0));
    mx.assign(LOG, vector<int>(N + 1, 0));
    depth.assign(N + 1, 0);
  }

  void add_edge(int u, int v, int w) {
    adj[u].push_back({v, w}), adj[v].push_back({u, w});
  }

  void dfs(int v, int p, int w) {
    parent[0][v] = p;
    mx[0][v] = w;
    for (auto [to, wt] : adj[v]) {
      if (to == p) continue;
      depth[to] = depth[v] + 1;
      dfs(to, v, wt);
    }
  }

  void build(int root = 1) {
    dfs(root, 0, 0);
    for (int k = 1; k < LOG; k++) {
      for (int v = 1; v <= N; v++) {
        parent[k][v] = parent[k-1][ parent[k-1][v] ];
        mx[k][v] = max(mx[k-1][v], mx[k-1][ parent[k-1][v] ]);
      }
    }
  }

  int query(int u, int v) {
    int ans = 0;
    if (depth[u] < depth[v]) swap(u, v);
    for (int k = LOG - 1; k >= 0; k--) if (depth[u] - (1 << k) >= depth[v]) {
      ans = max(ans, mx[k][u]);
      u = parent[k][u];
    }
    if (u == v) return ans;
    for (int k = LOG - 1; k >= 0; k--) if (parent[k][u] != parent[k][v]) {
      ans = max({ans, mx[k][u], mx[k][v]});
      u = parent[k][u], v = parent[k][v];
    }
    ans = max(ans, mx[0][u]);
    ans = max(ans, mx[0][v]);
    return ans;
  }
};

void solve() {
  read(N, M, Q);
  rep(M) {
    read(u, v, w);
    if (u != v) edges.push_back({u, v, w});
  }
  DSU dsu(N + 1);
  sort(edges.begin(), edges.end());
  for (const auto e : edges) {
    if (dsu.find_set(e.a) != dsu.find_set(e.b)) {
      mst.push_back(e);
      dsu.union_sets(e.a, e.b);
    }
  }
  DEBUG(print(mst););
  MSTPathMax solver(N);
  for (const auto& e : mst) {
    solver.add_edge(e.a, e.b, e.c);
  }
  solver.build();
  rep(Q) {
    read(u, v, w);
    if (u == v) {
      print("No");
    } else {
      const int mx = solver.query(u, v);
      print((w < mx ? "Yes" : "No"));
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; // read(tt);
  rep(tt) solve();
}