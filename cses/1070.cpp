#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    if (n == 4) {
        cout << "2 4 1 3" << '\n';
        return 0;
    }

    vector<int> ans;
    for (int i = 1; i <= n; i+=2) {
        ans.push_back(i);
    }
    for (int i = 2; i <= n; i+=2) {
        ans.push_back(i);
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}