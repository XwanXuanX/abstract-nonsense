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

int H, W;
string in;
int cnt[26] = {0};

void solve() {
  read(H, W);
  memset(cnt, 0, sizeof(cnt));
  rep(H) {
    read(in);
    for (const auto c : in) cnt[c - 'a']++;
  }
  // Distribute into the regions
  int pairof4 = (H/2) * (W/2);
  while (pairof4) {
    int done = 0;
    for (int i = 0; i < 26; ++i) if (cnt[i] >= 4) {
      const int take = min(pairof4, cnt[i] / 4);
      pairof4 -= take;
      cnt[i] -= 4 * take;
      done |= 1;
    }
    if (!done) {
      print("No\n"); return;
    }
  }
  // Distribute into palindrom string(s)
  auto can_form = [&](const int len) -> bool {
    int pairof2 = len / 2;
    while (pairof2) {
      int done = 0;
      for (int i = 0; i < 26; ++i) if (cnt[i] >= 2) {
        const int take = min(pairof2, cnt[i] / 2);
        pairof2 -= take;
        cnt[i] -= 2 * take;
        done |= 1;
      }
      if (!done) return false;
    }
    if (len % 2) {
      int done = 0;
      for (int i = 0; i < 26; ++i) if (cnt[i] % 2) {
        cnt[i] -= 1;
        done |= 1;
        break;
      }
      if (!done) return false;
    }
    return true;
  };
  if (H % 2 && W % 2) {
    print((can_form(H) && can_form(W - 1) ? "Yes\n" : "No\n")); return;
  } else if (H % 2) {
    print((can_form(W) ? "Yes\n" : "No\n")); return;
  } else if (W % 2) {
    print((can_form(H) ? "Yes\n" : "No\n")); return;
  }
  print("Yes\n");
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; // read(tt);
  rep(tt) solve();
}