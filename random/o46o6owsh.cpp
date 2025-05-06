#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    const int _n = n * (n-1) / 2;
    vector<int> a(_n);
    for (int i=0; i<_n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> ans;
    int st = 0;
    // loops on the # of appearance
    for (int i=n-1; i>=1; --i) {
        ans.push_back(a[st]);
        st += i;
    }
    // just give an upperbound LOL
    ans.push_back(1e9);
    for (int i=0; i<ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

/**
 * what matters here is the number of occurance
 * since the order of array b doesn't matter
 * -2 -2 -2 -2 0 0 0 0 0 3
 * -2 0 0 3 4
 * the smallest element is bound to appear exactly N-1 times
 * and by inspecting the number of times other elements appear
 * we can know how many times they appear in the original array
 */

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}