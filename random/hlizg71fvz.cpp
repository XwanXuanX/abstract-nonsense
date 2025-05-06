/**
 * Q: how many different gangs you need at least
 * if there are N nodes, then the most occuring gang cannot exceed (N/2) or (N/2) + 1
 */

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }
    map<int, vector<int>> gang;
    for (int i=0; i<n; ++i) {
        gang[a[i]].push_back(i + 1);
    }
    // we need to pick a random root, then attach all other gang to it
    // keep doing until we have one last gang left
    // attach them as the leaf
    if (gang.size() < 2) {
        cout << "NO\n";
        return;
    }
    vector<vector<int>> gangs;
    for (auto& p : gang) {
        gangs.push_back(p.second);
    }
    int start = gangs[0][0];
    vector<pair<int, int>> ans;
    for (int i=1; i<gangs.size(); ++i) {
        for (int j=0; j<gangs[i].size(); ++j) {
            ans.push_back(make_pair(start, gangs[i][j]));
        }
        start = gangs[i][0];
    }
    for (int i=1; i<gangs[0].size(); ++i) {
        ans.push_back(make_pair(start, gangs[0][i]));
    }
    cout << "YES\n";
    assert(ans.size() == n - 1);
    for (auto& p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }
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