#include <bits/stdc++.h>
using namespace std;

constexpr int dx[] = {1, -1, 0, 0};
constexpr int dy[] = {0, 0, 1, -1};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> G(n);
    for (int i = 0; i < n; ++i) {
        cin >> G[i];
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int ans = 0;

    function<void(int i, int j)> dfs;
    dfs = [&](int i, int j) {
        vis[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || G[ni][nj] == '#' || vis[ni][nj]) {
                continue;
            }
            dfs(ni, nj);
        }
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (G[i][j] == '.' && !vis[i][j]) {
                dfs(i, j);
                ans++;
            }
        }
    }

    cout << ans << '\n';
}