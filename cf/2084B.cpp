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

int n;
V<int> a;

void solve() {
    read(n);
    a.assign(n, 0);
    read(a);
    sort(all(a));
    int mn = a[0];
    if (a[1] == mn) {
        print("Yes");
        return;
    }
    // now what's left to check is:
    // can you select at least two elements to assign to the right
    V<int> b;
    for (int i = 1; i < n; ++i) {
        if (a[i] % mn == 0) {
            b.push_back(a[i]);
        }
    }
    if (b.size() < 2) {
        print("No");
        return;
    }
    int g = b[0];
    for (int i = 1; i < b.size(); ++i) {
        g = gcd(g, b[i]);
    }
    // since everything in b divides mn, then gcd >= mn
    // if gcd != mn, then gcd = k * mn, k > 1
    print(g == mn ? "Yes" : "No");
}

/**
 * partition the array into two parts; the min on the left side must divide everything on the right side
 * 1. if there are two min values, definitely possible
 * 2. if there are two coprime numbers, and there is 1, possible
 * 3. what affect the gcd of the right side? the two smallest value!
 * 4. for the minimum value:
 *    1) if you put it on the right, then 1 <= gcd <= min;
 *       but min(left) > min, thus cannot be possible => min must be on the left side
 *       => the global min must be gcd of right side
 */

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt = 1;
    read(tt);
    rep(tt) solve();
}