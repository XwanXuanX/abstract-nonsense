#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    struct cord { int i, j, s; };
    static constexpr int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

    static int orangesRotting(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        vector<vector<int>> V(n, vector<int>(m, 0));
        queue<cord> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    V[i][j] = 1;
                    q.push({i, j, 0});
                }
            }
        }
        int ans = 0;
        while (q.size()) {
            const auto [i, j, s] = q.front();
            q.pop();
            assert(grid[i][j] == 2 && V[i][j]);
            ans = max(ans, s);
            for (int k = 0; k < 4; ++k) {
                const int ni = i + dx[k], nj = j + dy[k];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m || V[ni][nj] || grid[ni][nj] != 1) continue;
                grid[ni][nj] = 2;
                V[ni][nj] = 1;
                q.push({ni, nj, s + 1});
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) return -1;
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)