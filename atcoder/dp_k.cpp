#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
inline namespace IO {
#define SFINAE(x, ...) template <class, class = void> struct x : std::false_type {}; template <class T> struct x<T, std::void_t<__VA_ARGS__>> : std::true_type {}
SFINAE(DefaultI, decltype(std::cin >> std::declval<T &>())); SFINAE(DefaultO, decltype(std::cout << std::declval<T &>())); SFINAE(IsTuple, typename std::tuple_size<T>::type); SFINAE(Iterable, decltype(std::begin(std::declval<T>())));
template <auto &is> struct Reader {
template <class T> void Impl(T &t) { if constexpr (DefaultI<T>::value) { is >> t; } else if constexpr (Iterable<T>::value) { for (auto &x : t) Impl(x); } else if constexpr (IsTuple<T>::value) { std::apply([this](auto &...args) { (Impl(args), ...); }, t); } else { static_assert(IsTuple<T>::value, "No matching type for read"); } }
template <class... Ts> void read(Ts &...ts) { ((Impl(ts)), ...); } };
template <class... Ts> void re(Ts &...ts) { Reader<cin>{}.read(ts...); }
template <auto &os, bool debug, bool print_nd> struct Writer {
string comma() const { return debug ? "," : ""; }
template <class T> constexpr char Space(const T &) const { return print_nd && (Iterable<T>::value or IsTuple<T>::value) ? '\n' : ' '; }
template <class T> void Impl(T const &t) const { if constexpr (DefaultO<T>::value) { os << t; } else if constexpr (Iterable<T>::value) { if (debug) os << '{'; int i = 0; for (auto &&x : t) { ((i++) ? (os << comma() << Space(x), Impl(x)) : Impl(x)); } if (debug) os << '}'; } else if constexpr (IsTuple<T>::value) { if (debug) os << '('; std::apply([this](auto const &...args) {int i = 0; (((i++) ? (os << comma() << " ", Impl(args)) : Impl(args)), ...);}, t); if (debug) os << ')'; } else { static_assert(IsTuple<T>::value, "No matching type for print"); } }
template <class T> void ImplWrapper(T const &t) const { if (debug) os << "\033[0;31m"; Impl(t); if (debug) os << "\033[0m"; }
template <class... Ts> void print(Ts const &...ts) const { ((Impl(ts)), ...); }
template <class F, class... Ts> void print_with_sep(const std::string &sep, F const &f, Ts const &...ts) const { ImplWrapper(f), ((os << sep, ImplWrapper(ts)), ...), os << '\n'; }
void print_with_sep(const std::string &) const { os << '\n'; } };
template <class... Ts> void pr(Ts const &...ts) { Writer<cout, false, true>{}.print(ts...); }
template <class... Ts> void ps(Ts const &...ts) { Writer<cout, false, true>{}.print_with_sep(" ", ts...); }
}  // namespace IO
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
inline namespace Tools {
template<typename T> using V = vector<T>; template<typename T, size_t SZ> using AR = array<T, SZ>;
template<typename T> using pqg = priority_queue<T, V<T>, greater<T>>; // return smallest
template<typename T> using pql = priority_queue<T, V<T>, less<T>>; // return largest
struct safe_hash { // safe hash function for unordered containers (unordered_set, unordered_map)
static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); }
size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); } };
template<typename Val> using safe_map = unordered_map<long long, Val, safe_hash>; using safe_set = unordered_set<long long, safe_hash>;
constexpr int popcount(int x) { return __builtin_popcount(x); }  // # of bits set
constexpr int floorlog2(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }  // floor(log2(x))
constexpr long long ceildiv(long long a, long long b) { return a / b + ((a ^ b) > 0 && a % b); }  // divide a by b rounded up
constexpr long long floordiv(long long a, long long b) { return a / b - ((a ^ b) < 0 && a % b); }  // divide a by b rounded down
}  // namespace Tools
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
inline namespace Consts {
constexpr int MOD = 1e9 + 7;
constexpr long long INF = 1e18;  // not too close to LLONG_MAX
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  // for every grid problem!!
}  // namespace Consts
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, k;
    re(n, k);
    V<int> a(n);
    for (int i = 0; i < n; ++i) {
        re(a[i]);
    }

    // First version
    if (1) {
        V<bool> dp(k+1, false);
        for (int i = 1; i <= k; ++i) {
            for (int j = 0; j < n; ++j) {
                // p1 cannot win with dp[i - a[j]], but when p1 at dp[i],
                // p2 would be at dp[i - a[j]], and p2 cannot win, thus p1 win
                if (i - a[j] >= 0 && !dp[i - a[j]]) {
                    // Thus p1 win
                    dp[i] = true;
                }
            }
        }
        ps((dp[k] ? "First\n" : "Second\n"));
    }

    // let's analyze the solution in depth, for this kind of taking turn games
    // how does the solution implement the idea of "alternation"?

    // the dp state means: if First can win if starting at [i]
    // if First lose with i, then First win with i + a[j] stones
    // if First win with i, then First lose with i + a[j] stones
    // also note that the state for first and second is opposite, we could only use the First's perspective

    // if First lose with i, then First win with i + a[j] stones. Why this?
    // Because remember the dp definition: can F win with i stones IF F starts first.
    // So when F starts first with i + a[j] stones, S will have i stones and lose
    // and vice versa

    // KEY! KEY! KEY! POINT!!!!!!!!!!!!!!!!!!!!!
    // So how the alternation is embedded in dp?
    // When players take turns alternatively,
    // the outcome of the current player will be the outcome of the other player,
    // IF you make a move (a move here means a state transition)

    // E.g.
    // So if p1 lose at a current state, then you make a move, then p2 lose at the same state
    // and thus p1 wins

    // THUS, when defining the dp states
    // we need to explicitly specify IF p1 starts first on this state
    // YOU NEED TO REMEMBER THIS VERY FIRMLY! ALWAYS REMIND YOURSELF ABOUT IT!
}