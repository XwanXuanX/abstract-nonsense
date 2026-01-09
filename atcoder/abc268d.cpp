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

int N, M;
V<string> S;
string T;
unordered_set<string> avoid;
V<int> cur;
V<V<int>> ways;

void dfs_single(const int NN, const int idx, const int remain) {
  if (idx == NN - 1) {
    cur[idx] = remain + 1;
    ways.push_back(cur);
    return;
  }
  for (int x = 0; x <= remain; ++x) {
    cur[idx] = x + 1;
    dfs_single(NN, idx + 1, remain - x);
  }
}

void dfs_multi(const int NN, const int MM) {
  for (int i = 0; i <= MM; ++i) {
    cur.assign(NN, 0);
    dfs_single(NN, 0, i);
  } 
}

void solve() {
  read(N, M);
  S.resize(N);
  read(S);
  rep(M) {
    read(T);
    avoid.insert(T);
  }
  if (N == 1) {
    print(((S[0].size() < 3 || S[0].size() > 16 || avoid.count(S[0]))
      ? "-1" : S[0]));
    return;
  }
  int tot = 0;
  for (const auto& s : S) {
    tot += s.size();
  }
  const int NN = N - 1;
  const int MM = 16 - tot - NN;
  dfs_multi(NN, MM);
  DEBUG(print(ways););
  sort(S.begin(), S.end());
  do {
    for (const auto& way : ways) {
      string res;
      for (int i = 0; i < static_cast<int>(way.size()); ++i) {
        res += S[i];
        rep(way[i]) res += "_";
      }
      res += S[N-1];
      const int sz = res.size();
      if (3 <= sz && sz <= 16 && !avoid.count(res)) {
        print(res); return;
      }
    }
  } while (next_permutation(S.begin(), S.end()));
  print(-1);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; // read(tt);
  rep(tt) solve();
}