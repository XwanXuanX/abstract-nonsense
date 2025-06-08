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

void solve() {
    read(n);
    V<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && i * i <= n) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    V<int> primes;
    for (int i = 0; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    auto bs = [&](int a) -> int {
        int lo = 0, hi = primes.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (a * primes[mid] <= n) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    };
    int ans = 0;
    for (int a = 1; a < n; ++a) {
        ans += bs(a);
    }
    print(ans);
}

/**
 * claim: we fix a, and for every prime number p <= O(1e7), we can take b = p * a,
 *        and that is a valid pair. In order words, we only make gcd(a, b) = a.
 * proofs:
 * 1. for a = 1, lcm(a, b) = b, and gcd(a, b) = 1, thus if b is prime, it's a valid pair
 * 2. for a pair of coprime numbers, a > 1 and b > a, then lcm(a, b) = a * b, and gcd(a, b) = 1;
 *    but a * b cannot possibly be prime, thus coprime numbers not valid
 * 3. for a pair of non-coprime numbers, a > 1 and b > a, but gcd(a, b) = k != a and k < a < b:
 *    we can prove by contradiction: assume lcm(a, b) / k = p(rime), then lcm(a, b) = k * prime;
 *    but lcm(a, b) = (a * b) / k. thus (a * b) / k = k * prime. but since a|k and b|k, then let
 *    m = a / k, and n = b / k; then (km * kn) / k = k * prime => m * n = prime.
 *    but this is a contradiction! thus we proved that for a pair of non-coprime numbers with gcd smaller than a,
 *    it's never possible!
 * 4. claim is proved!
 */

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt = 1;
    read(tt);
    rep(tt) solve();
}