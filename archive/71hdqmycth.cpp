#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }
    vector<int> bits(31, 0);
    // calc for the freq of each bit
    // for each number in bin rep, calculate the answer and take the max
    for (int i=0; i<n; ++i) {
        for (int j=0; j<31; ++j) {
            bits[j] += (bool)((1 << j) & a[i]);
        }
    }
    int mx = 0;
    for (int i=0; i<n; ++i) {
        // get the current binary rep
        vector<int> cb(31, 0);
        for (int j=0; j<31; ++j) {
            cb[j] += (bool)((1 << j) & a[i]);
        }
        int ans = 0;
        for (int j=0; j<31; ++j) {
            if (cb[j]) {
                // we need 0s
                ans += (n - bits[j]) * (1 << j);
            } else {
                // we need 1s
                ans += (bits[j]) * (1 << j);
            }
        }
        mx = max(mx, ans);
    }
    cout << mx << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}

/**
 * if you can turn on the nth bit, then no matter how many bits you can turn on from
 * [0, n-1] does not matter.
 * if nth bit is set to 1, and the number of numbers with nth bit is 0, then we can add
 * some multiple of power of 2 to the answer
 */