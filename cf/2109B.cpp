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
constexpr long long INF = 1e9;  // not too close to LLONG_MAX
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  // for every grid problem!!
/*********************************************************************************************************************************************************/

int n, m, a, b;

int tryy(int n, int m) {
    int ans = 1;
    while (n > 1) {
        n = n - n / 2;
        ans++;
    }
    while (m > 1) {
        m = m - m / 2;
        ans++;
    }
    return ans;
}

void solve() {
    re(n, m, a, b);
    int hor = max(b - 1, m - b);
    int ver = max(a - 1, n - a);
    ps(min(tryy(n - ver, m), tryy(n, m - hor)));
}

/**
 * solu:
 * 1. the order of vertical or horizontal cuts does not matter;
 * 2. so we just do vertical cuts first, then horizontal cuts;
 * 3. for the first cut, it's more useful if you can eliminate one dimension more
 * 4. for one dimension after the first cut, the remaining space is n1 = n0 - floor(n0 / 2)
 */

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