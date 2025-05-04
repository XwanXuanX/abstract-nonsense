/**
 * what is the property of such array?
 * what is the largest sum you can achieve?
 * every bit must have a zero among all n elements
 * how many DIFFERENT number must we use? if n >= k, then k; otherwise...
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long

constexpr int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    // there are exactly 1 zero per column
    // we need to calculate the number of ways where we can put that 0
    int a = 1;
    for (int i=0; i<k; ++i) {
        a = ((a % mod) * (n % mod)) % mod;
    }
    cout << a << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}