#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }
    vector<int> b(a.begin(), a.end());
    b.insert(b.begin(), 0);
    for (int i=1; i<n; ++i) {
        a[i] = max(a[i], a[i-1]);
    }
    for (int i=1; i<n+1; ++i) {
        b[i] += b[i-1];
    }
    // query
    int k;
    for (int i=0; i<q; ++i) {
        cin >> k;
        int j = upper_bound(a.begin(), a.end(), k) - a.begin();
        cout << b[j] << ' ';
    }
    cout << '\n';
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

/**
 * so the question is asking for the position of the first element which is bigger than
 * some number. binary search :)
 */