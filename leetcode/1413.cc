#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        const int n = mat.size(), m = mat[0].size();
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
        auto qr = [&](const int r1, const int c1, const int r2, const int c2) {
            const int total = pfs[r2][c2];
            const int top = (r1 > 0) ? pfs[r1 - 1][c2] : 0;
            const int left = (c1 > 0) ? pfs[r2][c1 - 1] : 0;
            const int overlap = (r1 > 0 && c1 > 0) ? pfs[r1 - 1][c1 - 1] : 0;
            return total - top - left + overlap;
        };
        queue<pair<int, int>> Q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                Q.push({i, j});
            }
        }
        int side = 0;
        while (Q.size()) {
            const auto [i, j] = Q.front();
            Q.pop();
            if (i + side >= n || j + side >= m) {
                continue;
            }
            const int sum = qr(i, j, i + side, j + side);
            if (sum <= threshold) {
                side++;
                Q.push({i, j});
            }
        }
        return side;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)