#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    int tot = (n * (n + 1)) / 2;
    if (tot % 2) {
        cout << "NO\n";
        return 0;
    }
    // there is always a solution to achieve half
    int half = tot / 2;
    set<int> a;
    for (int i = n; i >= 1; --i) {
        if (half >= i) {
            a.insert(i);
            half -= i;
        }
        if (half == 0) {
            break;
        }
    }
    set<int> b;
    for (int i = 1; i <= n; ++i) {
        if (!a.count(i)) {
            b.insert(i);
        }
    }

    cout << "YES\n";
    cout << a.size() << '\n';
    for (auto& i : a) {
        cout << i << ' ';
    }
    cout << '\n';
    cout << b.size() << '\n';
    for (auto& i : b) {
        cout << i << ' ';
    }
    cout << '\n';
}