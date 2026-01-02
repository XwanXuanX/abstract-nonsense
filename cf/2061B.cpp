#pragma GCC optimize("Ofast,unroll-loops")
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

int n;
vector<int> a;
#define int long long

/**
 * 5 5 5 10 -> 0 0 5
 * 0 0 0
 * 0 0 5
 */
void solve() {
  read(n);
  a.resize(n), read(a);
  // 2*Side > Bottom - Top
  sort(a.begin(), a.end());
  vector<int> diff, pmn(n - 1, LLONG_MAX), smn(n - 1, LLONG_MAX);
  for (int i = 1; i < n; ++i) diff.push_back(a[i] - a[i - 1]);
  pmn[0] = diff[0], smn[n - 2] = diff[n - 2];
  for (int i = 1; i < n - 1; ++i) pmn[i] = min({pmn[i], pmn[i - 1], diff[i]});
  for (int i = n - 3; i >= 0; --i) smn[i] = min({smn[i], smn[i + 1], diff[i]});
  for (int i = 1; i < n; ++i) if (a[i] == a[i - 1]) {
    const int side = 2 * a[i];
    const int lmn = i - 3 >= 0 ? pmn[i - 3] : LLONG_MAX, rmn = i + 1 < n - 1 ? smn[i + 1] : LLONG_MAX;
    const int cross = i - 2 >= 0 && i + 1 < n ? a[i + 1] - a[i - 2] : LLONG_MAX;
    if (side > cross) {
      print(a[i], a[i - 1], a[i - 2], a[i + 1]); return;
    }
    if (side > lmn) {
      for (int j = i - 2; j > 0; --j) if (a[j] - a[j - 1] == lmn) {
        print(a[i], a[i - 1], a[j], a[j - 1]); return;
      }
    }
    if (side > rmn) {
      for (int j = i + 1; j < n - 1; ++j) if (a[j + 1] - a[j] == rmn) {
        print(a[i], a[i - 1], a[j], a[j + 1]); return;
      }
    }
  }
  print(-1);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; read(tt);
  rep(tt) solve();
}