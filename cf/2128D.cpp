// Problem: D. Sum of LDS
// Contest: Codeforces - Codeforces Round 1039 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2128/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

inline namespace FastIO {
#define SFINAE(x, ...) template <class, class = void> struct x : std::false_type {}; template <class T> struct x<T, std::void_t<__VA_ARGS__>> : std::true_type {}
SFINAE(DefaultI, decltype(std::cin >> std::declval<T &>())); SFINAE(DefaultO, decltype(std::cout << std::declval<T &>())); SFINAE(IsTuples, typename std::tuple_size<T>::type); SFINAE(Iterable, decltype(std::begin(std::declval<T>())));
template <typename T> char sp(T& t) { return (Iterable<T>::value || IsTuples<T>::value) ? '\n' : ' '; }
template <typename T> void re(T& t) { if constexpr (DefaultI<T>::value) { cin >> t; } else if constexpr (Iterable<T>::value) { for (auto& x : t) re(x); } else if constexpr (IsTuples<T>::value) { std::apply([&](auto& ...args) { (re(args), ...); }, t); } }
template <typename T> void pt(T& t) { if constexpr (DefaultO<T>::value) { cout << t; } else if constexpr (Iterable<T>::value) { int i = 0; for (auto&& x : t) ((i++) ? (cout << sp(x), pt(x)) : pt(x)); } else if constexpr (IsTuples<T>::value) { std::apply([&](auto const& ...args) { int i = 0; (((i++) ? (cout << " ", pt(args)) : pt(args)), ...); }, t); } }
template <typename T, typename... Ts> void ps(const string& s, T& t, Ts& ...ts) { pt(t), ((cout << s, pt(ts)), ...), cout << '\n'; } void ps(const string&) { cout << '\n'; }
template <typename... Ts> void print(const Ts& ...ts) { FastIO::ps(" ", ts...); }
template <typename... Ts> void read(Ts& ...ts) { ((FastIO::re(ts)), ...); }
#undef SFINAE
}  // namespace FastIO

inline namespace Util {
#define rep(x)                     for (int _ = (0); _ < (x); ++_)
template <typename T> using V    = vector<T>;
template <typename T> using MnPQ = priority_queue<T, V<T>, greater<T>>;
template <typename T> using MxPQ = priority_queue<T, V<T>, less<T>>;
}  // namespace Util

#ifndef ONLINE_JUDGE
  #define debug(...) do { __VA_ARGS__ } while (0)
#else
  #define debug(...) do {} while (0)
#endif

/*
observe state transtition is very important!
a b c
1) a > b > c
2) a < b > c
3) a > b < c and a > c
6 1 5 2 4 3
1 2 2 3 3 4
  1 1 2 2 3
    1 2 2 3
      1 1 2
        1 2
          1
since max(a[i], a[i+1]) > a[i+2], then the subarray starting at a[i+2] must have longest subsequence length -1 or -2
-1 or -2 depends on a[i] and a[i+1]
I think this is solved.
4 3 1 2
1 2 3 3 = 9
  1 2 2 = 5
    1 1 = 2
      1 = 1 -> 17 which is correct
*/
#define int long long
void solve() {
  int n; read(n);
  V<int> a(n); read(a);
  auto LDS = [&](const V<int>& arr) -> V<int> {
    V<int> ans, lds(arr.size(), 0);
    ans.push_back(arr[0]);
    lds[0] = 1;
    for (int i = 1; i < arr.size(); i++) {
      if (arr[i] < ans.back()) {
        ans.push_back(arr[i]);
      } else {
        int low = 0, high = ans.size() - 1;
        while (low < high) {
          int mid = low + (high - low) / 2;
          if (ans[mid] > arr[i]) low = mid + 1;
          else high = mid;
        }
        ans[low] = arr[i];
      }
      lds[i] = ans.size();
    }
    return lds;
  };
  int ans = 0;
  auto handle = [&LDS, &ans](const V<int> arr) -> void {
    const auto even = LDS(arr);
    const int n = arr.size();
    int sum = accumulate(even.begin(), even.end(), 0ll), sub = 0;
    ans += sum;
    for (int i = 2; i < (int)even.size(); i += 2) {
      sum -= (even[i-1] + even[i-2]);
      const int len = n - i;
      sub += (arr[i-2] > arr[i-1] && arr[i-1] > arr[i]) ? 2 : 1;
      ans += (sum - len*sub);
    }
  };
  handle(a);
  a.erase(a.begin());
  handle(a);
  print(ans);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
  int tt = 1; read(tt);
  rep(tt) solve();
}