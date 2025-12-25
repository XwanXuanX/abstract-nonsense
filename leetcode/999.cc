#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    static constexpr int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

    int regionsBySlashes(vector<string>& grid) {
        const int n = grid.size();
        vector<vector<int>> expand(n * 3, vector<int>(n * 3, 0));
        auto mark1 = [&](const int i, const int j) {
            expand[i][j] = expand[i + 1][j + 1] = expand[i + 2][j + 2] = 1;
        };
        auto mark2 = [&](const int i, const int j) {
            expand[i + 2][j] = expand[i + 1][j + 1] = expand[i][j + 2] = 1;
        };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                const auto c = grid[i][j];
                if (c == '/') {
                    mark2(i * 3, j * 3);
                } else if (c == '\\') {
                    mark1(i * 3, j * 3);
                }
            }
        }
        const int nn = expand.size();
        vector<vector<int>> V(nn, vector<int>(nn, false));
        function<void(const int i, const int j)> dfs;
        dfs = [&](const int i, const int j) {
            assert(!V[i][j]);
            V[i][j] = true;
            for (int k = 0; k < 4; ++k) {
                const auto ni = i + dx[k], nj = j + dy[k];
                if (ni < 0 || ni >= nn || nj < 0 || nj >= nn || V[ni][nj] || expand[ni][nj]) {
                    continue;
                }
                dfs(ni, nj);
            }
        };
        int ans = 0;
        for (int i = 0; i < nn; ++i) {
            for (int j = 0; j < nn; ++j) {
                if (!V[i][j] && !expand[i][j]) {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)