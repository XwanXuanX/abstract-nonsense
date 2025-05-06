#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }
    if (n <= 1) {
        cout << "0\n";
        return;
    }
    map<int, int> mp;
    for (int i=0; i<n; ++i) {
        mp[a[i]]++;
    }
    int mx = 0;
    for (auto& p : mp) {
        mx = max(mx, p.second);
    }

    // change of stratagy: add same value first then distinct values
    int ans = min(mx, (int)mp.size() - 1);
    // then we can at most take one away
    int ans2 = min(mx - 1, (int)mp.size());
    cout << max(ans, ans2) << '\n';
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
 * what is the upper bound?
 * min((max number of student with the same skill), (# of distinct skills), (n/2))
 * what is the lower bound? 0
 * add all distinct values first, then see what you can add next - does not work...
 */