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
template <typename... Ts> void read(Ts& ...ts) {((re(ts)), ...);};
template <typename... Ts> void print(Ts& ...ts) {ps(" ", ts...);};

template <typename T> int  lwb(const V<T>& a, const T& b) {return int(lower_bound(all(a),b) - a.begin());};
template <typename T> int  upb(const V<T>& a, const T& b) {return int(upper_bound(all(a),b) - a.begin());};
template <typename T> void remDup(V<T>& v) {sort(all(v));v.erase(unique(all(v)), v.end());};
template <typename T> T    cdiv(T a, T b) requires std::integral<T> {return a/b + ((a^b) > 0 && a%b);};

// Open in case of emergency X_X:
// #define int      long long
// #define double   long double

int n;
string s;

void solve() {
    read(n, s);
    if (s[0] == s[n-1]) {
        if (s[0] == 'A') {
            print("Alice");
        } else {
            print("Bob");
        }
        return;
    }
    set<int> alice, bob;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
            alice.insert(i+1);
        } else {
            bob.insert(i+1);
        }
    }
    if (n == 2) {
        if (bob.contains(1) && alice.contains(2)) {
            print("Bob");
        } else {
            print("Alice");
        }
        return;
    }
    // in general case, where n > 2
    // if bob only has one card, then he definitely lose
    if (bob.size() == 1) {
        print("Alice");
        return;
    }
    // bob either have 1 or n, there are two cases which he can win
    if (bob.contains(1)) {
        if (bob.contains(n - 1)) {
            print("Bob");
            return;
        }
    } else {
        assert(bob.contains(n));
        int has = 0;
        for (int i = 2; i < n; ++i) {
            if (bob.contains(i)) {
                has |= 1;
            }
        }
        if (has) {
            print("Bob");
            return;
        }
    }
    print("Alice");
}

/**
 * It's important that: if a player can take card on the first turn, then that player wins
 * since B can see A's card, then if B has at least one card that is greater than
 * all of A's card, then B can win.
 * 1. if any player has 1 and n => that player wins
 * 2. if B has n and any card that is greater than 1 => B wins
 * 3. if B only has n => A wins
 * 4. if B only has 1 => A wins
 * 5. if B has 1 and n-1 => B wins
 */

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt = 1;
    read(tt);
    rep(tt) solve();
}