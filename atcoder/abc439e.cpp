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

int N, A, B;

/**
 * First thing to note is that if two kite share the same a, then they cannot be fly together.
 * Say that we sort the kites (a, b). k1: (a, b) and k2: (c, d), where a < c.
 * Then k1 and k2 can only be fly together iff b < d.
 * Say that we group the kites into buckets based on a. Then we are trying to find the LIS if we
 *  choose at most one element from each bucket.
 * The tricky part is, how can we enforce only select one element from each group?
 * Thinking about sorting each b in each bucket in reverse. Since we are finding the LIS,
 *  then the element from the same group can never be part of LIS together (since decreasing).
 * Thus the elements forming the LIS must come from different buckets. Problem solved.
 */

void solve() {
  read(N);
  map<int, V<int>> kts;
  rep(N) {
    read(A, B);
    kts[A].push_back(B);
  }
  V<int> a;
  for (auto& p : kts) {
    sort(p.second.begin(), p.second.end(), greater<int>());
    for (const auto e : p.second) {
      a.push_back(e);
    }
  }
  V<int> lis = {a[0]};
  for (int i = 1; i < a.size(); ++i) {
    if (a[i] > lis.back()) {
      lis.push_back(a[i]);
    } else {
      const int low = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
      lis[low] = a[i];
    }
  }
  print(lis.size());
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; // read(tt);
  rep(tt) solve();
}