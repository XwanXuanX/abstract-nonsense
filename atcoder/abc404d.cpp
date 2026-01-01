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

int n, m, sz, tmp;
vector<int> c;
vector<unordered_set<int>> a;
vector<int> pow3;
vector<vector<int>> az;

int check(const vector<int>& zoos) {
  vector<int> seen(m, 0);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += zoos[i] * c[i];
    for (int ani : az[i]) seen[ani] += zoos[i];
  }
  for (int i = 0; i < m; ++i) if (seen[i] < 2) return -1;
  return ans;
}

void solve() {
  read(n, m);
  c.resize(n); read(c);
  a.resize(m);
  for (int i = 0; i < m; ++i) {
    read(sz);
    rep(sz) {
      read(tmp); a[i].insert(tmp);
    }
  }
  // Precalculate the power of 3
  pow3.resize(n + 1, 1);
  for (int i = 1; i <= n; ++i) pow3[i] = pow3[i - 1] * 3;
  int ans = LLONG_MAX;
  az.resize(n);
  for (int i = 0; i < m; ++i) for (const auto zoo : a[i]) az[zoo - 1].push_back(i);
  for (int mk = 0; mk < pow3[n]; ++mk) {
    int x = mk;
    vector<int> bits(n, 0);
    for (int i = 0; i < n; ++i) bits[i] = x % 3, x /= 3;
    DEBUG(print(bits););
    // We need to check for this configuration can we visit all animals
    const int res = check(bits);
    DEBUG(print(res););
    if (res >= 0) ans = min(ans, res);
  }
  print(ans);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int tt = 1; // read(tt);
  rep(tt) solve();
}