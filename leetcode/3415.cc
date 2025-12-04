#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i + 1 < n && grid[i + 1][j] != grid[i][j]) {
                    return false;
                }
                if (j + 1 < m && grid[i][j + 1] == grid[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)