#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
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
inline namespace FileIO {
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void setIO(string s = "") { cin.tie(0)->sync_with_stdio(0); cout << fixed << setprecision(12); if (int(size(s))) { setIn(s + ".in"), setOut(s + ".out"); } }
}  // namespace FileIO
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
using ll = long long; using db = long double; using str = string; using pl = pair<ll, ll>; using pd = pair<db, db>;
template<typename T> using V = vector<T>; template<typename T, size_t SZ> using AR = array<T, SZ>;
using vb = V<bool>; using vl = V<ll>; using vd = V<db>; using vs = V<str>; using vpl = V<pl>; using vpd = V<pd>;
template<typename T> using pqg = priority_queue<T, V<T>, greater<T>>; // return smallest
template<typename T> using pql = priority_queue<T, V<T>, less<T>>; // return largest
struct safe_hash { // safe hash function for unordered containers (unordered_set, unordered_map)
static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); }
size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); } };
template<typename Val> using safe_map = unordered_map<ll, Val, safe_hash>; using safe_set = unordered_set<ll, safe_hash>;
#define sz(x) int(size(x))
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) // reverse sort
#define min_in(x) *(min_element(all(x))) // O(n)
#define max_in(x) *(max_element(all(x))) // O(n)
#define max_at(x) (max_element(all(x)) - bg(x)) // O(n)
#define min_at(x) (min_element(all(x)) - bg(x)) // O(n)
#define lcm(a,b) (a)*((b)/gcd(a,b));
constexpr int popcount(int x) { return __builtin_popcount(x); }  // # of bits set
constexpr int floorlog2(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }  // floor(log2(x))
constexpr ll ceildiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }  // divide a by b rounded up
constexpr ll floordiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }  // divide a by b rounded down
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
constexpr int MOD = 998244353;  // 1e9+7;
constexpr ll INF = 1e18;  // not too close to LLONG_MAX
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  // for every grid problem!!
#define int ll
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

void solve() {

}

signed main() {
        setIO();
        int t; re(t);
        while(t--) solve();
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
