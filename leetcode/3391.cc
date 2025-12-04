#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    /*
     * Note that the middle values in the path doesn't matter:
     * Let's say that the path is c1 -> c2 -> c3 -> c4 -> c5
     * Then the answer would be c2 - c1 + c3 - c2 + c4 - c3 + c5 - c4
     *  = c5 - c1
     * So for any paths, we just need to find two end points to determine the answer
     */
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> mn(n, vector<int>(m, INT_MAX));
        mn[0][0] = grid[0][0];
        for (int j = 1; j < m; ++j) {
            mn[0][j] = min({mn[0][j], grid[0][j], mn[0][j - 1]});
        }
        for (int i = 1; i < n; ++i) {
            mn[i][0] = min({mn[i][0], grid[i][0], mn[i - 1][0]});
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                mn[i][j] = min({mn[i][j], mn[i - 1][j], mn[i][j - 1], grid[i][j]});
            }
        }
        int ans = INT_MIN;
        for (int j = 1; j < m; ++j) {
            ans = max(ans, grid[0][j] - mn[0][j - 1]);
        }
        for (int i = 1; i < n; ++i) {
            ans = max(ans, grid[i][0] - mn[i - 1][0]);
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                ans = max(ans, grid[i][j] - min(mn[i - 1][j], mn[i][j - 1]));
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)