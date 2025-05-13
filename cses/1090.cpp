#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, x, in;
    cin >> n >> x;
    multiset<int> a;
    for (int i = 0; i < n; ++i) {
        cin >> in;
        a.insert(in);
    }

    int ans = 0;
    while (a.size() > 1) {
        int c = *a.begin();
        auto it = a.upper_bound(x - c);
        it--;
        if (it == a.end() || it == a.begin()) {
            a.erase(a.begin());
        } else {
            a.erase(it);
            a.erase(a.begin());
        }
        ans++;
    }

    cout << ans + a.size() << '\n';
}