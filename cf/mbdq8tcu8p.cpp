#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if (2 * a < b) {
        cout << (x * a) + (y * a) <<'\n';
        return;
    }
    // take double as much as possible is good
    cout << ((max(x, y) - min(x, y)) * a) + (min(x, y) * b) << '\n';
    return;
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
 * notice that the total number of operations for each type does not change
 * when is better to do single than double? that is when 2 * single < 1 * double 
 * but what's the point of increasing? 
 * if d << s, but diff = (x - y) will not change, so you still need to pay diff * s dollars
 */