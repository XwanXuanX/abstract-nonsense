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

int n;
V<int> a;

void solve() {
    read(n);
    a.assign(n, 0);
    read(a);
    int n1 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            n1++;
        }
    }
    if (n1 == 0) {
        V<pr<int>> ans;
        // 0 0 0 0
        // 1 0 0
        // 1 1
        // 0
        ans.push_back(make_pair(1, 2));
        ans.push_back(make_pair(2, n - 1));
        ans.push_back(make_pair(1, 2));
        print(ans.size());
        print(ans);
        return;
    }
    // just a slight modification, since requries l < r (read the problem carefully!)
    V<pr<int>> ans;
    int merged = 0;
    for (int i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            if (a[i] == 0 || a[i+1] == 0) {
                ans.push_back(make_pair(i + 1 - merged, i + 2 - merged));
                merged++;
            }
        }
    }
    if (n % 2 && a.back() == 0) {
        ans.push_back(make_pair(n - 1 - merged, n - merged));
        merged++;
    }
    ans.push_back(make_pair(1, n - merged));
    print(ans.size());
    print(ans);
}

/**
 * WHAT A MESSY IMPLEMENTATION!
 * obs: 
 * 1. if the array does not contain 0, then just 1 op is needed
 * 2. if you want the final array to be 0, then the previous step must NOT contain 0
 * 3. that means, you need to eliminate all 0s in the array.
 * 4. and there is always a sequence of operations to do so
 *    1) if the array contains only 0, then 3 operations are needed
 *    2) if the array contains at least 1 non-zero element, just transform each 0 individually
 *    3) which takes at most n - 1 ops, and the last op transform the entire array
 */

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt = 1;
    read(tt);
    rep(tt) solve();
}