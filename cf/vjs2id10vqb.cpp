#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    deque<int> p;
    for (int i = 0; i < n; ++i) {
        if (a[i]) {
            p.push_back(i);
        }
    }
    if ((int)p.size() < s) {
        cout << -1 << '\n';
        return;
    }

    int sum = accumulate(p.begin(), p.end(), 0);
    int l = 0, r = n - 1;
    int ans = 0;
    while ((int)p.size() > s) {
        int ld = sum - (p.size() * l);
        int rd = (p.size() * r) - sum;
        if (ld > rd) {
            ans += (r - p.back() + 1);
            r = p.back() - 1;
            sum -= p.back();
            p.pop_back();
        } else {
            ans += (p.front() - l + 1);
            l = p.front() + 1;
            sum -= p.front();
            p.pop_front();
        }
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