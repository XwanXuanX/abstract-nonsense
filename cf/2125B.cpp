#include <bits/stdc++.h>
using namespace std;

#define int long long

int a, b, k;

void solve() {
    cin >> a >> b >> k;
    // try to find a number that divide both a and b
    int g = gcd(a, b);
    int aa = a / g, bb = b / g;
    if (k >= aa && k >= bb) {
        cout << 1 << '\n';
        return;
    }
    cout << 2 << '\n';
}

signed main() {
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}