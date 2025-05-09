#include <bits/stdc++.h>
using namespace std;

constexpr int dx[] = {1, -1, 0, 0};
constexpr int dy[] = {0, 0, 1, -1};
constexpr char act[] = {'D', 'U', 'R', 'L'};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> G(n);
    for (int i = 0; i < n; ++i) {
        cin >> G[i];
    }

    int si = -1, sj = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (G[i][j] == 'A') {
                si = i, sj = j;
                break;
            }
        }
        if (si != -1 || sj != -1) {
            break;
        }
    }

    string ans;
    vector<vector<bool>> V(n, vector<bool>(m, false));
    function<void(int i, int j, string& path)> dfs;
    dfs = [&](int i, int j, string& path) {
        if (G[i][j] == 'B') {
            if (ans.size() == 0 || path.size() < ans.size()) {
                ans = path;
            }
            return;
        }
        V[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || V[ni][nj] || G[ni][nj] == '#') {
                continue;
            }
            path.push_back(act[k]);
            dfs(ni, nj, path);
            path.pop_back();
        }
        V[i][j] = false;
    };

    string path;
    dfs(si, sj, path);

    if (ans.size() > 0) {
        cout << "YES\n" << ans.size() << '\n' << ans << '\n';
    } else {
        cout << "NO\n";
    }
}