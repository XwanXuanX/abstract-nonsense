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
int n, m;
vector<int> l, r, s;
struct Edge { int u, v, w; };

void solve() {
  read(n, m);
  l.resize(m), r.resize(m), s.resize(m);
  for (int i = 0; i < m; ++i) read(l[i], r[i], s[i]);
  vector<Edge> edges;
  edges.reserve(n + 2*m);
  // Positivity constrains:
  // Each element in A must be a positive integer, so
  // A_i >= 1  =>  P_i - P_{i-1} >= 1  =>  P_i >= P_{i-1} + 1
  for (int i = 1; i <= n; ++i) edges.push_back({i - 1, i, 1});
  // Range equalities:
  // P_R - P_{L-1} = S => P_R >= P_{L-1} + S => P_{L-1} >= P_R - S
  for (int i = 0; i < m; ++i) {
    const int u = l[i] - 1, v = r[i];
    edges.push_back({u, v, s[i]}), edges.push_back({v, u, -s[i]});
  }
  // Bellman-Ford: longest path to P_v from all `in` sources
  const int NINF = static_cast<int>(-4e18);
  vector<int> dist(n + 1, 0);
  int updated = 0;
  for (int it = 0; it < n + 1; ++it) {
    updated &= 0;
    for (const auto& e : edges) if (dist[e.v] < dist[e.u] + e.w) {
      dist[e.v] = dist[e.u] + e.w, updated |= 1;
    }
    if (!updated) break;
  }
  // If after V iteration still updated, means positive cycle,
  // means P_v >= P_v + W (W > 0), impossible
  print((updated ? -1 : dist[n]));
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; // read(tt);
  rep(tt) solve();
}