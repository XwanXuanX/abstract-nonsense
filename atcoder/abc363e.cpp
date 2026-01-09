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

int H, W, Y;
V<V<int>> A, mark;
map<int, V<pair<int, int>>> wait_;
unordered_map<int, int> cnt;
struct Cord { int x, y, m; };
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void solve() {
  read(H, W, Y);
  A.assign(H, V<int>(W, 0));
  mark.assign(H, V<int>(W, 0));
  read(A);
  for (int j = 0; j < W; ++j) {
    wait_[A[0][j]].push_back({0, j}), wait_[A[H-1][j]].push_back({H-1, j});
  }
  for (int i = 1; i < H - 1; ++i) {
    wait_[A[i][0]].push_back({i, 0}), wait_[A[i][W-1]].push_back({i, W-1});
  }
  int visited = 0;
  queue<Cord> que;
  while (visited < H*W) {
    const auto& it = wait_.begin();
    const auto& [with, sts] = *it;
    for (const auto& [i, j] : sts) if (mark[i][j] == 0) {
      que.push({i, j, with});
      mark[i][j] = with;
      visited++;
    }
    wait_.erase(wait_.begin());
    while (que.size()) {
      const auto [i, j, m] = que.front(); que.pop();
      assert(mark[i][j] == m);
      for (int o = 0; o < 4; ++o) {
        const int ni = i + dx[o], nj = j + dy[o];
        if (ni < 0 || ni >= H || nj < 0 || nj >= W || mark[ni][nj] != 0) continue;
        if (A[ni][nj] <= m) { // we can visit this now
          que.push({ni, nj, m});
          mark[ni][nj] = m;
          visited++;
        } else { // we'll visit this later
          wait_[A[ni][nj]].push_back({ni, nj});
        }
      }
    }
  }
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cnt[mark[i][j]]++;
    }
  }
  int tot = H*W;
  for (int q = 1; q <= Y; ++q) {
    tot -= cnt[q];
    print(tot);
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; // read(tt);
  rep(tt) solve();
}