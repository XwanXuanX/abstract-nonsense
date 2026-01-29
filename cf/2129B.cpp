// Problem: B. Stay or Mirror
// Contest: Codeforces - Codeforces Round 1040 (Div. 1)
// URL: https://codeforces.com/problemset/problem/2129/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

inline namespace Util {
#define int    long long
#define double long double
constexpr int INF = 1ll << 60;
constexpr int MOD = 1'000'000'007; // 998'244'353;
template <typename T> using MaxPQ = priority_queue<T, vector<T>, less<T>>;
template <typename T> using MinPQ = priority_queue<T, vector<T>, greater<T>>;
template <typename T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } return false; }
template <typename T> bool chmax(T& a, const T& b) { if (b > a) { a = b; return true; } return false; }
}  // namespace Util

/*
consider p[i] = 1.
if a[i] = 1, which is the smallest number you can get, the inversions are (1,i), (2,i), ... (i-1,i).
if a[i] = 2n-1, which is the largest number you can get, the inversions are (i,i+1), (i,i+2), ... (i,n)
after we calculated the answer for p[i] = 1, remove p[i], then we are left with the same subproblem with length (n-1)
....big...x[i]...big....
*/
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    // for each element, calc the # of ele bigger on the left and smaller on the right
    for (int i = 0; i < n; ++i) {
        int lbigger = 0, rsmaller = 0;
        for (int j = i-1; j >= 0; --j) if (a[j] > a[i]) {
            lbigger++;
        }
        for (int j = i+1; j < n; ++j) if (a[j] > a[i]) {
            rsmaller++;
        }
        ans += min(lbigger, rsmaller);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
    int T = 1; cin >> T;
    while (T--) solve();
}