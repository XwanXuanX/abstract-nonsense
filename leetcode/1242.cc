#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> pfs(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                pfs[i][j] = mat[i][j];
                if (i > 0)
                    pfs[i][j] += pfs[i - 1][j];
                if (j > 0)
                    pfs[i][j] += pfs[i][j - 1];
                if (i > 0 && j > 0)
                    pfs[i][j] -= pfs[i - 1][j - 1];
            }
        }
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                const int r2 = min(i + k, n - 1), c2 = min(j + k, m - 1);
                const int r1 = max(i - k, 0), c1 = max(j - k, 0);
                const int tot = pfs[r2][c2];
                const int top = (r1 > 0) ? pfs[r1 - 1][c2] : 0;
                const int left = (c1 > 0) ? pfs[r2][c1 - 1] : 0;
                const int overlap = (r1 > 0 && c1 > 0) ? pfs[r1 - 1][c1 - 1] : 0;
                ans[i][j] = tot - top - left + overlap;
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)