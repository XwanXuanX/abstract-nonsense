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
int N;
struct tramp { int x, y, P; };
vector<tramp> A;

bool _check(const int train, const int start) {
  unordered_set<int> vis;
  queue<int> que;
  vis.insert(start), que.push(start);
  while (que.size()) {
    const int nod = que.front(); que.pop();
    assert(vis.count(nod));
    const auto [x, y, P] = A[nod];
    for (int i = 0; i < N; ++i) {
      const __int128_t dist = (__int128_t)llabs(x - A[i].x) + (__int128_t)llabs(y - A[i].y);
      const __int128_t jump = (__int128_t)train * (__int128_t)P;
      if (dist > jump || vis.count(i)) continue;
      vis.insert(i), que.push(i);
    }
  }
  return vis.size() == N;
}

bool check(const int train) {
  int ok = 0;
  for (int i = 0; i < N; ++i) ok |= _check(train, i);
  return ok;
}

void solve() {
  read(N);
  A.resize(N);
  for (int i = 0; i < N; ++i) read(A[i].x, A[i].y, A[i].P);
  int l = 0, r = 1e18, ans = LLONG_MAX;
  while (l <= r) {
    const int mid = l + ((r - l) >> 1);
    if (check(mid)) ans = min(ans, mid), r = mid - 1;
    else l = mid + 1;
  }
  print(ans);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; // read(tt);
  rep(tt) solve();
}