#include <bits/stdc++.h>
using namespace std;

int count1s(int n) {
    int ans = 0;
    while (n) {
        ans += (n & 1);
        n >>= 1;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m + 1);
    for (int i=0; i<m+1; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i=0; i<m; ++i) {
        if (count1s(a[m] ^ a[i]) <= k) {
            ans++;
        }
    }
    cout << ans << '\n';
}