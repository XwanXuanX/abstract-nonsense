#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int ans = 0;
    for (auto& p : cnt) {
        // we first greedly assign people to their smallest possible groups
        ans += p.second / p.first;
        // then record how many people are left after assigning
        p.second = p.second % p.first;
    }
    // then we need to see if the remaining people can form groups
    map<int, int> non0;
    for (auto& p : cnt) {
        if (p.second > 0) {
            non0[p.first] = p.second;
        }
    }
    int mx = 0;
    int sz = 0;
    for (auto& p : non0) {
        for (int i=0; i<p.second; ++i) {
            mx = max(mx, p.first);
            sz++;
            if (sz >= mx) {
                ans++;
                sz = mx = 0;
            }
        }
    }
    cout << ans << '\n';
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