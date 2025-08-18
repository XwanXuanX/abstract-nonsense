#include <bits/stdc++.h>
#include <optional>
using namespace std;

int n;
vector<int> p;

void solve() {
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    bool alt = 0;
    string ans;
    int left = 0, right = n - 1;
    while (left < right) {
        if (alt) {
            if (p[left] > p[right]) {
                ans.push_back('L');
                ans.push_back('R');
            } else {
                ans.push_back('R');
                ans.push_back('L');
            }
            alt = 0;
        } else {
            if (p[left] > p[right]) {
                ans.push_back('R');
                ans.push_back('L');
            } else {
                ans.push_back('L');
                ans.push_back('R');
            }
            alt = 1;
        }
        left++, right--;
    }
    if (left == right) {
        ans.push_back('L');
    }
    cout << ans << '\n';
}

// cant continue decreasing nor increasing 5 times in a roll
// check if such sequence exists, if not, just put 'L'
// otherwise, 

signed main() {
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}