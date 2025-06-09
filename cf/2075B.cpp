#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define all(x)                          x.begin(), x.end()
#define rep(x)                          for (int _ = (0); _ < (x); ++_)
template <typename T> using V           = vector<T>;
template <typename T> using pr          = pair<T, T>;
template <typename T> using minpq       = priority_queue<T, V<T>, greater<T>>;
template <typename T> using maxpq       = priority_queue<T, V<T>, less<T>>;

template <typename T, typename = void> struct DefaultI : std::false_type {}; template <typename T> struct DefaultI<T, std::void_t<decltype(std::cin  >> std::declval<T&>())>> : std::true_type {};
template <typename T, typename = void> struct DefaultO : std::false_type {}; template <typename T> struct DefaultO<T, std::void_t<decltype(std::cout << std::declval<T&>())>> : std::true_type {};
template <typename T, typename = void> struct IsTuples : std::false_type {}; template <typename T> struct IsTuples<T, std::void_t<typename std::tuple_size<T>::type>>         : std::true_type {};
template <typename T, typename = void> struct Iterable : std::false_type {}; template <typename T> struct Iterable<T, std::void_t<decltype(std::begin(std::declval<T>()))>>   : std::true_type {};
template <typename T> char sp(T& t) {return(Iterable<T>::value||IsTuples<T>::value)?'\n':' ';};
template <typename T> void re(T& t) {if constexpr(DefaultI<T>::value){cin>>t;}else if constexpr(Iterable<T>::value){for(auto&x:t)re(x);}else if constexpr(IsTuples<T>::value){std::apply([&](auto&...args){(re(args),...);},t);}};
template <typename T> void pt(T& t) {if constexpr(DefaultO<T>::value){cout<<t;}else if constexpr(Iterable<T>::value){int i=0;for(auto&&x:t)((i++)?(cout<<sp(x),pt(x)):pt(x));}else if constexpr(IsTuples<T>::value){std::apply([&](auto const&...args){int i=0;(((i++)?(cout<<" ",pt(args)):pt(args)),...);},t);}};
template <typename T, typename... Ts> void ps(const string& s, T& t, Ts& ...ts) {pt(t),((cout<<s,pt(ts)),...),cout<<'\n';}; void ps(const string&) {cout<<'\n';};
template <typename... Ts> void print(const Ts& ...ts) {ps(" ", ts...);};
template <typename... Ts> void read(Ts& ...ts) {((re(ts)), ...);};

template <typename T> int  lwb(const V<T>& a, const T& b) {return int(lower_bound(all(a),b) - a.begin());};
template <typename T> int  upb(const V<T>& a, const T& b) {return int(upper_bound(all(a),b) - a.begin());};
template <typename T> T    cdiv(T a, T b) requires std::integral<T> {return a/b + ((a^b) > 0 && a%b);};
template <typename T> void remDup(V<T>& v) {sort(all(v));v.erase(unique(all(v)), v.end());};

// Open in case of emergency X_X:
#define int      long long
// #define double   long double

int n, k;
V<int> a;

void solve() {
    read(n, k);
    a.assign(n, 0);
    read(a);
    if (k == n - 1) {
        print(accumulate(all(a), 0ll));
        return;
    } else if (k == 1) {
        int mx = 0;
        for (int i = 1; i < n - 1; ++i) {
            mx = max(mx, a[i]);
        }
        print(max(mx + max(a[0], a[n-1]), a[0] + a[n-1]));
        return;
    }
    V<int> b;
    for (int i = 1; i < n - 1; ++i) {
        b.push_back(a[i]);
    }
    sort(b.rbegin(), b.rend());
    b.insert(b.begin(), 0);
    for (int i = 1; i < b.size(); ++i) {
        b[i] += b[i-1];
    }
    int case1 = 0, case2 = 0, case3 = 0;
    // case1: select two edges, in middle select k - 1 max
    case1 = max(case1, a[0] + a[n-1] + b[k-1]);
    // case2: select one more in the middle or one more on the edge
    if (k + 1 < b.size()) {
        case2 = max(case2, max(b[k+1], b[k] + max(a[0], a[n-1])));
    } else {
        case2 = max(case2, b[k] + max(a[0], a[n-1]));
    }
    // case3: select one edge, left or right, you can also select the other edge
    case3 = max(case3, max(max(a[0], a[n-1]) + b[k], a[0] + a[n-1] + b[k-1]));
    // print(case1, case2, case3);
    print(max({case1, case2, case3}));
}

/**
 * obs:
 * 1. all the array will turn blue in the end
 * 2. only the last painted red will be counted, and we can do it in any order
 *    => we can select the max from the remaining reds
 * 3. ok here's a counterexample: 4 3 3 1 3 2 in this case, 4 3 3 and 3 will be selected, but 3 cannot be painted last
 * 4. we need to find k points in a, for k1 and kn, only the element on the edge can be considered
 * 5. for the remaining segment bounded by ki-1 and ki, we can take it's max
 * 6. for any pair of index (i, j), you can select
 *    1) k + 1 largest from [i, j]
 *    2) k largest from [i, j] + max(a[0], a[n-1]);
 * 7. we can compute the top k elements from a[1, n-2]
 */

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt = 1;
    read(tt);
    rep(tt) solve();
}