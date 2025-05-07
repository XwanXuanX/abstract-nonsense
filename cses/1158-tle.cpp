#include <bits/stdc++.h>
using namespace std;

int dp(int x, int i, const vector<int>& h, const vector<int>& s, vector<vector<int>>& mm) {
    if (x <= 0 || i <= 0) {
        return 0;
    }
    if (mm[x][i] != -1) {
        return mm[x][i];
    }
    // if we can pick the ith item
    int pick = 0;
    if (h[i] <= x) {
        pick = dp(x - h[i], i - 1, h, s, mm) + s[i];
    }
    // we can always not pick the item
    int notPick = dp(x, i - 1, h, s, mm);
    return mm[x][i] = max(pick, notPick);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> h(n + 1);
    vector<int> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    // recursive
    {
        // vector<vector<int>> mm(x + 1, vector<int>(n + 1, -1));
        // cout << dp(x, n, h, s, mm) << '\n';
    }
    // bottom-up
    {
        vector<vector<int>> mm(x + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= x; ++i) {
            for (int j = 1; j <= n; ++j) {
                int pick = 0;
                if (h[j] <= i) {
                    pick = mm[i - h[j]][j - 1] + s[j];
                }
                int notPick = mm[i][j - 1];
                mm[i][j] = max(pick, notPick);
            }
        }
        cout << mm[x][n] << '\n';
    }
}