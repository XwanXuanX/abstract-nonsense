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
template <class... Ts> void re(Ts &...ts) { details::Reader<cin>{}.read(ts...); }
template <class... Ts> void pr(Ts const &...ts) { details::Writer<cout, true>{}.print(ts...); }
template <class... Ts> void ps(Ts const &...ts) { details::Writer<cout, true>{}.print_with_sep(" ", ts...); }
/****************************************************************** TOOL *********************************************************************************/
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0)
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

typedef vector<int> vi;

class SegmentTree {         
private: 
    vi st, A;
    int n;
    int left (int p) { return p << 1; }                     /*same as binary heap operations*/
    int right(int p) { return (p << 1) + 1; }

    /*  L - left end of the array
        R - right end of the array
        p - current node of segment tree
    */
    void build(int p, int L, int R) {
        // If there is one element in array, store it in current node of
        // segment tree and return
        if (L == R) st[p] = L;

        // If there are more than one elements, then recur for left and
        // right subtrees and store the sum of values in this node
        else {
            int mid = (L+R)/2;
            build(left(p),L,mid);
            build(right(p),mid+1,R);

            int p1 = st[left(p)];
            int p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;
        } 
    }
    /*
        p - current node of segment tree
        L - left end of array
        R - right end of array
        i - left end of query requested
        j - right end of query requested
    */
    int rmq(int p, int L, int R, int i, int j) {
        if (i >  R || j <  L) return -1;                /*current segment outside query range*/
        if (L >= i && R <= j) return st[p];             /*Completely inside query range*/

        /*compute the min position in the left and right part of the interval*/
        int mid = (L+R)/2;
        int p1 = rmq(left(p) , L ,mid,i,j);
        int p2 = rmq(right(p),mid+1,R,i,j);

        if (p1 == -1) return p2;
        if (p2 == -1) return p1;
        return (A[p1] <= A[p2]) ? p1 : p2;
    }
    /*
        p - current node of segment tree
        L - left end of array
        R - right end of array
        idx - index of the element which is upadated in array
        new_value - new value of the changed element
    */
    int update_point(int p, int L, int R, int idx, int new_value) {
        int i = idx, j = idx;

        /*if the current interval does not intersect the update interval, return this st node value!*/
        if (i > R || j < L)
                return st[p];

        /*if the current interval is included in the update range, update that st[node]*/
        if (L == i && R == j) {
            A[i] = new_value;               /*update the underlying array*/
            return st[p] = L;
        }

        /*compute the minimum position in the left and right part of the interval*/
        int p1, p2;
        int mid = (L+R)/2;
        p1 = update_point(left(p) ,   L ,mid ,idx, new_value);
        p2 = update_point(right(p), mid+1, R ,idx, new_value);

        /*return the position where the overall minimum is*/
        return st[p] = (A[p1] <= A[p2]) ? p1 : p2;
    }

public:
    SegmentTree(const vi &_A) {
        A = _A; n = (int)A.size();              /*copy content for local usage*/
        int x = (int)(ceil(log2(n)));           /*Height of segment tree*/
        int max_size = 2*(int)pow(2, x) - 1;    /*Maximum size of segment tree*/
        st.assign(max_size, 0);                 /*create large enough vector of zeroes*/
        build(1, 0, n - 1);                     /*recursive build*/
    }

    int rmq(int i, int j) { 
        return rmq(1, 0, n - 1, i, j);          /*overloading*/
    }

    int update_point(int idx, int new_value) {
        return update_point(1, 0, n - 1, idx, new_value); 
    }
};

signed main() {
    fastIO;
    int n;
    re(n);
    V<int> h(n), a(n);
    for (int i = 0; i < n; ++i) {
        re(h[i]);
    }
    for (int i= 0; i < n; ++i) {
        re(a[i]);
        a[i] = -a[i];
    }

    V<int> dp(n+1, 0);
    SegmentTree st(dp);

    for (int i = 0; i < n; ++i) {
        int mxi = st.rmq(0, h[i] - 1);
        dp[h[i]] = dp[mxi] + a[i];
        st.update_point(h[i], dp[mxi] + a[i]);
    }

    int mxi = st.rmq(0, n);
    ps(-dp[mxi]);
}