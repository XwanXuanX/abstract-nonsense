/**
 * if a_n contains 0, the it's trivial
 * will the sequence become 0 eventually? YES!
 * assuming mx = mn = 9, then add at most 81 to the sum
 * and 999 + 81 = 1080, which def contains 0
 * so we only need to compute upto the conversion from 3 digs to 4 digs and stop
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long

int mxmn(int a) {
    int mx = 0;
    int mn = 10;
    while (a) {
        mx = max(mx, a % 10);
        mn = min(mn, a % 10);
        a /= 10;
    }
    return mx * mn;
}

void solve() {
    int a, K;
    cin >> a >> K;
    // we can just do 1000 times, cuz why not :)
    for (int i=0; i<min(K-1, 1000ll); ++i) {
        a = a + mxmn(a);
    }
    cout << a << '\n';
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