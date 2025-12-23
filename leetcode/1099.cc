#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

    // Solution 1
    int _maximumMinimumPath(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        vector<int> pos;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                pos.push_back(grid[i][j]);
            }
        }
        sort(pos.begin(), pos.end());
        auto check = [&](const int v) {
            vector<vector<int>> V(n, vector<int>(m, 0));
            queue<pair<int, int>> Q;
            auto push = [&](int r, int c) {
                if (r < 0 || r >= n || c < 0 || c >= m || V[r][c] || grid[r][c] < v) {
                    return;
                }
                Q.push({r, c});
                V[r][c] |= 1;
            };
            push(0, 0);
            while (Q.size()) {
                const auto [i, j] = Q.front();
                Q.pop();
                if (i == n - 1 && j == m - 1) {
                    return true;
                }
                for (int k = 0; k < 4; ++k) {
                    push(i + dx[k], j + dy[k]);
                }
            }
            return false;
        };

        int l = 0, r = pos.size() - 1, ans = 0;
        while (l <= r) {
            const int mid = (l + r) >> 1;
            if (check(pos[mid])) {
                ans = max(ans, pos[mid]);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

    // Solution 2
    int maximumMinimumPath(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({grid[0][0], {0, 0}});
        vector<vector<int>> V(n, vector<int>(m, 0));
        V[0][0] |= 1;
        int ans = grid[0][0];
        while (pq.size()) {
            const auto [i, j] = pq.top().second;
            const auto v = pq.top().first;
            pq.pop();
            ans = min(ans, v);
            if (i == n - 1 && j == m - 1) {
                break;
            }
            for (int k = 0; k < 4; ++k) {
                const int ni = i + dx[k], nj = j + dy[k];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m || V[ni][nj]) {
                    continue;
                }
                pq.push({grid[ni][nj], {ni, nj}});
                V[ni][nj] |= 1;
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)