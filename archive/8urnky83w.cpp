#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

// what does distinct means here?
// for each k, we have a lower bound
// once we fixed the lower bound, we can then choose any other odd number to fill the gap

/// preprocessing
constexpr int ub = 1e7 + 10;
vector<uint64_t> odds(ub, 0);

void solve() {
    int n, k;
    cin >> n >> k;
    if ((n % 2 == 0 && k % 2 != 0) || (n % 2 != 0 && k % 2 == 0) || k >= n) {
        cout << "NO\n";
        return;
    }
    int kth = odds[k - 1];
    cout << ((n >= kth) ? "YES\n" : "NO\n");
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /////
    int odd = 1;
    for (int i=0; i<ub; ++i) {
        odds[i] = odd;
        odd += 2;
    }
    for (int i=1; i<ub; ++i) {
        odds[i] += odds[i-1];
    }
    /////
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}