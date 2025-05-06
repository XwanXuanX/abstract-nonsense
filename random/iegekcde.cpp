#include <bits/stdc++.h>
using namespace std;
#define int long long

int msb(int n) {
    int ans = -1;
    while (n) {
        ans++;
        n >>= 1;
    }
    assert(ans >= 0);
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }
    map<int, int> cnt;
    for (int i=0; i<n; ++i) {
        int m = msb(a[i]);
        cnt[m]++;
    }
    int ans = 0;
    for (auto& p : cnt) {
        ans += (p.second * (p.second - 1)) / 2;
    }
    cout << ans << '\n';
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
 * for XOR, all different bits will be 1
 * for AND, all different bits will be 0
 * ai & aj >= ai ^ aj iff the first bit is the same and both are 1
 */