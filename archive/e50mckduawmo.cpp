#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }
    map<int, vector<int>> pos;
    for (int i=0; i<n; ++i) {
        pos[a[i]].push_back(i);
    }
    int found = false;
    for (auto& p : pos) {
        if (p.second.size() >= 3) {
            found = true;
            break;
        }
        for (int i=1; i<p.second.size(); ++i) {
            if (p.second[i] - p.second[i-1] > 1) {
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    if (found) {
        cout << "YES\n"; 
    } else {
        cout << "NO\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}

/**
 * we should only check 3 palindrom case. why? since there will always be a
 * subsequence of 3 from a palindrom of at least 3. so 3 will always exists if such
 * palindrom exists.
 * um, you can use binary search, but the complexity will be O(n^2log(n)) which is too much
 * if any number appears twice, and they are not next to each other, we have the answer
 */