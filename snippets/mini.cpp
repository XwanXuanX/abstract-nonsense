#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int    long long
#define double long double
constexpr int INF = 1ll << 60;
constexpr int MOD = 1'000'000'007; // 998'244'353;
template <typename T> using MaxPQ = priority_queue<T, vector<T>, less<T>>;
template <typename T> using MinPQ = priority_queue<T, vector<T>, greater<T>>;
template <typename T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } return false; }
template <typename T> bool chmax(T& a, const T& b) { if (b > a) { a = b; return true; } return false; }

void solve() {
    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
    int T = 1; cin >> T;
    while (T--) solve();
}