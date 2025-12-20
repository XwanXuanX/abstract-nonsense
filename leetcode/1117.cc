#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    struct cord { int i, j, st; };

    int maxDistance(vector<vector<int>>& grid) {
        const int n = grid.size();
        queue<cord> Q;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int h0 = 0, h1 = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    dp[i][j] = 0;
                    Q.push({i, j, 0});
                    h1 |= 1;
                } else {
                    h0 |= 1;
                }
            }
        }
        if (!h0 || !h1) {
            return -1;
        }
        while (Q.size()) {
            const auto [i, j, st] = Q.front();
            Q.pop();
            for (int k = 0; k < 4; ++k) {
                const int ni = i + dx[k], nj = j + dy[k];
                if (ni < 0 || ni >= n || nj < 0 || nj >= n || dp[ni][nj] != -1 || grid[ni][nj]) {
                    continue;
                }
                dp[ni][nj] = st + 1;
                Q.push({ni, nj, st + 1});
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)