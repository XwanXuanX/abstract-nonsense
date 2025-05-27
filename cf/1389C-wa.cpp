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

string s;

#define SA 0
#define DI 1

void solve() {
    re(s);
    int n = s.size();
    s.insert(s.begin(), 0);
    map<char,int> cnt;
    for (int i = 1; i <= n; ++i) {
        cnt[s[i]]++;
    }
    int single = 0;
    for (auto& p : cnt) {
        single = max(single, p.second);
    }
    V<V<int>> dp(n+1, V<int>(2, INF));
    dp[0][SA] = dp[0][DI] = 0;
    dp[1][SA] = 0;
    dp[2][SA] = s[2] != s[1], dp[2][DI] = 0;
    for (int i = 3; i <= n; ++i) {
        // dp[i][SA] = dp[i-1][SA] + 1;
        // for (int j = i - 1; j >= 1; --j) {
        //     if (s[i] == s[j]) {
        //         dp[i][SA] = min(dp[i][SA], dp[j][SA] + (i - j - 1));
        //         break;
        //     }
        // }
        dp[i][DI] = dp[i-1][DI] + 1;
        for (int j = i - 2; j >= 2; --j) {
            if (s[i] == s[j] && s[i-1] == s[j-1]) {
                dp[i][DI] = min(dp[i][DI], dp[j][DI] + (i - j - 2));
                break;
            }
        }
    }
    // ps(dp);
    ps(min(dp[n][DI], n - single));
}

// 0135785152174082012097654604938957981703096740171424318330885652765893707675593434217828455171007143914259658511312169208710262035594955071894747649

signed main() {
    fastIO;
    int tt = 1;
    re(tt);
    while (tt--) {
        solve();
    }
}