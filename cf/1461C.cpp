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

int n, m;
V<int> a;
V<pair<int,double>> p;

void solve() {
    re(n, m);
    a.assign(n+1, 0), p.assign(m+1, {});
    for (int i = 1; i <= n; ++i) {
        re(a[i]);
    }
    for (int i = 1; i <= m; ++i) {
        re(p[i].first, p[i].second);
    }
    if (is_sorted(a.begin(), a.end())) {
        ps(1.0);
        return;
    }
    int mx = 0;
    V<bool> valid(n+1, false), valid2(n+1, false), valid3(n+1, false);
    for (int i = 1; i <= n; ++i) {
        mx = max(mx, a[i]);
        if (mx <= i) {
            assert(mx == i);
            valid[i] = true;
        }
    }
    if (a[n] == n) { 
        valid2[n] = true;
    }
    for (int i = n - 1; i >= 1; --i) {
        if (!valid2[i+1] || a[i] + 1 != a[i+1]) {
            break;
        }
        valid2[i] = true;
    }
    valid3[n] = true;
    for (int i = n - 1; i >= 1; --i) {
        valid3[i] = (valid[i] && valid2[i+1]);
    }
    V<pair<int,double>> up; // 1e5
    for (int i = 1; i <= m; ++i) {
        if (valid3[p[i].first]) {
            up.push_back(p[i]);
        }
    }
    double fail = 1.0;
    for (int i = 0; i < up.size(); ++i) {
        fail *= double(1 - up[i].second);
    }
    ps(1 - fail);
}

signed main() {
    cout << fixed << setprecision(6);
    fastIO;
    int tt = 1;
#ifndef single
    re(tt);
#endif
    while (tt--) {
        solve();
    }
}