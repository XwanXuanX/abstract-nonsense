#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
/*********************************************************************************************************************************************************/
namespace details {
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
} // namespace details
/******************************************************************* IO **********************************************************************************/
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0)
template <class... Ts> void re(Ts &...ts) { details::Reader<cin>{}.read(ts...); }
template <class... Ts> void pr(Ts const &...ts) { details::Writer<cout, true>{}.print(ts...); }
template <class... Ts> void ps(Ts const &...ts) { details::Writer<cout, true>{}.print_with_sep(" ", ts...); }
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
#define int long long

void solve() {
    int n, k; re(n, k);
    V<int> a(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        re(a[i]);
    }
    V<V<int>> dp(n+1, V<int>(k+1, INF));
    for (int i = 0; i <= k; ++i) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i-1][0] + a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            // case 1: do nothing
            dp[i][j] = min(dp[i][j], dp[i-1][j] + a[i]);
            for (int o = 0; o <= min(i - 1, j); ++o) {
                // case 2: propogate the current element `o` times
                dp[i][j] = min(dp[i][j], dp[i-o-1][j-o] + a[i] * (o + 1));
                // case 3: propogate any element to the current index
                dp[i][j] = min(dp[i][j], dp[i-o][j-o] + a[i-o] * o);
            }
        }
    }
    ps(dp[n][k]);
}

signed main() {
    fastIO;
    int tt; re(tt);
    while (tt--) {
        solve();
    }
}