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
// #define int      long long
// #define double   long double

int n, k;

void solve() {
    read(n, k);
    V<int> ans(n);
    for (int i = 0; i < n - 2; i++) {
        if (k % 2) {
            ans[i] = n;
        } else {
            ans[i] = n - 1;
        }
    }
    ans[n-2] = n;
    ans[n-1] = n - 1;
    print(ans);
}

/**
 * obs:
 * 1. for the last two cell, put n, n - 1 -- for anyone who get to last two cell, will be stuck in there
 * 2. for any other cell, either teleport to n - 1 or n cell.
 * 3. if k is odd, then teleport to n cell
 * 4. if k is even, then teleport to n - 1 cell. DONE!
 */

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt = 1;
    read(tt);
    rep(tt) solve();
}