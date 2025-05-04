#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n, 0);
    for (int i=0; i<n-1; ++i) {
        if (s[i+1] == s[i]) {
            a[i] += 1;
        }
    }
    a.insert(a.begin(), 0);
    for (int i=1; i<n; ++i) {
        a[i] += a[i-1];
    }
    
    // query
    int q, l, r;
    cin >> q;
    for (int i=0; i<q; ++i) {
        cin >> l >> r;
        cout << a[r-1] - a[l-1] << '\n';
    }
}