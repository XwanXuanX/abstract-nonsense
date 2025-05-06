#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> o(n, 0);
    vector<int> e(n, 0);
    for (int i = 0; i < n; i+=2) {
        o[i] = a[i];
    }
    for (int i = 1; i < n; i+=2) {
        e[i] = a[i];
    }
    for (int i = 1; i < n; ++i) {
        o[i] += o[i-1];
        e[i] += e[i-1];
    }
    o.insert(o.begin(), 0);
    e.insert(e.begin(), 0);
    // we need to find the subarray where their partial sum equals
    // this means if we use one to subtract another, their partial sum should equal 0
    for (int i = 0; i <= n; ++i) {
        o[i] -= e[i];
    }
    // now the problem reduced to finding if there are 2 same number!
    // how beautiful!
    map<int, int> cnt;
    for (int i = 0; i <= n; ++i) {
        cnt[o[i]]++;
    }
    for (auto& p : cnt) {
        if (p.second > 1) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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