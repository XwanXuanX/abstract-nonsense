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

using Graph = map<int, V<int>>;

int n, m, a, b, c, q, u, v;
V<Graph> Gs;

void dfs(Graph& G, set<int>& done, int node) {
    done.insert(node);
    for (auto& adj : G[node]) {
        if (!done.contains(adj)) {
            dfs(G, done, adj);
        }
    }
}

void helper(Graph& G, V<set<int>>& vis) {
    for (int i = 1; i <= n; ++i) {
        dfs(G, vis[i], i);
    }
}

void solve() {
    re(n, m);
    map<int, V<pair<int,int>>> color;
    for (int i = 0; i < m; ++i) {
        re(a, b, c);
        color[c].push_back(make_pair(a, b));
    }
    for (auto& p : color) {
        Gs.push_back(Graph());
        auto& G = Gs.back();
        for (auto& e : p.second) {
            G[e.first].push_back(e.second), G[e.second].push_back(e.first);
        }
    }
    assert(Gs.size() == color.size());
    // for all nodes in all graphs, store the nodes that can be visited by that node in that graph
    V<V<set<int>>> visitor(Gs.size(), V<set<int>>(n+1));
    for (int i = 0; i < Gs.size(); ++i) {
        helper(Gs[i], visitor[i]);
    }
    re(q);
    for (int i = 0; i < q; ++i) {
        re(u, v);
        int ans = 0;
        for (int j = 0; j < Gs.size(); ++j) {
            ans += visitor[j][u].contains(v);
        }
        ps(ans);
    }
}

signed main() {
    fastIO;
    int tt = 1;
    // re(tt);
    while (tt--) {
        solve();
    }
}