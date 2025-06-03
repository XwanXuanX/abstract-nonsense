#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
/*********************************************************************************************************************************************************/
#define SFINAE(x, ...) template <class, class = void> struct x : std::false_type {}; template <class T> struct x<T, std::void_t<__VA_ARGS__>> : std::true_type {}
SFINAE(DefaultI, decltype(std::cin >> std::declval<T &>())); SFINAE(DefaultO, decltype(std::cout << std::declval<T &>())); SFINAE(IsTuple, typename std::tuple_size<T>::type); SFINAE(Iterable, decltype(std::begin(std::declval<T>())));
template <auto &is> struct Reader {
template <class T> void Impl(T &t) { if constexpr (DefaultI<T>::value) { is >> t; } else if constexpr (Iterable<T>::value) { for (auto &x : t) Impl(x); } else if constexpr (IsTuple<T>::value) { std::apply([this](auto &...args) { (Impl(args), ...); }, t); } else { static_assert(IsTuple<T>::value, "No matching type for read"); } }
template <class... Ts> void read(Ts &...ts) { ((Impl(ts)), ...); } };
template <auto &os, bool print_nd> struct Writer {
template <class T> constexpr char Space(const T &) const { return print_nd && (Iterable<T>::value or IsTuple<T>::value) ? '\n' : ' '; }
template <class T> void Impl(T const &t) const { if constexpr (DefaultO<T>::value) { os << t; } else if constexpr (Iterable<T>::value) { int i = 0; for (auto &&x : t) { ((i++) ? (os << Space(x), Impl(x)) : Impl(x)); } } else if constexpr (IsTuple<T>::value) { std::apply([this](auto const &...args) {int i = 0; (((i++) ? (os << " ", Impl(args)) : Impl(args)), ...);}, t); } else { static_assert(IsTuple<T>::value, "No matching type for print"); } }
template <class F, class... Ts> void print_with_sep(const std::string &sep, F const &f, Ts const &...ts) const { Impl(f), ((os << sep, Impl(ts)), ...), os << '\n'; }
template <class... Ts> void print(Ts const &...ts) const { ((Impl(ts)), ...); }
void print_with_sep(const std::string &) const { os << '\n'; } };
/******************************************************************* IO **********************************************************************************/
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0)
template <class... Ts> void re(Ts &...ts) { Reader<cin>{}.read(ts...); }
template <class... Ts> void pr(Ts const &...ts) { Writer<cout, true>{}.print(ts...); }
template <class... Ts> void ps(Ts const &...ts) { Writer<cout, true>{}.print_with_sep(" ", ts...); }
/****************************************************************** TOOL *********************************************************************************/
template<typename T> using V = vector<T>; template<typename T, size_t SZ> using AR = array<T, SZ>;
template<typename T> using pqg = priority_queue<T, V<T>, greater<T>>; // return smallest
template<typename T> using pql = priority_queue<T, V<T>, less<T>>; // return largest
constexpr int popcount(int x) { return __builtin_popcount(x); }  // # of bits set
constexpr int floorlog2(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }  // floor(log2(x))
constexpr long long ceildiv(long long a, long long b) { return a / b + ((a ^ b) > 0 && a % b); }  // divide a by b rounded up
constexpr long long floordiv(long long a, long long b) { return a / b - ((a ^ b) < 0 && a % b); }  // divide a by b rounded down
/***************************************************************** CONSTS ********************************************************************************/
constexpr int MOD = 1e9 + 7;
constexpr long long INF = 1e18;  // not too close to LLONG_MAX
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  // for every grid problem!!
/*********************************************************************************************************************************************************/

int n, h;
V<int> a;

void solve() {
    re(n, h);
    a.assign(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        re(a[i]);
    }
    int mxhealth = 0;
    sort(a.begin(), a.end());
    V<V<V<int>>> dp(n+1, V<V<int>>(3, V<int>(2, 0)));
    dp[0][0][0] = h;
    dp[0][0][1] = h * 3;
    dp[0][1][0] = h * 2;
    dp[0][1][1] = h * 6;
    dp[0][2][0] = h * 4;
    dp[0][2][1] = h * 12;
    for (int i = 1; i <= n; ++i) {
        for (int g = 0; g < 3; ++g) {
            for (int b = 0; b < 2; ++b) {
                dp[i][g][b] = 0;
                // no serum
                dp[i][g][b] = max(dp[i][g][b], dp[i-1][g][b]);
                // 1 blue
                if (b - 1 >= 0)
                    dp[i][g][b] = max(dp[i][g][b], dp[i-1][g][b-1] * 3);
                // 1 green
                if (g - 1 >= 0)
                    dp[i][g][b] = max(dp[i][g][b], dp[i-1][g-1][b] * 2);
                // 1 green 1 blue
                if (g - 1 >= 0 && b - 1 >= 0)
                    dp[i][g][b] = max(dp[i][g][b], dp[i-1][g-1][b-1] * 6);
                // 2 green
                if (g - 2 >= 0)
                    dp[i][g][b] = max(dp[i][g][b], dp[i-1][g-2][b] * 4);
                // 2 green 1 blue
                if (g - 2 >= 0 && b - 1 >= 0)
                    dp[i][g][b] = max(dp[i][g][b], dp[i-1][g-2][b-1] * 12);
                if (dp[i][g][b] > a[i]) {
                    dp[i][g][b] += (a[i] / 2);
                } else {
                    dp[i][g][b] = 0;
                }
                mxhealth = max(mxhealth, dp[i][g][b]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] < mxhealth) {
            ans++;
        }
    }
    ps(ans);
}

signed main() {
    fastIO;
    int tt = 1;
#ifndef single
    re(tt);
#endif
    while (tt--) {
        solve();
    }
}