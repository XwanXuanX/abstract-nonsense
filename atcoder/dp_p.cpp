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

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }

  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }

  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }

  Modular& operator+=(const Modular& other) { value += other.value; value -= (value >= mod()) * mod(); return *this; }
  Modular& operator-=(const Modular& other) { value -= other.value; value += (value < 0) * mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
    int64_t q = int64_t(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }

  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

  friend const Type& abs(const Modular& x) { return x.value; }

  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);

 private:
  Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}

template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}

template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}

// U == std::ostream? but done this way because of fastoutput
template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  return stream << number();
}

// U == std::istream? but done this way because of fastinput
template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}

// using ModType = int;

// struct VarMod { static ModType value; };
// ModType VarMod::value;
// ModType& md = VarMod::value;
// using Mint = Modular<VarMod>;

constexpr int md = MOD;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

// vector<Mint> fact(1, 1);
// vector<Mint> inv_fact(1, 1);

// Mint C(int n, int k) {
//   if (k < 0 || k > n) {
//     return 0;
//   }
//   while ((int) fact.size() < n + 1) {
//     fact.push_back(fact.back() * (int) fact.size());
//     inv_fact.push_back(1 / fact.back());
//   }
//   return fact[n] * inv_fact[k] * inv_fact[n - k];
// }

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    re(n);
    map<int,V<int>> G;
    for (int i = 0; i < n-1; ++i) {
        int x, y;
        re(x, y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    if (n == 1) {
        ps(2);
        return 0;
    }

    // this problem is another version of knapsack problem, which we include a node or not
    V<pair<Mint,Mint>> dp(n+1);
    
    function<void(int node, int prev)> dfs;
    dfs = [&](int node, int prev) -> void {
        // if a node is visited, not possible to be 0
        if (dp[node].first != 0 || dp[node].second != 0) {
            return;
        }
        // if the node is a leaf, then 2 ways to color it: W and B
        if (G[node].size() == 1 && G[node][0] == prev) {
            dp[node].first = dp[node].second = 1;
            return;
        }

        // fill dp for all child subtrees
        for (int adj : G[node]) {
            if (adj != prev) {
                dfs(adj, node);
            }
        }

        // populate dp for current subtree
        // if node is white, then the connected node can be white or black
        // if node is black, then the connected node can only be white
        dp[node].first = dp[node].second = 1;
        for (int adj : G[node]) {
            if (adj != prev) {
                dp[node].first *= (dp[adj].first + dp[adj].second);
                dp[node].second *= (dp[adj].first);
            }
        }

        return;
    };

    dfs(1, -1);

    // ps(dp);
    ps(dp[1].first + dp[1].second);
}