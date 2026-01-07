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

int N;
string S, T;

/**
 * This problem is intended to be solved using BFS due to it's suspicously small constraint.
 * BFS does not TLE because the total number of state is small.
 * The tight upper bound for the total number of state is:
 * 1. There are N + 1 ways to place two consecutive empty cells
 * 2. Once we place the empty cells, we must distribute the stones in the remaining N cells
 *    let b = # of black cells and w = # of white cells, and b + w = N
 *    Also notice that once the distribution of black cells are fixed, the distribution of white cells
 *    are also fixed.
 *    So the total number of ways of black distribution: NCb
 * Therefore, the total number of ways to distribute: (N + 1) * (NCb)
 * Thus the upper bound on the total number of states
 */

string move_s(string copy, const int space, const int move) {
  assert(move + 1 < N + 2 && space + 1 < N + 2);
  swap(copy[space], copy[move]), swap(copy[space+1], copy[move+1]);
  return copy;
}

void solve() {
  read(N, S, T);
  for (int i = 0; i < 2; ++i) S.push_back('.'), T.push_back('.');
  unordered_set<string> vis;
  queue<pair<string, int>> que;
  if (S == T) {
    print(0); return;
  }
  que.push({S, 0});
  vis.insert(S);
  while (que.size()) {
    const auto [str, s] = que.front(); que.pop();
    assert(vis.count(str));
    int empty = -1;
    for (int i = 0; i < N + 1; ++i) if (str[i] == '.' && str[i+1] == '.') {
      empty = i;
      break;
    }
    for (int i = 0; i < N + 1; ++i) {
      if (i != empty && i != empty + 1 && i + 1 != empty && i + 1 != empty + 1) {
        const string nstr = move_s(str, empty, i);   
        if (vis.count(nstr)) continue;
        if (nstr == T) {
          print(s + 1); return;
        }
        que.push({nstr, s + 1});
        vis.insert(nstr);
      }
    }
  }
  print(-1);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; // read(tt);
  rep(tt) solve();
}