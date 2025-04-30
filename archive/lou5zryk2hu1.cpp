#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n % 2) {
        cout << 1 << ' ' << n/2 << ' ' << n/2 << '\n';
        return;
    }
    if (n == 4) {
        cout << 2 << ' ' << 1 << ' ' << 1 << '\n';
        return;
    }
    if (n == 6) {
        cout << 2 << ' ' << 2 << ' ' << 2 << '\n';
        return;
    }
    // now we can add the first number up to 4 and not exceed limit
    // but we have to deal with the n/2 is even or odd problem
    n /= 2;
    if (n % 2) {
        cout << 2 << ' ' << n-1 << ' ' << n-1 << '\n';
    } else {
        cout << n << ' ' << n/2 << ' ' << n/2 << '\n';
    }
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